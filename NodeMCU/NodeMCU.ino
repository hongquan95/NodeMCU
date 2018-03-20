#define BLYNK_PRINT Serial    
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = "3dddac1594e74646bde292060be39113";    //AuthToken copy ở Blynk Project
char ssid[] = "TOP";  //Tên wifi
char pass[] = "0968457018";     //Mật khẩu wifi
int x, y, z;
void setup()
{
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
}

void readStt()
{
 x = digitalRead(D2);
 y = digitalRead(D3);
 z = digitalRead(D4);
}

BLYNK_WRITE(V4)
{
  String i = param.asStr();
  Serial.print("STT is: ");
  Serial.println(i);
  delay(200);
  
  if (i == "Quan")
  { 
     readStt();
     Blynk.email("You Stt", "Led 1 is:" + String(x) + " Led 2 is:" + String(y) + " Led 3 is:" + String(z));
     Serial.println("Email is sent")
     Blynk.virtualWrite(V4,"checked");
     delay(200);
  }
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
}
