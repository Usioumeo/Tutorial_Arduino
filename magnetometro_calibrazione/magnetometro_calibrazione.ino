// include la libreria che mette a disposizione l'oggetto IMU
#include "Arduino_LSM9DS1.h"

// le variabili che contengono i dati di calibrazione, accessibili sia dal setup() che dal loop()
float mx, my, mz;

// il numero di misurazioni di cui fare la media per ottenere i dati di calibrazione (e' piu'
// comodo riutilizzare una variabile costante invece che scrivere "20" dappertutto)
const int MISURAZIONI_CALIBRAZIONE = 20;

void setup() {
  // inizializza il seriale
  Serial.begin(9600);
  while (!Serial);

  // inizializza il LSM9DS1
  IMU.begin();

  // il codice qui sotto calcola i dati di calibrazione e li salva in mx, my ed mz,
  // sulla base della media di MISURAZIONI_CALIBRAZIONE misurazioni iniziali

  // inizializza mx, my ed mz a 0, per sicurezza
  mx = 0;
  my = 0;
  mz = 0;
  // questo e' un ciclo for: la variabile i, che conta le misure effettuate, inizialmente e' 0;
  // prima di ogni iterazione viene controllato se i e' minore di MISURAZIONI_CALIBRAZIONE, e se non
  // lo e' si esce dal ciclo
  for (int i = 0; i < MISURAZIONI_CALIBRAZIONE; ) {
    // le misurazioni sono a 20Hz, quindi piuttosto lente rispetto alla velocità di esecuzione di
    // codice dell'Arduino, pertanto bisogna controllare se sono arrivati dei dati prima di leggerli
    if (IMU.accelerationAvailable()) {
      float x, y, z;
      IMU.readMagneticField(x, y, z);
      mx = mx + x;
      my = my + y;
      mz = mz + z;
      // quando e' avvenuta una misurazione, incrementa i di 1
      i = i + 1;
    }
  }
  // per ottenere la media divide per MISURAZIONI_CALIBRAZIONE
  mx = mx / MISURAZIONI_CALIBRAZIONE;
  my = my / MISURAZIONI_CALIBRAZIONE;
  mz = mz / MISURAZIONI_CALIBRAZIONE;
}

void loop() {
  // le misurazioni sono a 20Hz, quindi piuttosto lente rispetto alla velocità di esecuzione di
  // codice dell'Arduino, pertanto bisogna controllare se sono arrivati dei dati prima di leggerli
  if (IMU.magneticFieldAvailable()) {

    // crea le variabili x, y e z, inizialmente senza alcun valore
    float x, y, z;

    // legge il valore del campo magnetico lungo x, y e z nelle tre variabili x, y e z
    // (unita' di misura: uT/microTesla)
    IMU.readMagneticField(x, y, z);

    // sottrae i valori di calibrazione iniziali per ottenere una misurazione relativa
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