#include <Wire.h>

#include "MLX90641_API.h"
#include "MLX90641_I2C_Driver.h"

#if defined(ARDUINO_ARCH_AVR)
    #define debug  Serial

#elif defined(ARDUINO_ARCH_SAMD) ||  defined(ARDUINO_ARCH_SAM)
    #define debug  Serial
#else
    #define debug  Serial
#endif

const byte MLX90641_address = 0x33; //Default 7-bit unshifted address of the MLX90641

#define TA_SHIFT 8 //Default shift for MLX90641 in open air

float MLX90641To[192];
paramsMLX90641 MLX90641;

void setup() {
    Wire.begin();
    Wire.setClock(400000); //Increase I2C clock speed to 400kHz

    debug.begin(9600);
    while (!debug); //Wait for user to open terminal
    debug.println("MLX90641 IR Array Example");
    delay(100);

    if (isConnected() == false) {
        debug.println("MLX90641 not detected at default I2C address. Please check wiring. Freezing.");
        delay(100);
        while (1);
    }
    debug.println("MLX90641 online!");
    delay(500);
    //Get device parameters - We only have to do this once
    int status;
    uint16_t eeMLX90641[832];
    status = MLX90641_DumpEE(MLX90641_address, eeMLX90641);
    if (status != 0) {
        debug.println("Failed to load system parameters");
        delay(500);
    }

    status = MLX90641_ExtractParameters(eeMLX90641, &MLX90641);
    if (status != 0) {
        debug.println("Parameter extraction failed");
        delay(500);
    }

    //Once params are extracted, we can release eeMLX90641 array
}

void loop() {
    delay(500);
    for (byte x = 0 ; x < 2 ; x++) { //Read both subpages
      uint16_t MLX90641Frame[242];
      int status = MLX90641_GetFrameData(MLX90641_address, MLX90641Frame);
      if (status < 0) {
            debug.print("GetFrame Error: ");
            debug.println(status);
      }
      //
      float vdd = MLX90641_GetVdd(MLX90641Frame, &MLX90641);
      float Ta = MLX90641_GetTa(MLX90641Frame, &MLX90641, vdd);// likely issue here
      float tr = Ta - TA_SHIFT; //Reflected temperature based on the sensor ambient temperature
      float emissivity = 0.95;

      MLX90641_CalculateTo(MLX90641Frame, &MLX90641, emissivity, tr, MLX90641To, vdd, Ta);
      Serial.println("TAING POST " + String(Ta));
    }
    int count = 0;
    
    Serial.print("[");
    for (int x = 0 ; x < 12 ; x++) {
      Serial.println();
      
      Serial.print("[");
      for (int y = 0; y < 16; y++) {
        Serial.print(String(MLX90641To[y+16*x]) + ", ");
        count++;
      }
      Serial.print("],");
  }
  Serial.print("]");
  delay(1000);

//Returns true if the MLX90641 is detected on the I2C bus
boolean isConnected() {
    Wire.beginTransmission((uint8_t)MLX90641_address);
    if (Wire.endTransmission() != 0) {
        return (false);    //Sensor did not ACK
    }
    return (true);
}
