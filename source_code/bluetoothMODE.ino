void bluetoothMode(){
}
void displayBluetooth(){
  display.clearDisplay();
  display.setTextColor(WHITE);
  display.setTextSize(0.5);
  display.setCursor(20, 0);
  display.println("MODE BLUETOOTH");
  //display.setCursor(60, 20);
  //display.println(valA);
  display.setCursor(0, 20);
  display.println("PAIR device bluetooth");
  display.display();
}
