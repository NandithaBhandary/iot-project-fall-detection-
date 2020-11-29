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
#define IR 15
#define IR1 2
#define buzzpin 5
int detection=HIGH;
int detection1=HIGH;// no obstacle
void setup() {
  Serial.begin(9600);  
  pinMode(IR, INPUT);
  pinMode(IR1, INPUT);
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
  detection = digitalRead(IR);
  detection1 = digitalRead(IR1);  
  Firebase.setInt(firebaseData,"/IR1", detection); 
  Firebase.setInt(firebaseData,"/IR2", detection1); 
  if(detection1 ==0 && detection== 0){
    //Serial.print("There is an obstacle!\n");
    digitalWrite(buzzpin,HIGH);
  }
  else{
    //Serial.print("No obstacle!\n");
    digitalWrite(buzzpin,LOW);
  }
  delay(500);    // in ms
}
