// Define los pines
const int lightCupPin = 2;
const int ledPin = 13;

void setup() {
  // Inicializa el puerto serie para la salida de datos
  Serial.begin(9600);

  // Configura el pin del sensor de luz como entrada
  pinMode(lightCupPin, INPUT);

  // Configura el pin del LED como salida
  pinMode(ledPin, OUTPUT);

  Serial.println("Iniciando Light Cup...");
}

void loop() {
  // Lee el estado del sensor de luz
  int sensorValue = digitalRead(lightCupPin);

  // Verifica si el sensor detecta luz o no
  if (sensorValue == HIGH) {
    Serial.println("Luz detectada.");
    digitalWrite(ledPin, HIGH); // Enciende el LED
  } else {
    Serial.println("No se detecta luz.");
    digitalWrite(ledPin, LOW); // Apaga el LED
  }

  // Espera medio segundo antes de la siguiente lectura
  delay(500);
}

