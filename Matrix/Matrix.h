#pragma once

#include "Arduino.h"

// Row IC Defines
#define DATA_164 3
#define CLK_164 A0

// Clocks for the column ICs
#define CLK1_574 A4

// Parallel Inputs of the column ICs
const int COLUMNS[5] 
{
  // Arduino Outputs for:
  4, // Column 1
  5, // Column 2
  6, // Column 3
  7, // Column 4
  8  // Column 5
};

class Matrix
{
public:
  Matrix(int rows, int columns);

  // Clock the ROW IC. The IC's make is SN74HC164N 
  void clock_164();
  
  // the COLUMN ICs' make is SN74HC574N
  void clock1_574();

  void displayRow(unsigned char* letter, int targetRow);
private:

  int _rows;
  int _columns;

};



