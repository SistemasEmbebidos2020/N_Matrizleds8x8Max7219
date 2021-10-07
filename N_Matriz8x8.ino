/*************************************************** 
  This is a library example for the MLX90614 Temp Sensor

  Designed specifically to work with the MLX90614 sensors in the
  adafruit shop
  ----> https://www.adafruit.com/products/1747 3V version
  ----> https://www.adafruit.com/products/1748 5V version

  These sensors use I2C to communicate, 2 pins are required to  
  interface
  Adafruit invests time and resources providing this open source code, 
  please support Adafruit and open-source hardware by purchasing 
  products from Adafruit!

  Written by Limor Fried/Ladyada for Adafruit Industries.  
  BSD license, all text above must be included in any redistribution
 ****************************************************/

#include <Wire.h>
#include <Adafruit_MLX90614.h>

Adafruit_MLX90614 mlx = Adafruit_MLX90614();


//#######################matriz###########################
#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Max72xxPanel.h>
 
//Vcc - Vcc
//Gnd - Gnd
//Din - Mosi (Pin 11)
//Cs  - SS (Pin 10)
//Clk - Sck (Pin 13)
 
const int pinCS = 10;
const int numberOfHorizontalDisplays = 4;   //
const int numberOfVerticalDisplays = 1;
const int RT = 1;
const int RTs = 1;

Max72xxPanel matrix = Max72xxPanel(pinCS, numberOfHorizontalDisplays, numberOfVerticalDisplays);

const int wait = 50; // Velocidad a la que realiza el scroll
 
const int spacer = 2; //4
const int width = 5 + spacer; // Ancho de la fuente a 5 pixeles //14
//##########################matriz#############################





void setup() {
  Serial.begin(9600);

  //Serial.println("Adafruit MLX90614 test");  

  mlx.begin();  

//###########matriz####################
   Serial.begin(9600);
   matrix.setIntensity(1); // Ajustar el brillo entre 0 y 15
   matrix.setPosition(3, 3, 0); // El cuarto display esta en <3, 0>
   //matrix.setPosition(6, 0, 3); // El cuarto display esta en <3, 0>  //descomentar si pone una segunda fila horizontal
   matrix.setRotation(0, RT);    // Posición del display
   matrix.setRotation(1, RT);    // Posición del display
   matrix.setRotation(2, RT);    // Posición del display
   matrix.setRotation(3, RT);    // Posición del display
   /*matrix.setRotation(4, RTs);    // Posición del display
   matrix.setRotation(5, RTs);    // Posición del display
   matrix.setRotation(6, RTs);    // Posición del display
   matrix.setRotation(7, RTs);    // Posición del display
   matrix.setRotation(8, RT);    // Posición del display
   matrix.setRotation(9, RT);    // Posición del display
   matrix.setRotation(10, RT);    // Posición del display
   matrix.setRotation(11, RT);    // Posición del display*/ //descomentar si pone una segunda fila horizontal
//####################matriz###################



}

void loop() {
//  Serial.print("Ambient = "); Serial.print(mlx.readAmbientTempC()); 
//  Serial.print("*C\tObject = "); 
Serial.print(mlx.readObjectTempC()); Serial.println("*C");
//  Serial.print("Ambient = "); Serial.print(mlx.readAmbientTempF()); 
//  Serial.print("*F\tObject = "); Serial.print(mlx.readObjectTempF()); Serial.println("*F");

  Serial.println();
  delay(500);

//######################matriz#################################
   String cadena = "TONNY";
   cadena = mlx.readObjectTempC();
   long int time = millis();
//   while(Serial.available()){
 //     cadena += char(Serial.read());
 //  }
   for(int i = 0; i < width * cadena.length() + matrix.width() - 1 - spacer; i++){
      matrix.fillScreen(LOW);
      int letter = i / width;
      int x = (matrix.width() - 1) - i % width;
      int y = (matrix.height() - 8) / 2; // Centrar el texto      el #7 cambia para centrar el texto
      while(x + width - spacer >= 0 && letter >= 0){
         if(letter < cadena.length()){
             matrix.drawChar(x, y, cadena[letter], HIGH, LOW, 1);   //cambia el 1 por el número que desees de grosor de cada caracter
         }
         letter--;
         x -= width;
      }
      matrix.write(); // Muestra loscaracteres
      delay(wait);
   }
//##########################matriz####################################

}
