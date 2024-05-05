
#include <NewPing.h>

// Var:

//================================================================
//Variaveis para o seguidor de linha

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
// 130
int Virar = 115;

//Variavel para girar
int Girar = 110;

//Variaveis para leitura
bool SensorCria = 0;
bool SensorGab = 0;

//=================================================================================

//Variáveis para o funcionamento da biblioteca newping

#define TRIGGER_PIN  13  // Porta do arduino reservada para p trigger
#define ECHO_PIN     11  // Porta do arduino reservada para o echo
#define MAX_DISTANCE 200 // Distância maxima que o sensor mede

//Variáveis variaveis para identificar os obstáculos
int mediaDist;
#define LedSonico 1
//=================================================================================

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // NewPing setup of pins and maximum distance.

void setup() {
  Serial.begin(115200); // Open serial monitor at 115200 baud to see ping results.
  
  pinMode(SensorCria, INPUT);
  pinMode(SensorGab, INPUT);

  pinMode (Mot1A, OUTPUT);
  pinMode(Mot1B, OUTPUT);

  pinMode(Mot2A, OUTPUT);
  pinMode(Mot2B, OUTPUT);

  mediaDist = sonar.convert_cm(sonar.ping_median(5));
}

void loop() {
  //leiutura da distância do obstaculo
  delay(50); // espera 50ms

  // pega a distância e imprime no serial em cm
  Serial.print("Distância: ");
  Serial.print(mediaDist); 
  Serial.println("cm");

  //Se a distância for menor que 20 o robô vai dar meia volta e acendo um LED vermelho
  if (mediaDist<=20) 
  {
    //faz o clebi dar meia volta
    analogWrite(Mot1A, Vel);
    analogWrite(Mot1B, LOW);

    analogWrite(Mot2A, LOW);
    analogWrite(Mot2B, Virar);

    //Acende um LED vermelho
    digitalWrite (LedSonico, HIGH);

    //Imprime que tem um obstaculo na serial
    Serial.print("Tem um obstaculo aí ó");
    
  }
}
