#include "HUSKYLENS.h"

HUSKYLENS huskylens;

const int ledPin = 13;

void setup() {
  Serial.begin(115200);
  Serial2.begin(9600);
  huskylens.begin(Serial2);
  
  if (!huskylens.available()) {
    Serial.println("HUSKYLENS no está disponible.");
    //while(1);
  }
  
  pinMode(ledPin, OUTPUT);
  Serial.println("HUSKYLENS está listo. Alinee una cara frente a la cámara.");
}

void loop() {
  if (huskylens.request()) {
    Serial.println("Solicitud enviada a HUSKYLENS.");
  } else {
    Serial.println("Error al enviar la solicitud.");
    delay(1000);
    return;
  }

  bool faceDetected = false;
  int attempts = 0;

  while (huskylens.available()) {
    HUSKYLENSResult result = huskylens.read();
    if (result.command == COMMAND_RETURN_BLOCK) {
      Serial.print("Comando recibido. ID: ");
      Serial.print(result.ID);
      Serial.print(" X: ");
      Serial.print(result.xCenter);
      Serial.print(" Y: ");
      Serial.println(result.yCenter);
      
      if (result.ID == 1) {
        faceDetected = true;
      }
    } else {
      Serial.print("Comando desconocido recibido: ");
      Serial.println(result.command);
    }
    attempts++;
  }

  Serial.print("Intentos de lectura: ");
  Serial.println(attempts);

  if (faceDetected) {
    digitalWrite(ledPin, HIGH); // Enciende el LED
    Serial.println("LED encendido. Cara detectada.");
  } else {
    digitalWrite(ledPin, LOW);  // Apaga el LED
    Serial.println("LED apagado. No se detectó ninguna cara.");
  }
  
  delay(1000); // Espera un segundo antes de la siguiente lectura
}

