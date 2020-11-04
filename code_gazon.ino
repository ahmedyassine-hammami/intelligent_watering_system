//Code and System developed by Ahmed Yassine HAMMAMI
//Contact by email for more information: ahmed-yassine.hammami@ensta-paris.fr 
// Date and time functions using a DS1307 RTC connected via I2C and Wire lib
#include <Wire.h>
#include "RTClib.h"

RTC_DS1307 rtc;

char daysOfTheWeek[7][12] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
int v1=12;
int v2=A0;
int v3=9;
int v4=7;
int v5=10;
int v6=11;
int coupure_phase=6;
int motor = 2;
int LED=13;
int test =1 ;
int arrosage=A2;
int delay_arrosage = 3000000 ;
int delay_arrosage_test = 1300;
int heure ;
int minutes ;
int seconde ;
int mois ;
int test_mois=0;
void setup() {
  
 pinMode(v1,OUTPUT);
 pinMode(v2,OUTPUT);
 pinMode(v3,OUTPUT);
 pinMode(v4,OUTPUT);
 pinMode(v5,OUTPUT);
 pinMode(v6,OUTPUT);
 pinMode(coupure_phase,OUTPUT);
  pinMode(motor,OUTPUT);
 pinMode(LED,OUTPUT);
 pinMode(test,INPUT);
 pinMode(arrosage,INPUT);

 /*analogWrite(v2,1024);
 digitalWrite(LED,HIGH);
 digitalWrite(v1,HIGH);
 digitalWrite(motor,HIGH);
 digitalWrite(v3,HIGH);
 digitalWrite(v4,HIGH);
 digitalWrite(v5,HIGH);
 digitalWrite(v6,HIGH);*/
 digitalWrite(coupure_phase,HIGH);
///////////////////////////////////////////



}


void loop() {
  
DateTime now = rtc.now();

    
mois=now.month();
heure=now.hour();
minutes=now.minute();
seconde=now.second();
 
if (mois==4||mois==5||mois==6||mois==7||mois==8||mois==9||mois==10){
  test_mois=1;
}
if (mois==1||mois==2||mois==3||mois==11||mois==12){
  test_mois=0;
}
/////////////////
digitalWrite(LED,HIGH);
vanne1(0);
vanne2(0);
vanne3(0);
vanne4(0);
vanne5(0);
vanne6(0);
moteur(0);
if ((heure==1 && minutes==15 && seconde==13 && test_mois==1) ||
(heure==1 && minutes==20&& seconde==13 && test_mois==1) || analogRead(arrosage)>700 ){
  vanne1(1);
  delay(100);
  moteur(1);
  delay(delay_arrosage);
  vanne2(1);
  delay(100);
  vanne1(0);
  delay(delay_arrosage);
  vanne3(1);
  delay(100);
  vanne2(0);
  delay(delay_arrosage);
  vanne4(1);
  delay(100);
  vanne3(0);
  delay(delay_arrosage);
  vanne5(1);
  delay(100);
  vanne4(0);
  delay(delay_arrosage);
  vanne6(1);
  delay(100);
  vanne5(0);
  delay(delay_arrosage);
  vanne6(0);
  moteur(0);}


if (digitalRead(test)==HIGH){

  vanne1(1);
  delay(100);
  moteur(1);
  delay(delay_arrosage_test);
  vanne2(1);
  delay(100);
  vanne1(0);
  delay(delay_arrosage_test);
  vanne3(1);
  delay(100);
  vanne2(0);
  delay(delay_arrosage_test);
  vanne4(1);
  delay(100);
  vanne3(0);
  delay(delay_arrosage_test);
  vanne5(1);
  delay(100);
  vanne4(0);
  delay(delay_arrosage_test);
  vanne6(1);
  delay(100);
  vanne5(0);
  delay(delay_arrosage_test);
  vanne6(0);
  moteur(0);

}
}

void vanne1(int i){
  if (i==1){digitalWrite(v1,LOW);}
  if (i==0){digitalWrite(v1,HIGH);}
}
void moteur(int i){
  if (i==1){digitalWrite(motor,LOW);}
  if (i==0){digitalWrite(motor,HIGH);}
}
void vanne3(int i){
  if (i==1){digitalWrite(v3,LOW);}
  if (i==0){digitalWrite(v3,HIGH);}
}
void vanne4(int i){
  if (i==1){digitalWrite(v4,LOW);}
  if (i==0){digitalWrite(v4,HIGH);}
}
void vanne5(int i){
  if (i==1){digitalWrite(v5,LOW);}
  if (i==0){digitalWrite(v5,HIGH);}
}

void vanne6(int i){
  if (i==1){digitalWrite(v6,LOW);}
  if (i==0){digitalWrite(v6,HIGH);}
}
void coupure(int i){
  if (i==1){digitalWrite(coupure_phase,LOW);}
  if (i==0){digitalWrite(coupure_phase,HIGH);}
}
void vanne2(int i){
  if (i==1){analogWrite(v2,0);}
  if (i==0){analogWrite(v2,1024);}
}
