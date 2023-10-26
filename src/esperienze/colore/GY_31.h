 #include<Arduino.h>

enum GY_31_mode{
  RED,
  GREEN,
  BLUE,
  CLEAR
  
};

class GY_31{
  int s0, s1, s2, s3, out;
  bool hasLed= false;
  int led=0;
  public:
  void setup(int s0, int s1, int s2, int s3, int out, int led){
    hasLed= true;
    this->led = led;
    pinMode(led, OUTPUT);
    setup(s0, s1, s2, s3, out);
  }
  
  void setup(int s0, int s1, int s2, int s3, int out){
    this->s0 = s0;
    this->s1 = s1;
    this->s2 = s2;
    this->s3 = s3;
    this->out = out;
    pinMode(s0, OUTPUT);
    pinMode(s1, OUTPUT);
    pinMode(s2, OUTPUT);
    pinMode(s3, OUTPUT);
    pinMode(out, INPUT);
  }

  void set_led(int m){
    if(hasLed&&(m==HIGH||m==LOW)){
      digitalWrite(led, m);
    }
  }
  
  int read(GY_31_mode m){
    switch(m){
      case RED:
        digitalWrite(s2, LOW);
        digitalWrite(s3, LOW);
      break;
      case BLUE:
        digitalWrite(s2, LOW);
        digitalWrite(s3, HIGH);
      break;
      case CLEAR:
        digitalWrite(s2, HIGH);
        digitalWrite(s3, LOW);
      break;
      case GREEN:
        digitalWrite(s2, HIGH);
        digitalWrite(s3, HIGH);
      break;
    }
    delay(1);
    pulseIn(out, HIGH);
    return pulseIn(out, HIGH);
  }
  
};

 
