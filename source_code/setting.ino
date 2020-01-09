void settingMode(){
  
}
void displaySetting(){
  display.clearDisplay();
  display.setTextColor(WHITE);
  display.setTextSize(0.5);
  display.setCursor(20, 0);
  display.println("SETTING");
  //display.setCursor(60, 20);
  //display.println(valA);
  display.setCursor(10, 10);
  display.println("kecepatan");
  display.setCursor(10, 20);
  display.println("Time Sampling");
  display.setCursor(10, 30);
  display.println("pulse Max");
  display.display();
}
