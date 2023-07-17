#include <Servo.h>
int irsensor =3 ;
int irsensor2 =5 ;
int led =13 ;
int servoPin = 4;

//seven segment
const int A = 12;
const int B = 11;
const int C = 10;
const int D = 9;
const int E = 8;
const int F = 7;
const int G = 6;
const int DP = 2;
Servo servo;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(irsensor, INPUT);
  pinMode(led, OUTPUT);
  servo.attach(servoPin);
  servo.write(0); 
  pinMode(A, OUTPUT);

  pinMode(B, OUTPUT);

  pinMode(C, OUTPUT);

  pinMode(D, OUTPUT);

  pinMode(E, OUTPUT);

  pinMode(F, OUTPUT);

  pinMode(G, OUTPUT);

  pinMode(DP, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(irsensor) == LOW){
    digitalWrite(led, HIGH);
    servo.write(90);
    one();
//  delay(1000);
    delay(10);
  }else{
    digitalWrite(led, LOW);
    servo.write(0);
    delay(10);
  }

  if(digitalRead(irsensor2) == LOW){
    digitalWrite(led, HIGH);
    servo.write(90);
    delay(10);
  }else{
    digitalWrite(led, LOW);
    servo.write(0);
    delay(10);
  }

  

//  one();
//
//  delay(1000);
//
//  two();
//
//  delay(1000);
//
//  three();
//
//  delay(1000);
//
//  four();
//
//  delay(1000);   
}

void zero(){

  digitalWrite(A, LOW);

  digitalWrite(B, LOW);

  digitalWrite(C, LOW);

  digitalWrite(D, LOW);

  digitalWrite(E, LOW);

  digitalWrite(F, LOW);

  digitalWrite(G, HIGH);

  digitalWrite(DP, LOW);

}

void one(){

  digitalWrite(A, HIGH);

  digitalWrite(B, LOW);

  digitalWrite(C, LOW);

  digitalWrite(D, HIGH);

  digitalWrite(E, HIGH);

  digitalWrite(F, HIGH);

  digitalWrite(G, HIGH);

  digitalWrite(DP, LOW);

}

void two(){

  digitalWrite(A, LOW);

  digitalWrite(B, LOW);

  digitalWrite(C, HIGH);

  digitalWrite(D, LOW);

  digitalWrite(E, LOW);

  digitalWrite(F, HIGH);

  digitalWrite(G, LOW);

  digitalWrite(DP, LOW);

}

void three(){

  digitalWrite(A, LOW);

  digitalWrite(B, LOW);

  digitalWrite(C, LOW);

  digitalWrite(D, LOW);

  digitalWrite(E, HIGH);

  digitalWrite(F, HIGH);

  digitalWrite(G, LOW);

  digitalWrite(DP, LOW);

}

void four(){

  digitalWrite(A, HIGH);

  digitalWrite(B,LOW );

  digitalWrite(C,LOW );

  digitalWrite(D, HIGH);

  digitalWrite(E, HIGH);

  digitalWrite(F,LOW );

  digitalWrite(G,LOW );

  digitalWrite(DP, LOW);

}
