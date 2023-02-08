// include la libreria che mette a disposizione l'oggetto IMU
#include "Arduino_LSM9DS1.h"

void setup() {
  // inizializza il seriale e attende che un computer vi si connetta
  Serial.begin(9600);
  while (!Serial);

  // inizializza il LSM9DS1
  IMU.begin();
}

void loop() {
  // le misurazioni sono a 104Hz, quindi piuttosto lente rispetto alla velocità di esecuzione di
  // codice dell'Arduino, pertanto bisogna controllare se sono arrivati dei dati prima di leggerli
  if (IMU.gyroscopeAvailable()) {

    // crea le variabili x, y e z, inizialmente senza alcun valore
    float x, y, z;

    // legge la velocita' angolare lungo x, y e z nelle tre variabili x, y e z
    // (unita' di misura: gradi al secondo)
    IMU.readGyroscope(x, y, z);

    // scrive sulla seriale una linea contenente i tre valori letti separati da uno spazio, così
    // che si possano visualizzare col Plotter Seriale
    Serial.print(x);
    Serial.print(" ");
    Serial.print(y);
    Serial.print(" ");
    Serial.println(z);
  }
}