// "Mot" Significa: "Motor".

//Motor da esquerda
#define Mot1A 5
#define Mot1B 6

//Motor da direita
#define Mot2A 9
#define Mot2B 10

int Vel_Mot1 = 255;
int Vel_Mot2 = 245;

void setup() {
  pinMode(Mot1A, OUTPUT);
  pinMode(Mot1B, OUTPUT);

  pinMode(Mot2A, OUTPUT);
  pinMode(Mot2B, OUTPUT); 
}

void loop() {
  analogWrite(Mot1A, Vel_Mot1);
  digitalWrite(Mot1B, LOW);

  analogWrite(Mot2A, Vel_Mot2);
  digitalWrite(Mot2B, LOW);

  delay(5000);

  digitalWrite(Mot1A, LOW);
  analogWrite(Mot1B, LOW);

  delay(500);

 digitalWrite(Mot1A, Vel_Mot1);
 analogWrite(Mot1B, LOW);

 delay(2500);

 digitalWrite(Mot1A, LOW);
 analogWrite(Mot1B, LOW);

 delay(500);
}
