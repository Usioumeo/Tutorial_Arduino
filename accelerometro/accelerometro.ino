// include la libreria che mette a disposizione l'oggetto IMU
#include "Arduino_LSM9DS1.h"

float mx, my, mz;

void setup() {
  // inizializza il seriale
  Serial.begin(9600);

  // inizializza il LSM9DS1
  IMU.begin();

  mx = 0;
  my = 0;
  mz = 0;
  for (int i = 0; i < 20; ) {
    if (IMU.accelerationAvailable()) {
      float x, y, z;
      IMU.readMagneticField(x, y, z);
      mx = mx + x;
      my = my + y;
      mz = mz + z;
      i = i + 1;
    }
  }
  mx = mx / 20;
  my = my / 20;
  mz = mz / 20;
}

void loop() {
  // le misurazioni sono a 104Hz, quindi piuttosto lente rispetto alla velocità di esecuzione di
  // codice dell'Arduino, pertanto bisogna controllare se sono arrivati dei dati prima di leggerli
  if (IMU.accelerationAvailable()) {

    // crea le variabili x, y e z, inizialmente senza alcun valore
    float x, y, z;

    // legge l'accelerazione lungo x, y e z nelle tre variabili x, y e z
    // (unita' di misura: g)
    IMU.readAcceleration(x, y, z);

    x = x - mx;
    y = y - my;
    z = z - mz;

    // scrive sulla seriale una linea contenente i tre valori letti separati da uno spazio, così
    // che si possano visualizzare col Plotter Seriale
    Serial.print(x);
    Serial.print(" ");
    Serial.print(y);
    Serial.print(" ");
    Serial.println(z);
  }
}