#include <DHTesp.h>

#define DHT11_PIN D0

DHTesp dht; // constructs a DHTesp object (C++ style)

void setup() {

  Serial.begin(9600);
  dht.setup(DHT11_PIN, DHTesp::DHT11);
  
}

void loop() {

  float myTemp = dht.getTemperature();
  float myHumd = dht.getHumidity();

  // check to see if the temperature and humidity values were retrieved successfully
  if (isnan(myTemp) || isnan(myHumd)) {
    Serial.println("Error Reading");
    Serial.println();

    delay(6000); // wait six seconds before trying to read again
    
    return;
  }

  float myTempF = (myTemp * (9.0/5.0)) + 32;

  Serial.print("Temp (C): "); Serial.println(myTemp);
  Serial.print("Temp (F): "); Serial.println(myTempF);
  Serial.print("Humd (%): "); Serial.println(myHumd);
  Serial.println();
  
  delay(2000);

}
