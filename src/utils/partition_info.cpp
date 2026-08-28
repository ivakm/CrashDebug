#include "partition_info.h"
#include <HardwareSerial.h>
#include "esp_partition.h"

void print_partition_table()
{
  esp_partition_iterator_t it = esp_partition_find(ESP_PARTITION_TYPE_ANY, ESP_PARTITION_SUBTYPE_ANY, NULL);

  Serial.println("=== Partition Table ===");
  Serial.printf("%-12s %-8s %-10s %-10s %-10s\n", "Name", "Type", "Subtype", "Address", "Size");
  Serial.println("------------------------------------------------------");

  while (it != NULL)
  {
    const esp_partition_t *p = esp_partition_get(it);
    Serial.printf("%-12s %-8d %-10d 0x%08x  0x%08x\n",
                  p->label, p->type, p->subtype, p->address, p->size);
    it = esp_partition_next(it);
  }

  esp_partition_iterator_release(it);
  Serial.println("======================");
}