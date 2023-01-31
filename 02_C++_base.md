# C++ base

### [Progetto di esempio: C++_base](./C%2B%2B_base/C%2B%2B_base.ino)

## Commenti

I commenti servono per aggiungere delle note al codice: non verranno mai eseguiti. Ci sono due formati:
- `// commento` crea un commento a partire da `//` e fino alla fine della linea
- `/* commento */` crea un commento a partire da `/*` e fino a `*/`

## Variabili

Le variabili servono per tenere salvati dei dati o dei passi parziali durante l'esecuzione del programma. Ad esempio, per la risoluzione di un'equazione di secondo grado, prima calcoliamo il delta, poi lo scriviamo a parte e infine lo utilizziamo nella formula.  

Le variabili esistono solo dal momento in cui le dichiariamo, hanno un **tipo** e hanno un **nome** per identificarle. Il tipo può essere, per il momento
- intero: `int`
- decimale: `float`

```cpp
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
```

Il valore contenuto nelle variabili può essere cambiato durante l'esecuzione usando l'operatore `=`. Attenzione: `x = y` significa "assegna il valore della variabile y alla variabile x". **NON** significa che d'ora in poi la variabile x sarà *sempre* uguale a y!

```cpp
// si possono dichiarare piu' variabili sulla stessa riga
int z = 0, w = 5;

z = w; // <- z ora contiene il valore 5
w = -7; // <- w ora contiene il valore -7

// scrive sulla seriale le linee "z = 5 - w = -7"
Serial.print("z = ");
Serial.println(z);
Serial.print(" - w = ");
Serial.println(w);
```

## Operazioni

Le operazioni matematiche di base sono disponibili:
- `x + y` somma
- `-x` opposto di x
- `x - y` differenza
- `x * y` moltiplicazione
- `x / y` divisione
- `x % y` resto della divisione di x per y

Si possono raggrupare le operazioni con le parentesi tonde `()`.

**Attenzione**: l'operatore `^` non esegue l'elevamento a potenza. Per elevare a potenza puoi scrivere `pow(base, esponente)` invece.

```cpp
int p = 5;
int q = p * p - (p + 7);

Serial.print("p = ");
Serial.print(p);
Serial.print("; q = p^2 - (p+7) = ");
Serial.print(q);
Serial.print("; il resto della divisione di q per 6 e' ");
Serial.println(q % 6);
```

Questo codice un po' più complicato risolve un'equazione di secondo grado:
```cpp
float a = 6, b = -5, c = 1; // i coefficienti dell'equazione

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
```

Alcune scorciatoie sono elencate qui di seguito:
- `x += y` equivale a `x = x + y`
- `x -= y` equivale a `x = x - y`
- `x *= y` equivale a `x = x * y`
- `x /= y` equivale a `x = x / y`
- `x %= y` equivale a `x = x % y`
- `++x` e `x++` equivalgono a `x = x + 1` ma:
  - `int y = ++x` -> y assume il valore di x dopo l'incremento
  - `int y = x++` -> y assume il valore di x prima dell'incremento 
- `--x` e `x--` equivalgono a `x = x - 1` e si comportano come `++x` e `x++


```cpp
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
```


## Condizioni

Talvolta si vuole compiere una scelta e cambiare le operazioni da eseguire in base ad una condizione: ad esempio, se il delta risulta minore di zero in un'equazione di secondo grado si scrive che è impossibile invece di continuare la risoluzione. In C++ questo concetto si esprime con le istruzioni `if` ed `else`. La sintassi è:

```cpp
if (condizione) {
	// se la condizione e' vera viene eseguito questo codice
} else {
	// se la condizione e' falsa viene eseguito quest'altro codice
}
```

Le parentesi grafe possono essere omesse se si scrive una sola istruzione. Il blocco dell'`else` può essere omesso nel caso non si sia interessati ad eseguire del codice quando la condizione è falsa. Nel caso si vogliano controllare più condizioni si può mettere un altro `if` direttamente dopo l'`else`, in questo modo:

```cpp 
if (condizione1) {
	// ...
} else if (condizione2) {
	// ...
} else {
	// ...
}
```

Per scrivere le condizioni esistono le seguenti operazioni:
- `x <= y`, `x < y`, `x >= y`, `x > y` fanno ciò che ci si aspetterebbe
- `x == y` restituisce vero se `x` è uguale a `y`
- `x != y` restituisce vero se `x` è diverso da `y`
- `!a` (NOT) restituisce l'opposto di `a`, quindi se `a` è vero `!a` è falso
- `a && b` (AND) restituisce vero solo quando sia `a` che `b` sono vere, altrimenti restituisce falso
- `a || b` (OR) restituisce vero quando almeno una tra `a` e `b` è vera, mentre se sia `a` che `b` sono false restituisce falso
- le parentesi `()` funzionano come con le altre operazioni

Esiste inoltre un tipo `bool` per le variabili, che può assumere solo i valori `true` e `false` e serve per tenere salvato il valore di una condizione, ovvero un valore di verità. I valori `bool` possono essere usati direttamente all'interno degli `if` al posto della condizione.

Da ricordare che secondo le *leggi di De Morgan* `!(a && b)` è la stessa cosa di `(!a) || (!b)`, e `!(a || b)` è la stessa cosa di `(!a) && (!b)`.

```cpp
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
```


## Cicli

Talvolta può essere utile eseguire del codice più volte. Per fare ciò esistono i cicli.

### for

Il ciclo `for` comprende tre elementi:
- inizializzazione: viene eseguita prima di eseguire il ciclo, e serve per dichiarare e inizializzare la variabile da usare per gestire il ciclo
- condizione: viene controllata prima di ogni iterazione; se è vera allora il ciclo continua, altrimenti si interrompe
- incremento: viene eseguito al termine di ogni iterazione, e serve solitamente per incrementare la variabile usata per gestire il ciclo

```cpp
for (inizializzazione; condizione; incremento) {
	// ...
}
```

Ad esempio, il seguente ciclo scrive i numeri da 0 a 7:

```cpp
for (int i = 0; i < 8; i++) {
	Serial.println(i);
}
```

### while

Talvolta non si ha bisogno di una variabile per gestire il ciclo, come nel caso del `for`, ma si vuole semplicemente continuare ad eseguire del codice fintantochè una condizione rimane vera. Per questo esiste il ciclo `while`:

```cpp
while (condizione) {
	// ...
}
```

Ad esempio, il seguente ciclo aspetta finchè non ci sono dei caratteri pronti alla lettura sulla seriale, controllando circa una volta al secondo:

```cpp
while (Serial.available() <= 0) {
	delay(1000); // aspetta un secondo prima di ricontrollare
}
```

### break e continue

Talvolta si ha la necessità di saltare un'iterazione oppure uscire da un ciclo in anticipo. Pertanto esistono i seguenti costrutti:
- `break` esce dal ciclo
- `continue` termina l'iterazione corrente

## Esempio complessivo

```cpp
Serial.println("Se a = 5 m/(s^2) e m = 6 kg, quanto vale Ftot?");
bool corretto = false;
for (int tentativi = 0; tentativi < 5; tentativi++) {
	int valore = Serial.parseInt();

	while (Serial.available()) {
		// se assieme al valore l'utente ha scritto anche dell'altro, facciamo in modo che sia tolto tutto
		Serial.read();
	}

	if (valore == 5 * 6) {
		corretto = true;
		break; // esce dal ciclo
	} else {
		if (valore <= 0) {
			Serial.print("Non ha senso che una forza sia negativa! ");
		}
		Serial.println("Riprova");
	}
}
if (corretto) {
	Serial.println("Corretto!");
} else {
	Serial.println("Il risultato era 30");
}
```