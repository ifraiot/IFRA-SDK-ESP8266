#include <ESP8266WiFi.h>
#include "WiFiUdp.h"
#include <PubSubClient.h>

#ifndef IFRASERVER
#define IFRASERVER "hub.ifra.io"
#endif

#ifndef MQTT_PORT
#define MQTT_PORT 1883
#endif
 
class IFRAIoT
{
private:
    char* _username;
    char* _password;
    WiFiClient _espClient;
    PubSubClient _mqtt_client;

public:
    IFRAIoT(char* username, char* password);
    bool wifiConnection(char *ssid, char *pass);
    bool mqttConnection(char *mqtt_topic);
    void addMeasure(char *var_id, float value);
    void send(void);
};





