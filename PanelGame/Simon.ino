void Simon() {
  
  static boolean gamestart = true;
  static int number = 3;
  static int SimonTable[100];
  static int count = 0;
  static boolean timeget = true;
  int pushing;
  static int LightUD;
  static unsigned long time;
  static unsigned int c = 0;
  
  
  if(gamestart) {
    gamestart = false;
    randomSeed((long)millis());
    //delay(300);
    for(int i = 0; i < number; i++) {
      SimonTable[i] = random(2, 6);
      //SimonTable[i] = LED0;
      //適正delayを探せ
      delay(450);
      digitalWrite(SimonTable[i], HIGH);
      delay(450);
      digitalWrite(SimonTable[i], LOW);
    }
  }
    
  pushing = Get();
  //Serial.println(pushing);
  //Serial.println(TACTtoLED(pushing));
  if(digitalRead(pushing) == LOW && pushing != -1) {
    //Serial.println(c);
    if(c <= 400) { c++; }
    if(c == 400) {
      LightUD = TACTtoLED(pushing);
      digitalWrite(LightUD, HIGH);
      if(SimonTable[count] != TACTtoLED(pushing)) {
        digitalWrite(LightUD, LOW);
        Serial.println(number - 3);
        fault();
        endflag = true;
      } else {
        count++;
        if(count == number) {
          digitalWrite(LightUD, LOW);
          success();
          count = 0;
          number++;
          gamestart = true;
        }
      }
      //digitalWrite(LightUD, LOW);
     }
  } else {
    c = 0;
    digitalWrite(LightUD, LOW);
    LightUD = -1;
  }
}
