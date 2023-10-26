# Utilizzo del sensore di colore GY_31

Con la libreria fornita all'interno di qusta cartella l'inizializzazione e la lettura dei vari parametri viene automatizzata. L'unico compito che spetta all'utilizzatore è di mappare i dati con una scala che abbia senso per come sta usando il sensore. Ad esempio se si usa il sensore al buio, oppure fuori al sole, oppure illuminando con i led sopra la scheda i dati di calibrazione cambiano enormemente.

Per questo motivo consiglio di decidere una modalità di lettura, impostare il programma con quella modalità e scrivere i dati su un plotter seriale. Ora osserviamo come si comporta il sensore quando mettiamo davanti al sensore dei cartoncini di controllo (rosso, blu e verde). E mappiamo con il comando `map(value, sx, dx, mappedsx, mappedDx)`.

Ad esempio se vediamo che quando inseriamo un cartoncino nero davanti al sensore il valore sale a 90, e quando invece mettiamo un cartoncino rosso scende a 15, possiamo usare il comando:

`map(value, 90, 15, 0, 100)` per fare in modo che quando vede nero ci dia un valore prossimo allo 0, e quando vede del rosso ci dia valori vicini al 100.


```C++
{{#include colore.ino}}
```