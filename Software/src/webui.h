#ifndef WEBUI_H
#define WEBUI_H

#include <Arduino.h>
#include <WebSocketsServer.h>

// ----- Type definitions
typedef union
{
  uint8_t arr[6];
  struct
  {
    uint8_t grp;
    uint8_t cmd;
    union
    {
      float val;
      uint8_t valU8[4];
    };
  } __attribute__((packed));
} cmd;

// Plot settings
struct
{
  boolean enable = 0; // Enable sending data
  uint8_t prescaler = 4;
} plot;

void sendWifiList(void);
void webSocketEvent(uint8_t num, WStype_t type, uint8_t *payload, size_t length);

bool WebUI_setup();
void WebUI_loop();

#endif // WEBUI_H
