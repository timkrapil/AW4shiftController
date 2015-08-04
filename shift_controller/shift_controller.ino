#include <Bounce2.h>
Bounce  bouncer1  = Bounce();
Bounce  bouncer2  = Bounce();
Bounce  bouncer3  = Bounce();


int latchpin = 5;// connect to pin 12 on the '595
int clockpin = 7; // connect to pin 11 on the '595
int datapin = 6; // connect to pin 14 on the '595

const int Relay1 = 2;
const int Relay2 = 3;

const int DownButton = 10;
const int UpButton = 11;




int Gear = 1;




void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(Relay1, OUTPUT);
  pinMode(Relay2, OUTPUT);
  digitalWrite(Relay1, HIGH);
  digitalWrite(Relay2, HIGH);

  pinMode(latchpin, OUTPUT);
  pinMode(clockpin, OUTPUT);
  pinMode(datapin, OUTPUT);


  pinMode(UpButton, INPUT_PULLUP);
  pinMode(DownButton, INPUT_PULLUP);
  
  

 bouncer1.attach(UpButton);
 bouncer2.attach(DownButton);
 
 
 bouncer1.interval(5);
 bouncer2.interval(5);
 
 

  Gear = 1;
  displayDigit(1);
}

void loop() {
 
 
  bouncer1.update();
  bouncer2.update();
  

  if (bouncer1.fell()){
    
      if (Gear < 4){
      Gear = Gear + 1;
      Serial.println("+");
      //delay(1000);
      }
    }
  if (bouncer2.fell()){
    
      if (Gear > 1){
      Gear = Gear -1;
      Serial.println("-");
      //delay(1000);
      }
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
