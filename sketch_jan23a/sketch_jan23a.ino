
#define distancePot A0
#define lightPot A1
#define durationPot A2
#define ldrPin A3
#define ledPin 12
#define TRIG 7
#define ECHO 6
int dPotVal, lPotVal, tPotVal, ldrVal;

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);
  // שורות ההגדרה הבאות לא הכרחיות מכיוון שמדובר בחיבורים אנאלוגיים
  pinMode(distancePot, INPUT);
  pinMode(lightPot, INPUT);
  pinMode(durationPot, INPUT);
  pinMode(ldrPin, INPUT);

  digitalWrite(ledPin, LOW);
}

void loop() {
  //קבלת מידע
  dPotVal = analogRead(distancePot);
  lPotVal = analogRead(lightPot);
  tPotVal = analogRead(durationPot);
  ldrVal = analogRead(ldrPin);

  // קריאת מרחק מחיישן אולטראסוני
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);

  long duration = pulseIn(ECHO, HIGH);
  int distance  = duration / 58.1;

  // מיפוי ערכי הפוטנציומטרים לערכים רךוונטים
  dPotVal = map(dPotVal, 0, 1023, 100, 300); // מיפוי לתחום ערכי מרחק רלוונטי להפעלה
  tPotVal = map(tPotVal, 0, 1023, 0, 60); // מיפוי למשך הפעלת נורה בשניות

  if ((distance < dPotVal) && (ldrVal < lPotVal)) { // מרחק קטן מהרצוי וחשוך בחוץ
    digitalWrite(ledPin, HIGH);
    delay(tPotVal * 1000);
    digitalWrite(ledPin, LOW);
  }
  delay(500);
}
