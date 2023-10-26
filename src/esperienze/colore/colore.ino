#include"GY_31.h"
GY_31 sensore;
void setup() {
  /*nella libreria ci sono 2 diversi setup:
    setup(s0, s1, s2, s3, out) 
    setup(s0, s1, s2, s3, out, led) //inizializza anche il pin Led

    e leggere i valori con:
    read(mod)dove mod può essere RED GREEN BLUE CLEAR
    attenzione, il sensore non è calibrato, nel 90% dei casi bisogna calibrare il sensore e rimapparlo con dei valori sensati. sotto vedete dei parametri che dovrebbero andare bene, ma potrebbero non essere perfetti

    set_led(mod) come da nome, si decide se accendere o meno i led
    */
    
  //S0, S1, S2, S3, out
  sensore.setup(8, 9, 10, 11, 12, 13);
  sensore.set_led(HIGH);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print("Rosso: ");
  Serial.println(sensore.read(RED)); // dato grezzo

  Serial.print("Rosso calibrato: ");
  Serial.println(map(sensore.read(RED), 60, 15, 0, 100)); // dato calibrato
  /*
  stando al datasheet, le calibrazioni corrette sono:
    rosso: map(data,60,15,0,100)
    blu:   map(data,80,11,0,100)
    verde: map(data,80,20,0,100)
    ma sentitevi liberi di cambiarle a vostro piacimento
  */
}
