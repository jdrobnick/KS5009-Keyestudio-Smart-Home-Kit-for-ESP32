#define fanPin1 19
#define fanPin2 18
#define btn1 16
#define btn2 27

int btn_count = 0;
int btn_count2 = 0;
int speed_val = 130;
boolean btn1_prev = HIGH;
boolean btn2_prev = HIGH;

void setup() {
  Serial.begin(115200);
  pinMode(btn1, INPUT);
  pinMode(btn2, INPUT);
  pinMode(fanPin1, OUTPUT);
  pinMode(fanPin2, OUTPUT);
}

void loop() {
  boolean btn1_val = digitalRead(btn1);
  boolean btn2_val = digitalRead(btn2);
  boolean power_state = btn_count % 2;

  // Button 1: toggle fan on/off (detect release edge)
  if (btn1_prev == LOW && btn1_val == HIGH) {
    delay(10);
    if (digitalRead(btn1) == HIGH) {
      btn_count++;
      Serial.println(btn_count);
    }
  }
  btn1_prev = btn1_val;

  // Button 2: cycle speed low/med/high (only while fan is on)
  if (power_state && btn2_prev == LOW && btn2_val == HIGH) {
    delay(10);
    if (digitalRead(btn2) == HIGH) {
      btn_count2++;
      if (btn_count2 > 3) btn_count2 = 1;
      switch (btn_count2) {
        case 1: speed_val = 130; break;
        case 2: speed_val = 180; break;
        case 3: speed_val = 230; break;
      }
      Serial.println(speed_val);
    }
  }
  btn2_prev = btn2_val;

  // Apply fan state every loop
  if (power_state) {
    digitalWrite(fanPin1, LOW);
    analogWrite(fanPin2, speed_val);
  } else {
    digitalWrite(fanPin1, LOW);
    analogWrite(fanPin2, 0);
  }
}
