#include <WiFi.h>

int Wifi_status_cnt = 0;

void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);

  delay(2000);
  Serial.println("Initial Connecting to WiFi...");

  WiFi.begin("Daisy", "11111111");

  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting...");
    Serial.println(WiFi.status());
  }

  Serial.println("WiFi connected!");
  Serial.println(WiFi.localIP());


}

void loop() {
  // Your main code here
  if(WiFi.status() != 3) {
    Serial.println(WiFi.status());
    delay(1000);
  }

}
