#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// Definimos el ancho y alto de la pantalla OLED
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

// Creamos un objeto de tipo Adafruit_SSD1306
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

void setup() {
  Serial.begin(115200);

  // Inicializamos la pantalla con I2C address 0x3C
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }
  
  // Limpiamos el buffer de la pantalla
  display.clearDisplay();
  
  // Configuramos el tamaño del texto
  display.setTextSize(1);
  // Configuramos el color del texto
  display.setTextColor(SSD1306_WHITE);
  // Configuramos la posición del cursor (X,Y)
  display.setCursor(0,0);
  // Imprimimos "Hola Mundo"
  display.println(F("Hola Mundo"));
  
  // Mostramos en la pantalla lo que tenemos en el buffer
  display.display();
}

void loop() {
  // No hacemos nada en el loop
}

