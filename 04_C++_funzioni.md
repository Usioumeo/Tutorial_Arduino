# Le funzioni

### [Progetto di esempio: C++_funzioni](./C%2B%2B_funzioni/C%2B%2B_funzioni.ino)

Immaginate se un architetto, nel momento in cui gli viene chiesto di costruire una casa, dovesse fare tutto da solo: progettare, comprare i materiali, costruire la struttura, fare l'impianto elettrico, ... Probabilmente impazzirebbe dopo poco, perchè è difficile saper fare bene tutti quei lavori tenendo tutto sotto controllo. Le aziende edili hanno infatti una gerarchia: l'architetto progetta, sulla base del progetto gli operai costruiscono l'edificio, poi arriva l'elettricista, ...

Anche quando si scrive un programma conviene separare le varie funzionalità in diversi "sottoprogrammi" chiamati dal "programma" principale quando serve. Questo rende il codice più leggibile, chiaro e testabile (un esame che verifica che una persona sappia fare il costruttore di case a tuttotondo sarebbe molto più difficile da scrivere di tanti esami più piccoli per le varie mansioni, come operaio o elettricista). Vediamo quindi come ottenere questo risultato con le funzioni di C++.


## Sintassi

Quando un architetto viene *chiamato* dall'azienda edile gli vengono fornite varie informazioni su ciò che deve progettare, e lui dopo aver svolto il suo lavoro *restituisce* all'azienda il progetto che ha prodotto. Una funzione di un programma funziona nello stesso modo: viene chiamata con una lista di parametri e (di solito) restituisce un risultato. Nell'esempio qui sotto la funzione `somma` riceve due parametri interi, `x` e `y`, e ne restituisce la somma, un'altro intero, grazie all'istruzione `return`. La funzione viene scritta all'esterno del `main`, e viene poi chiamata nel `main` utilizzando le parentesi tonde e mettendo al loro interno i due valori da assegnare ai parametri `x` e `y`, in questo caso `7` e `10`.

```cpp
int somma(int x, int y) {
	int risultato = x + y;
	return risultato;
}

// scrive "La somma e' 17"
Serial.print("La somma e': ");
Serial.println(somma(7, 10));
```

In generale, quindi, la sintassi è la seguente. Ci possono essere più `return` (ad esempio all'interno di un if) e, nel momento in cui viene incontrato un `return` l'esecuzione della funzione termina immediatamente e ritorna il valore specificato al chiamante.

```cpp
tipo_di_ritorno nome_funzione(tipo_parametro_1 nome_parametro_1, tipo_parametro_2 nome_parametro_2, ...) {
	// calcola tutto ciò che serve basandosi sui parametri
	return /* ... */;
}
```

La prima linea del codice qui sopra si chiama "segnatura" (signature) della funzione, in quanto contiene le informazioni che permettono di interagire con essa dall'esterno. Infatti, in un altro punto del codice si può chiamare tale funzione in questo modo:

```cpp
tipo_di_ritorno risultato = nome_funzione(parametro_1, parametro_2, ...);
```

La variabile "risultato" conterrà quindi il valore di ritorno assunto dalla chiamata alla funzione dopo che essa ha completato la sua esecuzione. Non è davvero necessario salvare tale valore direttamente in una variabile, ma si può in realtà usare come qualsiasi altra espressione, un po' come le funzioni matematiche (ad esempio, all'interno di un `if`, oppure in una somma, oppure anche nella chiamata ad un'altra funzione).


## Procedure

Quando una funzione non "restituisce" nulla, essa è detta essere una procedura. La sintassi è uguale a quella vista qui sopra, eccetto per il tipo di ritorno, che in questo caso sarà `void`, ovvero "nulla". 

```cpp
void saluta(int numeroDiVolte) {
	for(int i = 0; i < numeroDiVolte; ++i) {
		Serial.println("Ciao!");
	}
}
```

Ovviamente una funzione può ricevere 0 parametri, ad esempio:

```cpp
void errore() {
	Serial.println("C'e' stato un errore");
}
```

Se si vuole uscire da una procedura prima della fine (ad esempio all'interno di un `if`) si può usare `return;` senza nessun valore di ritorno.


## In Arduino

Si può notare che `setup()` e `loop()`, le due strutture che devono esserci in ogni programma Arduino, sono delle funzioni, e in particolare delle procedure senza parametri.

Anche `pinMode()`, `digitalWrite()` e `digitalRead()` sono delle funzioni.


## Funzioni di oggetti

Per interagire con il seriale, si usano `Serial.begin()`, `Serial.print()`, ... Anche tali costrutti sono delle chiamate a funzioni. Se si scrivesse solo `begin()` e `print()`, però, il programma non sarebbe valido: serve infatti anche il `Serial.` davanti. Infatti quelle funzioni sono "di proprietà" dell'oggetto `Serial`, che appunto si occupa della comunicazione seriale.

Capiterà di applicare funzioni ad un oggetto anche quando si gestiscono dei sensori. Ad esempio, per leggere valori dall'accelerometro integrato nella scheda, si usa la funzione `readAcceleration` applicata all'oggetto `IMU` ("inertial measurement unit"), e si scrive quindi `IMU.readAcceleration(x, y, z)`.
