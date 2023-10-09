const int dataPin = 3;       // Connect to D (data) of 74HC74 IC - Arduino pin 3
const int clockPin = 4;      // Connect to CP (clock pulse) of 74HC74 IC - Arduino pin 4
const int dFlipFlopOutputPin = 5; // Connect to Q (output) of 74HC74 IC - Arduino pin 5
const int xorOutputPin = 6; // Connect to XOR Output - Arduino pin 6
bool previousOutput = LOW;

//const int xorInvertedOutputPin = 7;  // Connect to XOR Inverted Output - Arduino pin 7

float probabilityDinTransition = 0.3;
float voltageHigh = 3.3;
float voltageLow = 0.0;
float averageVoltageX = 0.0;
unsigned long samplePeriod = 1000; // Time in milliseconds for each clock period

void setup() {
  pinMode(dataPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dFlipFlopOutputPin, INPUT);
  pinMode(xorOutputPin, OUTPUT);
 // pinMode(xorInvertedOutputPin, OUTPUT);

  // Initialize Serial communication for debugging purposes
  Serial.begin(9600);
}

void loop() {
  // Simulate a random data input (Din)
 
  
  // Apply the data input to the D input of the 74HC74 IC
 int dataInput = digitalRead(dataPin);
  
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
//  digitalWrite(xorInvertedOutputPin, xorInvertedOutput);
  previousOutput = dFlipFlopOutput;
  // Print the output states to the Serial Monitor
  Serial.print("Din: ");
  Serial.print(dataInput);
  Serial.print(", D flip-flop output (Q): ");
  Serial.print(dFlipFlopOutput);
  Serial.print(", XOR Output: ");
  Serial.println(xorOutput);
 // Serial.print(", XOR Inverted Output: ");
 // Serial.println(xorInvertedOutput);

  // Add a small delay before repeating the loop
  delay(1000);
}
