#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <DHT.h>
#include <Adafruit_Sensor.h>

#define DHTPIN 2
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

BlynkTimer timer;
char auth[] = "5R-O176YVEcBA2eXf36OKkydvmwBWjF9"; 
char ssid[] = "Tp-link 2.0";  
char pass[] = "9920366717@";  



int Light = D7; 
int Buzzer= D5;
int Gas_analog= A0;
int Gas_digital= D1;

void setup() {
  Blynk.begin(auth, ssid, pass);
  Serial.begin(115200);
  pinMode(Buzzer, OUTPUT);      
  pinMode(Gas_digital, INPUT);
  pinMode(Light, OUTPUT); 
  dht.begin();
 
  
}

void loop() 
{

 Blynk.run();
 getSendData();
 sendSensor();

}

void sendSensor()
{
  delay(10);
  float temp = dht.readTemperature();
  Serial.print(temp);
  Blynk.virtualWrite(V6, temp); 
}

 void getSendData()
 {
  delay(10);
  int gassensorAnalog = analogRead(Gas_analog);
  int gassensorDigital = digitalRead(Gas_digital);
  Blynk.virtualWrite(V5, gassensorAnalog );
  Serial.print("Gas Sensor: ");
  Serial.print(gassensorAnalog);
  Serial.print("\t");
  Serial.print("Gas Class: ");
  Serial.print(gassensorDigital);
  Serial.print("\t");
  Serial.print("\t");
  Blynk.virtualWrite(V5, gassensorAnalog);
  if (gassensorAnalog > 930) {
    Serial.println("Gas");

    digitalWrite (Light, HIGH) ;
    digitalWrite (Buzzer, HIGH) ; 
   
     Blynk.notify("Smoke Detected!"); 
    delay(1000);
    
    digitalWrite (Buzzer, LOW) ;  //no tone
  
     Blynk.notify("Smoke Detected!"); 
  }
  else {
    Serial.println("No Gas");
  }
  delay(100);
}
