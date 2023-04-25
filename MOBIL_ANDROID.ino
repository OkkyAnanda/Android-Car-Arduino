#include <SoftwareSerial.h>
#include <Servo.h>

SoftwareSerial bluetooth(11,10);
Servo servoLeft;
Servo servoRight;
Servo servoHead;

int M1MA = 7;
int M1MU = 6;
int M2MA = 5;
int M2MU = 4;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
bluetooth.begin(9600);
servoLeft.attach(8);
servoRight.attach(9);
servoHead.attach(3);
 servoLeft.write(180);
 servoRight.write(0);
 servoHead.write(90);
pinMode (4,OUTPUT) ;
pinMode (5,OUTPUT) ;
pinMode (6,OUTPUT) ;
pinMode (7,OUTPUT) ;
}

void loop(){
  //iniserial();
 // inibluetooth();
  if (bluetooth.available()>0){
  char data=bluetooth.read();
  if (data=='1'){
  maju();
 //bluetooth.println("maju");
  
}else if(data=='4'){
  belokkanan();
   // bluetooth.println("belok kanan");
}else if(data=='3'){
  belokkiri();
  bluetooth.println("belok kiri");
}else if(data=='2'){
  mundur();
 bluetooth.println("mundur");
}else if(data=='0'){
  berhenti();  
}else if(data=='5'){
  tangankanannaik();  
}else if(data=='6'){
  tangankananturun();
}else if(data=='7'){
  tangankirinaik();  
}else if(data=='8'){
  tangankiriturun();
}else if(data='a'){
  tangankanannaik();
  tangankirinaik();
}else if(data='b'){
  tangankananturun();
  tangankiriturun();
}else if(data='c'){
  maju();
  delay(1000);
  berhenti();
}else if(data='d'){
  mundur();
  delay(1000);
  berhenti();
}else if(data='e'){
  belokkanan();
  delay(500);
  berhenti();
 }else if(data='f'){
 belokkiri();
 delay(500);
 berhenti();
}else if(data=='g'){
  kepalakekanan();  
}else if(data=='h'){
  kepalakekiri();  
}else if(data=='i'){
  kepalaketengah();  
}
}
}

void inibluetooth() {
  // put your main code here, to run repeatedly:


}
void iniserial() {
  // put your main code here, to run repeatedly:

 if (Serial.available()>0){
  char data=Serial.read();
  if (data=='1'){
  maju();
 //  bluetooth.println("maju");
}else if(data=='4'){
  belokkanan();
   
}else if(data=='3'){
  belokkiri();
  
}else if(data=='2'){
  mundur();
 
}else if(data=='0'){
  berhenti();  
}else if(data=='5'){
  tangankanannaik();  
}else if(data=='6'){
  tangankananturun();
}else if(data=='7'){
  tangankirinaik();  
}else if(data=='8'){
  tangankiriturun();  
}else if(data=='g'){
  kepalakekanan();  
}else if(data=='h'){
  kepalakekiri();  
}else if(data=='i'){
  kepalaketengah();  
}
}  
}
void maju(){
digitalWrite (M1MA,HIGH);
digitalWrite (M1MU,LOW);
digitalWrite (M2MA,HIGH);
digitalWrite (M2MU,LOW);
}
void belokkanan(){
digitalWrite (M1MA,LOW);
digitalWrite (M1MU,HIGH);
digitalWrite (M2MA,HIGH);
digitalWrite (M2MU,LOW);
}
void belokkiri(){
digitalWrite (M1MA,HIGH);
digitalWrite (M1MU,LOW);
digitalWrite (M2MA,LOW);
digitalWrite (M2MU,HIGH);

}
void mundur(){
digitalWrite (M1MA,LOW);
digitalWrite (M1MU,HIGH);
digitalWrite (M2MA,LOW);
digitalWrite (M2MU,HIGH);
}
void berhenti(){
digitalWrite (M1MA,LOW);
digitalWrite (M1MU,LOW);
digitalWrite (M2MA,LOW);
digitalWrite (M2MU,LOW);
}
void tangankanannaik(){
servoRight.write(180);
}

void tangankananturun(){
servoRight.write(0);
}

void tangankirinaik(){
servoLeft.write(0);
}
void tangankiriturun(){
servoLeft.write(180);
}

void kepalakekiri(){
servoHead.write(180);
}
void kepalakekanan(){
servoHead.write(0);
}
void kepalaketengah(){
servoHead.write(90);
}

