---
bookFlatSection: true
title: "Eksempel 5 - LCD"
weight: 5
---
# Eksempel 1 - Sæt LCD op diagram op
Her skal der bruges 1 LCD I2C display og 4 han til hun ledninger. Så skal de forbindes som der vises nedenunder.

![El-Diagram for eksempel af LED](/static/eksempel-4.png)

# Eksempel 1 - Hente biblotek til LCD
For at kunne bruge vores LCD skal vi bruge et biblotek. Det biblotek kan findes igennem jeres Arduino program ved at gå op i `Sketch -> Include Library -> Manage Libraries`:

![Sketch -> Include Library -> Manage Libraries](/static/manage-lib.png)

Også skal søge på den her `LiquidCrystal`:

![lcd lib](/static/lcd-lib.png)

# Eksempel 1 - Kode til LCD

```cpp
#include <LiquidCrystal_I2C.h>
#include <Wire.h>

const int SCL_PIN = A5;
const int SDA_PIN = A4;

LiquidCrystal_I2C lcd(0x27,16,2);  // set the LCD address to 0x27 for a 16 chars and 2 line display

void setup()
{
  lcd.init(); // Initiere lcd display
  lcd.backlight(); // Put backlight på displayet
}


void loop()
{
  lcd.setCursor(0,0); // Sæt cursor på første linje første tegn
  lcd.print("Hello"); // Print besked på display
  lcd.setCursor(0,1); // Sæte cursor på anden linje første tegn
  lcd.print("Coding Pirates!!!");
  delay(1000);
}
```