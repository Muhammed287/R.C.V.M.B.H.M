#include<Wire.h>
const int MPU_addr=0x68;  // I2C address of the MPU-6050
int16_t AcX,AcY,AcZ;

#include <VirtualWire.h>
char *controller;
int t = 5;
void setup() {
  
 
  Wire.begin();
  Wire.beginTransmission(MPU_addr);
  Wire.write(0x6B);  // PWR_MGMT_1 register
  Wire.write(0);     // set to zero (wakes up the MPU-6050)
  Wire.endTransmission(true);
  Serial.begin(9600);    // 9600

  vw_set_ptt_inverted(true); //
  vw_set_tx_pin(10);
  vw_setup(2000);// speed of data transfer Kbps

}

void loop() {
Wire.beginTransmission(MPU_addr);
  Wire.write(0x3B);  // starting with register 0x3B (ACCEL_XOUT_H)
  Wire.endTransmission(false);
  Wire.requestFrom(MPU_addr,14,true);  // request a total of 14 registers
  AcX=Wire.read()<<8|Wire.read();  // 0x3B (ACCEL_XOUT_H) & 0x3C (ACCEL_XOUT_L)     
  AcY=Wire.read()<<8|Wire.read();  // 0x3D (ACCEL_YOUT_H) & 0x3E (ACCEL_YOUT_L)
  AcZ=Wire.read()<<8|Wire.read();  // 0x3F (ACCEL_ZOUT_H) & 0x40 (ACCEL_ZOUT_L)

  Serial.print("AcX = "); Serial.print(AcX);
  Serial.print(" | AcY = "); Serial.print(AcY);
  Serial.print(" | AcZ = "); Serial.println(AcZ);


  if ( AcX < -6000  && AcX > -10000 ) 
  {
      Serial.println("send 8");
      controller="8";
      vw_send((uint8_t *)controller, strlen(controller));
      vw_wait_tx();
      
      //delay(t);
  }
  else if (AcX < -10000  && AcX > -18000  ) 
  {   
      Serial.println("send 9");
      controller="9";
      vw_send((uint8_t *)controller, strlen(controller));
      vw_wait_tx();
      delay(t);
  }
  
  else if ( AcX > 6000  && AcX < 10000 ) 
  {   
      Serial.println("send 2");
      controller="2";
      vw_send((uint8_t *)controller, strlen(controller));
      vw_wait_tx();
      delay(t);
  }

  else if ( AcX > 10000  && AcX < 18000 ) 
  {   
      Serial.println("send 1");
      controller="1";
      vw_send((uint8_t *)controller, strlen(controller));
      vw_wait_tx();
      delay(t);
  }
    
  else if ( AcY > 6000  && AcY < 10000 ) 
  {
      Serial.println("send 6");
      controller="6";
      vw_send((uint8_t *)controller, strlen(controller));
      vw_wait_tx();
      delay(t);
  }
   else if ( AcY > 10000  && AcY < 18000 ) 
  {
      Serial.println("send 7");
      controller="7";
      vw_send((uint8_t *)controller, strlen(controller));
      vw_wait_tx();
      delay(t);
  }
  
  else if ( AcY < -6000  && AcY > -10000 ) 
  {
      Serial.println("send 4");
      controller="4";
      vw_send((uint8_t *)controller, strlen(controller));
      vw_wait_tx();
      delay(t);
  }
  else if ( AcY < -10000  && AcY > -18000 ) 
  {
      Serial.println("send 3");
      controller="3";
      vw_send((uint8_t *)controller, strlen(controller));
      vw_wait_tx();
      delay(t);
  }
  else {
      Serial.println("send 0");
      controller="0";
      vw_send((uint8_t *)controller, strlen(controller));
      vw_wait_tx();
      delay(t);
  }

 
  
}


