//  input = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26 }
//          { #  (  s  v  ,  s  v  )  ,  #  (   s   v   ,   s   v   )   ,   #   (   s   v   ,   s   v   )   \n }

uint8_t r_vel[3][2] = {0, 0, 0, 0, 0, 0};

void getVelocities(uint8_t n[])
{
  for (uint8_t j = 0; j < 3; j++)
  {
    for (uint8_t i = 0; i < 2; i++)
    {
      r_vel[j][i] = n[3 + 9 * j + 3 * i];
    }
  }
}

void makeOutput(uint8_t logica[], uint8_t output[])
{
  output[0] = 255;
  output[1] = logica[0];
  output[2] = r_vel[0][0];
  output[3] = r_vel[0][1];
  output[4] = logica[1];
  output[5] = r_vel[1][0];
  output[6] = r_vel[1][1];
  output[7] = logica[2];
  output[8] = r_vel[2][0];
  output[9] = r_vel[2][1];
}
