---
bookFlatSection: true
title: "Keypad eksemepel kode og setup"
weight: 2
---


# Setup
![Keypad](/static/keypad-wire.jpg)



# Bibloteket
Installer biblioteket fra Arduino IDE:
![Keypad biblioteket](/static/keypad-lib.jpg)


# Kode eksempler:
```cpp
#include <Keypad.h>

const int ROW_NUM = 4; //four rows
const int COLUMN_NUM = 4; //four columns

char keys[ROW_NUM][COLUMN_NUM] = {
  {'1','2','3', 'A'},
  {'4','5','6', 'B'},
  {'7','8','9', 'C'},
  {'*','0','#', 'D'}
};

byte pin_rows[ROW_NUM] = {9, 8, 7, 6}; //connect to the row pinouts of the keypad
byte pin_column[COLUMN_NUM] = {5, 4, 3, 2}; //connect to the column pinouts of the keypad

Keypad keypad = Keypad( makeKeymap(keys), pin_rows, pin_column, ROW_NUM, COLUMN_NUM );

void setup(){
  Serial.begin(9600);
}

void loop(){
  char key = keypad.getKey();

  if (key){
    Serial.println(key);
  }
}
```


### Kilde
[Kilde](https://arduinogetstarted.com/tutorials/arduino-keypad)