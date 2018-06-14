const int motA_pin1=4;
const int motA_pin2=5;
const int motA_EN=3; //pwm

const int motB_pin1=13;
const int motB_pin2=12;
const int motB_EN=11; //pwm
char ss=220;
char s=150;


#include <VirtualWire.h>

void setup() {

vw_set_rx_pin(8);
vw_set_ptt_inverted(true);
vw_setup(2000);
vw_rx_start();

motor_init();
Serial.begin(9600);
}


void loop() {
int ton=5;
int tres=1;
  
uint8_t buf[VW_MAX_MESSAGE_LEN];
uint8_t buflen = VW_MAX_MESSAGE_LEN;

if (vw_get_message(buf, &buflen)) { Serial.println(buf[0]);
   switch ( buf[0]) {
    case 56 : 
    forward() ;
    break;
    case 57 : 
    forward1() ;
    break;
    case 52 : 
    left() ;
    break;
    case 54 : 
    right() ;
    break;
    case 55 : 
    right1();
    break;
    case 51 : 
    left1();
    break;
    case 53 : 
    right1();
    break;
    case 49 : 
    revers1();
    break;
    case  50: 
    revers();
    break;
    default :
    stop();
    break; 
   }
}
}

void motor_init(){
pinMode (motA_pin1,OUTPUT);
pinMode (motA_pin2,OUTPUT);

pinMode (motB_pin1,OUTPUT);
pinMode (motB_pin2,OUTPUT);

pinMode (motA_EN,OUTPUT);
pinMode (motB_EN,OUTPUT);

analogWrite(motA_EN,0);
digitalWrite(motA_pin1,LOW);
digitalWrite(motA_pin2,LOW);

analogWrite(motB_EN,0);
digitalWrite(motB_pin1,LOW);
digitalWrite(motB_pin2,LOW);
}

void left(){

Serial.println("left");
analogWrite(motA_EN,50); 
analogWrite(motB_EN,250); 
digitalWrite(motA_pin1,LOW);
digitalWrite(motA_pin2,HIGH);

digitalWrite(motB_pin1,HIGH);
digitalWrite(motB_pin2,LOW);

}

 

void right(){
Serial.println("right");
analogWrite(motA_EN,250);
analogWrite(motB_EN,50);

digitalWrite(motA_pin1,LOW);
digitalWrite(motA_pin2,HIGH);

digitalWrite(motB_pin1,HIGH);
digitalWrite(motB_pin2,LOW);

}

void forward(){

Serial.println("for");
analogWrite(motA_EN,s);
digitalWrite(motA_pin1,LOW); 
digitalWrite(motA_pin2,HIGH); 

// analogWrite(motB_EN,speed-10);
analogWrite(motB_EN,s);
digitalWrite(motB_pin1,HIGH); 
digitalWrite(motB_pin2,LOW); 

 

}

void revers(){

Serial.println("revers");

analogWrite(motA_EN,s);
digitalWrite(motA_pin1,HIGH);
digitalWrite(motA_pin2,LOW);

analogWrite(motB_EN,s);
digitalWrite(motB_pin1,LOW); 
digitalWrite(motB_pin2,HIGH);

}

 

void stop(){
Serial.println("stop");
analogWrite(motA_EN,0);
digitalWrite(motA_pin1,LOW);
digitalWrite(motA_pin2,LOW);

analogWrite(motB_EN,0);
digitalWrite(motB_pin1,LOW); 
digitalWrite(motB_pin2,LOW);

}


void left1(){

analogWrite(motA_EN,50); 
analogWrite(motB_EN,250); 
digitalWrite(motA_pin1,LOW);
digitalWrite(motA_pin2,HIGH);

digitalWrite(motB_pin1,HIGH);
digitalWrite(motB_pin2,LOW);

}

 

void right1(){
Serial.println("right1");
analogWrite(motA_EN,250);
analogWrite(motB_EN,50);

digitalWrite(motA_pin1,LOW);
digitalWrite(motA_pin2,HIGH);

digitalWrite(motB_pin1,HIGH);
digitalWrite(motB_pin2,LOW);

}

void forward1(){


analogWrite(motA_EN,ss);
digitalWrite(motA_pin1,LOW); 
digitalWrite(motA_pin2,HIGH); 

analogWrite(motB_EN,ss);
digitalWrite(motB_pin1,HIGH); 
digitalWrite(motB_pin2,LOW);

 

}

void revers1(){

Serial.println("revers1");
analogWrite(motA_EN,ss);
digitalWrite(motA_pin1,HIGH);
digitalWrite(motA_pin2,LOW);

analogWrite(motB_EN,ss);
digitalWrite(motB_pin1,LOW); 
digitalWrite(motB_pin2,HIGH);

}




