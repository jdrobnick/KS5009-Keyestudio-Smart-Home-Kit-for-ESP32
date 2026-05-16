#define btn1 16
#define btn2 27

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
 #include <avr/power.h>
#endif

#define LED_PIN   26
#define LED_COUNT 4
Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

int btn_count = 0;
boolean btn1_prev = HIGH;
boolean btn2_prev = HIGH;

void setup()
{
  Serial.begin(115200);
  pinMode(btn1, INPUT);
  pinMode(btn2, INPUT);

  #if defined(__AVR_ATtiny85__) && (F_CPU == 16000000)
    clock_prescale_set(clock_div_1);
  #endif

  strip.begin();
  strip.show();
  strip.setBrightness(50);
}

void loop()
{
  boolean btn1_val = digitalRead(btn1);
  boolean btn2_val = digitalRead(btn2);

  // Button 1: decrement color (detect release edge)
  if (btn1_prev == LOW && btn1_val == HIGH) {
    delay(10);
    if (digitalRead(btn1) == HIGH) {
      if (btn_count > 0) btn_count--;
      Serial.println(btn_count);
    }
  }
  btn1_prev = btn1_val;

  // Button 2: increment color (detect release edge)
  if (btn2_prev == LOW && btn2_val == HIGH) {
    delay(10);
    if (digitalRead(btn2) == HIGH) {
      if (btn_count < 6) btn_count++;
      Serial.println(btn_count);
    }
  }
  btn2_prev = btn2_val;

  switch (btn_count)
  {
    case 0: colorWipe(strip.Color(  0,   0,   0), 50); break; // Off
    case 1: colorWipe(strip.Color(255,   0,   0), 50); break; // Red
    case 2: colorWipe(strip.Color(  0, 255,   0), 50); break; // Green
    case 3: colorWipe(strip.Color(  0,   0, 255), 50); break; // Blue
    case 4: colorWipe(strip.Color(255, 255,   0), 50); break; // Yellow
    case 5: colorWipe(strip.Color(255,   0, 255), 50); break; // Magenta
    case 6: colorWipe(strip.Color(255, 255, 255), 50); break; // White
  }
}

void colorWipe(uint32_t color, int wait)
{
  for (int i = 0; i < strip.numPixels(); i++) {
    strip.setPixelColor(i, color);
    strip.show();
    delay(wait);
  }
}
