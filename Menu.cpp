/******************************************************************************
** Program Filename: menu.cpp
** Author: Ben Johnson
** Date: April 30, 2018
** Description: pizza ordering site, terminal based.
** Inpupt: data read in from premade file and user input.
** Output: results printed to file or terminal depending on user's choice.
******************************************************************************/

#include "Employee.h"
#include "Hours.h"
#include "Pizza.h"
#include "Menu.h"
#include <fstream>

using namespace std;

/******************************************************************************
** Function: Constructor
** Description: creates menu
** Parameters: None.
** Pre-Conditions: None
** Post-Conditions: menu constructored
******************************************************************************/
Menu::Menu()
{
  num_pizzas = 0;
  pizzas = NULL;
}

/******************************************************************************
** Function: Deconstructor
** Description: deletes menu.
** Parameters: None.
** Pre-Conditions: None
** Post-Conditions: menu deleted
******************************************************************************/
Menu::~Menu()
{
  delete [] pizzas;
}

/******************************************************************************
** Function: copy constructor
** Description: copy menu.
** Parameters: None.
** Pre-Conditions: None
** Post-Conditions: copy made.
******************************************************************************/
Menu::Menu(const Menu &copy)
{
  num_pizzas = copy.num_pizzas;
  if(num_pizzas == 0)
    pizzas = NULL;
  else
  {
    pizzas = new Pizza[num_pizzas];
    for(int i = 0; i < num_pizzas; i++)
    {
      pizzas[i] = copy.pizzas[i];
    }
  }
}

/******************************************************************************
** Function: AOO
** Description: overloads
** Parameters: None.
** Pre-Conditions: None
** Post-Conditions: menu assigned.
******************************************************************************/
const Menu& Menu::operator=(const Menu &copy)
{
  num_pizzas = copy.num_pizzas;
  if(pizzas != NULL)
    delete [] pizzas;
  if(num_pizzas == 0)
    pizzas = NULL;
  else
  {
    pizzas = new Pizza[num_pizzas];
    for(int i = 0; i < num_pizzas; i++)
    {
      pizzas[i] = copy.pizzas[i];
    }
  }
  return *this;
}

/******************************************************************************
** Function: search_pizza_by_ingredients_to_include
** Description: restricts menu.
** Parameters: string* ingredients, int num_ingredients
** Pre-Conditions: None
** Post-Conditions: menu restricted.
******************************************************************************/
void Menu::search_pizza_by_ingredients_to_include(string* ingredients, int num_ingredients)
{
  bool flag = false;
  for(int i = 0; i < num_pizzas; i++)
  {
    for(int j = 0; j < num_ingredients; j++)
    {
      for(int k = 0; k < pizzas[i].get_num_ingredients(); k++)
      {
        if(ingredients[j] == pizzas[i].get_ingredients()[k])
          flag = true;
      }
    }
    if(!flag)
      pizzas[i].set_name("");
    flag = false;
  }
}

/******************************************************************************
** Function: search_pizza_by_ingredients_to_exclude
** Description: restricts menu.
** Parameters: string* ingredients, int num_ingredients
** Pre-Conditions: None
** Post-Conditions: menu restricted.
******************************************************************************/
void Menu::search_pizza_by_ingredients_to_exclude(string* ingredients, int num_ingredients)
{
  bool flag = false;
  for(int i = 0; i < num_pizzas; i++)
  {
    for(int j = 0; j < num_ingredients; j++)
    {
      for(int k = 0; k < pizzas[i].get_num_ingredients(); k++)
      {
        if(ingredients[j] == pizzas[i].get_ingredients()[k])
          flag = true;
      }
    }
    if(flag)
      pizzas[i].set_name("");
    flag = false;
  }
}

/******************************************************************************
** Function: search_pizza_by_cost
** Description: restricts menu.
** Parameters: string* ingredients, int num_ingredients
** Pre-Conditions: None
** Post-Conditions: menu restricted.
******************************************************************************/
void Menu::search_pizza_by_cost(int upper_bound, string size)
{
  for(int i = 0; i < num_pizzas; i++)
  {
    if(size == "S" || size == "s")
    {
      if(upper_bound < pizzas[i].get_small_cost())
        pizzas[i].set_name("");
    }
    if(size == "M" || size == "m")
    {
      if(upper_bound < pizzas[i].get_medium_cost())
        pizzas[i].set_name("");
    }
    if(size == "L" || size == "l")
    {
      if(upper_bound < pizzas[i].get_large_cost())
        pizzas[i].set_name("");
    }
  }
}

/******************************************************************************
** Function: print_refined_menu
** Description: prints menu.
** Parameters: None.
** Pre-Conditions: None
** Post-Conditions: menu printed.
******************************************************************************/
void Menu::print_refined_menu()
{
  cout << endl;
  for(int i = 0; i < num_pizzas; i++)
  {
    if(pizzas[i].get_name() != "")
    {
      cout <<pizzas[i].get_name() <<" "<< pizzas[i].get_small_cost()
        <<" "<< pizzas[i].get_medium_cost() <<" "
        << pizzas[i].get_large_cost() <<" "<<pizzas[i].get_num_ingredients()<<" ";
        for(int j = 0; j < pizzas[i].get_num_ingredients(); j++)
        {
          cout << pizzas[i].get_ingredients()[j] << " ";
        }
        cout << endl;
    }
  }
  cout<< endl;
}

/******************************************************************************
** Function: set_from_file
** Description: loads data.
** Parameters: None.
** Pre-Conditions: None
** Post-Conditions: data loaded.
******************************************************************************/
void Menu::set_from_file()
{
  find_num_pizzas();
  pizzas = new Pizza[num_pizzas];
  ifstream file("menu.txt");
  string name;
  int small, medium, large, num;
  for(int i = 0; i < num_pizzas; i++)
  {
    file >> name >> small >> medium >> large >> num;
    pizzas[i].set_name(name);
    pizzas[i].set_small_cost(small);
    pizzas[i].set_medium_cost(medium);
    pizzas[i].set_large_cost(large);
    pizzas[i].set_num_ingredients(num);
    string* ingredients = new string[num];
    for(int j = 0; j < num; j++)
    {
      file >> ingredients[j];
    }
    pizzas[i].set_ingredients(ingredients);
  }
  file.close();
}

/******************************************************************************
** Function: find_num_pizzas
** Description: finds number pizzas
** Parameters: None.
** Pre-Conditions: None
** Post-Conditions: number pizzas found
******************************************************************************/
void Menu::find_num_pizzas()
{
  ifstream file("menu.txt");
  int counter = 0;
  string temp;
  while(!file.eof())
  {
    getline(file, temp);
    if(temp.length() > 4)
      counter++;
  }
  num_pizzas = counter;
  file.close();
}

//getters
/******************************************************************************
** Function: Get number Pizza
** Description: Getter Function.
** Parameters: None.
** Pre-Conditions: None
** Post-Conditions: num_pizzas returned
******************************************************************************/
const int Menu::get_num_pizzas()
{
  return num_pizzas;
}

/******************************************************************************
** Function: Get Pizza
** Description: Getter Function.
** Parameters: None.
** Pre-Conditions: None
** Post-Conditions: pizza returned
******************************************************************************/
const Pizza* Menu::get_pizzas()
{
  return pizzas;
}

//setters
/******************************************************************************
** Function: Set Num Pizzas 
** Description: Stter Function
** Parameters: int num_pizzas
** Pre-Conditions: None
** Post-Conditions: num_pizzas set.
******************************************************************************/
void Menu::set_num_pizzas(int num_pizzas)
{
  this->num_pizzas = num_pizzas;
}

/******************************************************************************
** Function: Set Pizza
** Description: setter function.
** Parameters: Pizza* pizza
** Pre-Conditions: None
** Post-Conditions: pizza set.
******************************************************************************/
void Menu::set_pizzas(Pizza* pizzas)
{
  delete [] this->pizzas;
  this->pizzas = pizzas;
}
