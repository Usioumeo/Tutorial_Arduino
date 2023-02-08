# Utilizzo del sensore barometrico sul nano 33 ble sense
il sensore è un LPS22HB ed è possibile visionare il datasheet a questo [link](https://content.arduino.cc/assets/Nano_BLE_Sense_lps22hb.pdf)

In particolare questo sensore contiene un diaframma, che con il variare della pressione si deforma aumentando/diminuendo la resistenza interna. La libreria standard ci converte già i dati in kPa, e non ci resta che sfruttare i dati per ottenere qualche informazione.

$$ P = {P_0 e^{-gMh \over RT}} $$
di cui noi conosciamo
- P = pressione
- P0 = pressione al livello del mare
- g = accelerazione di gravità
- M = massa molare aria = 0.0289644 kg/mol
- R = 8,31432 N * M/(mol * K)

e ci manca da conoscere solo h, invertendo otteniamo

$$ h = {RT \over -gM}ln({P \over P_0})$$

e questa sarà la formula che faremo calcolare all'arduino nell'esempio.
