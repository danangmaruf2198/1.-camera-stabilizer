void manualMode() {
  if (submenu > 2) {
    submenu = 1;
  }
  else if (submenu < 1) {
    submenu = 2;
  }
  if (speedManual > 2000) {
    submenu = 2000;
  }
  else if (submenu < 1) {
    submenu = 1;
  }
}
void displayManual() {
  display.clearDisplay();
  display.setTextColor(WHITE);
  display.setTextSize(0.5);
  display.setCursor(0, 0);
  display.println("MANUAL TOMBOL");
  //display.setCursor(60, 20);
  //display.println(valA);
  display.setCursor(10, 10);
  display.println("play(kiri kanan)");
  display.setCursor(10, 20);
  display.println("Speed");
  display.setCursor(60, 20);
  display.println(speedManual);
  if (submenu == 1&&menu1==2) {
    display.setCursor(0, 10);
    display.println(">");
  }
  else if (submenu == 2&& menu1==2) {
    display.setCursor(0, 20);
    display.println(">");
  }

  else if (submenu == 2 && menu1 == 3) {
    display.setCursor(50, 20);
    display.println(">");
  }
  display.display();
}
void jalanManual(){
  if (submenu == 1 && menu1 == 3) {
    if (tombolOke == 1) {
    Serial.println("Kanan");
      digitalWrite(dirPin, HIGH);
      digitalWrite(stepPin, HIGH);
      delayMicroseconds(2000-speedManual);
      digitalWrite(stepPin, LOW);
      delayMicroseconds(2000-speedManual);
    }
    else if (tombolAtas == 1) {
    Serial.println("Kiri");
      digitalWrite(dirPin, LOW);
      digitalWrite(stepPin, HIGH);
      delayMicroseconds(2000-speedManual);
      digitalWrite(stepPin, LOW);
      delayMicroseconds(2000-speedManual);
    }
    else {
      digitalWrite(dirPin, LOW);
      digitalWrite(stepPin, LOW);
    }
  }
}
