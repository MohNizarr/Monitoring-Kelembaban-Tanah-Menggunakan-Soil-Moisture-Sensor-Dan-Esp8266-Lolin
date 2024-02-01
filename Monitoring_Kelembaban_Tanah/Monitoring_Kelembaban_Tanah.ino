#include<ESP8266WiFi.h> //Library ESP8266
#include<BlynkSimpleEsp8266.h> //Library Blynk

#define BLYNK_PRINT Serial

BlynkTimer timer;
char auth[] ="NvQ9R_G9uD9I3EQBGZoQBW9tKKEy32Tt"; //Auth Token Blynk

char ssid[] ="ijjokuijjomu"; //Nama WiFi
char pass[] ="nasiambyar"; //Password Wifi

void myTimeEvent()
{
  int adc = analogRead(A0); //PIN Sensor
  float tegangan = adc * (5.0 / 1023.0);
  Blynk.virtualWrite(V0, adc); //PIN V0 sebagai ADC 
  Blynk.virtualWrite(V1, tegangan); //PIN V1 sebagai Tegangan
}

void setup() {
  // put your setup code here, to run once:
Serial.begin(115200);
Blynk.begin(auth,ssid,pass);
timer.setInterval(1000L, myTimeEvent); //1000L = 1 Detik
}

void loop() {
  // put your main code here, to run repeatedly:
Blynk.run();
timer.run();
}
