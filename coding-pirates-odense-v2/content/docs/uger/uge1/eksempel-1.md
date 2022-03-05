---
bookFlatSection: true
title: "Eksempel 1 - LED"
weight: 2
---
# Eksempel 1 - LED control
Første Eksempel er for at få en led til at blinke. Det er en af de mest klassiske programmer på Arduinoen.

Følgende billede viser hvordan de elektroniske komponenter skal kobles sammen:
![El-diagram for eksempel 1](/static/example1.png)


## Kodeeksempel 1 - Få en LED til at blinke
```cpp
const int ledPin = 13;

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
```

## Kodeeksempel 2 - Få LED til at blinke vha. variabel
```cpp
const int ledPin = 7;
bool ledState = false;

void setup() {
    // Opsæt kommunikationshastighed med PC
    Serial.begin(115200);

    // Opsæt ledPin til at blive anvendt som output
    pinMode(ledPin, OUTPUT);
}

void loop() {
    // Sæt ledState lig med negationen af sin egen værdi
    ledState = !ledState;

    // Sæt outputtet på ledPin til ledState
    digitalWrite(ledPin, ledState);
    
    // Skriv forskellige tekster til PC afhængig af værdien af ledState
    if (ledState == true) {
        Serial.println("LED'en er tændt.");
    } else {
        Serial.println("LED'en er slukket.");
    }

    // Vent 1000 millisekunder
    delay(1000);
}
```

De følgende 4 eksempler, viser hvordan, det samme resultat, kan skrives på forskellige måder.
## Kodeeksempel 3 - Få LED til at blinke ved at læse pinværdi, og gemme i variabel
```cpp
const int ledPin = 7;

void setup() {
    // Opsæt kommunikationshastighed med PC
    Serial.begin(115200);

    // Opsæt ledPin til at blive anvendt som output
    pinMode(ledPin, OUTPUT);
}

void loop() {
    // Sæt ledState lig med negationen ledPins signal
    bool ledState = !digitalRead(ledPin);

    // Sæt outputtet på ledPin til ledState
    digitalWrite(ledPin, ledState);
    
    // Skriv forskellige tekster til PC afhængig af værdien af ledState
    if (ledState == true) {
        Serial.println("LED'en er tændt.");
    } else {
        Serial.println("LED'en er slukket.");
    }

    // Vent 1000 millisekunder
    delay(1000);
}
```

## Kodeeksempel 4 - Få LED til at blinke ved at læse pinværdi
```cpp
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
```

# Eksempel 2 - LED strip control (Avanceret)

```cpp
#include <FastLED.h>

// How many leds in your strip?
#define NUM_LEDS 64 

// For led chips like Neopixels, which have a data line, ground, and power, you just
// need to define DATA_PIN.  For led chipsets that are SPI based (four wires - data, clock,
// ground, and power), like the LPD8806, define both DATA_PIN and CLOCK_PIN
#define DATA_PIN 7
#define CLOCK_PIN 13

// Define the array of leds
CRGB leds[NUM_LEDS];

void setup() { 
	Serial.begin(57600);
	Serial.println("resetting");
	LEDS.addLeds<WS2812,DATA_PIN,RGB>(leds,NUM_LEDS);
	LEDS.setBrightness(84);
}

void fadeall() { for(int i = 0; i < NUM_LEDS; i++) { leds[i].nscale8(250); } }

void loop() { 
	static uint8_t hue = 0;
	Serial.print("x");
	// First slide the led in one direction
	for(int i = 0; i < NUM_LEDS; i++) {
		// Set the i'th led to red 
		leds[i] = CHSV(hue++, 255, 255);
		// Show the leds
		FastLED.show(); 
		// now that we've shown the leds, reset the i'th led to black
		// leds[i] = CRGB::Black;
		fadeall();
		// Wait a little bit before we loop around and do it again
		delay(10);
	}
	Serial.print("x");

	// Now go in the other direction.  
	for(int i = (NUM_LEDS)-1; i >= 0; i--) {
		// Set the i'th led to red 
		leds[i] = CHSV(hue++, 255, 255);
		// Show the leds
		FastLED.show();
		// now that we've shown the leds, reset the i'th led to black
		// leds[i] = CRGB::Black;
		fadeall();
		// Wait a little bit before we loop around and do it again
		delay(10);
	}
}
```