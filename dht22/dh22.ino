#include <SoftwareSerial.h>

// Definir los pines para SoftwareSerial
#define RX_PIN 10
#define TX_PIN 11

// Crear un objeto SoftwareSerial
SoftwareSerial Bluetooth(RX_PIN, TX_PIN);

// Definir el pin del LED integrado
#define LED_PIN 13

void setup() {
  // Iniciar la comunicación serie para el monitor serie
  Serial.begin(9600);
  // Iniciar la comunicación serie para Bluetooth
  Bluetooth.begin(9600);

  // Configurar el pin del LED como salida
  pinMode(LED_PIN, OUTPUT);
  // Apagar el LED inicialmente
  digitalWrite(LED_PIN, LOW);

  // Mensaje de inicio
  Serial.println("Módulo Bluetooth HC-05 iniciado. Enviar 'ON' para encender el LED y 'OFF' para apagarlo.");
}

void loop() {
  // Comprobar si hay datos disponibles desde Bluetooth
  if (Bluetooth.available()) {
    String command = Bluetooth.readStringUntil('\n');
    command.trim(); // Eliminar espacios en blanco

    // Mostrar el comando recibido en el monitor serie
    Serial.println("Comando recibido: " + command);

    // Comprobar el comando y actuar en consecuencia
    if (command == "ON") {
      digitalWrite(LED_PIN, HIGH);
      Serial.println("LED encendido");
      Bluetooth.println("LED encendido");
    } else if (command == "OFF") {
      digitalWrite(LED_PIN, LOW);
      Serial.println("LED apagado");
      Bluetooth.println("LED apagado");
    } else {
      Serial.println("Comando no reconocido");
      Bluetooth.println("Comando no reconocido");
    }
  }
}

