# Tutorial di Arduino e C++

Per scaricare tutti le spiegazioni e i progetti basta premere sul pulsante verde `Code` qui in alto a destra, e poi su `Download ZIP`. Serve poi spacchettare/estrarre i file dalla ZIP così che Arduino riesca ad aprirli correttamente.

I file `.ino` sono quelli che si possono aprire con l'Arduino IDE, mentre i file `.md` sono quelli con le spiegazioni e si possono aprire con un editor di testo o il Blocco Note.

# mdbook
Se preferite potete andare a [questo indirizzo](https://usioumeo.github.io/Tutorial_Arduino/) per una visualizzazione più carina

## Spiegazioni

Nei vari file ci sono le **spiegazioni** dei vari concetti assieme ad **esempi**. Ci sono poi anche alcuni progetti esemplificativi caricabili sulla scheda di Arduino nelle sottocartelle.

- [conosciamo_la_scheda](./src/tutorial/scheda/conosciamo_la_scheda.md): informazioni riguardo alla scheda e ai sensori in dotazione della scuola
- [introduzione_Arduino](./src/tutorial/intro_arduino/introduzione_Arduino.md): scheletro di un programma di Arduino, comandi per gestire i pin, comunicazione base su seriale
- [C++_base](./src/tutorial/cpp_base/C%2B%2B_base.md): commenti, variabili, operazioni, condizioni, cicli in C++ (progetto Arduino allegato: [cpp_base.ino](./src/tutorial/cpp_base/cpp_base.ino))
- [seriale](./src/tutorial/seriale/seriale.md): più funzionalità della seriale, plotter seriale per fare grafici
- [C++_funzioni](./src/tutorial/cpp_funzioni/C%2B%2B_funzioni.md): funzioni e procedure in C++, utili principalmente per sapere cosa succede (progetto Arduino allegato: [cpp_funzioni.ino](./src/tutorial/cpp_funzioni/cpp_funzioni.ino))

## Esperienze

Le spiegazioni dei vari sensori, assieme a delle esperienze di laboratorio base già funzionanti, sono i seguenti:

- [ultrasuoni](./src/esperienze/ultrasuoni/ultrasuoni.md): sensore ad ultrasuoni per misurare distanze (progetto Arduino allegato: [ultrasuoni.ino](./src/esperienze/ultrasuoni/ultrasuoni.ino))
- [accelerometro](./src/esperienze/accelerometro/accelerometro.md): accelerometro del sensore LSM9DS1 (progetto Arduino allegato: [accelerometro.ino](./src/esperienze/accelerometro/accelerometro.ino))
- [giroscopio](./src/esperienze/giroscopio/giroscopio.md): giroscopio del sensore LSM9DS1 (progetto Arduino allegato: [giroscopio.ino](./src/esperienze/giroscopio/giroscopio.ino))
- [magnetometro](./src/esperienze/magnetometro/magnetometro.md): magnetometro del sensore LSM9DS1 (progetto Arduino allegato: [magnetometro.ino](./src/esperienze/magnetometro/magnetometro.ino))
- [magnetometro_calibrazione](./src/esperienze/magnetometro_calibrazione/magnetometro_calibrazione.md): magnetometro con calibrazione (progetto Arduino allegato: [magnetometro_calibrazione.ino](./src/esperienze/magnetometro_calibrazione/magnetometro_calibrazione.ino))
- [~~Magnetometro esterno~~](./src/esperienze/magnetometro_esterno/magnetometro_esterno.md): magnetometro del professor Colonna, non in dotazione della scuola (progetto Arduino allegato: [magnetometro_esterno.ino](./src/esperienze/magnetometro_esterno/magnetometro_esterno.ino))
- [barometro](./src/esperienze/barometro/barometro.md): sensore di pressione (progetto Arduino allegato: [barometro.ino](./src/esperienze/barometro/barometro.ino))
- [colore](./src/esperienze/colore/colore.md): sensore di colore e luce (progetto Arduino allegato: [colore.ino](./src/esperienze/colore/colore.ino))
- [momento_inerzia](./src/esperienze/momento_inerzia/): uso del magnetometro per calcolare il momento d'inerzia di un magnete sospeso ad un filo attorcigliato (progetto Arduino allegato: [momento_inerzia.ino](./src/esperienze/momento_inerzia/momento_inerzia.ino))
- [temperatura_umidita](./src/src/esperienze/temperatura_umidita/temperatura_umidita.md): uso del sensore esterno di temperatura e umidità DHT11 (progetto Arduino allegato: [temperatura_umidita.ino](./src/src/esperienze/temperatura_umidita/temperatura_umidita.ino))
