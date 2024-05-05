//variáveis para funciomento do sensor ultrassônico
#include <NewPing.h>

#define TRIGGER_PIN   2 
#define ECHO_PIN      3 
#define MAX_DISTANCE 200 // (cm)

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

unsigned int pingSpeed = 50; // frequencia de leituras de distancia (ms)
unsigned long pingTimer;     // agenda a proxima leitura
int dist; 
int cont;
int mediaDist;

//===================================================================================

//variáveis para seguir as linhas

// Motor esquerdo:
#define MotE1 9
#define MotE2 10

// Motor direito:
#define MotD1 5
#define MotD2 6

#define PinInfraD 4
#define PinInfraE 12

int Vel= 142;
int Virar = 80;

//Variaveis para leitura
bool InfraD = 0;
bool InfraE = 0;

//===================================================================================


void setup() {
  Serial.begin(115200);


  //setup sensor ultrassônico
  pingTimer = millis(); 
  cont = 1;
  mediaDist = 0;

  //setup sensor segue linha 
  pinMode(PinInfraD, INPUT);
  pinMode(PinInfraE, INPUT);

  pinMode(MotE1, OUTPUT);
  pinMode(MotE2, OUTPUT);

  pinMode(MotD1, OUTPUT);
  pinMode(MotD2, OUTPUT);

  InfraD = digitalRead (PinInfraD);
  InfraE = digitalRead (PinInfraE);
}

void loop() {
  
    if (millis() >= pingTimer) {   // a cada 50ms executa o bloco
    pingTimer += pingSpeed;// agenda a proxima ativação
    sonar.ping_timer (echoCheck);
    mediaDist+=dist;
    cont++;
    
    if (cont == 5){ 
      Serial.print("media=");
      mediaDist = mediaDist/5;
      Serial.println(mediaDist);

      if (mediaDist<=20) 
       {

       //faz o clebi dar a volta no obstáculos 
       Serial.println("Tem um obstáculo aí ó");

       Quadrado();
      }
       mediaDist = 0;
       cont = 1;
       delay(80);
    }

  }

//===================================================================================

  //seguidor de linha
  
     InfraD = digitalRead (PinInfraD);
     InfraE = digitalRead (PinInfraE);
   
      if(InfraE == 0 && InfraD == 0)
        frente ();
      
      else if(InfraE == 0 && InfraD == 1) 
             direita ()

      else if(InfraE == 1 && InfraD == 0) 
             esquerda ();
      
      else //os dois InfraEs estao no preto, logo ele vai pra frente
        frente ();

}

//===================================================================================

//funcoes para o sensor ultrassônico

void Quadrado(){
  //Código do quadrado

       Serial.println("Inicia quadrado!!!");  

       direita ();
       delay (400);

       //Vai pra frente (olhando pra direita)
       frente();
       delay (700);

      //Virar pra esquerda
      esquerda();
      delay (400);

      //Vai pra frente (olhando pra esquerda)
      frente();
      delay (1000);

      //Virar pra esquerda
      esquerda();
      delay (400);

      while ( InfraD == 0 && InfraE ==0){

      //Vai pra frente (olhando pra esquerda)
      frente();

      InfraD = digitalRead (PinInfraD);
      InfraE = digitalRead (PinInfraE);
      }
     
       //delay pra reencontrar a linha
       delay(169);
       
       //Virar pra direita
       direita();
       delay(200);
}
     
//Função que o arduio deve realizar a cada 50ms para verificar se tem algum obstáculo a frente
void echoCheck() {
  if (sonar.check_timer()) {
      // pega a resultado e converte para cm (com uma constante chamada US_ROUNDTRIP_CM)
      dist = sonar.ping_result / US_ROUNDTRIP_CM; 
  }
}

//===================================================================================

//funcoes para o seguidor de linhas

void frente (){
  Serial.println("vai pra frente fi");
        analogWrite(MotE1, Vel);
        analogWrite(MotE2, LOW);
      
        analogWrite(MotD1, Vel);
        analogWrite(MotD2, LOW);
}

void direita () {
  Serial.println("Em direção a direita!!!");
        analogWrite(MotE1, Vel);
        analogWrite(MotE2, LOW);
      
        analogWrite(MotD1, LOW);
        analogWrite(MotD2, Virar);
}

void esquerda () {
  Serial.println("Em direção a esquerda!!!");
        analogWrite(MotE1, LOW);
        analogWrite(MotE2, Virar);
      
        analogWrite(MotD1, Vel);
        analogWrite(MotD2, LOW);
}