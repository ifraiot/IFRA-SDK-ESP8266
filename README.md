# IFRAIoT


## Example
Send Humidity and Temperature data from ESP8266 device to IFRA IoT Platform. 
```
#include <IFRAIoT.h>
#include <DHT.h>

#define USERNAME "05fd5734-612d-4844-b90b-f554f59f37e2"
#define PASSWORD "7897e894-c899-40c1-9f5a-1daee6826826"

#define WIFI_SSID "ifrasoft"
#define WIFI_PASSWORD "@ifrasoft2020"

IFRAIoT device(USERNAME, PASSWORD);
DHT dht(2, DHT11, 15);

void setup() {
  Serial.begin(115200);
  device.wifiConnection(WIFI_SSID, WIFI_PASSWORD);



  dht.begin();

}

void loop() {
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  device.addMeasure("Humidity", h);
  device.addMeasure("Temperature", t);
  device.send();
  delay(1000);
}
```
