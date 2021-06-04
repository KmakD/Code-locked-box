#include <Servo.h>
#define servo_pin 3
#define button1 10
#define button2 11
#define button3 12
#define button4 13
#define photoresistor A51

int p = 0;
String code = "acbd";
String check_code = "";
Servo servo;

void setup() {
  Serial.begin(9600);
  servo.attach(servo_pin);
  pinMode(button1, INPUT_PULLUP);
  pinMode(button2, INPUT_PULLUP);
  pinMode(button3, INPUT_PULLUP);
  pinMode(button4, INPUT_PULLUP);
  servo.write(5);
}

void loop() {
  
  //write button sequence
  if(check_code.length() < 4){
    if(digitalRead(button1) == LOW){
      check_code = check_code + 'a';
      Serial.println(check_code);
      delay(500);
    }else   if(digitalRead(button2) == LOW){
      check_code = check_code + 'b';
      Serial.println(check_code);
      delay(500);
    }else   if(digitalRead(button3) == LOW){
      check_code = check_code + 'c';
      Serial.println(check_code);
      delay(500);
    }else   if(digitalRead(button4) == LOW){
      check_code = check_code + 'd';
      Serial.println(check_code);
      delay(500);
    }
  }else {
    check_code = "";
  }

   
   if(check_code == code){  //unlock box
    servo.write(100);
    delay(5000);
    p = 0;
   } else if(analogRead(photoresistor) < 50 && p == 0){ //lock box automaticly
    delay(1000);       
    servo.write(5);
    p = 1;
   }
}
