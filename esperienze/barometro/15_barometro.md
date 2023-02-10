# Utilizzo del sensore barometrico sul nano 33 ble sense

- Il sensore integrato sulla scheda è un LPS22HB.
- Il datasheet è accessibile [qui](./LSM9DS1.pdf) (scaricato) o [qui](https://content.arduino.cc/assets/Nano_BLE_Sense_lps22hb.pdf) (fonte originale).
- In particolare questo sensore contiene un diaframma, che con il variare della pressione si deforma aumentando/diminuendo la resistenza interna.

La libreria del barometro, [BARO.h](./BARO.h) ci converte già i dati in $kPa$, e non ci resta che sfruttare i dati per ottenere qualche informazione.

$$ P = {P_0 e^{-gMh \over RT}} $$

di cui noi conosciamo
- P = pressione
- P0 = pressione al livello del mare
- g = accelerazione di gravità
- M = massa molare aria = $0.0289644 \space kg/mol$
- R = $8.31432 \space N \cdot m/(mol \cdot K)$

e ci manca da conoscere solo h, invertendo otteniamo

$$ h = {RT \over -gM}ln({P \over P_0})$$

e questa sarà la formula che faremo calcolare all'arduino nell'esempio.
