#include <FB_HTTPClient32.h>
#include <FirebaseESP32.h>
#include <FirebaseJson.h>
#include "FirebaseESP32.h"
FirebaseData firebaseData;
#include <WiFi.h>                                                // esp32 library                                            
#define FIREBASE_HOST "fall-detect-bc0b4.firebaseio.com"
#define FIREBASE_AUTH "V0iAyyixuWEnT3usuMF2vf1aMXKl0qQMOrqUcpwu"    
#define WIFI_SSID "Naresh"           
#define WIFI_PASSWORD "11April2002"

#define buzzpin 5

void setup() {
  Serial.begin(9600);  
  pinMode(buzzpin, OUTPUT);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);                                  
  Serial.print("Connecting to ");
  Serial.print(WIFI_SSID);
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
}
void loop() {  
  int x= Firebase.getInt(firebaseData,"/Fall"); 
  Serial.println(x)
  if(x == 1){
    //Serial.print("There is an obstacle!\n");
    digitalWrite(buzzpin,HIGH);
    delay(1500);
    digitalWrite(buzzpin,LOW);
  }
  else{
    //Serial.print("No obstacle!\n");
    //digitalWrite(buzzpin,LOW);
  }
  delay(500);    // in ms
}
