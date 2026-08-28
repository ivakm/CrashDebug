#include "partition_raw.h"
#include <HardwareSerial.h>
#include "esp_flash.h"

#define PARTITION_TABLE_ADDR 0x8000
#define READ_SIZE 256

void read_partition_raw()
{
    uint8_t buf[READ_SIZE];

    esp_err_t err = esp_flash_read(NULL, buf, PARTITION_TABLE_ADDR, READ_SIZE);

    if (err != ESP_OK)
    {
        Serial.printf("Read error: %d\n", err);
        return;
    }

    Serial.println("=== Raw Partition Table (hex) ===");
    for (int i = 0; i < READ_SIZE; i++)
    {
        Serial.printf("%02X ", buf[i]);
        if ((i + 1) % 16 == 0)
            Serial.println();
    }
    Serial.println("=================================");
}