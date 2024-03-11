#include "Matrix.h"

unsigned char X[3]
{
  0b00000101,
  0b00000010,
  0b00000101
};

unsigned char T[3]
{
  0b00000111,
  0b00000010,
  0b00000010
};

Matrix matrix(3,3);

void setup() 
{
  matrix.SetUp();
}

void loop() 
{
  matrix.displayLetter(T);
  delay(5);
}

