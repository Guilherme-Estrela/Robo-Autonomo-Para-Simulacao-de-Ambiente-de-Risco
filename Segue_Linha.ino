// Var:

// Motor esquerdo:
#define Mot1A 5
#define Mot1B 6

// Motor direito:
#define Mot2A 9
#define Mot2B 10

// Sensor Direita:
#define PinSensorCria 12

// Sensor Esquerdo:
#define PinSensorGab 4

// Velocidade Padrão:
int Vel = 240;

//Velocidade para curvas
int Virar = 115;

//Variavel para girar
int Girar = 110;

//Variaveis para leitura
bool SensorCria = 0;
bool SensorGab = 0;

// Setup:
void setup ()
{
pinMode(SensorCria, INPUT);
pinMode(SensorGab, INPUT);

pinMode (Mot1A, OUTPUT);
pinMode(Mot1B, OUTPUT);

pinMode(Mot2A, OUTPUT);
pinMode(Mot2B, OUTPUT);
}

// Loop:
void loop()
{
//Leitura dos pinos
  SensorCria = digitalRead (PinSensorCria);
  SensorGab = digitalRead (PinSensorGab);
  
// Situações Hipotéticas:

if((SensorCria == 1 && SensorGab == 1))

// Nesta hipótese, os dois sensores seguirão em linha reta.

{
analogWrite(Mot1A, Vel);
analogWrite(Mot1B, LOW);

analogWrite(Mot2A, Vel);
analogWrite(Mot2B, LOW);

// Logo, os dois motores deverão seguir linearmente, de forma contínua.

}

else if ((SensorCria == 1 && SensorGab == 0))

// Nesse caso, apenas o sensor da direita estará na linha (detectando).

{
analogWrite(Mot1A, Vel);
analogWrite(Mot1B, LOW);

analogWrite(Mot2A, LOW);
analogWrite(Mot2B, Virar);
// Assim, o Crebi irá executar a curva para direita.
}

else if ((SensorCria == 0 && SensorGab == 1))

// Aqui, somente o sensor da esquerda estará detectando a linha.

{
analogWrite(Mot1A, LOW);
analogWrite(Mot1B, Virar);

analogWrite(Mot2A, Vel);
analogWrite(Mot2B, LOW);

// Então, o Crebi virará em direção a esquerda.
}

else
//Caso nenhuma das sentenças anteriores seja verdadeira
{
analogWrite(Mot1A, Girar);
analogWrite(Mot1B, LOW);

analogWrite(Mot2A, LOW);
analogWrite(Mot2B, LOW);
}

}
