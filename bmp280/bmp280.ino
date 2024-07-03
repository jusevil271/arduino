#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BMP280.h>

// Crear un objeto del sensor BMP280
Adafruit_BMP280 bmp; // I2C

void setup() {
  // Iniciar la comunicación serie
  Serial.begin(9600);
  Serial.println(F("Iniciando sensor BMP280..."));
  
  // Verificar si el sensor está conectado
  if (!bmp.begin(0x76)) {
    Serial.println(F("No se encontró el sensor BMP280. Verifique las conexiones."));
    //while (1); // Detener el programa si no se encuentra el sensor
  }
  
  // Configuración del sensor (opcional)
  bmp.setSampling(Adafruit_BMP280::MODE_NORMAL,     // Modo
                  Adafruit_BMP280::SAMPLING_X2,     // Muestreo de temperatura
                  Adafruit_BMP280::SAMPLING_X16,    // Muestreo de presión
                  Adafruit_BMP280::FILTER_X16,      // Filtro
                  Adafruit_BMP280::STANDBY_MS_500); // Intervalo de espera
}

void loop() {

    if (!bmp.begin(0x76)) {
    Serial.println(F("No se encontró el sensor BMP280. Verifique las conexiones."));
    //while (1); // Detener el programa si no se encuentra el sensor
  }
  // Leer temperatura y presión del sensor
  float temperatura = bmp.readTemperature();
  float presion = bmp.readPressure();
  
  // Mostrar los valores en el puerto serie
  Serial.print(F("Temperatura: "));
  Serial.print(temperatura);
  Serial.println(F(" °C"));
  
  Serial.print(F("Presión: "));
  Serial.print(presion / 100.0F); // Convertir de Pa a hPa
  Serial.println(F(" hPa"));
  
  // Esperar un segundo antes de la próxima lectura
  delay(1000);
}
