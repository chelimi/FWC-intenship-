#include <LiquidCrystal.h>

// Define LCD module connections
const int rs = 8;
const int en = 9;
const int d4 = 10;
const int d5 = 11;
const int d6 = 12;
const int d7 = 13;

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

const int dataPin = 3;        // Connect to D (data) of 74HC74 IC - Arduino pin 3
const int clockPin = 4;       // Connect to CP (clock pulse) of 74HC74 IC - Arduino pin 4
const int dFlipFlopOutputPin = 5; // Connect to Q (output) of 74HC74 IC - Arduino pin 6
const int xorOutputPin = 6;  // Connect to XOR Output - Arduino pin 10

bool previousOutput = LOW;    // Variable to store the previous state of D flip-flop output (Q)
float probabilityDinTransition = 0.3;
float voltageHigh = 3.3;
float voltageLow = 0.0;
float averageVoltageX = 0.0;
unsigned long samplePeriod = 1000;

void setup() {
  pinMode(dataPin, INPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dFlipFlopOutputPin, INPUT);
  pinMode(xorOutputPin, OUTPUT);

  // Initialize the LCD
  lcd.begin(16, 2);
  lcd.clear();
  lcd.print("Average Voltage:");
  Serial.begin(9600);
}

void loop() {
  unsigned long startTime = millis(); // Get the starting time of the clock period
  // Manually set the data input (Din) to simulate transitions
   bool dataInput = digitalRead(dataPin);
  // Create a rising edge on the clock (CP) to trigger the D flip-flop
  digitalWrite(clockPin, HIGH);
  delay(1);
  digitalWrite(clockPin, LOW);
  // Read the output (Q) of the 74HC74 IC and store it in a variable
  bool dFlipFlopOutput = digitalRead(dFlipFlopOutputPin);
  // Calculate XOR Output and XOR Inverted Output
  bool xorOutput = dFlipFlopOutput ^ previousOutput;
 // bool xorInvertedOutput = !xorOutput;
  // Output the results of XOR gate to the respective pins
  digitalWrite(xorOutputPin, xorOutput);
  averageVoltageX = (averageVoltageX + (xorOutput == HIGH ? voltageHigh : voltageLow)) / 2.0;
  unsigned long elapsedTime = millis() - startTime;
  // Wait for the remaining time of the clock period before starting the next clock periodS
  if (elapsedTime < samplePeriod) {
    delay(samplePeriod - elapsedTime);
  }
//  digitalWrite(xorInvertedOutputPin, xorInvertedOutput);
  previousOutput = dFlipFlopOutput;
  // Display the average voltage at node X on the LCD
  lcd.setCursor(0, 1);
  lcd.print("        "); // Clear the previous value
  lcd.setCursor(0, 1);
  lcd.print(averageVoltageX, 2); // Display average voltage with 2 decimal places
  // Add a small delay before repeating the loop
  delay(1000);
  Serial.print("Din: ");
  Serial.print(dataInput);
  Serial.print(", D flip-flop output (Q): ");
  Serial.print(dFlipFlopOutput);
  Serial.print(", XOR Output: ");
  Serial.print(xorOutput);
  Serial.print(",averageVoltageX: ");
  Serial.println(averageVoltageX);
}
