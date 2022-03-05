const int inputPin = A0;
const int outputPin = 6;

void setup() {
    // Opsæt kommunikationshastighed med PC
    Serial.begin(115200);

    pinMode(outputPin, OUTPUT);
}

void loop() {
    // Læs inputsignalet på den analoge indgang A0, og gem resultatet i variablen input
    // Analog read returnerer en værdi mellem 0 og 1023 proportionelt med spændingen på A0 
    int input = analogRead(A0);

    // Map inputværdien mellem 0 og 1023 til en proportionel værdi mellem 0 og 255
    // Map anvendes fordi, Arduinoen læser analoge inputværdier med en opløsning på 1024 steps, mens output kun har en opløsning på 256 steps. 
    input = map(input, 0, 1023, 0, 255);

    // Skriv den mappede inputværdi til outputPin
    analogWrite(outputPin, input);

    // Vent 100 millisekunder
    delay(100);
}