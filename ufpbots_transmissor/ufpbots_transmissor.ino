#include <SPI.h>
#include <RF24.h>
#include <nRF24L01.h>
#include <printf.h>

#include "logica.h"
#include "config.h"
#include "output.h"

// declare variables
RF24 radio(9, 10); //ce,csn pin
const uint64_t add1 = 0x0a0c0a0c0aLL;
uint8_t input_data[27];
char ascii_input[27];
uint8_t output[10];

void setup() {
  TransmitterConfiguration();
  Serial.begin(9600);
  radio.begin();
  printf_begin();
  radio.openWritingPipe(add1);
  radio.printDetails(); //check if there is an error appear when you try to connect nRF to arduino
  Serial.println("Transmitter initialized");
}

void loop() {
  //radio.write(msg, sizeof(msg));
}

void serialEvent()
{
  memset(input_data, ' ', sizeof(input_data));
  Serial.readBytesUntil('\n', input_data, sizeof(input_data));
  Serial.print("\nInput is: [[ ");
  for (uint8_t i = 0; i < 26; i++)
  {
    Serial.print(input_data[i]);
    ascii_input[i] = input_data[i];
    if (i < 25)
      Serial.print(", ");
    else
      Serial.println(" ]]");
  }

  Serial.print("Which is, in ASCII: ");
  Serial.println(ascii_input);
  getLogics(input_data);
  getVelocities(input_data);
  for (uint8_t j = 0; j < 4; j++)
  {
    if (j == 0)
    {
      Serial.println("\n#\tLogica\tV.Esq\tV.Dir");
    }
    else
    {
      for (uint8_t i = 0; i < 4; i++)
      {
        if (i == 0)
        {
          Serial.print("R");
          Serial.print(j);
          Serial.print("\t");
        }
        else if (i == 1)
        {
          Serial.print(logica[j - 1]);
          Serial.print("\t");
        }
        else
        {
          Serial.print(r_vel[j - 1][i - 2]);
          Serial.print("\t");
        }
      }
      Serial.print("\n");
    }
  }
  makeOutput(logica, output);
  radio.write(output, sizeof(output));
  Serial.print("\nSent:  [[ ");
  for (uint8_t i = 0; i < 10; i++)
  {
    Serial.print(output[i]);
    if (i < 9)
      Serial.print(", ");
    else
      Serial.println(" ]]");
  }
}
