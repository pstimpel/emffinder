/* EMF Detector for LED Bargraph v1.0
original code/project by Aaron ALAI - aaronalai1 ät gmail punked com
modified for use w/ LED bargraph by Collin Cunningham - collin ät makezine punked com
shortened and refactored by Christian Figge - info ät flazer punked net (flazer.com)

Info:
Use IOPins 02 - 12 for LED-Bargraph
*/

#define MEASURES 15
int senseLimit = 15;
int antenna = A5;
int rangeswitch = 12;
int buzzerswitch = 13;
volatile int ranges[] = {50, 150, 250, 350, 450, 550, 650, 750, 850, 950};

int ledcount = sizeof(ranges)/sizeof(int); //same size as values in ranges (10)
int ledPinOffset = 2; //offset of starting pinout number
int bucket[MEASURES]; //bucket of values 
int total = 0;
int pos   = 0;
int avg   = 0;
int val   = 0;
int volatile oldrangevalue = 20;
void setup() {
  Serial.begin(9600);
  pinMode(antenna, INPUT);
  for (int i=ledPinOffset; i<ledcount+ledPinOffset; i++) {
    pinMode(i, OUTPUT);
  }
  pinMode(rangeswitch, INPUT_PULLUP);
  pinMode(buzzerswitch, OUTPUT);
  for (int i=0; i<MEASURES; i++) {
    bucket[i] = 0;
  }
  digitalWrite(buzzerswitch, HIGH);
  delay(50);
  digitalWrite(buzzerswitch, LOW);
}

void loop() {

  val = analogRead(antenna);
  if (val >= 1){
    val = constrain(val, 1, senseLimit);
    val = map(val, 1, senseLimit, 1, 1023);
    total -= bucket[pos];
    bucket[pos] = val;
    total += bucket[pos];
    pos = (pos + 1);

    if (pos >= MEASURES) {
      pos = 0;
    }
    avg = total / MEASURES;

    for (int i=0; i<ledcount; i++) {
      if (avg > ranges[i]) {
        digitalWrite(i+ledPinOffset, HIGH);
        if(i==ledcount-1) {
         digitalWrite(buzzerswitch, HIGH);
         delay(5);
        }
      } else {
        digitalWrite(i+ledPinOffset, LOW);
        digitalWrite(buzzerswitch, LOW);
      }
    }
    //Serial.print("val :");
    //Serial.println(val);
  }

  int switchvalue = digitalRead(rangeswitch);
  if(oldrangevalue != switchvalue) {
    oldrangevalue = switchvalue;
    if(switchvalue == LOW) {
      ranges[0] = 50;
      ranges[1] = 150;
      ranges[2] = 250;
      ranges[3] = 350;
      ranges[4] = 450;
      ranges[5] = 550;
      ranges[6] = 650;
      ranges[7] = 750;
      ranges[8] = 850;
      ranges[9] = 950;
      
      //Serial.println("switchvalue:^");
      
    } else {
      ranges[0] = 25;
      ranges[1] = 75;
      ranges[2] = 125;
      ranges[3] = 175;
      ranges[4] = 225;
      ranges[5] = 275;
      ranges[6] = 325;
      ranges[7] = 375;
      ranges[8] = 425;
      ranges[9] = 475;
      
      //Serial.println("switchvalue:_");
    
    }
    digitalWrite(buzzerswitch, HIGH);
    delay(50);
    digitalWrite(buzzerswitch, LOW);
  }
}
