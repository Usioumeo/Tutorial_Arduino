# Introduzione ad Arduino

## Struttura di un programma per Arduino

In Arduino la struttura base di un programma è impostata in questo modo:
```cpp
//inclusione librerie
#include<Wire.h>//libreria di esempio


// Funzione che verrà chiamata automaticamente all'avvio del programma
void setup(){

}

// Funzione che verrà chiamata ripetutamente una volta terminato il setup
void loop(){

}

```

## Scrittura e lettura di pin digitali

Su tutte le schede Arduino ci sono molti pin digitali, e per prima cosa dobbiamo imparare a riconoscerli.
I pin digitali possono essere identificati da un numero, oppure per rendere la sintassi più chiara con una D davanti. Ad esempio D10 è il pin digitale 10. Nella maggior parte dei casi le porte sono numerate correttamente sulla scheda, ma in alcuni casi non è così. Pertanto quando si inizia ad utilizzare una nuova scheda bisogna accertarsi di come vengono identificati i pin.
Inoltre è possibile utilizzare anche i pin di entrata analogica (ad esempio A0) come un pin digitale (dopo una corretta configurazione con `pinMode`).


### Funzione pinMode
Una volta identificati i pin è necessario configurarli correttamente con: `pinMode(pin, modalità);`.

Il parametro "modalità" accetta i seguenti parametri:
- `OUTPUT`: Semplice modalità di output(3.3V, massimo 15 mA)
- `INPUT`: Semplice modalità di input (di solito i pin in modalità lettura hanno una resistenza nell'ordine dei 100MOhm)
- `INPUT_PULLUP`: 10kOhm. Se è scollegato segna HIGH

Nel caso di pullup o pulldown particolari sarà necessario realizzarli con un circuito esterno.

### Funzione digitalWrite

Se è stata impostata la modalità OUTPUT si può scrivere con la funzione `digitalWrite(pin, valore)`. Il valore può essere solo `HIGH` (3.3V) o `LOW` (0.0V).

### Funzione digitalRead

Se è stata impostata la modalità INPUT oppure INPUT_PULLUP si può leggere il valore del pin con la funzione `digitalRead(pin)`.
In caso il voltaggio sia vicino a 3.3V ritorna `HIGH`, altrimenti `LOW`.
Se il pin è scollegato, oppure non è possibile campionare correttamente il valore, la funzione restituirà valori randomici. Per evitare questo comportamento esiste `INPUT_PULLUP`, che grazie al pullup interno imposta sempre un valore definito correttamente.

### Un esempio

```cpp
void setup(){
	// imposto il pin 13 (ovvero il led sulla scheda) in modalità output
	pinMode(D13, OUTPUT);

	// imposto il pin 13 a high, accendendo il led.
	digitalWrite(D13, HIGH);
}

void loop(){

}
```

## Delay
Spesso un programma deve interfacciarsi con persone e/o sensori che non riescono a funzionare a velocità paragonabili al clock del controllore. Ed ecco che arrivano in nostro soccorso le funzioni `delay` e `delayMicroseconds` della libreria standard di Arduino. Entrambe prendono come parametro la quantità di tempo da attendere, la prima in millisecondi, e la seconda in microsecondi.
```cpp
void setup(){
	pinMode(D13, OUTPUT);
}

void loop() {
  digitalWrite(D13, HIGH);   // accende il led
  delay(500);                // aspetta mezzo secondo
  digitalWrite(D13, LOW);    // spegne il led
  delay(500);                // aspetta mezzo secondo
}
```
In generale questo tipo di funzioni sono precise e non causano problemi "strani" su piccoli delay, però se si vuole eseguire del codice con un periodo preciso non sono l'ideale, in quanto l'esecuzione del codice non è istantanea e quindi andrebbe ad aggiungere man mano del ritardo. Quando possibile il programma andrebbe quindi migrato usando le funzioni `millis()` e `micros()`.

## Seriale

Per far parlare il nostro programma con un computer collegato è necessario scrivere sulla seriale.
Tutti i controllori hanno della componentistica dedicata, ed è necessario solo imparare la sintassi base per saperli usare.

### Funzione Serial.begin
`Serial.begin(baud)` serve per inizializzare la connessione: prima di poter usare la seriale dobbiamo decidere un baudrate con cui inviare i dati.
Entrambi i terminali (computer e scheda) devono usare lo stesso baud, e baud più alti significa comunicazioni più veloci. Se a qualcuno interessano maggiori dettagli li può trovare [qui](https://www.arduino.cc/reference/en/language/functions/communication/serial/begin/). Il baudrate deve essere un baudrate standard, ecco una lista di quelli più comuni:

- 300
- 600
- 1200
- 2400
- 4800
- 9600
- 14400
- 19200
- 28800
- 31250
- 38400
- 57600
- 115200
``
### Funzione Serial.print e println
`Serial.print(parametro)` scrive il parametro in seriale. `Serial.println(parametro)` dopo aver scritto un valore va a capo.

### Esempio di uso della seriale
```cpp
void setup() {
	// apre la comunicazione seriale con baudrate di 9600
	Serial.begin(9600);

	// scrive "Setup!" e poi va a capo
	Serial.println("Setup!");
}

void loop() {
	// millis() restituisce il numero di millisecondi dall'inizio del programma
	int millisecondi = millis();

	// scrive "...ms" ad ogni iterazione di loop(), dove ... è il valore ottenuto qui sopra
	Serial.print(millisecondi);
	Serial.println("ms");

	// aspetta un secondo prima di ripetere
	delay(1000);
}
```