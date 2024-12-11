// ##########################
// #    SMARTSHOP NETWORK   #
// ##########################

# pragma once

# include <WiFi.h>

# include <sylo/logging.hpp>

# include "private/wifi_creds.hpp"

/// @brief Hostname of the Hub
# define COSY_HUB_HOSTNAME "hub.local"

// Ports
# define COSY_HUB_MQTT_PORT 1883

namespace cosy {
  namespace remote {
    void connect(const char* hostname) {
      // Configure WiFi
      WiFi.config(INADDR_NONE, INADDR_NONE, INADDR_NONE, INADDR_NONE);
      WiFi.setHostname(hostname);
      WiFi.mode(WIFI_MODE_STA);
      WiFi.begin(PRIVATE_WIFI_SSID, PRIVATE_WIFI_PWD);

      // Connection attempt
      log_info("| > Connecting ");
      while (WiFi.status() != WL_CONNECTED) {
        log_info(".");
        delay(500);
      }
      log_infoln(" done!");
      
      log_info("| | > IP: ");
      log_infoln(WiFi.localIP());

      log_info("| | > RRSI: ");
      log_infoln(WiFi.RSSI());
    }

    /// @brief Resolves the IP-Address of the hub-server when connected to a WiFi
    /// @return The IP-Address of the hub
    IPAddress resolve_hub() {
      IPAddress hub_ip;

      log_info("> Resolving hub hostname ... ");
      WiFi.hostByName(COSY_HUB_HOSTNAME, hub_ip);
      log_infoln("done!");

      log_debug("| > IP: '");
      log_debug(hub_ip);
      log_debugln("'");

      return hub_ip;
    }
  }
}