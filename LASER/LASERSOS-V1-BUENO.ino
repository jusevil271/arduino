// Definir el pin del láser
const int laserPin = 9;

// Duraciones en milisegundos para el código Morse
const int dotDuration = 200;
const int dashDuration = dotDuration * 3;
const int symbolSpace = dotDuration;
const int letterSpace = dotDuration * 3;
const int wordSpace = dotDuration * 7;

void setup() {
  // Configurar el pin del láser como salida
  pinMode(laserPin, OUTPUT);
}

void loop() {
  // Enviar señal SOS en código Morse: ... --- ...
  sendSOS();
  delay(wordSpace); // Esperar antes de repetir la señal SOS
}

void sendSOS() {
  // Enviar S: ...
  sendDot();
  sendDot();
  sendDot();
  delay(letterSpace); // Espacio entre letras
  
  // Enviar O: ---
  sendDash();
  sendDash();
  sendDash();
  delay(letterSpace); // Espacio entre letras
  
  // Enviar S: ...
  sendDot();
  sendDot();
  sendDot();
  delay(wordSpace); // Espacio entre palabras
}

void sendDot() {
  digitalWrite(laserPin, HIGH); // Encender el láser
  delay(dotDuration);           // Esperar la duración del punto
  digitalWrite(laserPin, LOW);  // Apagar el láser
  delay(symbolSpace);           // Espacio entre símbolos
}

void sendDash() {
  digitalWrite(laserPin, HIGH); // Encender el láser
  delay(dashDuration);          // Esperar la duración de la raya
  digitalWrite(laserPin, LOW);  // Apagar el láser
  delay(symbolSpace);           // Espacio entre símbolos
}
