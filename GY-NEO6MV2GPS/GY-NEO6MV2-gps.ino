#include <TinyGPS++.h>
#include <HardwareSerial.h>

// Crear una instancia de TinyGPS++
TinyGPSPlus gps;

// Usar Serial1 para la comunicación con el GPS
HardwareSerial &gpsSerial = Serial1;

void setup() {
  Serial.begin(115200); // Comunicación con el monitor serie
  gpsSerial.begin(9600); // Comunicación con el módulo GPS

  Serial.println("Iniciando GPS...");
}

void loop() {
  // Leer datos del GPS
  while (gpsSerial.available() > 0) {
    char c = gpsSerial.read();
    Serial.write(c); // Imprimir cada carácter recibido para depuración
    gps.encode(c);
  }

  // Mostrar datos básicos del GPS en el monitor serie
  if (gps.location.isValid()) {
    Serial.print("Latitud: ");
    Serial.println(gps.location.lat(), 6);
    Serial.print("Longitud: ");
    Serial.println(gps.location.lng(), 6);
  } else {
    Serial.println("Latitud/Longitud no válidos");
  }

  if (gps.date.isValid()) {
    Serial.print("Fecha: ");
    Serial.print(gps.date.day());
    Serial.print("/");
    Serial.print(gps.date.month());
    Serial.print("/");
    Serial.println(gps.date.year());
  } else {
    Serial.println("Fecha no válida");
  }

  if (gps.time.isValid()) {
    Serial.print("Hora: ");
    Serial.print(gps.time.hour());
    Serial.print(":");
    Serial.print(gps.time.minute());
    Serial.print(":");
    Serial.println(gps.time.second());
  } else {
    Serial.println("Hora no válida");
  }

  delay(1000); // Leer cada segundo
}

