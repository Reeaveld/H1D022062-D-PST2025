#include <Arduino.h>
#include <LiquidCrystal_I2C.h>

int SDA_PIN = D2;
int SCL_PIN = D3;
LiquidCrystal_I2C lcd(0x27, 16, 1);

void setup()
{
    Wire.begin(SDA_PIN, SCL_PIN);
    lcd.init(); // Inisialisasi LCD I2C
    lcd.backlight(); // Nyalakan backlight LCD
    lcd.setCursor(0, 0); // Set cursor ke kolom 0 baris 0
    lcd.print("Hidup Jokowi"); // Tampilkan pesan di LCD
    lcd.setCursor(0, 1); // Set cursor ke kolom 0 baris 1
    lcd.print("<3 Jokowi <3");
}

void loop()
{
  lcd.scrollDisplayLeft(); // Scroll display ke kiri
  delay(100);
}