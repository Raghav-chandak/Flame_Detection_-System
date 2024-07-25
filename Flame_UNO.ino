#include <Servo.h>.
#include <Wire.h>.
#include <LiquidCrystal_I2C.h>.

Servo myServo;
LiquidCrystal_I2C lcd(0x27, 16, 2);

int mic = 4;
int ledr = 3;
int ledg = 2;
int motor = 7;


void setup() {
  pinMode(mic, INPUT);
  pinMode(ledr, OUTPUT);
  pinMode(ledg, OUTPUT);
  pinMode(motor, OUTPUT);
  lcd.begin();
  lcd.backlight();
  myServo.attach(5);
  // put your setup code here, to run once:
}

void loop() {
  if(digitalRead(mic) == LOW){
    lcd.setCursor(0,0);
	  lcd.print("FIRE!  FIRE!");
    digitalWrite(ledr, HIGH);
    digitalWrite(ledg, LOW);
    digitalWrite(motor, LOW);
    for(int i=0;i<=90;i++){  
    myServo.write(i);
    delay(30);
    }
    for(int i=90;i>0;i--){  
    myServo.write(i);
    delay(30);
    }
  }

  else{
    lcd.setCursor(2,0);
	  lcd.print("DRDO PROJECT");
    lcd.setCursor(7,1);
    lcd.print(" 4 ");
    digitalWrite(ledr, LOW);
    digitalWrite(motor, HIGH);  
    digitalWrite(ledg, HIGH);
    lcd.clear();
    }
  // put your main code here, to run repeatedly:

}