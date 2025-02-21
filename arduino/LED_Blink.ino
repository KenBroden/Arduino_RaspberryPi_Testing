void setup() {
    // put your setup code here, to run once:
  pinMode(12, OUTPUT); // initialize digital pin 12 as an output.
  }
  
  void loop() {
    // put your main code here, to run repeatedly:
    digitalWrite(12, HIGH);  // turn the LED on (HIGH is the voltage level)
    delay(50);             // Delay 1000mS = 1Sec
      digitalWrite(12, LOW);  // turn the LED off by making the voltage LOW
    delay(50);             // Delay 1000mS = 1Sec    
  }
  