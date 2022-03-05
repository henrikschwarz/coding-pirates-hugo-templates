const int ledPin = 7;

void setup() {
    // Opsæt kommunikationshastighed med PC
    Serial.begin(115200);

    // Opsæt ledPin til at blive anvendt som output
    pinMode(ledPin, OUTPUT);
}

void loop() {
    // Sæt outputtet på ledPin til lig med negationen ledPins signal
    digitalWrite(ledPin, !digitalRead(ledPin));
    
    // Skriv forskellige tekster til PC afhængig af værdien af ledState
    if (digitalRead(ledPin) == true) {
        Serial.println("LED'en er tændt.");
    } else {
        Serial.println("LED'en er slukket.");
    }

    // Vent 1000 millisekunder
    delay(1000);
}