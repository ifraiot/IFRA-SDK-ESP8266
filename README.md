# IFRAIoT


## Example
```
#include <IFRAIoT.h>
 
#define USERNAME "05fd5734-612d-4844-b90b-f554f59f37e2"
#define PASSWORD "7897e894-c899-40c1-9f5a-1daee6826826"
 
#define WIFI_SSID "ifrasoft"
#define WIFI_PASSWORD "12345"

IFRAIoT device(USERNAME,PASSWORD);
 
void setup() {
    Serial.begin(115200);
    device.wifiConnection(WIFI_SSID,WIFI_PASSWORD);
     
}

void loop() {
  device.addMeasure("Temp1", 10.0);
  device.addMeasure("Temp2", 10.0);
  device.send();
  delay(1000);
}
```
