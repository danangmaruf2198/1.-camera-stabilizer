
void displayPOT(void) {
  Serial.println("masuk POT");
  display.clearDisplay();
  display.setTextColor(WHITE);
  display.setTextSize(0.5);
  display.setCursor(20, 0);
  display.println("MODE POTENSIO");
  //display.setCursor(60, 20);
  //display.println(valA);
  display.setCursor(10, 10);
  display.println("Delay Mode");
  display.setCursor(10, 20);
  display.println("Position Mode");
  display.setCursor(10, 30);
  display.println("Max Delay Speed");
  display.setCursor(60, 30);
  display.println(speedPot);
  if (submenu == 1 && menu1 == 2) {
    display.setCursor(0, 10);
    display.println(">");
  }
  else if (submenu == 2 && menu1 == 2) {
    display.setCursor(0, 20);
    display.println(">");
  }
  else if (submenu == 3 && menu1 == 2) {
    display.clearDisplay();
    display.setTextColor(WHITE);
    display.setTextSize(0.5);
    display.setCursor(20, 0);
    display.println("MODE POTENSIO");
    display.setCursor(0, 10);
    display.println(">");
    display.setCursor(10, 10);
    display.println("Max Delay");
    display.setCursor(100, 10);
    display.println(speedPot);
  }

  else if (submenu == 3 && menu1 == 3) {
    display.clearDisplay();
    display.setTextColor(WHITE);
    display.setTextSize(0.5);
    display.setCursor(20, 0);
    display.println("MODE POTENSIO");
    display.setCursor(90, 10);
    display.println(">");
    display.setCursor(10, 10);
    display.println("Max Delay");
    display.setCursor(100, 10);
    display.println(speedPot);
  }

  display.display();

}
void POT() {
  potensio = analogRead(A1);
  potensio = map(potensio, 0, 1024, 0, speedPot);
  if (submenu > 3) {
    submenu = 1;
  }
  else if (submenu < 1) {
    submenu = 3;
  }
}
void jalanPotensioDelay() {
  potensio = analogRead(A1);
  potensio = map(potensio, 0, 1024, 0, speedPot);
  display.clearDisplay();
  display.setTextColor(WHITE);
  display.setTextSize(0.5);
  display.setCursor(20, 0);
  display.println("MODE DELPOT");
  //display.setCursor(60, 20);
  //display.println(valA);
  display.setCursor(10, 10);
  display.println("BACK untuk kembali");
  display.display();
  digitalWrite(dirPin, HIGH);
  if (tombolOke == 1) {
    for (int x = 0; x < 400; x++) {
      digitalWrite(stepPin, HIGH);
      delayMicroseconds(potensio);
      digitalWrite(stepPin, LOW);
      delayMicroseconds(potensio);
    }
    delay(1000);
    digitalWrite(dirPin, LOW);
    for (int x = 0; x < 400; x++) {
      
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(potensio);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(potensio);
  }
  delay(1000);
}
display.display();

}
