#include <DS3231.h>
#include <Wire.h>
#include <Servo.h>


DS3231  rtc(SDA, SCL);

Time  t;
Servo servo_9;
int pos = 0;
int pos_next=90;
int piezo=10;
int led=7;


int Hor;

int Min;

int Sec;




void setup()

{  

  Wire.begin();

  rtc.begin();

  Serial.begin(9600);
  pinMode(piezo,OUTPUT);
    pinMode(led,OUTPUT);
     servo_9.attach(9);
     servo_9.write(pos);
  // The following lines can be uncommented to set the date and time

  //rtc.setDOW(MONDAY);     // Set Day-of-Week to SUNDAY

 // rtc.setTime(19, 9, 0);     // Set the time to 12:00:00 (24hr format)

 // rtc.setDate(25 ,6, 2018);   // Set the date to January 1st, 2014

 

}




void loop()

{

  t = rtc.getTime();

  Hor = t.hour;

  Min = t.min;

  Sec = t.sec;


  Serial.print("Time: ");

  Serial.print(rtc.getTimeStr());

 Serial.println("Date: ");

 Serial.println(rtc.getDateStr());




 if(( Hor == 20 || Hor==21) &&  (Min ==17)&&(Sec==5)) //Comparing the current time with the Alarm time

{

 Func();

} 

 delay(1000); 



}

void Func()
{
   tone(piezo,500); 
     delay(1000);
     noTone(piezo);
     digitalWrite(led,HIGH);
    servo_9.write(pos_next);
     delay(1000);
      servo_9.write(pos);
      delay(500);
       servo_9.write(pos_next);
       delay(500);
        servo_9.write(pos);
        delay(500);
         servo_9.write(pos_next);
         delay(2000);
     servo_9.write(pos);
   digitalWrite(led,LOW); 
}




