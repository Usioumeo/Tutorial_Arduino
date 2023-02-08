# Seriale

L'introduzione alla comunicazione seriale è su [01_introduzione_Arduino](./01_introduzione_Arduino.md#seriale).

## Attendere una connessione al computer

Arduino Uno si resetta in automatico nel momento in cui si apre la seriale dall'Ide, quindi è possibile leggere anche eventuali messaggi scritti poco dopo l'avvio della scheda. Invece il Nano 33 BLE Sense non fa così. Può fare utile quindi, all'interno del `setup()`, attendere che ci sia una connessione ad un computer prima di fare qualsiasi cosa:
```cpp
void setup(){
	//apre la seriale con baudrate di 9600
	Serial.begin(9600);

  // attende finche' un computer connesso non apre il monitor seriale
  while (!Serial);
}
```

## Altri comandi utili

### Funzione Serial.available
Se ci sono dei dati nel buffer della seriale, `Serial.available()` ritorna il numero di byte in coda nel buffer.

### Funzione Serial.read
`Serial.read()` ritorna il primo byte dal buffer, rimuovendolo dalla coda. Se non ci sono altri elementi nel buffer ritorna -1;

### Un esempio riassuntivo
Ecco un esempio che risponde su seriale qualsiasi cosa riceva.
```cpp
void setup(){
	//apre la seriale con baudrate di 9600
	Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0) { // se ho dei caratteri nel buffer della seriale
  	//leggo il valore, e lo salvo nella variabile tmp
  	char tmp = Serial.read();

	//scrivo il carattere tmp in seriale
	Serial.write(tmp);
  }
}
```

## Plotter seriale per fare grafici

La seriale si può usare anche per tracciare dei grafici dell'evoluzione di una variabile nel tempo. Questo può essere utile per monitorare l'andamento di un sensore oppure visualizzare delle statistiche.

Se durante l'esecuzione di un programma su Arduino ogni linea della seriale contiene lo stesso numero di valori separati da spazi, quando l'Arduino è connesso al computer è possibile selezionare `Strumenti -> Plotter Seriale` nel menù dell'Arduino IDE e visualizzare dei grafici sovrapposti per ogni colonna di valori. Sull'asse x si ha il tempo (o meglio, il numero di linea ricevuta dalla scheda), mentre sull'asse y si hanno i valori assunti dalle varie colonne.

Ad esempio un codice del genere...

```cpp
void setup() {
    Serial.begin(9600);
}

void loop() {
    int tempo = millis();
    Serial.print(tempo);
    Serial.print(" ");
    Serial.println(sqrt(tempo));

    delay(500); // aspettiamo mezzo secondo prima di ripetere
}
```

...produrrebbe sulla seriale un output simile al seguente...

```
12 3.46
512 22.62
1013 31.83
1514 38.91
...
```

...che quindi produrrebbe due grafici (sovrapposti):
- il primo composto dai punti: `(0, 12)`, `(1, 512)`, `(2, 1013)`, `(3, 1514)`
- il secondo composto dai punti: `(0, 3.46)`, `(1, 22.62)`, `(2, 31.83)`, `(3, 38.91)`
