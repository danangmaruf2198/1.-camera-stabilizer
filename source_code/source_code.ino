#include <Wire.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h>
#define OLED_ADDR   0x3C
#include<EEPROM.h>
Adafruit_SSD1306 display(-1);
byte tombolAtas, tombolAtasAkhir, tombolBawah, tombolBawahAkhir, tombolOke, tombolOkeAkhir, tombolBack, tombolBackAkhir, menu1, pilihan = 1, submenu = 1;
int AspeedManual = EEPROM.read(1), BspeedManual = EEPROM.read(2), AspeedPot = EEPROM.read(3), BspeedPot = EEPROM.read(4), AspeedOtomatis = EEPROM.read(5), BspeedOtomatis = EEPROM.read(6), AstepValue = EEPROM.read(7), BstepValue = EEPROM.read(8), kaliPengulangan = 2, ulang = 0;
int speedManual = AspeedManual*256+BspeedManual, speedPot = AspeedPot*256+BspeedPot, speedOtomatis = AspeedOtomatis*256+BspeedOtomatis, stepValue = AstepValue*256+BstepValue;
//EEPROM.update(1,1900);
//EEPROM.update(2,3000);
//EEPROM.update(3,500); 
//EEPROM.update(4,300);
//tombol atas 40-45
//timbol bawah 172-177
//tombol back 61-67
//tombol ok 102-108
// PR MANUAL MODE DI HOLD ATAS BAWAH DAN BACK
// COBA PIN ENABLE MOTOR
#define NUMFLAKES 10
#define XPOS 0
#define YPOS 1
#define DELTAY 2
#define LOGO16_GLCD_HEIGHT 10
#define LOGO16_GLCD_WIDTH  16
static const unsigned char PROGMEM logo_bmp[] =
{ B11100000, B00000111,
  B11100000, B00000111,
  B11110000, B00001111,
  B11111000, B00011111,
  B11111100, B00111111,
  B11111110, B01111111,
  B11111111, B11111111,
  B11101111, B11110111,
  B11100111, B11100111,
  B11100011, B11000111,
  B11100000, B00000111,
  B11100000, B00000111,
  B11100000, B00000111,
  B11100000, B00000111,
  B11100000, B00000111,
  B11100000, B00000111
};
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64

#define encoder0PinA  2
#define encoder0PinB  3
volatile unsigned int encoder0Pos = 0;

int valA;
int valB;
int valC;

const int stepPin = 3;
const int dirPin = 2;
int  arah, y, x, potensioSekarang, potensio;
byte clk;
byte menuCount = 1;
byte dir = 0;
bool runState = false;

void setup() {
  pinMode(6, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);
  Serial.begin(9600);
  display.begin(SSD1306_SWITCHCAPVCC, OLED_ADDR);
  display.display();
  display.clearDisplay();
}

void loop() {
  event_tombolnya();
  menuAwal();
  AspeedManual = speedManual / 256; EEPROM.write(1, AspeedManual);
  BspeedManual = speedManual % 256; EEPROM.write(2,BspeedManual);
  AspeedPot = speedPot / 256; EEPROM.write(3,AspeedPot);
  BspeedPot = speedPot % 256; EEPROM.write(4,BspeedPot);
  AspeedOtomatis = speedOtomatis / 256; EEPROM.write(5,AspeedOtomatis);
  BspeedOtomatis = speedOtomatis % 256; EEPROM.write(6,BspeedOtomatis);
  AstepValue = stepValue / 256; EEPROM.write(7,AstepValue);
  BstepValue = stepValue % 256; EEPROM.write(8,BstepValue);
  
  while (submenu == 1 && menu1 == 3 && pilihan == 1) {
    event_tombolnya();
    jalanManual();
  }
  while (submenu == 1 && menu1 == 3 && pilihan == 5) {
    event_tombolnya();
    jalanPotensioDelay();
  }
  while (submenu == 1 && menu1 == 3 && pilihan == 2) {
    event_tombolnya();
    jalanOtomatis();
  }
  Serial.print(submenu);
  Serial.print("  ");
  Serial.print(pilihan);
  Serial.print("  ");
  Serial.print(menu1);
  Serial.print("  ");
  Serial.print(kaliPengulangan);
  Serial.println("  ");
  display.clearDisplay();
}

void testscrolltext(void) {
  display.clearDisplay();
  display.setTextSize(2); // Draw 2X-scale text
  display.setTextColor(WHITE);
  display.setCursor(10, 0);
  display.println(F("MECHLAB"));
  display.setTextSize(1);
  display.setCursor(0, 20);
  display.println(F("press OK for menu"));
  display.display();      // Show initial text

  // Scroll in various directions, pausing in-between:
  display.startscrollright(0x00, 0x0F);
  delay(2000);
  display.stopscroll();
  delay(1000);
  display.startscrollleft(0x00, 0x0F);
  delay(2000);
  display.stopscroll();
  delay(1000);
  display.startscrolldiagright(0x00, 0x07);
  delay(2000);
  display.startscrolldiagleft(0x00, 0x07);
  delay(2000);
  display.stopscroll();
  delay(1000);
}
