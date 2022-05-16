---
bookFlatSection: true
title: "Inbyggede kommandoer"
weight: 2
---

# Datatyper i Arduino(C++)
Arduino har de har datatyper:
| Datatype | Beskrivelse |
|----------| ------------|
| int | Det er en integer (hel tal) | 
| float | Det er et floating point tal (decimal tal) | 
| double | Mere præcis decimal. | 
| long | Længere hel tal (kan holde længere værdier) | 
| bool | En boolean kan kun være sand (true/1) eller falsk (false/0)
| Char | Et enkel bogstav | 
| String | En liste af char's | 

## Definer en variable
Du definer en variable sådan her `datatype navn = værdi;`. Så med en int ville det være `int i = 10;`.

# Logiske operatorer
| Operator | Beskrivelse |
|----------| ------------|
| == | lige med |
| != | ikke lige med |
| < | mindre end |
| <= | mindre end eller lige med |
| > | større end |
| => | større eller lige med |
| `i++` | Gør i en større | 
| `i--` | Gør 1 en mindre
# If else statement
Et if else statement kan styre kode udfra om det i parantesene er sandt eller falsk. F.eks:
```cpp
void loop{
    if (true){
        Serial.println("Det her kører fordi true er true!!");
    }    
}
```

Et else statement er det der bliver kørt hvis logikken i `if` ikke er sandt:
```cpp
void loop{
    if (false){
        Serial.println("bliver ikke kørt fordi det er false!!");
    } else {
        Serial.println("Det her bliver kørt fordi det er true!!");
    }
}
```

Du kan også lave et ellers sandt (else if):
```cpp
void loop{
    if (1==2) {
        Serial.println("bliver kun kørt hvis 1 == 2");
    } else if (1 == 1){
        Serial.println("bliver kun kørt hvis 1 == 1"); // Det her er sandt så det er hvad der bliver kørt
    } else {
        Serial.println("bliver kun kørt hvis 1 == 1 og 1 == 2 begge ikke er sande");
    }
}
```

# For loop
Et for loop er noget der looper så længe det er sand (lige som if sand):
```cpp
for ( int i = 0; i < 10; i++){ 
    // I er lige med 0, 
    // kør så længe i er mindre end 10
    // Gør i 1 større hver gang det kører
    Serial.println(i);
}