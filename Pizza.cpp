/******************************************************************************
** Program Filename: pizza.cpp
** Author: Ben Johnson
** Date: April 30, 2018
** Description: pizza ordering site, terminal based.
** Inpupt: data read in from premade file and user input.
** Output: results printed to file or terminal depending on user's choice.
******************************************************************************/

#include "Employee.h"
#include "Hours.h"
#include "Pizza.h"

using namespace std;

/******************************************************************************
** Function: Constructor
** Description: cretas object.
** Parameters: None.
** Pre-Conditions: None
** Post-Conditions: Object created.
******************************************************************************/
Pizza::Pizza()
{
  name = "";
  small_cost = 0;
  medium_cost = 0;
  large_cost = 0;
  num_ingredients = 0;
  ingredients = NULL;
}

/******************************************************************************
** Function: Deconstructor
** Description: deletes object
** Parameters: None.
** Pre-Conditions: None
** Post-Conditions: object deleted
******************************************************************************/
Pizza::~Pizza()
{
  delete [] ingredients;
  ingredients = NULL;
}

/******************************************************************************
** Function: Copy constructor
** Description: copy made.
** Parameters: None.
** Pre-Conditions: None
** Post-Conditions: copy made.
******************************************************************************/
Pizza::Pizza(const Pizza &copy)
{
  name = copy.name;
  small_cost = copy.small_cost;
  medium_cost = copy.medium_cost;
  large_cost = copy.large_cost;
  num_ingredients = copy.num_ingredients;
  if(num_ingredients == 0)
    ingredients = NULL;
  else
  {
    ingredients = new string[num_ingredients];
    for(int i = 0; i < num_ingredients; i++)
    {
      ingredients[i] = copy.ingredients[i];
    }
  }
}

/******************************************************************************
** Function: AOO
** Description: make copy.
** Parameters: None.
** Pre-Conditions: None
** Post-Conditions: copy made.
******************************************************************************/
const Pizza& Pizza::operator=(const Pizza &copy)
{
  name = copy.name;
  small_cost = copy.small_cost;
  medium_cost = copy.medium_cost;
  large_cost = copy.large_cost;
  num_ingredients = copy.num_ingredients;
  if(ingredients != NULL)
    delete [] ingredients;
  if(num_ingredients == 0)
    ingredients = NULL;
  else
  {
    ingredients = new string[num_ingredients];
    for(int i = 0; i < num_ingredients; i++)
    {
      ingredients[i] = copy.ingredients[i];
    }
  }
  return *this;
}

//getters
/******************************************************************************
** Function: Get Name
** Description: Getter Function.
** Parameters: None.
** Pre-Conditions: None
** Post-Conditions: name returned.
******************************************************************************/
const string Pizza::get_name()
{
  return name;
}

/******************************************************************************
** Function: Get Small Cost
** Description: Getter Function.
** Parameters: None.
** Pre-Conditions: None
** Post-Conditions: small cost returned
******************************************************************************/
const int Pizza::get_small_cost()
{
  return small_cost;
}

/******************************************************************************
** Function: Get medium cost
** Description: Getter Function.
** Parameters: None.
** Pre-Conditions: None
** Post-Conditions: medium_cost returned
******************************************************************************/
const int Pizza::get_medium_cost()
{
  return medium_cost;
}

/******************************************************************************
** Function: Get large_cost
** Description: Getter Function.
** Parameters: None.
** Pre-Conditions: None
** Post-Conditions: large cost returned
******************************************************************************/
const int Pizza::get_large_cost()
{
  return large_cost;
}

/******************************************************************************
** Function: Get Number Ingredients
** Description: Getter Function.
** Parameters: None.
** Pre-Conditions: None
** Post-Conditions: Number Ingredients Returned.
******************************************************************************/
const int Pizza::get_num_ingredients()
{
  return num_ingredients;
}

/******************************************************************************
** Function: Get Ingredients
** Description: Getter Function.
** Parameters: None.
** Pre-Conditions: None
** Post-Conditions: ingredients got.
******************************************************************************/
const string* Pizza::get_ingredients()
{
  return ingredients;
}

//setters
/******************************************************************************
** Function: Set Name
** Description: Setter Function.
** Parameters: inpout.
** Pre-Conditions: None
** Post-Conditions: Name set
******************************************************************************/
void Pizza::set_name(string name)
{
  this->name = name;
}

/******************************************************************************
** Function: Ste small_cost
** Description: Setter Function.
** Parameters: inpout.
** Pre-Conditions: None
** Post-Conditions: small cost set
******************************************************************************/
void Pizza::set_small_cost(int small_cost)
{
  this->small_cost = small_cost;
}

/******************************************************************************
** Function: Set medium_cost
** Description: Setter Function.
** Parameters: inpout.
** Pre-Conditions: None
** Post-Conditions: medium_cost set
******************************************************************************/
void Pizza::set_medium_cost(int medium_cost)
{
  this->medium_cost = medium_cost;
}

/******************************************************************************
** Function: Set large_cost
** Description: Setter Function.
** Parameters: inpout.
** Pre-Conditions: None
** Post-Conditions: large cost set.
******************************************************************************/
void Pizza::set_large_cost(int large_cost)
{
  this->large_cost = large_cost;
}

/******************************************************************************
** Function: set num_ingredients
** Description: Setter Function.
** Parameters: inpout.
** Pre-Conditions: None
** Post-Conditions: num_ingredients set
******************************************************************************/
void Pizza::set_num_ingredients(int num)
{
  this->num_ingredients = num;
}

/******************************************************************************
** Function: set Ingredients
** Description: Setter Function.
** Parameters: inpout.
** Pre-Conditions: None
** Post-Conditions: ingredients set.
******************************************************************************/
void Pizza::set_ingredients(string* ingredients)
{
  delete [] this->ingredients;
  this->ingredients = ingredients;
}
