#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BMP280.h>
#include <MPU9250.h>

// Crear instancias de los sensores
Adafruit_BMP280 bmp;
MPU9250 mpu;

void setup() {
  Serial.begin(115200);
  Wire.begin();

  // Inicializar BMP280
  if (!bmp.begin(0x76)) {
    Serial.println("No se encontró el BMP280. Verifique las conexiones.");
    while (1);
  }

  // Configuración del BMP280
  bmp.setSampling(Adafruit_BMP280::MODE_NORMAL,     /* Operating Mode. */
                  Adafruit_BMP280::SAMPLING_X2,     /* Temp. oversampling */
                  Adafruit_BMP280::SAMPLING_X16,    /* Pressure oversampling */
                  Adafruit_BMP280::FILTER_X16,      /* Filtering. */
                  Adafruit_BMP280::STANDBY_MS_500); /* Standby time. */

  // Inicializar MPU9250
  if (!mpu.setup(0x68)) {
    Serial.println("No se encontró el MPU9250. Verifique las conexiones.");
    while (1);
  }
}

void loop() {
  // Leer datos del BMP280
  Serial.print("Temperatura = ");
  Serial.print(bmp.readTemperature());
  Serial.println(" *C");

  Serial.print("Presión = ");
  Serial.print(bmp.readPressure() / 100.0F);
  Serial.println(" hPa");

  Serial.print("Altitud aproximada = ");
  Serial.print(bmp.readAltitude(1013.25)); // Ajuste esto a la presión de su localidad
  Serial.println(" m");

  // Leer datos del MPU9250
  mpu.update();

  Serial.print("Aceleración X: ");
  Serial.print(mpu.getAccX());
  Serial.print(" Y: ");
  Serial.print(mpu.getAccY());
  Serial.print(" Z: ");
  Serial.println(mpu.getAccZ());

  Serial.print("Giroscopio X: ");
  Serial.print(mpu.getGyroX());
  Serial.print(" Y: ");
  Serial.print(mpu.getGyroY());
  Serial.print(" Z: ");
  Serial.println(mpu.getGyroZ());

  Serial.print("Magnetómetro X: ");
  Serial.print(mpu.getMagX());
  Serial.print(" Y: ");
  Serial.print(mpu.getMagY());
  Serial.print(" Z: ");
  Serial.println(mpu.getMagZ());

  Serial.println();

  delay(1000); // Leer cada segundo
}
