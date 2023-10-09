#include <LiquidCrystal.h>

// Define LCD module connections
const int rs = 8;
const int en = 9;
const int d4 = 10;
const int d5 = 11;
const int d6 = 12;
const int d7 = 13;

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

const int dataPin = 3;        // Connect to D (data) of 74HC74 IC - Arduino pin 8
const int clockPin = 4;       // Connect to CP (clock pulse) of 74HC74 IC - Arduino pin 9
const int dFlipFlopOutputPin = 5; // Connect to Q (output) of 74HC74 IC - Arduino pin 6
const int xorOutputPin = 6;  // Connect to XOR Output - Arduino pin 10

bool previousOutput = LOW;    // Variable to store the previous state of D flip-flop output (Q)
float voltageSum = 0;
int sampleCount = 0;

void setup() {
  pinMode(dataPin, INPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dFlipFlopOutputPin, INPUT);
  pinMode(xorOutputPin, OUTPUT);

  // Initialize the LCD
  lcd.begin(16, 2);
  lcd.clear();
  lcd.print("Average Voltage:");
}

void loop() {
  // Simulate a random data input (Din) with a transition probability of 0.3
  bool dataInput = random(100) < 30 ? !previousOutput : previousOutput;

  // Apply the data input to the D input of the 74HC74 IC
  digitalWrite(dataPin, dataInput);

  // Create a rising edge on the clock (CP) to trigger the D flip-flop
  digitalWrite(clockPin, HIGH);
  delay(1);
  digitalWrite(clockPin, LOW);

  // Read the output (Q) of the 74HC74 IC and store it in a variable
  bool dFlipFlopOutput = digitalRead(dFlipFlopOutputPin);

  // Calculate XOR Output using the previous and current D flip-flop outputs
  bool xorOutput = dFlipFlopOutput ^ previousOutput;

  // Update the previous D flip-flop output to the current state
  previousOutput = dFlipFlopOutput;

  // Calculate the probability of input data bit (Din) transition
  float probability = dataInput == previousOutput ? 0.3 : 1.0 - 0.3;

  // Accumulate the voltages to calculate the average value at node X
  float voltage = xorOutput ? 3.3 : 0;
  voltageSum += (voltage * probability);
  sampleCount++;

  // Output the XOR gate result to the XOR Output pin
  digitalWrite(xorOutputPin, xorOutput);

  // Display the average voltage at node X on the LCD
  float averageVoltage = voltageSum / sampleCount;
  lcd.setCursor(0, 1);
  lcd.print("        "); // Clear the previous value
  lcd.setCursor(0, 1);
  lcd.print(averageVoltage, 2); // Display average voltage with 2 decimal places
  if (abs(averageVoltage - 0.8415) < 0.0001) {
    while (true) {
      // Do nothing, the loop will be stopped here
    }
  }
  // Add a small delay before repeating the loop
  delay(1000);
}
