int ledPin = 11;
int ledPin2 = 12;
int ledPin3 = 13;
int trigPin = 2;
int echoPin = 3;
int trigPin2 = 5;
int echoPin2 = 6;
int trigPin3 = 9;
int echoPin3 = 10;
int buzzer = 7;
int tiempo = 100;
long DO = 523.25, //definimos las frecuencias de las notas
     DoS = 554.37,
     RE = 587.33,
     RES = 622.25,
     MI = 659.26,
     FA = 698.46,
     FAS = 739.99,
     SOL = 783.99,
     SOLS = 830.61,
     LA = 880,
     LAS = 932.33,
     SI = 987.77,
     RE2 = 1174.66,
     FAS2 = 1479.98,
     PAU = 30000;

long notas[] = {DO, DoS, RE, RES, MI, FA, FAS, SOL, SOLS, LA, LAS, SI, RE2, FAS2, PAU};

//FUNCION DEL TONE
void notaMusical(int distancia, int num) {
  if (distancia < 30 && distancia > 24) {
    tone(buzzer, notas[num]);
    delay(tiempo);
    noTone(buzzer);
    delay(tiempo);
    tone(buzzer, notas[num]);
    delay(tiempo);
  }
  else if (distancia < 24 && distancia > 18) {
    tone(buzzer, notas[num + 1]);
    delay(100);
    noTone(buzzer);
    delay(100);
    tone(buzzer, notas[num + 1]);
    delay(100);
  }
  else if (distancia < 18 && distancia > 12) {
    tone(buzzer, notas[num + 2]);
    delay(tiempo);
    noTone(buzzer);
    delay(tiempo);
    tone(buzzer, notas[num + 2]);
    delay(tiempo);
  }
  else if (distancia < 12 && distancia > 6) {
    tone(buzzer, notas[num + 3]);
    delay(tiempo);
    noTone(buzzer);
    delay(tiempo);
    tone(buzzer, notas[num + 3]);
    delay(tiempo);
  }
  else if (distancia < 6) {
    tone(buzzer, notas[num + 4]);
    delay(tiempo);
    noTone(buzzer);
    delay(tiempo);
    tone(buzzer, notas[num + 4]);
    delay(tiempo);
  }
  else {
    noTone(buzzer);
  }
}
void setup() {
  Serial.begin (9600);
  pinMode(buzzer, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
  pinMode(trigPin3, OUTPUT);
  pinMode(echoPin3, INPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
}

void loop() {
  //SENSOR1
  int duration, distance;
  digitalWrite (trigPin, HIGH);
  delayMicroseconds (10);
  digitalWrite (trigPin, LOW);
  duration = pulseIn (echoPin, HIGH);
  distance = (duration / 2) / 29.1;

  if (distance < 30) {
    digitalWrite (ledPin, HIGH);
    notaMusical(distance, 0);
    Serial.print(distance);
    Serial.print("cm ------ SOY EL UNO");
    Serial.println();
  } else {
    digitalWrite (ledPin, LOW);
  }
  //SENSOR2
  int duration2, distance2;
  digitalWrite (trigPin2, HIGH);
  delayMicroseconds (10);
  digitalWrite (trigPin2, LOW);
  duration = pulseIn (echoPin2, HIGH);
  distance2 = (duration / 2) / 29.1;

  if (distance2 < 30) {
    digitalWrite (ledPin2, HIGH);
    notaMusical(distance2, 1);
    Serial.print(distance2);
    Serial.print("cm ------ SOY EL DOS");
    Serial.println();
  }
  else {
    digitalWrite (ledPin2, LOW);
  }
  //SENSOR3
  int duration3, distance3;
  digitalWrite (trigPin3, HIGH);
  delayMicroseconds (10);
  digitalWrite (trigPin3, LOW);
  duration = pulseIn (echoPin3, HIGH);
  distance3 = (duration / 2) / 29.1;

  if (distance3 < 30) {  // Change the number for long or short distances.
    digitalWrite (ledPin3, HIGH);
    notaMusical(distance3, 2);
    Serial.print(distance3);
    Serial.print("cm ------ SOY EL TRES");
    Serial.println();
  }
  else {
    digitalWrite (ledPin3, LOW);
  }
}
