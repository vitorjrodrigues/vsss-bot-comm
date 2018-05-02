
#define MODE  2

int transmit_mode = 0;

void TransmitterConfiguration()
{
  pinMode(MODE, INPUT);
  transmit_mode = digitalRead(MODE);
}
