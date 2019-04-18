#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27, 16, 2);


void setup()
{
  // initialize the LCD
  lcd.begin();

  // Turn on the blacklight
  lcd.setBacklight((uint8_t)1);

  // First row
  lcd.print("Warming up");

  // Second row
  lcd.setCursor(0,1);
  lcd.print("the toaster....");

  pinMode(2, OUTPUT);
  delay(1000);
}

int t;

void loop()
{  
  t = 5;
  
  while(t>=0){
  lcd.clear();
  
  // First row
  lcd.setCursor(7,0);
  lcd.print(t);

  // Second row
  lcd.setCursor(4,1);
  lcd.print("seconds");
  delay(1000);
  
  t--;}
  
  lcd.clear();
  
  // First row
  lcd.clear();
  lcd.setCursor(2,0);
  lcd.print("RUN BITCH!!!!");
  digitalWrite(2, HIGH);  //LED on
  delay(1000);
  digitalWrite(2, LOW);
  
}
