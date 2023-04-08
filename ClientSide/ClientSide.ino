#include <SoftwareSerial.h>
#include <DHT.h>
#include "pitches.h"

#define DHT_PIN_DATA 2
#define LDR_PIN_SIG A0
#define SOILMOISTURE_5V_PIN_SIG A1

#define BUZZER_PIN 8

SoftwareSerial espSerial(7, 6); // RX, TX
DHT dht(DHT_PIN_DATA, DHT11);

int minutes_between = 1;  

char[] server_ip = "<your_ip>"
char[] server_port = "<your_port>"

void setup() {
  Serial.begin(115200);
  dht.begin();
  pinMode(BUZZER_PIN, OUTPUT);
  // sendData("Pipka ta Boba");
}

void loop() {
  // float humidity = dht.readHumidity();
  // float temperature = dht.readTemperature();
  int ldrValue = analogRead(LDR_PIN_SIG);
  // int soilMoistureValue = analogRead(SOILMOISTURE_5V_PIN_SIG);

  long time = millis();

  sendData(String(ldrValue));

  delay(millis()-time);
  // sendData(String(humidity) + "," + String(temperature) + "," + String(ldrValue) + "," + String(soilMoistureValue));
}

void sendData(String data){
  espSerial.begin(115200);

  tone(BUZZER_PIN, NOTE_G4, 15);

  // Send HTTP POST request
  espSerial.println("AT+CIPSTART=\"TCP\",\"" + server_ip + "\"," + server_port);
  // digitalWrite(buzzerPin, LOW);
  delay(15);

  noTone(BUZZER_PIN);
  espSerial.println("AT+CIPMODE=1");
  delay(15);
  espSerial.println("AT+CIPSEND");
  
  delay(15);
  espSerial.println("POST /data HTTP/1.1");
  espSerial.println("Host: " + server_ip + ":" + server_port);
  espSerial.println("Connection: keep-alive");
  espSerial.println("Content-Type: text/plain");
  espSerial.println("Content-Length: " + String(data.length()));
  espSerial.println();
  espSerial.println(data);
}