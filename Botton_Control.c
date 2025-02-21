#include <wiringPi.h>
#include <stdio.h>
#include <stdlib.h>
// #include <unistd.h>  // For usleep()

#define RED_LED 0     // gpio 17 WiringPi Pin 0
#define GREEN_LED 2   // gpio 27 WiringPi Pin 2
#define BUTTON 3      // gpio 22 WiringPi Pin 3

void setup() {
    wiringPiSetup(); // Initialize WiringPi library
    pinMode(RED_LED, OUTPUT);
    pinMode(GREEN_LED, OUTPUT);
    pinMode(BUTTON, INPUT);
    pullUpDnControl(BUTTON, PUD_DOWN); // Enable pull-down resistor
}

void loop() {
    while (1) {
        if (digitalRead(BUTTON) == HIGH) {
            digitalWrite(GREEN_LED, HIGH); // Turn on Green LED
            for (int i = 0; i < 5; i++) {  // Blink Red LED
                digitalWrite(RED_LED, HIGH);
                delay(200); // 200ms delay
                digitalWrite(RED_LED, LOW);
                delay(200);
                if (digitalRead(BUTTON) == LOW) break; // Stop blinking if button released
            }
        } else {
            digitalWrite(GREEN_LED, LOW); // Turn off Green LED
            digitalWrite(RED_LED, LOW);   // Ensure Red LED is off
        }
        delay(100); // Small delay for debounce handling
    }
}

int main() {
    setup();
    loop();
    return 0;
}
