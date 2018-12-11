/******************************************************************************
** Program Filename: menu.h
** Author: Ben Johnson
** Date: April 30, 2018
** Description: pizza ordering site, terminal based.
** Inpupt: data read in from premade file and user input.
** Output: results printed to file or terminal depending on user's choice.
******************************************************************************/

#ifndef MENU
#define MENU

#include <iostream>

using namespace std;

class Menu {

  private:

    int num_pizzas;
    Pizza* pizzas;

  public:

    void search_pizza_by_cost(int upper_bound, string size);
    void search_pizza_by_ingredients_to_include(string* ingredients, int num_ingredients);
    void search_pizza_by_ingredients_to_exclude(string* ingredients, int num_ingredients);

    void set_from_file();
    void find_num_pizzas();
    void print_refined_menu();

    //constructors
    Menu();
    ~Menu();
    Menu(const Menu &copy);
    const Menu& operator=(const Menu &copy);

    //getters
    const int get_num_pizzas();
    const Pizza* get_pizzas();

    //setters
    void set_num_pizzas(int num_pizzas);
    void set_pizzas(Pizza* pizzas);

};

#endif
