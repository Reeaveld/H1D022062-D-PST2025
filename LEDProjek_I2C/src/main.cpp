// GND ke GND
// VCC ke Vin
// SDA ke D2
// SCL ke D3

#include <Arduino.h>
#include <Wire.h>
// put function declarations here:
int SDA_PIN = D2;
int SCL_PIN = D3;

void setup()
{
  Wire.begin(SDA_PIN, SCL_PIN);
  Serial.begin(9600); // Inisialisasi I2C dengan custom PIN SDA dan SCL pin
}

void loop() {
  byte error, address;
  int nDevices = 0;

  Serial.print("Scanning...");
  nDevices = 0;

  for(address = 1; address < 127; address++) {
    Wire.beginTransmission(address);
    error = Wire.endTransmission();

    if (error == 0) {
      Serial.print("I2C terbaca pada address 0x");
      if (address < 16) {
        Serial.print("0");
      }
      Serial.print(address, HEX);
      Serial.println("...!");
      nDevices++;
    }
      else if (error == 4) {
      Serial.print("Ada error yang tidak diketahui di address 0x");
      if (address < 16) {
        Serial.print("0");
      }
      Serial.println(address, HEX);
    }
  }
  
  if (nDevices == 0) {
    Serial.print("Tidak ada satupun alamat I2C yang terdeteksi\n");
  } else {
    Serial.print("Selesai\n");
  }
  delay(5000); // Tunggu 5s untuk scan selanjutnya
}