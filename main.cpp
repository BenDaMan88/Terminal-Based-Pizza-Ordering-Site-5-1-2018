/******************************************************************************
** Program Filename: main.cpp
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
#include "Restaurant.h"

using namespace std;

//functions
void start_program(Restaurant &pizza_shop);
const void print_info(Restaurant &pizza_shop);
void run_customer(Restaurant &pizza_shop);
void run_employee(Restaurant &pizza_shop, int i);
void print_customer_options();
void print_employee_options();

/******************************************************************************
** Function: Start Program
** Description: creates a pizza ordering site.
** Parameters: None.
** Pre-Conditions: None
** Post-Conditions: The pizza ordering site has been made.
******************************************************************************/
void start_program(Restaurant &pizza_shop)
{
  pizza_shop.load_data();
  string input = "";
  do{
    cout << "\nWelcome to " << pizza_shop.get_name() << "!" << endl;
    cout << "\nAre you a customer (C) or employee (E) or would you like to quit (Q)? ";
    getline(cin, input);
    if (input == "C" || input == "c")
      run_customer(pizza_shop);
    else if(input == "E" || input == "e")
    {
      int i = 0;
      if(pizza_shop.login(i))
        run_employee(pizza_shop, i);
    }
    else if(input != "Q" && input != "q")
      cout << "invalid input, please provide valid input. " << endl;
  }while (input != "Q" && input != "q");
  cout << endl;
}

/******************************************************************************
** Function: Run Customer
** Description: creates a pizza ordering site.
** Parameters: Restaurant &pizza_shop
** Pre-Conditions: Restaurant is made.
** Post-Conditions: The pizza ordering site has been made.
******************************************************************************/
void run_customer(Restaurant &pizza_shop)
{
  cout << "\nWelcome valued customer!" << endl;
  string input = "";
  while(input != "8")
  {
    print_customer_options();
    getline(cin, input);
    if(input == "1") pizza_shop.view_menu();
    if(input == "2") pizza_shop.search_menu_by_price();
    if(input == "3") pizza_shop.search_by_ingredients();
    if(input == "4") pizza_shop.place_order();
    if(input == "5") pizza_shop.view_hours();
    if(input == "6") pizza_shop.view_address();
    if(input == "7") pizza_shop.view_phone();
  }
}

/******************************************************************************
** Function: Print Customer Options
** Description: creates a pizza ordering site.
** Parameters: None.
** Pre-Conditions: None
** Post-Conditions: The pizza ordering site has been made.
******************************************************************************/
void print_customer_options()
{
  cout << "\nWhat would you like to do?\n" << endl;
  cout << "1. View Menu" << endl;
  cout << "2. Search by Cost" << endl;
  cout << "3. Search by Ingredients" << endl;
  cout << "4. Place Order" << endl;
  cout << "5. View Hours" << endl;
  cout << "6. View Address" << endl;
  cout << "7. View Phone" << endl;
  cout << "8. Log out" << endl;
  cout << "\nSelection: ";
}

/******************************************************************************
** Function: Run Employee
** Description: creates a pizza ordering site.
** Parameters: Restaurant &pizza_shop, int i
** Pre-Conditions: Restaurant is made.
** Post-Conditions: The pizza ordering site has been made.
******************************************************************************/
void run_employee(Restaurant &pizza_shop, int i)
{
  cout << "\nWelcome " << pizza_shop.get_employee()[i].first_name
       << " " << pizza_shop.get_employee()[i].last_name << "!" << endl;
  string input = "";
  while(input != "10")
  {
    print_employee_options();
    getline(cin, input);
    if(input == "1") pizza_shop.change_hours();
    if(input == "2") pizza_shop.view_orders();
    if(input == "3") pizza_shop.remove_orders();
    if(input == "4") pizza_shop.add_to_menu();
    if(input == "5") pizza_shop.remove_from_menu();
    if(input == "6") pizza_shop.view_menu();
    if(input == "7") pizza_shop.view_hours();
    if(input == "8") pizza_shop.view_address();
    if(input == "9") pizza_shop.view_phone();
  }
}

/******************************************************************************
** Function: Print Employee Options
** Description: creates a pizza ordering site.
** Parameters: None.
** Pre-Conditions: None
** Post-Conditions: The pizza ordering site has been made.
******************************************************************************/
void print_employee_options()
{
  cout << "\nWhat would you like to do?\n" << endl;
  cout << "1. Change Hours" << endl;
  cout << "2. View Orders" << endl;
  cout << "3. Remove Order" << endl;
  cout << "4. Add Item to Menu" << endl;
  cout << "5. Remove Item from Menu" << endl;
  cout << "6. View Menu" << endl;
  cout << "7. View Hours" << endl;
  cout << "8. View Address" << endl;
  cout << "9. View Phone" << endl;
  cout << "10. Log out" << endl;
  cout << "\nSelection: ";
}

/******************************************************************************
** Function: Main
** Description: creates a pizza ordering site.
** Parameters: None.
** Pre-Conditions: None
** Post-Conditions: The pizza ordering site has been made.
******************************************************************************/
int main()
{
  Restaurant pizza_shop;
  start_program(pizza_shop);

  return 0;
}
