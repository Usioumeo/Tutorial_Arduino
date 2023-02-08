# Utilizzo del sensore barometrico sul nano 33 ble sense
il sensore è un LPS22HB ed è possibile visionare il datasheet a questo [link](https://content.arduino.cc/assets/Nano_BLE_Sense_lps22hb.pdf)

In particolare questo sensore contiene un diaframma, che con il variare della pressione si deforma aumentando/diminuendo la resistenza interna. La libreria standard ci converte già i dati in kPa, e non ci resta che sfruttare i dati per ottenere qualche informazione.

