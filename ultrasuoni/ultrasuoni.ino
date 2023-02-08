int pin_trig = 9; // pin TRIG (trigger)
int pin_echo = 8; // pin ECHO

void setup() {
  // inizializza la seriale su cui inviare i dati
  Serial.begin(9600);

  // configura il pin TRIG trigger ad output
  pinMode(pin_trig, OUTPUT);
  // configura in pin ECHO ad input
  pinMode(pin_echo, INPUT);
}

void loop() {
  // impulso di 10 microsecondi sul pin TRIG
  digitalWrite(pin_trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(pin_trig, LOW);

  // Quando il sensore riceve un segnale su TRIG, esegue i seguenti passi, in ordine:
  // - trasmette un segnale acustico
  // - imposta ECHO ad HIGH
  // - attende finche' non riceve il segnale acustico riflesso
  // - imposta ECHO a LOW
  // La funzione pulseIn serve per misurare per quanto tempo ECHO rimane ad HIGH.
  float tempo_microsecondi = pulseIn(pin_echo, HIGH);

  // il tempo sara' quello di andata e poi ritorno del suono, quindi per ottenere la
  // distanza basta dividere per due e moltiplicare per la velocita del suono
  // (che e' di 340.19m/s = 34019cm/s = 0.034019cm/us)
  float distanza_centimetri = (tempo_microsecondi / 2) * 0.034019;

  // scrive il valore sul monitor seriale
  Serial.println(distanza_centimetri);

  // aspetta mezzo secondo, per non sparare dati a raffica
  delay(500);
}
