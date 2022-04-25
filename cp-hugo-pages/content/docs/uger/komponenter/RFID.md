---
bookFlatSection: true
title: "RFID eksemepel kode og setup"
weight: 2
---

# Setup
Ledningerne for RFID modulet:
![Ledninger for RFID modul](/static/rfid-wire.jpg)

Og en tabel over forbindelserne:
![Tabel over forbindelser til RFID modulet](/static/rfid-table.jpg)

# Bibloteket
Installer biblioteket fra Arduino IDE:
![Biblioteket for RFID modulet](/static/rfid-lib1.jpg)

# Kode eksempler:
```cpp

#include <SPI.h>
#include <MFRC522.h>

#define SS_PIN 10
#define RST_PIN 5

MFRC522 rfid(SS_PIN, RST_PIN);

void setup() {
  Serial.begin(9600);
  SPI.begin(); // init SPI bus
  rfid.PCD_Init(); // init MFRC522

  Serial.println("Tap RFID/NFC Tag on reader");
}

void loop() {
  if (rfid.PICC_IsNewCardPresent()) { // new tag is available
    if (rfid.PICC_ReadCardSerial()) { // NUID has been readed
      MFRC522::PICC_Type piccType = rfid.PICC_GetType(rfid.uid.sak);
      //Serial.print("RFID/NFC Tag Type: ");
      //Serial.println(rfid.PICC_GetTypeName(piccType));

      // print NUID in Serial Monitor in the hex format
      Serial.print("UID:");
      for (int i = 0; i < rfid.uid.size; i++) {
        Serial.print(rfid.uid.uidByte[i] < 0x10 ? " 0" : " ");
        Serial.print(rfid.uid.uidByte[i], HEX);
      }
      Serial.println();

      rfid.PICC_HaltA(); // halt PICC
      rfid.PCD_StopCrypto1(); // stop encryption on PCD
    }
  }
}
```


## Kode med servo:
```cpp
/*
 * Created by ArduinoGetStarted.com
 *
 * This example code is in the public domain
 *
 * Tutorial page: https://arduinogetstarted.com/tutorials/arduino-rfid-nfc-servo-motor
 */

#include <SPI.h>
#include <MFRC522.h>
#include <Servo.h>

#define SS_PIN    10
#define RST_PIN   9
#define SERVO_PIN A5

MFRC522 rfid(SS_PIN, RST_PIN);
Servo servo;

byte authorizedUID[4] = {0xFF, 0xFF, 0xFF, 0xFF};
int angle = 0; // the current angle of servo motor

void setup() {
  Serial.begin(9600);
  SPI.begin(); // init SPI bus
  rfid.PCD_Init(); // init MFRC522
  servo.attach(SERVO_PIN);
  servo.write(angle); // rotate servo motor to 0°

  Serial.println("Tap RFID/NFC Tag on reader");
}

void loop() {
  if (rfid.PICC_IsNewCardPresent()) { // new tag is available
    if (rfid.PICC_ReadCardSerial()) { // NUID has been readed
      MFRC522::PICC_Type piccType = rfid.PICC_GetType(rfid.uid.sak);

      if (rfid.uid.uidByte[0] == authorizedUID[0] &&
          rfid.uid.uidByte[1] == authorizedUID[1] &&
          rfid.uid.uidByte[2] == authorizedUID[2] &&
          rfid.uid.uidByte[3] == authorizedUID[3] ) {
        Serial.println("Authorized Tag");

        // change angle of servo motor
        if (angle == 0)
          angle = 90;
        else //if(angle == 90)
          angle = 0;

        // control servo motor arccoding to the angle
        servo.write(angle);
        Serial.print("Rotate Servo Motor to ");
        Serial.print(angle);
        Serial.println("°");
      } else {
        Serial.print("Unauthorized Tag with UID:");
        for (int i = 0; i < rfid.uid.size; i++) {
          Serial.print(rfid.uid.uidByte[i] < 0x10 ? " 0" : " ");
          Serial.print(rfid.uid.uidByte[i], HEX);
        }
        Serial.println();
      }

      rfid.PICC_HaltA(); // halt PICC
      rfid.PCD_StopCrypto1(); // stop encryption on PCD
    }
  }
}
```


### Kilde:
[Kilde](https://arduinogetstarted.com/tutorials/arduino-rfid-nfc)