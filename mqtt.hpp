// ###############################
// #    circlelab MQTT-TOPICS    #
// ###############################

# pragma once

// Libraries
# include <WiFi.h>
# include <PubSubClient.h>

# include "network.hpp"

// Functions
# define JOIN_TOPICS(__t1, __t2) __t1 "/" __t2

// Topics
# define TOPIC_MODULES                  "circlelab/modules"

# define TOPIC_TEMP                     "circlelab/temp"
# define TOPIC_HUMID                    "circlelab/humid"

# define TOPIC_LIGHT_CHAIN_MAIN         "circlelab/light/chain_main"
# define TOPIC_LIGHT_CHAIN_LIVING       "circlelab/light/chain_living"

// MQTT data structure
namespace circlelab {
  static float humid = 0.0;
  static float temp = 0.0;

  namespace light {
    static bool chain_main = false;
    static bool chain_living = false;
  }
}

namespace cosy {
  namespace remote {
    typedef void (*MQTTCallback)(char*, uint8_t*, unsigned int);

    void connect_mqtt(PubSubClient* mqtt_client, MQTTCallback mqtt_callback) {
      IPAddress hub_ip = resolve_hub();
       
      mqtt_client->setServer(hub_ip, COSY_HUB_MQTT_PORT);
      mqtt_client->setCallback(mqtt_callback);
    }
  }
}