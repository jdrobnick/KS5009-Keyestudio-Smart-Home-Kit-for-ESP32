#define btn1 16
#define led_y 12

int btn_count = 0;
boolean btn1_prev = HIGH;

void setup()
{
  Serial.begin(115200);
  pinMode(btn1, INPUT);
  pinMode(led_y, OUTPUT);
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
      Serial.println(btn_count);
      digitalWrite(led_y, btn_count % 2 ? HIGH : LOW);
    }
  }
  btn1_prev = btn1_val;
}
