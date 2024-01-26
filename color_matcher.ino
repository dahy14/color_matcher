// define all the pins to use
#define blueBtn A0 
#define redBtn A1
#define greenBtn A2

#define indGreen 5
#define indRed 6

#define bLed 9
#define rLed 10
#define gLed 11

int randomLedOff;
int randomLedOn;
int level;

void setup() {
  pinMode(blueBtn, INPUT);
  pinMode(redBtn, INPUT);
  pinMode(greenBtn, INPUT);
  
  randomSeed(A5);

  Serial.begin(9600);
  // change the level to 1 or 2 
  int lvl = 1
  randomColor(lvl);
 }

void loop() {
  int blueDB = digitalRead(blueBtn); 
  int redDB = digitalRead(redBtn);
  int greenDB = digitalRead(greenBtn);
  
  // level 1 code 
  if(randomLedOn == bLed) {
    if (blueDB == HIGH) {
        Serial.println("correct");
        indicator(indGreen);
        randomColor(1);
    } else { 
      Serial.println("wrong"); 
      indicator(indRed);
    }
  }
  if(randomLedOn == rLed) {
    if (redDB == HIGH) {
        Serial.println("correct");
        indicator(indGreen);
        randomColor(1);
    } else { 
      Serial.println("wrong"); 
      indicator(indRed);
    }
  }
  if(randomLedOn == gLed) {
    if (greenDB == HIGH) {
        Serial.println("correct");
        indicator(indGreen);
        randomColor(1);
    } else { 
      Serial.println("wrong"); 
      indicator(indRed);
    }
  }
  // level 2 code
  if(randomLedOff == bLed){
    if (blueDB == HIGH) {
        Serial.println("wrong");
        indicator(indRed);
    }else if (redDB == HIGH && greenDB == HIGH) {
     Serial.println("correct");
     indicator(indGreen);
     randomColor(2);} 
  } 
    if(randomLedOff == rLed){
      if (redDB == HIGH) {
          Serial.println("wrong");
          indicator(indRed);
          }
      else if (blueDB == HIGH && greenDB == HIGH) { Serial.println("correct");
      indicator(indGreen);
      randomColor(2);}
  }
  if(randomLedOff == gLed)   {
    if (greenDB == HIGH) {
        Serial.println("wrong");
        indicator(indRed);
    } 
    else if (redDB == HIGH && blueDB == HIGH) { Serial.println("correct"); 
    indicator(indGreen);
    randomColor(2);
    }
  }


}

void randomColor(int level) {
    // on = 0, off = 255 because of the common anode LED
    // One led turns on to a random value
    if (level == 1) {
      randomLedOn = random(9,12);
      analogWrite(randomLedOn, 0);
    }
    // all led turns on to a random value, then one random led turns off 
    if(level == 2) {
      for(int i = 0; i < 3; i++) {
        analogWrite(8 + i, random(0,255));
    }
    randomLedOff = random(9,12);
    analogWrite(randomLedOff, 255);
    } 
}



void indicator(int pinNumber) {
  digitalWrite(pinNumber, 1);
  delay(500);
  digitalWrite(pinNumber, 0);
}