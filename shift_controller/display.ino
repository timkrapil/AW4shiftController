

void displayDigit(int digit){
  int segment[10] = {63,6,91,79,102,109,125,7,127,111 }; // for common cathode  


  
  digitalWrite(latchpin, LOW);
  shiftOut(datapin, clockpin, MSBFIRST, 0); // clears the display
  digitalWrite(latchpin, HIGH);

  digitalWrite(latchpin, LOW);
  shiftOut(datapin, clockpin, MSBFIRST, segment[digit]);
  digitalWrite(latchpin, HIGH);

  
}

