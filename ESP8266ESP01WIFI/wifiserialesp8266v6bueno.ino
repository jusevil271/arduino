#include <SoftwareSerial.h>

// Crear un objeto SoftwareSerial para comunicarse con el ESP8266
SoftwareSerial esp8266(2, 3); // RX, TX

void setup() {
  // Iniciar la comunicación serie con el monitor serie
  Serial.begin(115200);
  // Iniciar la comunicación serie con el ESP8266
  esp8266.begin(115200);

  // Esperar a que el ESP8266 inicie
  delay(2000);

  // Reseteo del módulo ESP8266
  if (sendATCommand("AT+RST", "ready", 5000)) {
    Serial.println("ESP-01 reiniciado correctamente");
  } else {
    Serial.println("Error al reiniciar el ESP-01");
  }
  
  // Enviar comando AT para verificar la conexión
  if (sendATCommand("AT", "OK", 1000)) {
    Serial.println("ESP-01 está funcionando correctamente");
  } else {
    Serial.println("ESP-01 no responde. Por favor, verifica la conexión y configuración.");
  }
}

void loop() {
  // No se necesita hacer nada en el bucle principal para esta prueba
}

bool sendATCommand(String command, String expectedResponse, int timeout) {
  // Enviar el comando AT al ESP8266
  esp8266.println(command);
  Serial.println("Enviando comando: " + command); // Imprimir comando enviado
  long int time = millis();
  String response = ""; // Variable para almacenar la respuesta del ESP8266

  // Esperar la respuesta del ESP8266
  while ((time + timeout) > millis()) {
    while (esp8266.available()) {
      char c = esp8266.read();
      response += c;
    }
  }
  
  Serial.println("Respuesta: " + response); // Imprimir la respuesta recibida

  // Verificar si la respuesta contiene la respuesta esperada
  if (response.indexOf(expectedResponse) >= 0) {
    return true;
  } else {
    Serial.println("Error: Respuesta no esperada");
    return false;
  }
}

