https://wokwi.com/projects/468714405751327745

#include <Keypad.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Servo.h>

LiquidCrystal_I2C lcd(0x27,16,2);
Servo doorServo;

const String password = "1234";
String input = "";

const byte ROWS = 4;
const byte COLS = 4;

char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte rowPins[ROWS] = {2,3,4,5};
byte colPins[COLS] = {6,7,8,10};

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

void setup() {

  lcd.init();
  lcd.backlight();

  doorServo.attach(9);
  doorServo.write(0);

  lcd.print("Enter Password");
}

void loop() {

  char key = keypad.getKey();

  if(key){

    if(key == '#'){

      lcd.clear();

      if(input == password){

        lcd.print("Access Granted");

        doorServo.write(90);

        delay(5000);

        doorServo.write(0);

      }

      else{

        lcd.print("Access Denied");

      }

      delay(2000);

      input="";

      lcd.clear();

      lcd.print("Enter Password");

    }

    else{

      input += key;

      lcd.setCursor(input.length()-1,1);

      lcd.print("*");

    }

  }

}
