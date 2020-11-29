//connection vcc to 3v3
//gnd to gnd
//out to d15
//out of other sensor d2
//i think ground to ground is wrong
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
}
void loop() {  
  detection = digitalRead(IR);
  detection1 = digitalRead(IR1);
  if(detection1 ==0 && detection== 0){
    Serial.print("There is an obstacle!\n");
    digitalWrite(buzzpin,HIGH);
  }
  else{
    Serial.print("No obstacle!\n");
    digitalWrite(buzzpin,LOW);
  }
  delay(500);    // in ms
}
