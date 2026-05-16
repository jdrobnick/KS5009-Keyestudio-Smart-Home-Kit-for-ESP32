#include <musicESP32_home.h>
music Music(25);
#define btn1 16

int btn_count = 0;
boolean btn1_prev = HIGH;

void setup()
{
  Serial.begin(115200);
  pinMode(btn1, INPUT);
}

void loop()
{
  boolean btn1_val = digitalRead(btn1);

  // Detect rising edge (button released) with debounce
  if (btn1_prev == LOW && btn1_val == HIGH)
  {
    delay(10);
    if (digitalRead(btn1) == HIGH)
    {
      btn_count++;
      if (btn_count > 3) btn_count = 1;
      Serial.println(btn_count);

      switch (btn_count)
      {
        case 1: Music.Ode_to_Joy(); break;
        case 2: Music.christmas();  break;
        case 3: Music.tetris();     break;
      }
    }
  }
  btn1_prev = btn1_val;
}
