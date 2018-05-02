
#define ESQ_0	5		  // ESQ_0 is the positive PWM of the left wheel
#define ESQ_1	6		  // ESQ_1 is the negative PWM of the left wheel
#define DIR_0	9		  // DIR_0 is the positive PWM of the right wheel
#define	DIR_1	10		// DIR_1 is the negative pwm of the right wheel

void setPWM()
{
  pinMode(ESQ_0, OUTPUT); // set pins to output
  pinMode(ESQ_1, OUTPUT);
  pinMode(DIR_0, OUTPUT);
  pinMode(DIR_1, OUTPUT);
}

void STOP()
{
  //Controla Motor da Roda Esquerda
  analogWrite(ESQ_0, 0);
  analogWrite(ESQ_1, 0);
  //Controla Motor da Roda Direita
  analogWrite(DIR_0, 0);
  analogWrite(DIR_1, 0);
}

void FRWD(uint8_t ID, uint8_t DADOS[])
{
  //Controla Motor da Roda Esquerda
  analogWrite(ESQ_0, DADOS[(3 * ID - 1)]);
  analogWrite(ESQ_1, 0);
  //Controla Motor da Roda Direita
  analogWrite(DIR_0, DADOS[(3 * ID)]);
  analogWrite(DIR_1, 0);
}

void BKWD(uint8_t ID, uint8_t DADOS[])
{
  //Controla Motor da Roda Direita
  analogWrite(ESQ_0, 0);
  analogWrite(ESQ_1, DADOS[(3 * ID - 1)]);
  //Controla Motor da Roda Esquerda
  analogWrite(DIR_0, 0);
  analogWrite(DIR_1, DADOS[(3 * ID)]);
}


void TLFT(uint8_t ID, uint8_t DADOS[])
{
  //Controla Motor da Roda Esquerda
  analogWrite(ESQ_0, 0);
  analogWrite(ESQ_1, DADOS[(3 * ID - 1)]);
  //Controla Motor da Roda Direita
  analogWrite(DIR_0, DADOS[(3 * ID)]);
  analogWrite(DIR_1, 0);
}

void TRGT(uint8_t ID, uint8_t DADOS[])
{
  //Controla Motor da Roda Esquerda
  analogWrite(ESQ_0, DADOS[(3 * ID - 1)]);
  analogWrite(ESQ_1, 0);
  //Controla Motor da Roda Direita
  analogWrite(DIR_0, 0);
  analogWrite(DIR_1, DADOS[(3 * ID)]);
}





