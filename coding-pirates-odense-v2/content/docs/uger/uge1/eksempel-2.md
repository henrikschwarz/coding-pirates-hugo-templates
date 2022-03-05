---
bookFlatSection: true
title: "Eksempel 2 - LED & Tactile button"
weight: 2
---
# Eksempel 2 - LED control vha. input og knap
I andet eksempel skal du arbejde med input pins på Arduinoen. I denne øvelse skal du få en knap til at lyse, når der trykkes på en knap.

Følgende billede viser hvordan de elektroniske komponenter skal kobles sammen:
![El-diagram for eksempel 2](/static/example2.png)

# Kodeeksempel 1 - Få en LED til at lyse, når der trykkes på en knap
![Kodeeksempel 1](/static/e2c1.png)

<!--
```cpp
const int ledPin = 8;
const int inputPin = 7;

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

    // Sæt outputtet på ledPin til den læste værdi på inputPin
    digitalWrite(ledPin, input);

    // Vent 100 millisekunder
    delay(100); 
}
```
-->

# Kodeeksempel 2 - Få LED til at lyse og sende tekst til PC ved ændring i input state
![Kodeeksempel 2](/static/e2c2.png)

<!--
```cpp
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
```
-->