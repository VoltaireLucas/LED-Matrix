#include "Matrix.h"

int X[3][3] = 
{
  {1,0,1},
  {0,1,0},
  {1,0,1}
};

Matrix matrix(3,3);

void setup() 
{
  matrix.SetUp();

  // All columns LOW
  for (int i{0}; i < 3; i++)
  {
    digitalWrite(COLUMNS[i], LOW);
  }
}

void loop() 
{
  matrix.test();
  delay(5);
}

