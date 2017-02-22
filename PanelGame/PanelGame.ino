#define LED0 2
#define LED1 3
#define LED2 4
#define LED3 5
//#define LED4 6
//#define LED5 7
//#define LED6 8
//#define LED7 9
//#define LED8 10
#define TACT0 8
#define TACT1 9
#define TACT2 10
#define TACT3 11
//#define TACT4 9
//#define TACT5 16
//#define TACT6 17
//#define TACT7 18
//#define TACT8 19
int gameselect = 0;
boolean endflag = false;


void setup() {
  //put your setup code here, to run once:
  Serial.begin(9600);
  for(int i = 2; i < 6; i++) {
    pinMode(i, OUTPUT);
  }
  for(int i = 8; i < 12; i++) {
    pinMode(i, INPUT_PULLUP);
  }
  
  gameselect = choose();
  allLightDown();
}

void loop() {
  //put your main code here, to run repeatedly:
  switch(gameselect) {
  case LED0:
    Simon();
    break;
  }
  if(endflag) while(true);
}

void allLightUp() {
  for(int i = 2; i < 6; i++) {
    digitalWrite(i, HIGH);
  }
//  digitalWrite(18, HIGH);
//  digitalWrite(19, HIGH);
}

void allLightDown() {
  for(int i = 2; i < 6; i++) {
    digitalWrite(i, LOW);
  }
//  digitalWrite(A4, LOW);
//  digitalWrite(A5, LOW);
}

int Get() {
  if(digitalRead(TACT0) == LOW) return TACT0;
  if(digitalRead(TACT1) == LOW) return TACT1;
  if(digitalRead(TACT2) == LOW) return TACT2;
  if(digitalRead(TACT3) == LOW) return TACT3;
//  if(digitalRead(TACT4) == LOW) return TACT4;
//  if(digitalRead(TACT5) == LOW) return TACT5;
//  if(digitalRead(TACT6) == LOW) return TACT6;
//  if(digitalRead(TACT7) == LOW) return TACT7;
//  if(digitalRead(TACT8) == LOW) return TACT8;
  return -1;
}

int TACTtoLED(byte t) {
  if(t == TACT0) return LED0;
  if(t == TACT1) return LED1;
  if(t == TACT2) return LED2;
  if(t == TACT3) return LED3;
//  if(t == TACT4) return LED4;
//  if(t == TACT5) return LED5;
//  if(t == TACT6) return LED6;
//  if(t == TACT7) return LED7;
//  if(t == TACT8) return LED8;
}

void fault() {
  digitalWrite(LED0, HIGH);
  digitalWrite(LED2, HIGH);
//  digitalWrite(LED4, HIGH);
//  digitalWrite(LED6, HIGH);
//  digitalWrite(LED8, HIGH);
  delay(3000);
  allLightDown();
}

void success() {
  digitalWrite(LED0, HIGH);
  digitalWrite(LED1, HIGH);
  digitalWrite(LED2, HIGH);
  digitalWrite(LED3, HIGH);
//  digitalWrite(LED5, HIGH);
//  digitalWrite(LED6, HIGH);
//  digitalWrite(LED7, HIGH);
//  digitalWrite(LED8, HIGH);
  delay(3000);
  allLightDown();
}  

int choose() {
  digitalWrite(LED0, HIGH);
  //digitalWrite(LED1, HIGH);
  while(true) {  
    if(digitalRead(TACT0) == LOW) return LED0;
    //if(digitalRead(TACT1) == LOW) return LED1;
  }
}
