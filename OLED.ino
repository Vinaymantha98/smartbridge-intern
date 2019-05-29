#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define OLED_RESET D5
/* Object named display, of the class Adafruit_SSD1306 */
Adafruit_SSD1306 display(OLED_RESET);

#if (SSD1306_LCDHEIGHT != 64)
fg'#error("Height incorrect, please fix Adafruit_SSD1306.h!");
#endif

uint8_t s = 0, m = 0, h = 0;
const int buttonPin=D4;
const int ledPin = D6;
int buttonState = 0;

void setup()   {
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C); /* Initialize display with address 0x3C */
  display.clearDisplay();  /* Clear display */
  display.setTextSize(1);	/* Select font size of text. Increases with size of argument. */
  display.setTextColor(WHITE);	/* Color of text*/
  pinMode(ledPin,OUTPUT);
  pinMode(buttonPin,INPUT);
  
}

void loop() {
  buttonState= digitalRead(buttonPin);
  if(buttonState==HIGH)
  {
  display.clearDisplay();
  drawStr(20,50,"on");
  }
  else{
  display.clearDisplay();
  drawStr(20,50,"off");
}
}

void drawStr(uint8_t x, uint8_t y, char* str){
  display.setCursor(x, y);  /* Set x,y coordinates */
  display.println(str);
}
