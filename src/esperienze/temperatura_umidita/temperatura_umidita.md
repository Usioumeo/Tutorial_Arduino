# Uso del sensore esterno di temperatura e umidità DHT11

- Il sensore che ha la scuola si è il DHT11.
- Il datasheet è accessibile [qui](./DHT11.pdf) (scaricato) o [qui](https://pdf1.alldatasheet.com/datasheet-pdf/download/1132088/ETC2/DHT11.html) (fonte originale).

## Collegamento PIN su Arduino

L'immagine qui sotto mostra come attaccare i cavi all'arduino. I PIN alle estremità sono per l'alimentazione. L'altro PIN è per i dati, e in questo caso verrà usato il PIN 2 dell'Arduino UNO, ma qualsiasi altro PIN numerato può andare.

Attenzione che le connessioni sul sensore sono fatte in riferimento al sensore direzionato nel modo raffigurato.

![collegamento PIN](./DHT11_Interfacing_Diagram.png)

## Installazione libreria

Per poter leggere le informazioni inviate dal sensore sul PIN dai dati, è necessario usare una libreria.
- andare in `Strumenti -> Gestione librerie`
- cercare "DHT sensor library" ed installare "DHT sensor library" di Adafruit (ce ne sono altre ma scegliere proprio quella)
- se compare una finestra di conferma, dire `Install all`
- ora la libreria si può includere nei progetti con `#include "DHT.h"`

## Codice

La linea `DHT dht(2, DHT11);` specifica la configurazione del sensore collegato, quindi il `2` va cambiato se abbiamo usato un PIN di arduino diverso per collegare il PIN dati del sensore.

```C++
{{#include temperatura_umidita.ino}}
```