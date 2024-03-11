#pragma once

#include "Arduino.h"

#define ON LOW
#define OFF HIGH


// Row IC 
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

  // setup for all the pins.
  void SetUp();

  // Clock the ROW IC. The IC's make is SN74HC164N 
  void clock_164();
  
  // the COLUMN ICs' make is SN74HC574N
  void clock1_574();

  void displayNum(int num[][3]); // 3 is the number of columns.

  void test1();

  void displayLetter(unsigned char* letter);

private:
  int rows;
  int columns;
};



