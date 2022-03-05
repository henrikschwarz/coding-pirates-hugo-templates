const int ledPin = 8;
const int inputPin = 7;

bool lastState = false;

void setup() {

    // Opsæt kommunikationshastighed med PC
    Serial.begin(115200);

    // Opsæt ledPin til at blive anvendt som output
    pinMode(ledPin, OUTPUT);

    // Opsæt inputPin til at blive anvendt som input
    pinMode(inputPin, INPUT);
}

void loop() {
    // Læs signalet på inputPin og gem resultatet i input
    bool input = digitalRead(inputPin);

    // Tjek om input har ændret sig siden sidste læsning
    if (input != lastState) {
        // Skriv tekst til PC afhængig af inputtets værdi
        if (input) {
            Serial.println("Knappen er trykket ned.");
        } else {
            Serial.println("Knappen er sluppet.");
        }
    }

    lastState = input;

    // Sæt outputtet på ledPin til den læste værdi på inputPin
    digitalWrite(ledPin, input);

    // Vent 100 millisekunder
    delay(100); 
}