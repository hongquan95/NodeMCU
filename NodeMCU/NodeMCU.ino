
#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <SimpleTimer.h>
#include <DHT.h>

char auth[] = "3dddac1594e74646bde292060be39113";    //AuthToken copy ở Blynk Project
//char ssid[] = "TOP";  //Tên wifi
//char pass[] = "0968457018";     //Mật khẩu wifi

char ssid[] = "NHATRO98";  //Tên wifi
char pass[] = "568568568";     //Mật khẩu wifi

int x, y, z;
#define DHTPIN D5         // Pin ket noi voi DHT
#define DHTTYPE DHT11     // Su dung cam bien DHT11
DHT dht(DHTPIN, DHTTYPE); // Cau hinh chan DHT

void setup()
{
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
  dht.begin();                          // Khoi tao DHT
}
BLYNK_READ(V0) //Blynk app has something on V5
{
  float h = dht.readHumidity();     //Doc gia tri do am
  
  Serial.println("Do am:" + String(h));
  Blynk.virtualWrite(V0, h); //sending to Blynk
}
BLYNK_READ(V1) //Blynk app has something on V5
{
  float t = dht.readTemperature();  //Doc gia tri nhiet do
  Serial.print("Nhiet do:" + String(t));
  Blynk.virtualWrite(V1, t); //sending to Blynk
}

void loop()
{
  Blynk.run();
}
