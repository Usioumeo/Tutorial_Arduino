// i pin da cui leggiamo il valore del campo magnetico
int pin_analog = A0; // pin per lettura analogica
int pin_digital = 3; // pin per lettura digitale

void setup ()
{
    // inizializza il seriale
    Serial.begin(9600);

    // abilita i pin alla lettura
    pinMode(pin_analog, INPUT);
    pinMode(pin_digital, INPUT);
}

void loop ()
{
    // i dati di analogRead vanno da 0 a 1023 e coprono il range da 0v a 5v
    int letturaAnalogica = analogRead(pin_analog);
    // conversione in volt della lettura analogica
    float letturaAnalogicaVolt = letturaAnalogica / 1023.0 * 5.0;
    // se vogliamo trasformare letturaAnalogicaVolt in Tesla dobbiamo fare riferimento
    // al datasheet dell'SS49E (il primo grafico a pagina 3)
    float campoMagneticoTesla = (letturaAnalogica - 2.5) * 0.2 / 3;

    // la lettura digitale dice solo se il campo magnetico ha superato il threshold
    // impostato girando la vite sul sensore
    bool letturaDigitale = digitalRead(pin_digital);

    // scriviamo il campo magnetico in tesla sulla seriale
    Serial.println(campoMagneticoTesla);

    // aspettiamo 50ms per non sparare letture troppo velocemente
    delay(50);
}