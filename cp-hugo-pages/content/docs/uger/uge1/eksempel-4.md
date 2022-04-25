---
bookFlatSection: true
title: "Eksempel 4 - Buzzer"
weight: 4
---
# Eksempel 1 - Buzzer
I det her eksempel skal vi sætte en buzzer op. For at gøre det skal vi bruge det her el-diagram:

![buzzer](/static/buzzer_bb_cut.png)

# Eksempel 1 - Buzzer kode
For at få buzzeren til at virke skal vi bruge `tone` og `noTone` som laver bølger med forskellige frekvenser og sender det til buzzeren.
```cpp
#define BUZZER_PIN 8 // Sæt buzzer pin
int frekvens = 330;

void setup() {
  pinMode(8, OUTPUT);
}

void loop() {
  tone(BUZZER_PIN, frekvens);
}
```
