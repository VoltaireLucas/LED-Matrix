#include "Matrix.h"

void setup() 
{
  // Set up Row IC
  pinMode(DATA_164, OUTPUT);
  pinMode(CLK_164, OUTPUT);

  // Set up Column IC
  pinMode(CLK1_574, OUTPUT);
  for (int i{0}; i < 5; i++)
  {
    pinMode(COLUMNS[i], OUTPUT);
    digitalWrite(COLUMNS[i], LOW);
  }
  clock1_574();

  for (int i{0}; i < 3; i++)
  {
    digitalWrite(DATA_164, HIGH);
    clock_164();
  }
}

int i = 0;
void loop() 
{
  if (i % 3 == 0)
  {
    digitalWrite(DATA_164, LOW);
  } else {
    digitalWrite(DATA_164, HIGH);
  }

  clock_164();
  delay(500);
  i++;
}

void clock_164()
{
  digitalWrite(CLK_164, HIGH);
  digitalWrite(CLK_164, LOW);
}

void clock1_574()
{
  digitalWrite(CLK1_574, HIGH);
  digitalWrite(CLK1_574, LOW);
}
