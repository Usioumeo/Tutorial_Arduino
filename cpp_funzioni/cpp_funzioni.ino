void saluta() {
  Serial.println("Ciao");
}

float sinc(float v) {
  if (v == 0.0) {
    return 1;
  } else {
    return sin(v) / v;
  }
}

void setup() {
  Serial.begin(9600);
  saluta();
}

void loop() {
  // come x usiamo il numero di secondi dall'accensione dell'Arduino, meno 5
  float x = millis() / 1000.0 - 5.0;

  // due funzioni matematiche
  float y1 = sinc(x); // sin(x)/x
  float y2 = exp(x); // e^x

  // ad ogni iterazione di loop() scrive i valori di y corrispondenti
  Serial.print(y1);
  Serial.print(" ");
  Serial.println(y2);

  // chiamata alla procedura delay per aspettare 100 millisecondi
  // (cosi' avremo una frequenza di scrittura delle y di circa 10Hz)
  delay(100);
}