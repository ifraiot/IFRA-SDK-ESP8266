#include "IFRAIoT.h"


IFRAIoT::IFRAIoT(char* username, char* password ){
        _username = username;
        _password = password;
        _mqtt_client.setClient(_espClient);
        _mqtt_client.setServer(IFRASERVER, MQTT_PORT);
        // _mqtt_client.setCallback(callback);
}

bool IFRAIoT::wifiConnection(char *ssid, char *pass){
  WiFi.begin(ssid, pass);
  Serial.print("Start connect wifi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  WiFi.setAutoReconnect(true);
  Serial.println(F("WiFi connected"));
  Serial.println(F("IP address: "));
  Serial.println(WiFi.localIP());
}


bool IFRAIoT::mqttConnection(char *mqtt_topic){

     Serial.print("Attempting MQTT connection...");
    if (_mqtt_client.connect("ESP8266Client", _username, _password)) {
      Serial.println("connected");
      _mqtt_client.subscribe(mqtt_topic);
    } else {
      Serial.print("failed, rc=");
      Serial.print(_mqtt_client.state());
      Serial.println(" try again in 5 seconds");
      delay(5000);
  }
  
   _mqtt_client.loop();
}

void IFRAIoT::addMeasure(char *var_id, float value){
  
}

void IFRAIoT::send(void){
   if(!_mqtt_client.connected()) {
         mqttConnection("organization/2/messages");
   }else{
      Serial.println("ready to send");
   }
}
