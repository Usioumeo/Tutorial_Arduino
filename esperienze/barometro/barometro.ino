#include"BARO.h"
#include<math.h>
// importare la libreria dalla cartella locale

void setup() {
  //inizializzo la seriale
  Serial.begin(9600);
  while (!Serial);

  if (!BARO.begin()) {
    Serial.println("Impossibile connettersi al sensore!");
    while (1);
  }
}

void loop() {
  // leggere il sensore (ritorna la pressione in kPa)
  float pressure = BARO.readPressure();
  
  //calcolo l'altitudine dalla pressione
  float altitude = -293.15*8.31/(9.81*0.02896)*log(pressure/101.3);
  

  // visualizzo su serial
  Serial.print("Altitudine in base alla pressione = ");
  Serial.print(altitude);
  Serial.println(" m");

  // attendo 1 secondo
  delay(1000);
}
