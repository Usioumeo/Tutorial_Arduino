/*questo programma funziona solo sul nano 33 BLE 
l'idea è quella di usare il magnetometro presente sulla scheda per monitorare come ruota un corpo (ed eventualmente se è sufficientemente preciso anche velocità e accelerazioni)
NB: potrebbe essere necessaario un filtro

In ogni caso basta leggere il sensore con misura(), passare gli assi che vogliamo studiare (nell'esempio x e y) alla funzione posizione(), che controllando con i dati precedenti interpreta come è ruotato il magnete

NB: la velocità massima studiabile teoricamente è di 600 RPM, per evitare problemi con il rumore dei sensori sarebbe meglio non superare i 300RPM

è possibile loggare i dati che ci interessano sulla seriale(come si vede in loop), e usando la funzionalità della porta seriale è possibile ottenere un timeStamp senza doverlo impostare da codice

inoltre in questo esempio il sensore si calibra all'avvio del programma, e quando viene premuto un tasto esterno (nell'esempio messo tra gnd e il pin D12, con una resistenza dimensionata per non bruciare i pin */


// include la libreria che mette a disposizione l'oggetto IMU
#include "Arduino_LSM9DS1.h"

//configuarzione programma
#define pinLed 13
#define pinButton 3
#define minField 15 //microTesla

#define calibrationMeasures 50

//variabili usate dalle funzioni, non modificare
float curPos=0.0;
float prevPhase=0.0;
float bx, by, bz;

//funzione di calibrazione, chiamata all'avvio o quando si preme un bottone
void calibrazione(){
  digitalWrite(pinLed, LOW);
  curPos=0.0;
  prevPhase=0.0;
  bx=0.0;
  by=0.0;
  bz=0.0;
  for(int i=0; i<calibrationMeasures; i++){
    while(!IMU.magneticFieldAvailable());
    float tx, ty, tz;
    IMU.readMagneticField(tx, ty, tz);
    bx+=tx;
    by+=ty;
    bz+=tz;
  }
  bx/=calibrationMeasures;
  by/=calibrationMeasures;
  bz/=calibrationMeasures;
  digitalWrite(pinLed, HIGH);
}

// attende che la misura sia disponibile e legge i dati dal sensore
void misura(float &x, float &y, float &z){
  while(!IMU.magneticFieldAvailable());
  IMU.readMagneticField(x, y, z);
  x-=bx;
  y-=by;
  z-=bz;
}

// dati i 2 assi, calcola la posizione corrente del disco, se la misura non supera il treshold non viene considerata
float posizione(float x, float y){
  //pitagora per controllare la potenza del campo magnetico
  if(x*x+y*y<=minField*minField){
    return curPos;
  }
  float curPhase = atan2(y, x);
  if(abs(curPhase-prevPhase)<M_PI){
    curPos+=curPhase-prevPhase;
  }else{
    if(abs(curPhase+M_PI*2-prevPhase)<abs(curPhase-M_PI*2-prevPhase)){
      curPos+=curPhase+2*M_PI-prevPhase;
    }else{
      curPos+=curPhase-2*M_PI-prevPhase;
    }
  }
  prevPhase=curPhase;
  return curPos;
  
}

void setup() {
  Serial.begin(115200);
  // inizializza il LSM9DS1
  IMU.begin();
  pinMode(pinLed, OUTPUT);
  pinMode(pinButton, INPUT_PULLUP);
  calibrazione();
}



float posizionePrecedente=0.0;
float velocitaPrecedente=0.0;
void loop() {
  if(digitalRead(pinButton)==LOW){
    calibrazione();
  }else{
    float x, y, z;
    misura(x, y, z);
    float posizioneCorrente = posizione(x, y);
    float velocitaCorrente = posizioneCorrente-posizionePrecedente;
    float accelerazioneCorrente = velocitaCorrente-velocitaPrecedente;
    Serial.print(accelerazioneCorrente);
    posizionePrecedente=posizioneCorrente;
    velocitaPrecedente=velocitaCorrente;
  }
}
