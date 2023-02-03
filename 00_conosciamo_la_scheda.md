# Conosciamo la scheda

## La dotazione della scuola
In laboratorio di informatica sono presenti delle schede `Arduino UNO` (grandi classici), ma in dotazione all'laboratorio di fisica ci sono le schede `Arduino Nano 33 BLE Sense`.
Pertanto ci sembra utile elencare un po' di risorse relative a queste ultime in modo da averle a portata di mano se fosse necessaria una rapida consultazione.
- [Arduino Store](https://store.arduino.cc/products/arduino-nano-33-ble-sense)
- [Descrizione hardware (con relativi datasheet)](https://docs.arduino.cc/hardware/nano-33-ble-sense)

## I sensori
- Accelerometro, Giroscopio, Bussola: LSM9DS1
- Microfono: MP34DT05
- Luce: APDS9960
- Pressione: LPS22HB
- Umidità: HTS221


- 13 pin digitali + 1 led sulla board (in teoria tutti gestibili con il PWM, ma è meglio controllare, data l'imprecisione nella documentazione)
- 8 entrate analogiche (12 bit, 200 kHz)

## Collegamento al computer

Per collegarsi al computer è sufficiente collegare l'usb. All'interno di Arduino IDE bisogna poi impostare la scheda e la porta a cui è connessa dal menù "Strumenti". Per verificare se il programma è scritto correttamente si può usare il pulsante "Verifica", mentre per caricare un programma sulla scheda si preme sul pulsante "Carica".