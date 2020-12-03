#include<Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_ADXL345_U.h>
#include <WiFi.h>
const char* ssid = "*...*";
const char* password = "Nanditha@1";
const uint16_t port = 8090;
const char * host = "192.168.43.64";
int a[3];
long pulse;
long Systolic;
long Diastolic;
WiFiClient client;
Adafruit_ADXL345_Unified accel = Adafruit_ADXL345_Unified();
WiFiServer wifiServer(80);
void setup() {
  Serial.begin(9600);
 // Serial.begin(115200);
 
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.println("hello");
  }
 
  Serial.print("WiFi connected with IP: ");
  Serial.println(WiFi.localIP());
  if(!accel.begin())
  {
    Serial.println("ADXL345 not detected");
    while(1);
  }
  wifiServer.begin();
  randomSeed(analogRead(0));
}

void loop() {
  // put your main code here, to run repeatedly:
  pulse= random(60,80);
  Systolic=random(90,120);
  Diastolic= random(60,80);
  sensors_event_t event;
  accel.getEvent(&event);
  float at = sqrt(event.acceleration.x*event.acceleration.x + event.acceleration.y*event.acceleration.y + event.acceleration.z*event.acceleration.z);
 // Serial.println(at);
  if (at < 2) {
       Serial.print("FALL DETECTED");
       pulse=random(135,150);
       Systolic=random(35,50);
       Diastolic= random(60,80);
       
  sensors_event_t event;
       
   }
   
 
    if (!client.connect(host, port)) {

        Serial.println("Connection to host failed");
        return;
    }
 
    Serial.println("Connected to server successful!");
    String myString = String(pulse)+String(",")+String(Systolic)+String(",")+String(Diastolic);
    client.print(myString);
    client.stop();
    //int c = (char)client.read();
   WiFiClient newClient= wifiServer.available();
    if (!client) {
      return;
    }
 
  // Wait until the client sends some data
  Serial.println("new client");
  while(!client.available()){
    delay(100);
  }
 
  // Read the first line of the request
    
    Serial.println("Disconnecting...");
    
  /* else {
       digitalWrite(13,LOW);
        }*/
       //send (pulse,systol,diastol) via socket
  delay(100);
  client.stop();
}
