#include <Arduino.h>

#define IN1_PIN PB2 // Pin connected to IN1 of H-Bridge
#define IN2_PIN PA8 // Pin connected to IN2 of H-Bridge

// Define AC frequency (50Hz or 60Hz)
#define AC_FREQUENCY 50 // Change to 60 if needed

// Calculate PWM period in milliseconds for the given frequency
#define PWM_PERIOD_MS (1000 / (2 * AC_FREQUENCY)) // Half-period duration in ms

// Define ON and OFF durations in milliseconds
#define ON_DURATION_MS 1000
#define OFF_DURATION_MS 1000

void setup()
{
    // Set H-Bridge control pins as outputs
    pinMode(IN1_PIN, OUTPUT);
    pinMode(IN2_PIN, OUTPUT);
}

void loop()
{
    // Step 1: Generate the VAC signal for 5 seconds
    unsigned long startTime = millis(); // Record the start time
    while (millis() - startTime < ON_DURATION_MS)
    {
        // Generate square wave signals for the H-Bridge

        // Forward (IN1 = HIGH, IN2 = LOW)
        digitalWrite(IN1_PIN, HIGH);
        digitalWrite(IN2_PIN, LOW);
        delay(PWM_PERIOD_MS); // Wait for half-period

        // Reverse (IN1 = LOW, IN2 = HIGH)
        digitalWrite(IN1_PIN, LOW);
        digitalWrite(IN2_PIN, HIGH);
        delay(PWM_PERIOD_MS); // Wait for half-period
    }

    // Step 2: Stop the signal for 5 seconds
    digitalWrite(IN1_PIN, LOW); // Set both pins LOW
    digitalWrite(IN2_PIN, LOW); // This puts the H-Bridge in coast mode
    delay(OFF_DURATION_MS);     // Wait for 5 seconds
}