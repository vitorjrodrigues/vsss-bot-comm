#include <SPI.h>
#include <RF24.h>
#include <nRF24L01.h>
#include <printf.h>

#include "config.h"
#include "bridgemap.h"

// declare variables
RF24 radio(2, 3); //ce,cs pin
const uint64_t add1 = 0x0a0c0a0c0aLL;
uint8_t RECEBE[10];  // Variavel a receber a transmissao em RF
char i = 0;
boolean countStart = false;
int count = 0;

void setup() {
  //----- Define fisicamente o endereço do robô
  //pinMode(2,INPUT);//para robo 1
  //pinMode(3,INPUT);//para robo 2

  //----- Configura os pinos de PWM para a ponte H (ver bridgemap.h para definicao)
  setPWM();

  //----- Configura a serial para comunicação com o robô
  Serial.begin(9600);
  radio.begin();
  printf_begin();
  radio.openReadingPipe(1, add1);
  radio.startListening();

  //----- Configura os robos para iniciarem parados
  STOP();
}

void loop() {
  //----- Recebe configuracoes para modo de tranmissao e ID (ver config.h para definicao)
  //RecieverConfiguration();  // Desativado enquanto as entradas seletoras nao estiverem sendo usadas

  //----- Recebe sinal transmitido em RF se disponivel
  if (radio.available())
  {
    memset(RECEBE, ' ', sizeof(RECEBE));
    radio.read(RECEBE, sizeof(RECEBE));
    //----- Exibe o ID correspondente do robo e modo de operacao
    Serial.print("Hi, I am Robot ");
    Serial.println(robo_ID);
    Serial.print("Recieving data as ");
    if (transmit_mode == 0)
    {
      Serial.println("RF");
    }
    else
    {
      Serial.println("IR");
    }
    //----- Envia o valor recebido para a serial
    Serial.print("Recieved: [[ ");
    for (uint8_t i = 0; i < 10; i++)
    {
      Serial.print(RECEBE[i]);
      if (i < 9)
        Serial.print(", ");
      else
        Serial.println(" ]]\n");
    }
  }

  //---------------------------------------------------------------------
  //Laço para controle do robô
  //---------------------------------------------------------------------
  if (robo_ID > 0) // aqui vai ler o buffer do robo 1, 2 ou 3
  {
    //----- Case para as logicas correspondentes (ver bridgemap.h para referencia)
    //----- A posicao no vetor recebido a ser enviada depende do id do robo
    switch (RECEBE[(1 + 3 * (robo_ID - 1))]) {
      case 12: //robo recebe logica para ir pra frente - F
        FRWD(robo_ID, RECEBE);
        break;
      case 10: //robo recebe logica para girar AntiHorario - AH
        TLFT(robo_ID, RECEBE);
        break;
      case 20: //robo recebe logica para girar Horario - H
        TRGT(robo_ID, RECEBE);
        break;
      case 18: //robo recebe logica para ir pra tras - T
        BKWD(robo_ID, RECEBE);
        break;
      default: //Mantem o rob� parado
        STOP();
    }
  }
  else // aqui vai ler o buffer do robo 0 (robo 0 e padrao, significa que nenhum robo esta selecionado)
  {
    STOP();
  }
}
