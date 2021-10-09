#include<SPI.h>
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = "5R-O176YVEcBA2eXf36OKkydvmwBWjF9"; 
char ssid[] = "Tp-link 2.0";  
char pass[] = "9920366717@";  

//BlynkTimer timer;

void sendSensor()
{
  float i;
  float temp = analogRead(2); 
  float voltage = (temp / 1023.0) * 3.3;
  float tempC = (voltage - 0.5) * 10;
  for(i=tempC;i<=5;i++)
  {
    tempC = tempC + 1;
    if(tempC = 33)
    {
      break;
    }
    return;
  }
  Serial.println(tempC);
  Blynk.virtualWrite(V6, tempC); 
}
void setup()
{
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
  pinMode(2, INPUT);
 // timer.setInterval(10000L);
}

void loop()
{
  Blynk.run();
  sendSensor();
 // timer.run();
}
