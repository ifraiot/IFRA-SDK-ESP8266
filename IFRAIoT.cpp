#include "IFRAIoT.h"

DynamicJsonDocument _doc(1024);

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

}
 
void IFRAIoT::addMeasure(char *var_id, float value){
   
   if(_doc.size()<1){
      _arr = _doc.to<JsonArray>(); 
   }
      JsonObject obj  = _doc.createNestedObject();
      obj["bn"] = var_id;
      obj["n"] = var_id;
      obj["v"] = value;
      obj["bu"] = var_id;
      obj["t"] = var_id;
 
}

void IFRAIoT::send(void){
   if(!_mqtt_client.connected()) {
     if (_mqtt_client.connect("ESP8266Client", _username, _password)) {
       Serial.println("connected");
       _mqtt_client.subscribe("organization/2/messages");
     } else {
      Serial.print("failed, rc=");
      Serial.print(_mqtt_client.state());
      Serial.println(" try again in 5 seconds");
      delay(5000);
      return;
     }
         
   }else{
      // serializeJsonPretty(_doc, Serial);
   
      char message[2024];
      serializeJsonPretty(_doc, message);

      _mqtt_client.publish("organization/2/messages", message);
      Serial.println(message);
   }
    _doc.clear();
    _mqtt_client.loop();
}
