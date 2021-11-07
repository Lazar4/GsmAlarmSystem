#include <SoftwareSerial.h>
#define trigPin 2
#define echoPin 3

// Configure software serial port
SoftwareSerial SIM900(7, 8);

//Variable to save incoming SMS characters
char incoming_char=0;
String message;
int led = 9; //led for indication
int sirena = 5; //alarm sound
long duration;
int distance;

void setup() {
   SIM900.begin(19200);
   Serial.begin(19200); 
  // Give time to your GSM shield log on to network
  delay(20000);
  // AT command to set SIM900 to SMS mode
  SIM900.print("AT+CMGF=1\r"); 
 
  // Set module to send SMS data to serial out upon receipt 
  SIM900.print("AT+CNMI=2,2,0,0,0\r");

  pinMode(led, OUTPUT);
  pinMode(button, INPUT_PULLUP);
  pinMode(sirena, OUTPUT);
  digitalWrite(led,LOW);

   pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {

  //setting up ultrasonic sensor
  digitalWrite(trigPin, LOW);   
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);

  // Calculate the distance:
  distance = duration * 0.034 / 2;
  Serial.print("Distance = ");  
  Serial.print(distance);
  Serial.println(" cm");
  delay(50);
  
  if(SIM900.available() >0) {
    message = SIM900.readString();
    //Get the character from the cellular serial port
  
  }
  else
  {
  message = "";
  }
   if(message.indexOf("+381601416081")> -1){
    if(message.indexOf("ON") > -1){
      Serial.println("LED ON");
      digitalWrite(led, HIGH);
  }
    else if(message.indexOf("OFF") > -1){

      Serial.println("LED OFF");
      digitalWrite(led,LOW);
}

  delay(10);
}
 if(distance < 20  && digitalRead(led) == HIGH){
  SIM900.println("ATD + +381601416081;");
  delay(100);
  SIM900.println();
  digitalWrite(sirena, HIGH);
  delay(4000);
  digitalWrite(sirena, LOW);

 }
}