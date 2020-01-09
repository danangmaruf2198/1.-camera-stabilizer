void returnHome(void) {

  display.clearDisplay();
  display.setTextColor(WHITE);
  display.setTextSize(2);
  display.setCursor(22, 0);
  display.println("MECHLAB");
  display.setTextSize(0.25);
  display.setCursor(15, 20);
  display.println("press OK to menu");
  display.display();

}
void kondisi1(void) {
  display.clearDisplay();
  display.setTextColor(WHITE);
  display.setTextSize(0.5);
  display.setCursor(40, 0);
  display.println("MENU AWAL");
  //display.setCursor(60, 20);
  //display.println(valA);

  display.setCursor(10, 10);
  display.println("mode manual");

  display.setCursor(10, 20);
  display.println("mode otomatis");

  display.setCursor(10, 30);
  display.println("pake bluetooth");

  display.setCursor(10, 40);
  display.println("Setting");

  display.setCursor(10, 50);
  display.println("Kalibrasi Home");

  if (pilihan == 1) {
    display.setTextColor(WHITE);
    display.setTextSize(0.5);
    display.setCursor(0, 10);
    display.println(">");
  }

  else if (pilihan == 2) {
    display.setTextColor(WHITE);
    display.setTextSize(0.5);
    display.setCursor(0, 20);
    display.println(">");
  }
  display.display();

}
//=============================

void kondisi2(void) {
  display.clearDisplay();
  display.setTextColor(WHITE);
  display.setTextSize(0.5);
  display.setCursor(40, 0);
  display.println("MENU AWAL");
  //display.setCursor(60, 20);
  //display.println(valA);
  display.setCursor(10, 10);
  display.println("pake bluetooth");

  display.setCursor(10, 20);
  display.println("Setting");

  display.setCursor(10, 30);
  display.println("input POTENSIO");

  if (pilihan == 3) {
    display.setTextColor(WHITE);
    display.setTextSize(0.5);
    display.setCursor(0, 10);
    display.println(">");
  }

  else if (pilihan == 4) {
    display.setTextColor(WHITE);
    display.setTextSize(0.5);
    display.setCursor(0, 20);
    display.println(">");
  }
  display.display();
}
//============================


void kondisi3(void) {
  display.clearDisplay();
  display.setTextColor(WHITE);
  display.setTextSize(0.5);
  display.setCursor(40, 0);
  display.println("MENU AWAL");
  //display.setCursor(60, 20);
  //display.println(valA);
  display.setCursor(10, 10);
  display.println("input POTENSIO");

  display.setCursor(10, 20);
  display.println("kalibrasi HOME");

  if (pilihan == 5) {
    display.setTextColor(WHITE);
    display.setTextSize(0.5);
    display.setCursor(0, 10);
    display.println(">");
  }

  else if (pilihan == 6) {
    display.setTextColor(WHITE);
    display.setTextSize(0.5);
    display.setCursor(0, 20);
    display.println(">");
  }
  display.display();
}
//============================menu
void menuAwal() {
  if (menu1 == 0) {
    returnHome();
  }
  else if (menu1 == 1 && pilihan <= 2) {
    kondisi1();

  }
  else if (menu1 == 1 && pilihan > 2 && pilihan <= 4) {
    kondisi2();
  }

  else if (menu1 == 1 && pilihan > 4) {
    kondisi3();
  }
  //=====================SUBMENU 1
  else if (menu1 == 2) {

    if (pilihan == 1) {
      displayManual();
      manualMode();
    }
    else if (pilihan == 2) {
      displayOtomatis();
      otomatisMode();
    }
    else if (pilihan == 3) {
      bluetoothMode();
      displayBluetooth();
    }
    else if (pilihan == 4) {
      displaySetting();
      settingMode();
    }
    else if (pilihan == 5) {
      displayPOT();
      POT();
    }
    else if (pilihan == 6) {
      kalibrasiHome();
      displayKalibrasi();
    }
  }
  //=============================================SUBMENU2
   else if ( menu1 == 3) { 
    if (pilihan == 1) {
      displayManual();
      manualMode();
    } if (pilihan == 5) {
       displayPOT();
      POT();
    }if (pilihan == 2) {
      displayOtomatis();
      otomatisMode();
    }
  }

 
}
