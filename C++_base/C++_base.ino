void setup() {
  Serial.begin(9600);
  Serial.println("Setup");




  // variabile di tipo intero con nome x e valore 0
  int x = 6;

  // variabile di tipo intero con nome y e valore non impostato
  int y;

  // variabile di tipo decimale con nome temperatura e valore 19.5
  float temperatura = 19.5;

  // si può usare Serial.print() anche con le variabili!
  // dato che y non ha un valore impostato potrebbe venir scritto un numero a caso
  Serial.print("x e' uguale a ");
  Serial.print(x);
  Serial.print(", y e' uguale a ");
  Serial.print(y);
  Serial.print(" e la temperatura e' di ");
  Serial.print(temperatura);
  Serial.println("°C");




  // si possono dichiarare piu' variabili sulla stessa riga
  int z = 0, w = 5;

  z = w; // <- z ora contiene il valore 5
  w = -7; // <- w ora contiene il valore -7

  // scrive sulla seriale le linee "z = 5 - w = -7"
  Serial.print("z = ");
  Serial.println(z);
  Serial.print(" - w = ");
  Serial.println(w);




  float a = 6, b = -5, c = 1; // i coefficienti dell'equazione di secondo grado

  float delta = b * b - 4 * a * c; // il delta (viene uguale a 1)

  // sqrt(valore) serve per calcolare la radice quadrata
  float x1 = (-b + sqrt(delta)) / (2 * a);
  float x2 = (-b - sqrt(delta)) / (2 * a);

  Serial.print("L'equazione ");
  Serial.print(a);
  Serial.print("x^2 + ");
  Serial.print(b);
  Serial.print("x + ");
  Serial.print(c);
  Serial.print(" = 0 ha come soluzioni x1 = ");
  Serial.print(x1);
  Serial.print(" e x2 = ");
  Serial.println(x2);




  int i = 6;
  i += 7; // i ora vale 13
  --i; // i ora vale 12
  i %= 5; // i ora vale 2

  float f = -5.2;
  f /= -6.7; // f ora vale 0.776...

  Serial.print("i = ");
  Serial.print(i);
  Serial.print("; f = ");
  Serial.println(f);




  float h = 5.3, k = 7.1;

  // variabile di tipo bool per salvare il risultato di una condizione
  bool hkSonoUguali = (h == k);
  if (h < k) { // condizione tra le parentesi tonde
    Serial.println("h e' minore di k");
  } else if (hkSonoUguali) { // la condizione e' salvata nella variabile xySonoUguali
    Serial.println("h e' uguale a k");
  } else {
    Serial.println("h e' maggiore di k");
  }
}

void loop() {

}
