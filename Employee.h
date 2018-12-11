/******************************************************************************
** Program Filename: Employee.h
** Author: Ben Johnson
** Date: April 30, 2018
** Description: pizza ordering site, terminal based.
** Inpupt: data read in from premade file and user input.
** Output: results printed to file or terminal depending on user's choice.
******************************************************************************/

#ifndef EMPLOYEE
#define EMPLOYEE

#include <iostream>

using namespace std;

struct employee {
  string id;
  string first_name;
  string last_name;
  string password;
};

#endif
