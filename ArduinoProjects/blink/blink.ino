const int ledPin = 7;

void setup() {
    // Opsæt kommunikationshastighed med PC
    Serial.begin(115200);

    // Opsæt ledPin til at blive anvendt som output
    pinMode(ledPin, OUTPUT);
}

void loop() {
    // Sæt udgangen til et højt signal
    digitalWrite(ledPin, HIGH);
    
    // Send besked til PC
    Serial.println("LED'en blev tændt.");

    // Vent 1000 millisekunder
    delay(1000);
    
    // Sæt udgangen til et lavt signal
    digitalWrite(ledPin, LOW);

    // Send besked til PC
    Serial.println("LED'en blev slukket.");

    // Vent 1000 millisekunder
    delay(1000);
}


