#include "HUSKYLENS.h"

HUSKYLENS huskylens;

void setup() {
  Serial.begin(115200);
  Serial1.begin(9600);
  huskylens.begin(Serial1);
  
  if (!huskylens.available()) {
    Serial.println("HUSKYLENS no está disponible.");
    //while(1);
  }
  
  Serial.println("HUSKYLENS está listo.");
}

void loop() {
  if (huskylens.request()) {
    Serial.println("Solicitud enviada a HUSKYLENS.");
  } else {
    Serial.println("Error al enviar la solicitud.");
  }

  while (huskylens.available()) {
    HUSKYLENSResult result = huskylens.read();
    if (result.command == COMMAND_RETURN_BLOCK) {
      Serial.print("ID: ");
      Serial.print(result.ID);
      Serial.print(" X: ");
      Serial.print(result.xCenter);
      Serial.print(" Y: ");
      Serial.println(result.yCenter);
    }
  }
  delay(1000);
}

