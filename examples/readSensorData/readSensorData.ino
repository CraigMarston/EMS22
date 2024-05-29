// Example code for EMS22 library - Absolute Rotary Encoder
// Written by William Hammer, NTNU 2023.

// This example supports daisy chained encoders.
// Daisy chain means connecting output from one encoder into input of another encoder.

// Get the library at https://github.com/autoHammer/EMS22
#include "EMS22.h"

// Check connection in the datasheet at https://www.elfadistrelec.no/Web/Downloads/_t/ds/EMS22A50-B28-LS6_eng_tds.pdf
const int CLK = 11;   // encoder pin 2
const int DO  = 10;   // encoder pin 4
const int CS  = 9;    // encoder pin 6

// Declare object
AbsEncoder Coder(CLK, DO, CS);

void setup() {
  Serial.begin(9600);
  while (!Serial); // wait for serial to establish

  // Initialize object
  Coder.begin();
}

void loop() {
  // Read the value of all encoders. Data is stored in the object Coder.
  // Must be ran every time data needs to be updated.
  Coder.read();

  // Fetch data. Input is the encoder index.
  // The encoder connected closest to the Arduino has index 0.
  // AnalogData is a number between 0 and 1024 (one loop).
  int encoder0Data = Coder.getAnalogData(0);
  //Serial.println(encoder0Data);

  // plotAngles will format and print all angle data.
  // Use Serial plotter under "Tools" to see the result.
  Coder.plotAngles();

  // Store all analog data into a list.
  // First index is first connected encoder.
  int dataList[2];
  Coder.copyAllAnalog(dataList);
  //Serial.println(dataList[0]);

  delay(1);
}
