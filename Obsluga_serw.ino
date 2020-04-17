
  
void setup() {
  pinMode(3, OUTPUT); //Konfiguracja pinu 3 jako wyjście
}
 
void loop() {
  digitalWrite(3, HIGH); //Włączenie diody
  delay(1000); //Odczekanie 1 sekundy
  digitalWrite(3, LOW); //Wyłączenie diody
  delay(1000);
}
