---
bookFlatSection: true
title: "Servo eksemepel kode og setup"
weight: 2
---

# Servo ledninger
![Ledninger for servo modul](/static/servo-wire.png)



# Servo eksempel kode
```cpp
#include <Servo.h>

Servo myservo;  // create servo object to control a servo
int pos = 0;    // variable to store the servo position

void setup() {
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
}

void loop() {
  for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
}
```

# Servo kommandoer
Det her er kommandoer som Servo tager:
- `Servo myservo;` - definerer et servo objekt som kan kontrollere en servo der gemmes i variablen `myservo`.
- `myservo.attach(9);` - sætter servo objektet til at kontrollere servo på pin 9
- `myservo.write(pos);` - sætter servo objektet til at gå til positionen i variablen `pos`. Det kan være en værdi i mellem `0` og `180`.


# Kilder
- [Servo library](https://docs.arduino.cc/learn/electronics/servo-motors)