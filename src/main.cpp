#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED width,  in pixels
#define SCREEN_HEIGHT 64 // OLED height, in pixels

// create an OLED display object connected to I2C
Adafruit_SSD1306 oled(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

float calculatePercentChange(int, int);

void setup()
{
  Serial.begin(9600);

  // initialize OLED display with I2C address 0x3C
  if (!oled.begin(SSD1306_SWITCHCAPVCC, 0x3C))
  {
    Serial.println(F("failed to start SSD1306 OLED"));
    while (1)
      ;
  }

  delay(2000);         // wait two seconds for initializing
  oled.clearDisplay(); // clear display

  oled.setTextSize(1);      // set text size
  oled.setTextColor(WHITE); // set text color
  oled.setCursor(0, 2);     // set position to display (x,y)
  oled.println("Sourdough \nBulk Fermantation \nTimer!");  // set text
  oled.display();           // display on OLED

}

void loop()
{
  int ogMeasurement = 80;
  int timer = 0;

  oled.clearDisplay();      
  oled.setCursor(0, 2);
  oled.println("Calibrating..."); // set text
  oled.println("Measuring at "+ String(ogMeasurement) + "mm");
  oled.println("timer started: ");
  oled.println(String(timer) + " seconds");
  oled.println("temp: 70F, expecting at 75% increase");
  oled.display();                 // display on OLED
  delay(2000);

  int readings[] = {80, 80, 75, 74, 72, 70, 68, 67, 66, 62, 60, 59, 58, 55, 54, 50, 40, 30, 10, 10, 10, 10, 0};

  for (int i = 1; i < sizeof(readings); ++i)
  {
    // for each reading, add 5 minutes 
    timer += 360;
    int newValue = readings[i];
    
    float percentChange = calculatePercentChange(ogMeasurement, newValue);

    oled.clearDisplay();                                     // clear display
    oled.setCursor(0, 2);                                    // set position to display (x,y)
    oled.println("distance: " + String(newValue)); // set text
    oled.println("Percent " + String(percentChange) + "%");
    oled.println("timer: " + String(timer/60) + " min");
    oled.println("temp: 70F, RH 65%");
    oled.display(); 
    delay(2000);

  }
}

float calculatePercentChange(int ogMeasurement, int newValue)
{
  float percentChange = ((float)(ogMeasurement - newValue) / ogMeasurement) * 100;
  return percentChange;
}