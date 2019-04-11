#include <Keypad.h>

int green = 2;
int red = 13;

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
  pinMode(green, OUTPUT);
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

  while(actualTimer > 0){
    actualTimer--;
    Serial.println(actualTimer);

    for(int i = 0; i < 100; i++){
      delay(10);
      char customKey = myKeypad.getKey();
      if(customKey == '*'){
        actualTimer = 0;
        Serial.println("Timer stopped");
      }
    }
  }
}
















    /*
    if(digit == 1){
    
      if(customKey == '1'){
        Serial.println("1");
        
        for(int i = 0; i < 1; i++){
          digitalWrite(green, HIGH);
          delay(500);
          digitalWrite(green, LOW);
          delay(500);
          digit = 2;
        }
      }
  
      else if(customKey == '2'){        
        for(int i = 0; i < 2; i++){
          digitalWrite(green, HIGH);
          delay(500);
          digitalWrite(green, LOW);
          delay(500);
          digit = 2;
        }
      }
    }

    if(digit == 2){
      
      if(customKey == '1'){
        for(int i = 0; i < 1; i++){
          digitalWrite(red, HIGH);
          delay(500);
          digitalWrite(red, LOW);
          delay(500);
          digit = 1;
        }
      }
  
      else if(customKey == '2'){
        for(int i = 0; i < 2; i++){
          digitalWrite(red, HIGH);
          delay(500);
          digitalWrite(red, LOW);
          delay(500);
          digit = 1;
        }
      }
      
    }
        
  }
}*/
