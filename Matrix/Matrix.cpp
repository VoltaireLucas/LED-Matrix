#include "Matrix.h"
#include "Arduino.h"


Matrix::Matrix(int rows, int columns) : _rows(rows), _columns(columns) {};

// void displayRow(unsigned char* letter, int targetRow)
// {
//     for(int i{_columns+1}; i >=0; i--) 
//     {
//       int state = (letter[targetRow] >> i) & 1;
//       digitalWrite(COLUMNS[_columns - i], state);
//     }
// }


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