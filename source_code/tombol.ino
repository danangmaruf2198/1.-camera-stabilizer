//tombol atas 40-45
//timbol bawah 172-177
//tombol back 61-67
//tombol ok 102-108
void ambiltombol() {
  if (analogRead(A0) >= 40 && analogRead(A0) <= 45) {
    tombolAtas = 0;
    tombolBawah = 1;
    tombolBack = 0;
    tombolOke = 0;
  }
  else if (analogRead(A0) >= 172 && analogRead(A0) <= 177) {
    tombolAtas = 1;
    tombolBawah = 0;
    tombolBack = 0;
    tombolOke = 0;
  }
  else if (analogRead(A0) >= 61 && analogRead(A0) <= 67) {
    tombolAtas = 0;
    tombolBawah = 0;
    tombolBack = 1;
    tombolOke = 0;
  }
  else if (analogRead(A0) >= 102 && analogRead(A0) <= 108) {
    tombolAtas = 0;
    tombolBawah = 0;
    tombolBack = 0;
    tombolOke = 1;
  }
  else {
    tombolAtas = 0;
    tombolBawah = 0;
    tombolBack = 0;
    tombolOke = 0;

  }
}

void event_tombolnya() {
  ambiltombol();
  if (submenu == 1 && menu1 == 3 && pilihan == 1) {

  }
  else if (submenu == 1 && menu1 == 3 && pilihan == 5) {

  }
  else {
    if (tombolOke != tombolOkeAkhir) {
      if (tombolOke == HIGH) {

        menu1++;


        // EEPROM.write(1,counter1);

      }
    }
    if (tombolAtas != tombolAtasAkhir) {
      if (tombolAtas == HIGH) {
        if (menu1 < 2) {
          pilihan++;
        }
        else if (menu1 == 2) {
          submenu++;
        }
        else if (menu1 == 3 && pilihan == 1 && submenu == 2) {
          speedManual++;
        }

        else if (menu1 == 3 && pilihan == 5 && submenu == 3) {
          speedPot -= 10;
        }

        else if (menu1 == 3 && pilihan == 2 && submenu == 2) {
          stepValue--;
        }
        else if (menu1 == 3 && pilihan == 2 && submenu == 3) {
          speedOtomatis -= 10;
        }
        else if (menu1 == 3 && pilihan == 2 && submenu == 4   ) {
          kaliPengulangan--;
        }
      }
    }
    if (tombolBawah != tombolBawahAkhir) {
      if (tombolBawah == HIGH) {
        if (menu1 < 2) {
          pilihan--;
        }
        else if (menu1 == 2) {
          submenu--;
        }
        else if (menu1 == 3 && pilihan == 1 && submenu == 2) {
          speedManual--;
        }
        else if (menu1 == 3 && pilihan == 5 && submenu == 3) {
          speedPot += 10;
        }
        else if (menu1 == 3 && pilihan == 2 && submenu == 2) {
          stepValue++;
        }
        else if (menu1 == 3 && pilihan == 2 && submenu == 3) {
          speedOtomatis += 10;
        }
        else if (menu1 == 3 && pilihan == 2 && submenu == 4) {
          kaliPengulangan++;
        }
      }
    }
  }

  if (tombolBack != tombolBackAkhir) {
    if (tombolBack == HIGH) {

      menu1--;


      // EEPROM.write(2,counter2);

    }
  }
  tombolAtasAkhir = tombolAtas;
  tombolBawahAkhir = tombolBawah;
  tombolOkeAkhir = tombolOke;
  tombolBackAkhir = tombolBack;
  if (menu1 > 4) {
    menu1 = 4;
  } if (menu1 < 0) {
    menu1 = 0;
  } if (pilihan > 6) {
    pilihan = 1;
  } if (pilihan < 1) {
    pilihan = 6;
  }



}
