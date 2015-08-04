#include <Bounce2.h>
Bounce  bouncer1  = Bounce();
Bounce  bouncer2  = Bounce();
Bounce  bouncer3  = Bounce();
Bounce  bouncer4  = Bounce();

int latchpin = 5;// connect to pin 12 on the '595
int clockpin = 7; // connect to pin 11 on the '595
int datapin = 6; // connect to pin 14 on the '595

const int Relay1 = 2;
const int Relay2 = 3;

const int FirstButton = 10;
const int SecondButton = 11;
const int ThirdButton = 12;
const int FourthButton = 13;


int Gear = 1;




void setup() {
  // put your setup code here, to run once:
  // Serial.begin(9600);
  pinMode(Relay1, OUTPUT);
  pinMode(Relay2, OUTPUT);
  digitalWrite(Relay1, HIGH);
  digitalWrite(Relay2, HIGH);

  pinMode(latchpin, OUTPUT);
  pinMode(clockpin, OUTPUT);
  pinMode(datapin, OUTPUT);


  pinMode(FirstButton, INPUT_PULLUP);
  pinMode(SecondButton, INPUT_PULLUP);
  pinMode(ThirdButton, INPUT_PULLUP);
  pinMode(FourthButton, INPUT_PULLUP);

 bouncer1.attach(FirstButton);
 bouncer2.attach(SecondButton);
 bouncer3.attach(ThirdButton);
 bouncer4.attach(FourthButton);
 bouncer1.interval(5);
 bouncer2.interval(5);
 bouncer3.interval(5);
 bouncer4.interval(5);

  Gear = 1;
  displayDigit(1);
}

void loop() {
 
 
  bouncer1.update();
  bouncer2.update();
  bouncer3.update();
  bouncer4.update();

  if (bouncer1.read() == 0){
    Gear = 1;
    }
  if (bouncer2.read() == 0){
    Gear = 2;
    }
  if (bouncer3.read() == 0){
    Gear = 3;
    }
  if (bouncer4.read() == 0){
    Gear = 4;
    }

  
    switch (Gear) {
        case 1:    // first gear
          displayDigit(1);
          digitalWrite(Relay1, HIGH);
          digitalWrite(Relay2, HIGH);
          break;
        case 2:    // second gear
          displayDigit(2);
          digitalWrite(Relay1, LOW);
          digitalWrite(Relay2, HIGH);
          break;
        case 3:    // third gear
          displayDigit(3);
          digitalWrite(Relay1, HIGH);
          digitalWrite(Relay2, LOW);
          break;
        case 4:    // fourth gear
          displayDigit(4);
          digitalWrite(Relay1, LOW);
          digitalWrite(Relay2, LOW);
          break;
      }
  delay(1);
  
}
