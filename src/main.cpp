#include <Arduino.h>
#include "utils/partition_info.h"

void setup()
{
  Serial.begin(115200);
  delay(1000);
  print_partition_table();
}

void loop() {}