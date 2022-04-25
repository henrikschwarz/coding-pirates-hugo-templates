---
bookFlatSection: true
title: "RTC eksemepel kode og setup"
weight: 2
---


# RTC Ledninger
![Ledninger for RTC modul](/static/rtc-wires.jpg)


# RTC Biblotek
Først gå ind i `Manage Libraries` i Arduino IDE.
![Manage Libraries](/static/rtc-lib1.png)

Så Skriv `RTClib` i søgefeltet og klik på `Install Library`
![Manage Libraries](/static/rtc-lib2.png)

# RTC kode
Setup code for vores RTC:
```cpp

#include <RTClib.h>

RTC_DS3231 rtc; // Definerer en RTC klasse

void setup () {
  Serial.begin(9600);

  // SETUP RTC MODULE
  if (! rtc.begin()) {
    Serial.println("Couldn't find RTC");
    while (1);
  }

  // Sæt RTC tid og data til computerens tid og dato
  rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));

}
```
Nu skal vi lave en funktion til at læse tid og dato fra RTC modulet.
```cpp
void loop(){
    DateTime now = rtc.now();
    Serial.print("It is now "); 
    Serial.print(now.hour());
    Serial.print(":");
    Serial.print(now.minute());
    Serial.print(":");
    Serial.print(now.second());
    Serial.print(" ");
    Serial.print(now.day());
    Serial.print("/");
    Serial.print(now.month());
    Serial.print("/");
    Serial.print(now.year());
    Serial.println();
}
```

For at printe det på vores LCD kan vi bruge:
```cpp

void printToLCD(DateTime now, LiquidCrystalI2C lcd){
    lcd.setCursor(0, 1);
    lcd.print("TIME");
    lcd.print(" ");
    lcd.print(now.hour());
    lcd.print(':');
    lcd.print(now.minute());
    lcd.print(':');
    lcd.print(now.second());
    lcd.print("  ");

    lcd.setCursor(0, 0);
    lcd.print("DATE");
    lcd.print(" ");
    lcd.print(now.day());
    lcd.print('/');
    lcd.print(now.month());
    lcd.print('/');
    lcd.print(now.year());
    lcd.print("  ");   
}
```


### Kilde
[Kilde](https://arduinogetstarted.com/tutorials/arduino-rtc)