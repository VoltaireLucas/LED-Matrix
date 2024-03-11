#include "Matrix.h"
#include "Arduino.h"


Matrix::Matrix(int rows, int columns) : rows(rows), columns(columns) {};

void Matrix::SetUp()
{
  // Set up Row IC
  pinMode(DATA_164, OUTPUT);
  pinMode(CLK_164, OUTPUT);

  // Set up Column IC, all Columns initially closed.
  pinMode(CLK1_574, OUTPUT);
  for (int i{0}; i < 5; i++)
  {
    pinMode(COLUMNS[i], OUTPUT);
    digitalWrite(COLUMNS[i], HIGH);
  }
  clock1_574();

  // Shift in 1s to all row outputs. All Rows initally closed.
  for (int i{0}; i < this->rows; i++)
  {
    digitalWrite(DATA_164, HIGH);
    clock_164();
  }

  delay(10);
}

void Matrix::displayNum(int num[][3]) 
{
  static int targetRow{0};

  if (targetRow >= this->rows)
  {
    targetRow = 0;
  }

  // Push a zero (ON) to the IC every 3 (number of rows) cycles
  if (targetRow % this->rows == 0)
  {
    digitalWrite(DATA_164, LOW); // Corresponding Row is ON
  } else 
  {
    digitalWrite(DATA_164, HIGH); // Corresponding Row is OFF
  }

  this->clock_164(); // Shift in the bit by clocking the IC
  // delay(5); // Wait after opening a row

  // Open or close a column
  for (int i{0}; i < this->columns; i++)
  {
    int state = num[targetRow][i]; 
    digitalWrite(COLUMNS[i], state);
  }

  this->clock1_574(); // Clock the Column IC to reflect inputs to the outputs.
  // delay(5); // Wait after opening the columns

  targetRow++; // Deal with the next row in the next iteration.
}


void Matrix::test()
{
  static int targetRow{0};

  if (targetRow >= this->rows)
  {
    targetRow = 0;
  }

  // Push a zero (ON) to the IC every 3 (number of rows) cycles
  if (targetRow % this->rows == 0)
  {
    digitalWrite(DATA_164, LOW); // Corresponding Row is ON

    digitalWrite(COLUMNS[0], LOW);
    digitalWrite(COLUMNS[1], HIGH);
    digitalWrite(COLUMNS[2], LOW);
  } else
  {
    digitalWrite(DATA_164, HIGH); // Corresponding Row is OFF
    if (targetRow % this->rows == 1)
    {
      digitalWrite(COLUMNS[0], HIGH);
      digitalWrite(COLUMNS[1], LOW);
      digitalWrite(COLUMNS[2], HIGH);
    } else if (targetRow % this->rows == 2)
    {
      digitalWrite(COLUMNS[0], LOW);
      digitalWrite(COLUMNS[1], HIGH);
      digitalWrite(COLUMNS[2], LOW);
    }
    
  }
  this->clock_164();
  this->clock1_574();

  targetRow++;
}

void Matrix::clock_164()
{
  digitalWrite(CLK_164, HIGH);
  digitalWrite(CLK_164, LOW);
}

void Matrix::clock1_574()
{
  digitalWrite(CLK1_574, HIGH);
  digitalWrite(CLK1_574, LOW);
}