


#include <SoftwareSerial.h>

SoftwareSerial BTSerial(2, 3);   // RX | TX
int flag = 0; 


void setup() {
  pinMode(13,OUTPUT);   
  pinMode(12,OUTPUT);  
  pinMode(11,OUTPUT);   
  pinMode(10,OUTPUT);   
  pinMode(9,OUTPUT);    
  pinMode(6,OUTPUT);   
  Serial.begin(9600);
  BTSerial.begin(9600);  // HC-05 default speed in AT 

}

void loop() {
  
  flag = RF();

  if (flag==1){
    //Serial.println(flag); 
    goForward();
    flag=9;
    }

  if (flag==2){
    //Serial.println(flag); 
    turnLeft();
    flag=9;
    }

  if (flag==3){
    //Serial.println(flag); 
    turnRight();
    flag=9;
    }
    
  if (flag==4){
    //Serial.println(flag); 
    goBackward();
    flag=9;
    }
  
  if (flag==5){
    //Serial.println(flag); 
    KgoForward();
    }

  if (flag==6){
    //Serial.println(flag); 
    KturnLeft();
    }

  if (flag==7){
    //Serial.println(flag); 
    KturnRight();
    flag=9;
    }
    
  if (flag==8){
    //Serial.println(flag); 
    KgoBackward();
    }

   if(flag==9){
    //Serial.println(flag); 
    StopV();
    }
  
}//loop()


int RF(){
  if (BTSerial.available()){
    int f=0;
    f = BTSerial.read();
    Serial.end();
    return f; 
    }
  }

void turnLeft(){
  
  digitalWrite(11,HIGH);
  analogWrite(9,100); 
  delay(1000);
  analogWrite(9,0); 
  digitalWrite(11,LOW);
  delay(100);
  }

void turnRight(){
  
  digitalWrite(13,HIGH);
  analogWrite(6,100);
  delay(1000);
  analogWrite(6,0);
  digitalWrite(13,LOW);
  delay(100);
  }

void goForward(){
  
 digitalWrite(13,HIGH);
 digitalWrite(11,HIGH);
 analogWrite(9,100); 
 analogWrite(6,100); 
 delay(1000);
 analogWrite(9,0); 
 analogWrite(6,0); 
 digitalWrite(13,LOW);
 digitalWrite(11,LOW);
 delay(100);
  }

void goBackward(){
  
 digitalWrite(12,HIGH);
 digitalWrite(10,HIGH);
 analogWrite(9,100); 
 analogWrite(6,100);
 delay(1000);
 analogWrite(9,0); 
 analogWrite(6,0);
 digitalWrite(12,LOW);
 digitalWrite(10,LOW);
 delay(100);
  
  }


void KgoForward(){
  
 digitalWrite(13,HIGH);
 digitalWrite(11,HIGH);
 analogWrite(9,200); //left moptor with speed 100
 analogWrite(6,200); //right moptor with speed 100
 delay(100);
  }


void KgoBackward(){
  
 digitalWrite(12,HIGH);
 digitalWrite(10,HIGH);
 analogWrite(9,200); 
 analogWrite(6,200);
 delay(100);
  
  }


void KturnLeft(){
  
  digitalWrite(11,HIGH);
  analogWrite(9,200); 
  delay(100);
  }

void KturnRight(){
  
  digitalWrite(13,HIGH);
  analogWrite(6,200);
  delay(100);
  }

void StopV(){
  
 digitalWrite(13,LOW);
 digitalWrite(12,LOW);
 digitalWrite(11,LOW);
 digitalWrite(10,LOW);
 delay(100);
  }
