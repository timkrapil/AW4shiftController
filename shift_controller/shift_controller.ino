#include <Bounce2.h>
Bounce  bouncer1  = Bounce();
Bounce  bouncer2  = Bounce();
Bounce  bouncer3  = Bounce();
Bounce  bouncer4  = Bounce();



const int Relay1 = 0;
const int Relay2 = 1;

const int FirstButton = 10;
const int SecondButton = 11;
const int ThirdButton = 12;
const int FourthButton = 13;


int Gear = 1;

int a = 2;  //For displaying segment "a"
int b = 3;  //For displaying segment "b"
int c = 4;  //For displaying segment "c"
int d = 5;  //For displaying segment "d"
int e = 6;  //For displaying segment "e"
int f = 8;  //For displaying segment "f"
int g = 9;  //For displaying segment "g"

void displayDigit(int digit){

  turnOff();

 //Conditions for displaying segment a
 if(digit!=1 && digit != 4)
 digitalWrite(a,HIGH);

 //Conditions for displaying segment b
 if(digit != 5 && digit != 6)
 digitalWrite(b,HIGH);

 //Conditions for displaying segment c
 if(digit !=2)
 digitalWrite(c,HIGH);

 //Conditions for displaying segment d
 if(digit != 1 && digit !=4 && digit !=7)
 digitalWrite(d,HIGH);

 //Conditions for displaying segment e
 if(digit == 2 || digit ==6 || digit == 8 || digit==0)
 digitalWrite(e,HIGH);

 //Conditions for displaying segment f
 if(digit != 1 && digit !=2 && digit!=3 && digit !=7)
 digitalWrite(f,HIGH);
 if (digit!=0 && digit!=1 && digit !=7)
 digitalWrite(g,HIGH);

}
void turnOff()
{
  digitalWrite(a,LOW);
  digitalWrite(b,LOW);
  digitalWrite(c,LOW);
  digitalWrite(d,LOW);
  digitalWrite(e,LOW);
  digitalWrite(f,LOW);
  digitalWrite(g,LOW);
}




void setup() {

  pinMode(Relay1, OUTPUT);
  pinMode(Relay2, OUTPUT);
  digitalWrite(Relay1, HIGH);
  digitalWrite(Relay2, HIGH);

  pinMode(a, OUTPUT);  //A
  pinMode(b, OUTPUT);  //B
  pinMode(c, OUTPUT);  //C
  pinMode(d, OUTPUT);  //D
  pinMode(e, OUTPUT);  //E
  pinMode(f, OUTPUT);  //F
  pinMode(g, OUTPUT);  //G


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

  if (bouncer1.read() == 0){Gear = 1;}
   if (bouncer2.read() == 0){Gear = 2;}
    if (bouncer3.read() == 0){Gear = 3;}
     if (bouncer4.read() == 0){Gear = 4;}


    switch (Gear) {
        case 1:    // first gear
          turnOff();
          displayDigit(1);
          digitalWrite(Relay1, HIGH);
          digitalWrite(Relay2, HIGH);
          break;
        case 2:    // second gear
          turnOff();
          displayDigit(2);
          digitalWrite(Relay1, LOW);
          digitalWrite(Relay2, HIGH);
          break;
        case 3:    // third gear
          turnOff();
          displayDigit(3);
          digitalWrite(Relay1, HIGH);
          digitalWrite(Relay2, LOW);
          break;
        case 4:    // fourth gear
          turnOff();
          displayDigit(4);
          digitalWrite(Relay1, LOW);
          digitalWrite(Relay2, LOW);
          break;
      }
  delay(1);




}
