#include  <LiquidCrystal.h>  
#include  <Servo.h> 
int trigPin = 7;   
Servo motor;
int echoPin = 6;                              
int time1;                                              
int distance;                                            
int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
 LiquidCrystal lcd(rs, en, d4, d5, d6, d7);             
 void setup() {
   pinMode(trigPin, OUTPUT);                           
   pinMode(echoPin,INPUT);                               
   lcd.begin(16, 2);       
   motor.attach(9);   
   Serial.begin(9600);                       
 }
 void loop() {
  
   for(int i=0;i<360;i++)
   {
     digitalWrite(trigPin, LOW);                           
   delayMicroseconds(5);
   digitalWrite(trigPin, HIGH);
   delayMicroseconds(10);
   digitalWrite(trigPin, LOW);
   time1 = pulseIn(echoPin, HIGH, 11600);                
   distance= time1*0.0345/2;                               
   lcd.clear();                                          
   lcd.setCursor(0, 0);                                     
   lcd.print("Distance :");                                
   lcd.setCursor(0, 1);                                  
   lcd.print(distance);                                   
   lcd.print(" cm");
   Serial.println(distance);
    if(i<180){
    motor.write(i);
    delay(50);
    }else
    {motor.write(360-i);
    delay(50);
      }
   }
   
 }  
