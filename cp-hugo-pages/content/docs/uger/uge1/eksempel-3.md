---
bookFlatSection: true
title: "Eksempel 3 - LED & Potentiometer"
weight: 2
---
# Eksempel 3 - LED PWM control vha. analogt input og potentiometer
I tredje eksempel skal du arbejde med analoge input pins på Arduinoen. I denne øvelse skal du få en LED til at lyse proportionelt med et potentiometers position.

Følgende billede viser hvordan de elektroniske komponenter skal kobles sammen:
![El-diagram for eksempel 3](/static/example3.png)

# Kodeeksempel 1 - Få en LED til at lyse proportionelt med potentiometer

![Kodeeksempel 1](/static/e3c1.png)

<!--
```cpp
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
```
-->