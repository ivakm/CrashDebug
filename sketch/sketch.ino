#include <Arduino.h>

void crash_me() {
  volatile int x = 0;
  volatile int y = 10 / x;
  (void)y;
}

void crash_pointer()
{
  int *ptr = (int *)0xDEADBEEF;
  *ptr = 42;
}

void setup()
{
  Serial.begin(9600);
  delay(1000);
  Serial.println("Start working...");
  crash_pointer();
  // crash_me();
}

void loop() {}