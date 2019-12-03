#include <Wire.h>    
 
#define disk1 0x50  //Address of 24LC256 eeprom chip
int n;
int array1[10]; 
 
void setup(void)
{
  Serial.begin(9600);
  Wire.begin(); 
  long int new1;
  long int number = 4296236;
  new1 = number;

  for(int j=0; number>9 ; j++)
  {
    number/=10;
    n++;  
  }
  n++;
  
  for (int i = n-1; i >= 0; i--) {
    array1[i] = new1 % 10;
    new1 /= 10;
  }  
  for (int k=0;k<n;k++)
  {
  writeEEPROM(disk1,k,array1[k]);
  Serial.print(readEEPROM(disk1,k));
  }
}
 
void writeEEPROM(int deviceaddress, unsigned int eeaddress, byte data ) 
{
  Wire.beginTransmission(deviceaddress);
  Wire.write((int)(eeaddress >> 8));   // MSB
  Wire.write((int)(eeaddress & 0xFF)); // LSB
  Wire.write(data);
  Wire.endTransmission();
 
  delay(5);
}
 
byte readEEPROM(int deviceaddress, unsigned int eeaddress ) 
{
  byte rdata = 0xFF;
 
  Wire.beginTransmission(deviceaddress);
  Wire.write((int)(eeaddress >> 8));   // MSB
  Wire.write((int)(eeaddress & 0xFF)); // LSB
  Wire.endTransmission();
 
  Wire.requestFrom(deviceaddress,1);
 
  if (Wire.available()) rdata = Wire.read();
 
  return rdata;
}

void loop()
{
  
 

}
