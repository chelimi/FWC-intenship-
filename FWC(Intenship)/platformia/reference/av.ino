const int dataPin = 3;       // Connect to D (data) of 74HC74 IC - Arduino pin 3
const int clockPin = 4;      // Connect to CP (clock pulse) of 74HC74 IC - Arduino pin 4
const int dFlipFlopOutputPin = 5; // Connect to Q (output) of 74HC74 IC - Arduino pin 5
const int xorOutputPin = 6; // Connect to XOR Output - Arduino pin 6
bool previousOutput = LOW;

float voltageHigh = 3.3;
float voltageLow = 0.0;
float averageVoltageX = 0.0;
int sampleCount = 0;

void setup() {
  pinMode(dataPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dFlipFlopOutputPin, INPUT);
  pinMode(xorOutputPin, OUTPUT);

  // Initialize Serial communication for debugging purposes
  Serial.begin(9600);
}

void loop() {
  // Manually set the data input (Din) to simulate transitions
  bool dataInput = LOW; // Change this to LOW or HIGH manually to simulate Din transition

  // Apply the data input to the D input of the 74HC74 IC
  digitalWrite(dataPin, dataInput);

  // Create a rising edge on the clock (CP) to trigger the D flip-flop
  digitalWrite(clockPin, HIGH);
  delay(1);
  digitalWrite(clockPin, LOW);
  
  // Read the output (Q) of the 74HC74 IC and store it in a variable
  bool dFlipFlopOutput = digitalRead(dFlipFlopOutputPin);

  // Calculate XOR Output and XOR Inverted Output
  bool xorOutput = dFlipFlopOutput ^ previousOutput;

  // Output the results of XOR gate to the respective pins
  digitalWrite(xorOutputPin, xorOutput);
  averageVoltageX = (averageVoltageX + (xorOutput == HIGH ? voltageHigh : voltageLow)) / 2.0;

  // Calculate the probability of input data bit (Din) transition (always 0.5 since it's manually controlled)
  float probability = 0.5;
  sampleCount++;

  previousOutput = dFlipFlopOutput;
  
  // Print the output states to the Serial Monitor
  Serial.print("Din: ");
  Serial.print(dataInput);
  Serial.print(", D flip-flop output (Q): ");
  Serial.print(dFlipFlopOutput);
  Serial.print(", XOR Output: ");
  Serial.print(xorOutput);
  Serial.print(", Average Voltage at Node X: ");
  Serial.println(averageVoltageX, 4);

  // Add a small delay before repeating the loop
  delay(1000);
}

//With this code, you can manually control the Din input by setting the dataInput variable to either LOW (GND) or HIGH (VCC). The code will calculate the average voltage at node X accordingly. The Serial Monitor will display the input states (Din), the D flip-flop output (Q), the XOR Output, and the average voltage at node X. The calculation will be based on the probability of Din transition (0.5, as it's manually controlled) and will be updated every 100 milliseconds.
