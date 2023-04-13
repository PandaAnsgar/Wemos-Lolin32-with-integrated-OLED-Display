
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

//define the size of screen
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define WHITE SSD1306_WHITE

//create variables
int sec = 0;
int minutes = 0;

//set up the display
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);
 
void setup() {
  //start serial communication
  Serial.begin(115200);
  
  // Start I2C Communication SDA = 5 and SCL = 4 on Wemos Lolin32 ESP32 with built-in SSD1306 OLED
  Wire.begin(5, 4);

  //start the display
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C, false, false)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);   
  }
  display.setTextColor(WHITE);
  display.setTextSize(1);
}
void loop() {
  //set the time
  sec++;
  if (sec >= 60){
    minutes++;
    sec = 0;
  }
  //print the time
  display.clearDisplay();
  display.setCursor(30, 20);
  display.print(minutes);
  display.print(" , ");
  display.print(sec);
  display.display();
  delay(1000);
}