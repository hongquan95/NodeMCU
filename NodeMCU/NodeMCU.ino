#define BLYNK_PRINT Serial    
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = "3dddac1594e74646bde292060be39113";    //AuthToken copy ở Blynk Project
char ssid[] = "TOP";  //Tên wifi
char pass[] = "0968457018";     //Mật khẩu wifi
int x, y;
void setup()
{
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
}

void readStt()
{
 x = digitalRead(D2);
 y = digitalRead(D3);
}
void writeStt(int x, int y)
{
  Serial.print("Led 1 is: ");
  Serial.println(x);
  Serial.print("Led 2 is: ");
  Serial.println(y);
  delay(100);
}

void loop()
{
  Blynk.run();
  readStt();
  writeStt(x,y);
}
