// include la libreria che mette a disposizione l'oggetto IMU
#include "Arduino_LSM9DS1.h"

//configuarzione programma
#define pinLed D13
#define pinButton D12
#define minField 15 //microTesla

#define calibrationMeasures 50

float curPos=0.0;
float prevPhase=0.0;

float bx, by, bz;
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

void misura(float &x, float &y, float &z){
  while(!IMU.magneticFieldAvailable());
  IMU.readMagneticField(x, y, z);
  x-=bx;
  y-=by;
  z-=bz;
}

float posizione(float x, float y){
  if(x*x+y*y>=minField*minField){
    return curPos;
  }
  float curPhase = atan2(y, x);
  if(abs(curPhase-prevPhase)<abs(curPhase+M_PI*2-prevPhase)){
    curPos+=curPhase-prevPhase;
  }else{
    curPos+=curPhase+2*M_PI-prevPhase;
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
void loop() {
  if(digitalRead(pinButton)==LOW){
    calibrazione();
  }
  float x, y, z;
  misura(x, y, z);
  float posizioneCorrente = posizione(x, y);
  Serial.print(posizioneCorrente);
  Serial.print(" ");
  Serial.print(posizioneCorrente-posizionePrecedente);
  Serial.println("");
  
}
