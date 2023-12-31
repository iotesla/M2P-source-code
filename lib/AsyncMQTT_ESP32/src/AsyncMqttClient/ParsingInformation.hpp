/****************************************************************************************************************************
  ParsingInformation.hpp
  
  AsyncMQTT_ESP32 is a library for ESP32 boards using WiFi or LwIP W5500 / W6100 / ENC28J60 / LAN8720 Ethernet

  Based on and modified from :

  1) async-mqtt-client (https://github.com/marvinroger/async-mqtt-client)
  2) AsyncMQTT_Generic (https://github.com/khoih-prog/AsyncMQTT_Generic)

  Built by Khoi Hoang https://github.com/khoih-prog/AsyncMQTT_ESP32
 *****************************************************************************************************************************/

#pragma once

#ifndef PARSING_INFORMATION_HPP
#define PARSING_INFORMATION_HPP

namespace AsyncMqttClientInternals 
{
  enum class BufferState : uint8_t 
  {
    NONE              = 0,
    REMAINING_LENGTH  = 2,
    VARIABLE_HEADER   = 3,
    PAYLOAD           = 4
  };

  struct ParsingInformation 
  {
    BufferState bufferState;

    uint16_t maxTopicLength;
    char* topicBuffer;

    uint8_t packetType;
    uint16_t packetFlags;
    uint32_t remainingLength;
  };
}  // namespace AsyncMqttClientInternals

#endif    // PARSING_INFORMATION_HPP
