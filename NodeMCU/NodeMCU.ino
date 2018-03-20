#define BLYNK_PRINT Serial    
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = "3dddac1594e74646bde292060be39113";    //AuthToken copy ở Blynk Project
char ssid[] = "TOP";  //Tên wifi
char pass[] = "0968457018";     //Mật khẩu wifi
void setup()
{
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
}

BLYNK_WRITE(V3)
{
  int pinValue = param.asInt(); // assigning incoming value from pin V1 to a variable
  // You can also use:
  // String i = param.asStr();
  // double d = param.asDouble();
//  Serial.print("V3 Slider value is: ");
//  Serial.println((pinValue+9999)/19.5);
}

void loop()
{
  Blynk.run();
//  float x = digitalRead(D3);
//  delay(200);
//  if ( x < 1)
//   {
//    Serial.print(x);
//    Blynk.email("hongquan95.tran@gmail.com", "Subject: Nhan email ne", "Email toi roi ne");
//    Blynk.notify("Hey, Blynkers! My hardware can push now!");
//    delay(10000);
//   }
   
}
