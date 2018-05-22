
/*----Tabela de logicas possiveis---------------------
  ------------------------------------------------------
	0:	0b00000000, STOP, Robo Parado
	12:	0b00001100, FRWD, Para Frente
	18:	0b00010010, BKWD, Para Tras
	20:	0b00010100, TRGT, Giro Hor�rio
	10:	0b00001010, TLFT, Giro Anti-Hor�rio
  ------------------------------------------------------
  ----------------------------------------------------*/

#define STOP 0    // Stop
#define FRWD 12   // Forwards
#define BKWD 18   // Backwards
#define TRGT 20   // Turn Right
#define TLFT 10   // Turn Left

uint8_t logica[3];

void getLogics(uint8_t n[])
{
  // Logicas para o robo ID 1
  if (n[2] == '+' && n[5] == '+')
    logica[0] = FRWD;
  else if (n[2] == '+' && n[5] == '-')
    logica[0] = TRGT;
  else if (n[2] == '-' && n[5] == '+')
    logica[0] = TLFT;
  else if (n[2] == '-' && n[5] == '-')
    logica[0] = BKWD;
  else
    logica[0] = STOP;

  // Logicas para o robo ID 2
  if (n[11] == '+' && n[14] == '+')
    logica[1] = FRWD;
  else if (n[11] == '+' && n[14] == '-')
    logica[1] = TRGT;
  else if (n[11] == '-' && n[14] == '+')
    logica[1] = TLFT;
  else if (n[11] == '-' && n[14] == '-')
    logica[1] = BKWD;
  else
    logica[1] = STOP;

  // Logicas para o robo ID 3
  if (n[20] == '+' && n[23] == '+')
    logica[2] = FRWD;
  else if (n[20] == '+' && n[23] == '-')
    logica[2] = TRGT;
  else if (n[20] == '-' && n[23] == '+')
    logica[2] = TLFT;
  else if (n[20] == '-' && n[23] == '-')
    logica[2] = BKWD;
  else
    logica[2] = STOP;
}





