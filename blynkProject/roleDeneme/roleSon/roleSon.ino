#define BLYNK_TEMPLATE_ID "TMPL6vmxNAOaK"
#define BLYNK_TEMPLATE_NAME "ROLE"
#define BLYNK_AUTH_TOKEN "uvNOn793wJ-04SZis7y5eD3s5iVruUBu"
#define BLYNK_PRINT Serial

#include <ESP8266WiFi.h>  
#include <BlynkSimpleEsp8266.h>

char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "SUPERONLINE_WiFi_44AB";  
char pass[] = "WFALJVMEFVA3"; 
int rolePin = D3;
void setup()
{     
  Serial.begin(115200);
  pinMode(rolePin, INPUT);

  Blynk.begin(auth, ssid, pass);

  if (!Blynk.connected()) {
    Serial.println("Hata olustu: Blynk baglantisi kurulamadi!");
    while (1);  // Programı burada durdurabilir veya başka bir şey yapabilirsiniz
  }

  digitalWrite(rolePin, HIGH);
}

void isikDurum()
{
  int roleState = digitalRead(rolePin);
  if (roleState == HIGH)
  {
    Serial.println("Isik Acik");
    delay(1000);
  }
  else
  {
    Serial.println("Isik Kapali");
    delay(1000);
  }
}

void loop()
{
  Blynk.run();
  isikDurum();
}
