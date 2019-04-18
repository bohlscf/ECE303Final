#include <Keypad.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27, 16, 2);

int lcdPin = 2;
int buttonPin = 

const byte ROWS = 4;
const byte COLS = 4;

char keys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

byte rowPins[ROWS] = {11, 10, 9, 8}; //{A0, A1, A2, A3};
byte colPins[COLS] = {7, 6, 5, 4};

Keypad myKeypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

int digit = 0;
int timer = 0;
int actualTimer = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  // initialize the LCD
  lcd.begin();

  // Turn on the blacklight
  lcd.setBacklight((uint8_t)1);

  // First row
  lcd.print("Warming up");

  // Second row
  lcd.setCursor(0,1);
  lcd.print("the toaster....");

  pinMode(lcdPin, OUTPUT);
  delay(1000);
}


void loop() {
  // put your main code here, to run repeatedly:
  char customKey = myKeypad.getKey(); //defining the key that was pressed

  if(customKey){
    Serial.println("I've been pressed");

    if(customKey == '#'){
      actualTimer = timer;      
      Serial.print("Actual Timer = ");
      Serial.println(actualTimer);
      timer = 0;
    }
    
    else if(customKey == '1'){
      Serial.println("it is a 1");
      timer = timer * 10 + 1;
      Serial.println(timer);
    }

    else if(customKey == '2'){
      Serial.println("it is a 2");
      timer = timer * 10 + 2;
      Serial.println(timer);
    }

    else if(customKey == '3'){
      Serial.println("it is a 3");
      timer = timer * 10 + 3;
      Serial.println(timer);
    }

    else if(customKey == '4'){
      Serial.println("it is a 4");
      timer = timer * 10 + 4;
      Serial.println(timer);
    }

    else if(customKey == '5'){
      Serial.println("it is a 5");
      timer = timer * 10 + 5;
      Serial.println(timer);
    }

    else if(customKey == '6'){
      Serial.println("it is a 6");
      timer = timer * 10 + 6;
      Serial.println(timer);
    }

    else if(customKey == '7'){
      Serial.println("it is a 7");
      timer = timer * 10 + 7;
      Serial.println(timer);
    }

    else if(customKey == '8'){
      Serial.println("it is a 8");
      timer = timer * 10 + 8;
      Serial.println(timer);
    }

    else if(customKey == '9'){
      Serial.println("it is a 9");
      timer = timer * 10 + 9;
      Serial.println(timer);
    }
  }

  if(timer > 0 && actualTimer == 0){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Current Timer is:");
    lcd.setCursor(7,1);
    lcd.print(timer);
    delay(50);
  }

  while(actualTimer > 0){
    
    Serial.println(actualTimer);
    lcd.clear();
  
    // First row
    lcd.setCursor(7,0);
    lcd.print(actualTimer);
  
    // Second row
    lcd.setCursor(4,1);
    lcd.print("seconds");
    //delay(1000);
    actualTimer--;
    
      for(int i = 0; i < 100; i++){
        delay(10);
        char customKey = myKeypad.getKey();
        if(customKey == '*'){
          actualTimer = 0;
          Serial.println("Timer stopped");
        }
      } 


      //Everything that happens when alarm goes off, needs to be in this loop
      if(actualTimer == 0){
         lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("TURN BUZZER ON!!");
        digitalWrite(lcdPin, HIGH);  
        delay(4000);                 //turn this message off when the alarm goes off 
        digitalWrite(lcdPin, LOW);
        lcd.clear();
      }
  }

  
}

