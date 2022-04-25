#include <SFE_BMP180.h>


SFE_BMP180 pressure;
double baseline;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("REBOOT");
  if(pressure.begin())
  {
    Serial.println("connection successfull");
  } else {
    Serial.println("menno");
  }
}

void loop() {
  // put your main code here, to run repeatedly:

}
