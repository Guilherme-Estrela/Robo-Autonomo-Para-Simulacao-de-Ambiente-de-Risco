// Var:

// "Mot" Significa: "Motor".

//Motor esquerda
#define Mot1A 5
#define Mot1B 6

//Motor direita
#define Mot2A 9
#define Mot2B 10

int Vel = 255;
int Curva = 150; 

void setup() {
  pinMode(Mot1A, OUTPUT);
  pinMode(Mot1B, OUTPUT);
  
  pinMode(Mot2A, OUTPUT);
  pinMode(Mot2B, OUTPUT); 
}

void loop() {

 //curva para direita por 2,5s
 analogWrite(Mot1A, Vel);
 analogWrite(Mot1B, LOW);

 analogWrite(Mot2A, Curva);
 analogWrite(Mot2B, LOW);

 delay(2200);

//curva para esquerda por 5s
 analogWrite(Mot1A, Curva);
 analogWrite(Mot1B, LOW);

 analogWrite(Mot2A, Vel);
 analogWrite(Mot2B, LOW);

 delay(6500);

 //coreçao de direçao
 analogWrite(Mot1A, Vel);
 analogWrite(Mot1B, LOW);

 analogWrite(Mot2A, LOW);
 analogWrite(Mot2B, LOW);

 delay (500);

//curva para direita por 2,5s
 analogWrite(Mot1A, Curva);
 analogWrite(Mot1B, LOW);

 analogWrite(Mot2A, Vel);
 analogWrite(Mot2B, LOW);

 delay(2500);

 //parar por 500ms
 analogWrite(Mot1A, LOW);
 analogWrite(Mot1B, LOW);

 analogWrite(Mot2A, LOW);
 analogWrite(Mot2B, LOW);

 delay (500);

 //fazer uma curva 90° para esquerda
 analogWrite(Mot1A, LOW);
 analogWrite(Mot1B, LOW);

 analogWrite(Mot2A, Vel);
 analogWrite(Mot2B, LOW);

 delay (800);
}
