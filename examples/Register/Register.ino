#include <Arduino.h>
#include <TinyBool.h>

// Define LED pin
const int ledPin = 13;

// Create an 8-bit control register
TinyBool Register(8);

// Setup function
void setup() {

	// Set LED pin as output
	pinMode(ledPin, OUTPUT);

	// Start serial communication
	Serial.begin(115200);

	// Set the 7th bit of the control register to HIGH
	Register[7] = HIGH;

}

void loop() {

	// Check the 3rd bit and set the LED accordingly
	if (Register[3]) {
		digitalWrite(ledPin, HIGH); // Turn on the LED
	} else {
		digitalWrite(ledPin, LOW); // Turn off the LED
	}

	// Change the state of the 3rd bit every 1 seconds
	Register[3] = !Register[3]; // Change the bit value
	
	// Wait for 1 seconds
	delay(1000);

	// Print the LED state
	Serial.print("LED State: "); Serial.println(Register[3] ? "ON" : "OFF");

	// Get the initial container data
	uint8_t* containerData = (uint8_t*) Register.DataContainer();

	// Print the initial container data
	Serial.print("Initial Container Data: "); Serial.println(*containerData, BIN);

	// Print a separator
    Serial.println("-----------------------------");

}