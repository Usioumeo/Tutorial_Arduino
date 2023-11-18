// include la libreria per il sensore DHT11
#include "DHT.h"

// qui si specifica la configurazione del sensore:
// - il primo parametro e' il PIN, in questo caso 2
//     (va cambiato in base a dove e' attaccato il pin di dati)
// - il secondo parametro e' il modello del sensore collegato
//     (dato che la scuola possiede solo DHT11, non va mai cambiato)
DHT dht(2, DHT11);

void setup() {
  // inizializziamo la connessione seriale con il computer
  Serial.begin(9600);

  // inizializziamo la connessione con il sensore (importante!)
  dht.begin();
}

void loop() {
  // crea la variable h e ci salva la lettura dell'umidita dal sensore (in %)
  float h = dht.readHumidity();

  // crea la variabile t e ci salva la lettura della temperatura dal sensore (in °C)
  float t = dht.readTemperature();

  // Scrive delle linee formattate cosi': UMIDITA TEMPERATURA
  // Mettendo due valori separati da spazio su ogni riga potremo
  // visualizzarli contemporaneamente aprendo il "Plotter seriale".
  Serial.print(h); // scrive h senza andare a capo
  Serial.print(" "); // scrive uno spazio dopo h
  Serial.println(t); // scrive t e poi va a capo (perche' c'e' il println)
}
