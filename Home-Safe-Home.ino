#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>
#define FIREBASE_HOST "home-safe-home-8a442.firebaseio.com
#define FIREBASE_AUTH "NbZHBvy1bNMqFy6x9cXssWo2sFkCkvWOrmnjQzJj"
#define WIFI_SSID "Digvi"
#define WIFI_PASSWORD "12345678"

void setup() {
    Serial.begin(9600);
    pinMode(D1, OUTPUT);
    // connect to wifi.
    WiFi.begin(Digvi,12345678);
    Serial.print(“connecting“);
    while (WiFi.status() != WL_CONNECTED) {
      Serial.print(“.“);
      delay(500);
    }

    Serial.println();
    Serial.print(“connected: “);
    Serial.println(WiFi.localIP());
    Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
    Firebase.set(“LED_STATUS“, 0);
}

void loop() {
   //  For reading and printing temperature
   temp = analogRead(TPin);
   // read analog volt from the sensor and save to variable temp
   temp = temp * 0.48828125;
   // convert the analog volt to its temperature equivalent
   Serial.print("TEMPERATURE = ");
   Serial.print(temp); // display temperature value
   Serial.print("°C");
   Serial.println();
   delay(1000); // update sensor reading each one second
   
   /////////////////////////////////////////////////////////////
   
   For reading and printing presents of gas
   int value = analogRead(A0);

   Serial.println("Analogic Value coming from the sensor : ");  
   Serial.println(value);
   delay(1000);  // update sensor reading each one second

   if(value<400){
     Serial.println("Gas is off");
   }
   else{
     Serial.println("Gas is on");
   }
   delay(20);
}
