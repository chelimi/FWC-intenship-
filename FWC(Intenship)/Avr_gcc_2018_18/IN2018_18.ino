#include <LiquidCrystal.h>

LiquidCrystal lcd(8, 9, 4, 5, 6, 7); // RS, EN, D4, D5, D6, D7

float number;
int a;
float b;
String binary_whole_part = "";
String binary_fractional_part = "";

void setup() {
  lcd.begin(16, 2); // Initialize the LCD with 16 columns and 2 rows
  lcd.print("Enter number:");
  
  Serial.begin(9600);
  Serial.print("Enter the number: ");
  while (!Serial.available()) {
    // Wait for user input
  }
  number = Serial.parseFloat();
  
  a = int(number);
  b = number - a;
  
  while (a > 0) {
    int c = a % 2;
    a /= 2;
    binary_whole_part = String(c) + binary_whole_part;
  }
  
  while (b > 0 && binary_fractional_part.length() <= 15) {
    b *= 2;
    int bit = int(b);
    binary_fractional_part += String(bit);
    b -= bit;
  }
  
  lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Binary: ");
    lcd.setCursor(0, 1);
    lcd.print(binary_whole_part + "." + binary_fractional_part);

    // Print binary on Serial Monitor
    Serial.print("Binary Representation: ");
    Serial.println(binary_whole_part + "." + binary_fractional_part);
}

void loop() {
  // Empty loop
} 
