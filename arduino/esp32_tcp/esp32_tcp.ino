#include <WiFi.h>
//#include <ESP8266WiFi.h>

const char *ssid = "SK_WiFiGIGA1A6B";
const char *password = "2006085176";
const int server_port = 55000;

WiFiServer server(server_port);

void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);

  delay(2000);
  Serial.println("Initial Connecting to WiFi...");

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting...");
    Serial.println(WiFi.status());
  }

  Serial.println("WiFi connected!");
  // check for the presence of the shield:
  if (WiFi.status() == WL_NO_SHIELD) {
    Serial.println("WiFi shield not present");
    while (true);       // don't continue
  }
  Serial.println("IP Address: " + WiFi.localIP().toString());

  // Start the server
  Serial.println("Server Connecting...");
  server.begin();
  Serial.println("Server started on port " + String(server_port));
}

void loop() {
  WiFiClient client = server.available();
  if(client){
    Serial.println("Client connected");

    // Read data from the client
    String data_received = client.readStringUntil('\n');
    Serial.println("Data received from Colab: " + data_received);

    // Send a response back to the client
    client.println("Hello from Arduino!");

    // Close the connection
    client.stop();
    Serial.println("Client disconnected");
  }
}
