void otomatisMode() {
  ulang=0;
  if (submenu > 4) {
    submenu = 1;
  }
  else if (submenu < 1) {
    submenu = 4;
  }
}
void displayOtomatis() {
  display.clearDisplay();
  display.setTextColor(WHITE);
  display.setTextSize(0.5);
  display.setCursor(20, 0);
  display.println("MODE OTOMATIS");
  display.setCursor(10, 10);
  display.println("Run Stepper");
  display.setCursor(10, 20);
  display.println("Step Value");
  display.setCursor(100, 20);
  display.println(stepValue);
  display.setCursor(10, 30);
  display.println("Max Delay Speed");
  display.setCursor(60, 30);
  display.println(speedOtomatis);
  display.setCursor(10, 40);
  display.println("Repeat");
  display.setCursor(60, 40);
  display.println(kaliPengulangan);


  if (submenu == 1 && menu1 == 2) {
    display.setCursor(0, 10);
    display.println(">");
  }
  else if (submenu == 2 && menu1 == 2) {
    display.setCursor(0, 20);
    display.println(">");
  }
  else if (submenu == 2 && menu1 == 3) {
    display.setCursor(90, 20);
    display.println(">");
  }
  else if (submenu == 3 && menu1 == 2) {
    display.clearDisplay();
    display.setTextColor(WHITE);
    display.setTextSize(0.5);
    display.setCursor(20, 0);
    display.println("MODE OTOMATIS");
    display.setCursor(0, 10);
    display.println(">");
    display.setCursor(10, 10);
    display.println("delay step");
    display.setCursor(100, 10);
    display.println(speedOtomatis);
    display.setCursor(10, 20);
    display.println("Repeat");
    display.setCursor(70, 20);
    display.println(kaliPengulangan);
  }
  else if (submenu == 4 && menu1 == 2) {
    display.clearDisplay();
    display.setTextColor(WHITE);
    display.setTextSize(0.5);
    display.setCursor(20, 0);
    display.println("MODE OTOMATIS");
    display.setCursor(0, 20);
    display.println(">");
    display.setCursor(10, 10);
    display.println("delay step");
    display.setCursor(100, 10);
    display.println(speedOtomatis);
    display.setCursor(10, 20);
    display.println("Repeat");
    display.setCursor(70, 20);
    display.println(kaliPengulangan);
  }

  else if (submenu == 3 && menu1 == 3) {
    display.clearDisplay();
    display.setTextColor(WHITE);
    display.setTextSize(0.5);
    display.setCursor(20, 0);
    display.println("MODE OTOMATIS");
    display.setCursor(90, 10);
    display.println(">");
    display.setCursor(10, 10);
    display.println("delay step");
    display.setCursor(100, 10);
    display.println(speedOtomatis);
    display.setCursor(10, 20);
    display.println("Repeat");
    display.setCursor(70, 20);
    display.println(kaliPengulangan);
  }

  else if (submenu == 4 && menu1 == 3) {
    display.clearDisplay();
    display.setTextColor(WHITE);
    display.setTextSize(0.5);
    display.setCursor(20, 0);
    display.println("MODE OTOMATIS");
    display.setCursor(60, 20);
    display.println(">");
    display.setCursor(10, 10);
    display.println("delay step");
    display.setCursor(100, 10);
    display.println(speedOtomatis);
    display.setCursor(10, 20);
    display.println("Repeat");
    display.setCursor(70, 20);
    display.println(kaliPengulangan);
  }
  display.display();
}



void jalanOtomatis() {
  display.clearDisplay();
  display.setTextColor(WHITE);
  display.setTextSize(0.5);
  display.setCursor(20, 0);
  display.println("MODE OTOMATIS");
  //display.setCursor(60, 20);
  //display.println(valA);
  display.setCursor(10, 10);
  display.println("BACK untuk kembali");
  display.display();
  for (ulang; ulang < kaliPengulangan; ulang++) {
    Serial.println(ulang);
  digitalWrite(dirPin, HIGH);
    for (int x = 0; x < stepValue; x++) {
      digitalWrite(stepPin, HIGH);
      delayMicroseconds(speedOtomatis);
      digitalWrite(stepPin, LOW);
      delayMicroseconds(speedOtomatis);
    }
    delay(1000);
    digitalWrite(dirPin, LOW);
    for (int x = 0; x < stepValue; x++) {
      digitalWrite(stepPin, HIGH);
      delayMicroseconds(speedOtomatis);
      digitalWrite(stepPin, LOW);
      delayMicroseconds(speedOtomatis);
    }
    delay(1000);
  }
    ulang=kaliPengulangan;
    display.setCursor(10, 20);
    display.println("running Selesai");
  display.display();
}
