#ifndef RClient_h
#define RClient_h

#include "Arduino.h"

class RClient
{

  private:
    const char *ssid = "DESKTOP-PTFSVRE 2560";
    const char *password = "E404h58]";

  public:
    RClient();
    void setupClient(void);
    void getRequest(String);
};

#endif // RClient_h