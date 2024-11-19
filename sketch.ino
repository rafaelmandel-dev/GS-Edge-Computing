#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "DHT.h"

#define DHTPIN 2
#define DHTTYPE DHT22 

DHT dht(DHTPIN, DHTTYPE);

LiquidCrystal_I2C lcd(0x27, 16, 2); 

#define POT_VENTO_PIN A0 
#define POT_RELEVO_PIN A1 

void setup() {
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Analisando...");
  lcd.setCursor(0, 1);
  lcd.print("Por favor aguarde");
  delay(3000);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Monitor Clima");
  dht.begin();
  pinMode(POT_VENTO_PIN, INPUT);
  pinMode(POT_RELEVO_PIN, INPUT);
  delay(2000);
}
void loop() {
  float temperatura = dht.readTemperature();
  float umidade = dht.readHumidity();
  int ventoValue = analogRead(POT_VENTO_PIN);
  int relevoValue = analogRead(POT_RELEVO_PIN);
  float vento = map(ventoValue, 0, 1023, 0, 100);
  float relevo = map(relevoValue, 0, 1023, 0, 1000);
  String tipoEnergia;
  if (vento > 20 && temperatura < 30) {
    tipoEnergia = "Energia Eolica";
  } else if (temperatura > 30 && umidade > 50) {
    tipoEnergia = "Energia Solar";
  } else if (relevo > 800) {
    tipoEnergia = "Energia Hidreletrica";
  } else {
    tipoEnergia = "Combinação das energias";
  }
  if (isnan(temperatura) || isnan(umidade)) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Erro no Sensor");
    delay(2000);
    return;
  }
  String clima = temperatura < 20 ? "Frio" : "Calor";
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(temperatura);
  lcd.print("C");
  lcd.setCursor(0, 1);
  lcd.print("Umid: ");
  lcd.print(umidade);
  lcd.print("%");
  delay(2000);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Vento: ");
  lcd.print(vento);
  lcd.print(" km/h");
  lcd.setCursor(0, 1);
  lcd.print("Relevo: ");
  lcd.print(relevo);
  lcd.print(" m");
  delay(2000);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Clima: ");
  lcd.print(clima);
  delay(2000);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Melhor Energia:");
  lcd.setCursor(0, 1);
  lcd.print(tipoEnergia);
  delay(3000);
}