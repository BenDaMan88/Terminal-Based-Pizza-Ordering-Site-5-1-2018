/******************************************************************************
** Program Filename: pizza.h
** Author: Ben Johnson
** Date: April 30, 2018
** Description: pizza ordering site, terminal based.
** Inpupt: data read in from premade file and user input.
** Output: results printed to file or terminal depending on user's choice.
******************************************************************************/

#ifndef PIZZA
#define PIZZA

#include <iostream>

using namespace std;

class Pizza {

  private:

    string name;
    int small_cost;
    int medium_cost;
    int large_cost;
    int num_ingredients;
    string* ingredients;

  public:

    Pizza();
    ~Pizza();
    Pizza(const Pizza &copy);
    const Pizza& operator=(const Pizza &copy);

    //getters
    const string get_name();
    const int get_small_cost();
    const int get_medium_cost();
    const int get_large_cost();
    const int get_num_ingredients();
    const string* get_ingredients();

    //setters
    void set_name(string name);
    void set_small_cost(int small_cost);
    void set_medium_cost(int medium_cost);
    void set_large_cost(int large_cost);
    void set_num_ingredients(int num);
    void set_ingredients(string* ingredients);

};

#endif
