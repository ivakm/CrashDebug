#include <Arduino.h>
#include "utils/partition_raw.h"

void setup()
{
  Serial.begin(115200);
  delay(1000);
  read_partition_raw();
}

void loop() {}