/******************************************************************************
** Program Filename: Restaurant.cpp
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
#include <fstream>
#include <string>
#include <cmath>

using namespace std;

/******************************************************************************
** Function: Restaurant
** Description: constructor
** Parameters: None.
** Pre-Conditions: None
** Post-Conditions: Restaurant is made.
******************************************************************************/
Restaurant::Restaurant()
{
  employees = NULL;
  num_employees = 0;
  week = NULL;
  num_days = 0;
  name = "";
  phone = "";
  address = "";
  menu = Menu();
}

/******************************************************************************
** Function: Deconstructor
** Description: deltes obkect
** Parameters: None.
** Pre-Conditions: None
** Post-Conditions: Restaurant has been deleted.
******************************************************************************/
Restaurant::~Restaurant()
{
  delete [] employees;
  employees = NULL;
  delete [] week;
  week = NULL;
}

/******************************************************************************
** Function: Copy Constructor
** Description: creates a pizza ordering site.
** Parameters: const Restaurant &copy
** Pre-Conditions: None
** Post-Conditions: copy has been made.
******************************************************************************/
Restaurant::Restaurant(const Restaurant &copy)
{
  name = copy.name;
  phone = copy.phone;
  address = copy.address;
  menu = copy.menu;
  num_days = copy.num_days;
  num_employees = copy.num_employees;
  if(num_days == 0)
    week = NULL;
  else
  {
    week = new hours[num_days];
    for(int i = 0; i < num_days; i++)
    {
      week[i] = copy.week[i];
    }
  }
  if(num_employees == 0)
    employees = NULL;
  else
  {
    employees = new employee[num_employees];
    for(int i = 0; i < num_employees; i++)
    {
      employees[i] = copy.employees[i];
    }
  }
}

/******************************************************************************
** Function: AOO
** Description: creates a pizza ordering site.
** Parameters: const Restaurant &copy
** Pre-Conditions: None
** Post-Conditions: left has been populated.
******************************************************************************/
const Restaurant& Restaurant::operator=(const Restaurant &copy)
{
  name = copy.name;
  phone = copy.phone;
  address = copy.address;
  menu = copy.menu;
  num_days = copy.num_days;
  num_employees = copy.num_employees;
  if(week != NULL) delete [] week;
  if(num_days == 0) week = NULL;
  else
  {
    week = new hours[num_days];
    for(int i = 0; i < num_days; i++)
    {
      week[i] = copy.week[i];
    }
  }
  if(employees != NULL) delete [] employees;
  if(num_employees == 0) employees = NULL;
  else
  {
    employees = new employee[num_employees];
    for(int i = 0; i < num_employees; i++)
    {
      employees[i] = copy.employees[i];
    }
  }
  return *this;
}

/******************************************************************************
** Function: Load Data
** Description: reads from files to correctly populate menu, employees, hours.
** Parameters: None.
** Pre-Conditions: None
** Post-Conditions: Tdata has been loaded.
******************************************************************************/
void Restaurant::load_data()
{
  set_restaurant_info();
  num_employees = find_num_employees();
  employees = new employee[num_employees];
  ifstream file("employee.txt");
  for(int i = 0; i < num_employees; i++)
  {
    file >> employees[i].id >> employees[i].first_name
         >> employees[i].last_name >> employees[i].password;
  }
  menu.set_from_file();
}

/******************************************************************************
** Function: Set Restaurant Info
** Description: creates a pizza ordering site.
** Parameters: None.
** Pre-Conditions: None
** Post-Conditions: restaurant_info has been loaded.
*****************************************************************************/
void Restaurant::set_restaurant_info()
{
  ifstream res_info("restaurant_info.txt");
  getline(res_info, name);
  getline(res_info, phone);
  getline(res_info, address);
  res_info >> num_days;
  if(week != NULL) delete [] week;
  week = new hours[num_days];
  for (int i = 0; i < num_days; i++)
  {
    res_info >> week[i].day >> week[i].open_hour >> week[i].close_hour;
  }
  res_info.close();
}

/******************************************************************************
** Function: View Menu
** Description: prints menu.
** Parameters: None.
** Pre-Conditions: None
** Post-Conditions: Menu printed.
******************************************************************************/
void Restaurant::view_menu()
{
  cout << "\nMenu: " << endl;
  for (int i = 0; i < menu.get_num_pizzas(); i++)
  {
    Pizza p = menu.get_pizzas()[i];
    cout << i+1 << ". " <<p.get_name() <<" "<< p.get_small_cost()
      <<" "<< p.get_medium_cost()
      <<" "<< p.get_large_cost() <<" "<<p.get_num_ingredients()<<" ";
      for(int j = 0; j < p.get_num_ingredients(); j++)
      {
        cout << p.get_ingredients()[j] << " ";
      }
      cout << endl;
  }
}

/******************************************************************************
** Function: View Hours 
** Description: prints hours.
** Parameters: None.
** Pre-Conditions: None
** Post-Conditions: hours printed.
******************************************************************************/
void Restaurant::view_hours()
{
  cout << "\nHours: " << endl;
  for(int i = 0; i < num_days; i++)
  {
    cout << week[i].day << " " << week[i].open_hour << " " <<
    week[i].close_hour << endl;
  }
  cout << endl;
}

/******************************************************************************
** Function: View Address
** Description: prints address
** Parameters: None.
** Pre-Conditions: None
** Post-Conditions: address printed.
******************************************************************************/
void Restaurant::view_address()
{
  cout << "\nAddress: " << address << endl;
}

/******************************************************************************
** Function: View Phone
** Description: prints phone.
** Parameters: None.
** Pre-Conditions: None
** Post-Conditions: phone printed.
******************************************************************************/
void Restaurant::view_phone()
{
  cout << "\nPhone Number: " << phone << endl;
}

/******************************************************************************
** Function: is_pos_int
** Description: check if int
** Parameters: stirng input.
** Pre-Conditions: None
** Post-Conditions: None.
******************************************************************************/
bool Restaurant::is_pos_int(string input)
{
  if(input.length() == 0 || (input.length() == 1 && (input[0] < '1' || input[0] > '9')))
    return false;
  int counter = 0;
  for(int i = 0; i < input.length(); i++)
  {
    if(input[i] < '0' || input[i] > '9')
      return false;
    if(input[i] == '0')
      counter++;
  }
  if(counter == input.length())
    return false;
  return true;
}

/******************************************************************************
** Function: Get int
** Description: make it int.
** Parameters: string int.
** Pre-Conditions: None
** Post-Conditions: int converted.
******************************************************************************/
int Restaurant::get_int(string input)
{
  int total = 0;
  for(int i = 0; i < input.length(); i++)
  {
      total += (int(input[i]) - 48) * pow(10, input.length() - i -1);
  }
  return total;
}

/******************************************************************************
** Function: search_by_ingredients
** Description: creates a pizza ordering site.
** Parameters: None.
** Pre-Conditions: None
** Post-Conditions: The pizza ordering site has been made.
******************************************************************************/
void Restaurant::get_ingredients_info(string&num,string*&ingredients,int&num_ingredients)
{
  cout << "How many ingredients do you want to search for? ";
  getline(cin, num);
  while(!is_pos_int(num))
  {
    cout << "Thats not a valid number. Enter a number: ";
    getline(cin, num);
  }
  num_ingredients = get_int(num);
  ingredients = new string[num_ingredients];
  for(int i = 0; i < num_ingredients; i++)
  {
    cout << "Give me the name of ingredient number " << i+1 << ": ";
    getline(cin, ingredients[i]);
  }
}

/******************************************************************************
** Function: search_by_ingredients
** Description: creates a pizza ordering site.
** Parameters: None.
** Pre-Conditions: None
** Post-Conditions: The pizza ordering site has been made.
******************************************************************************/
void Restaurant::search_by_ingredients()
{
  int num_ingredients = 0;  Menu temp = menu;
  string num = "", choice = "", choice2 = ""; string* ingredients;
  get_ingredients_info(num, ingredients, num_ingredients);
  temp.search_pizza_by_ingredients_to_include(ingredients, num_ingredients);
  temp.print_refined_menu();
  cout << "\nDo you also want to search for ingredients to exclude? (Y)-Yes (N)-No: ";
  getline(cin, choice);
  while(choice != "Y" && choice != "N")
  {
    cout << "Invalid input. Enter valid input: "; getline(cin, choice);
  }
  if(choice == "Y")
  {
    delete [] ingredients; get_ingredients_info(num, ingredients, num_ingredients);
    temp.search_pizza_by_ingredients_to_exclude(ingredients, num_ingredients);
    temp.print_refined_menu();
  }
  cout << "Do you want to place an order based on this search? (Y)-Yes (N)-No: ";
  getline(cin, choice2);
  while(choice2 != "N" && choice2 != "Y")
  {
    cout << "Invalid input. Give valid input: "; getline(cin, choice2);
  }
  if(choice2 == "Y")
    place_order(temp);
  delete [] ingredients;
}

/******************************************************************************
** Function: search_menu_by_price
** Description: restricts menu from input.
** Parameters: None.
** Pre-Conditions: None
** Post-Conditions: menu has been constricted.
******************************************************************************/
void Restaurant::search_menu_by_price()
{
  string size = "", input = "", choice = "";
  cout << endl;
  while(size!="S" && size!="s" && size!="M" && size!="m" && size!="L" && size!="l")
  {
    cout << "What size pizza do you want to search by? ";
    getline(cin, size);
  }
  cout << endl;
  while(!is_pos_int(input))
  {
    cout << "What is the upper bound price to search by? ";
    getline(cin, input);
  }
  int num = get_int(input);
  Menu temp = menu;
  temp.search_pizza_by_cost(num, size);
  temp.print_refined_menu();
  cout << "Do you want to place an order based on this search? (Y)-Yes (N)-No: ";
  getline(cin, choice);
  while(choice != "N" && choice != "Y")
  {
    cout << "Invalid input. Give valid input: ";
    getline(cin, choice);
  }
  if(choice == "Y")
    place_order(temp);
}

/******************************************************************************
** Function: Login
** Description: log employee in.
** Parameters: None.
** Pre-Conditions: None
** Post-Conditions: employee logged in or quited.
******************************************************************************/
bool Restaurant::login(int &i)
{
  string id, password;
  bool flag = false, pass_flag = false, quit = false;
  cout << endl;
  while(!flag)
  {
    cout << "Enter your employee ID: ";
    i = 0;
    getline(cin, id);
    for(i; i < num_employees; i++)
    {
      if(id == employees[i].id)
      {
        flag = true;
        break;
      }
    }
  }
  cout << endl;
  while(!pass_flag && !quit)
  {
    cout << "Enter your password or enter \"Q\" to quit: ";
    getline(cin, password);
    if(password == "Q" || password == "q") quit = true;
    if(password == employees[i].password) pass_flag = true;
  }
  if(quit) return false;
  return true;
}

/******************************************************************************
** Function: View Orders
** Description: prints orders.
** Pre-Conditions: None
** Post-Conditions: orders printed.
******************************************************************************/
void Restaurant::view_orders()
{
  ifstream file("orders.txt");
  string temp;
  cout << "\nOrders: \n" << endl;
  while(!file.eof())
  {
    getline(file, temp);
    if(temp.length() > 2)
      cout << temp << endl;
  }
  cout << endl;
}

/******************************************************************************
** Function: Is pizza
** Description: checks if valid pizza name.
** Parameters: string input.
** Pre-Conditions: None
** Post-Conditions: pizza is valid or not.
******************************************************************************/
bool Restaurant::is_pizza(string input)
{
  for(int i = 0; i < menu.get_num_pizzas(); i++)
  {
    Pizza p = menu.get_pizzas()[i];
    if(input == p.get_name())
      return true;
  }
  return false;
}

/******************************************************************************
** Function: Is pizza
** Description: checks if valid pizza name.
** Parameters: string input., Menu &menu
** Pre-Conditions: None
** Post-Conditions: pizza is valid or not.
******************************************************************************/
bool Restaurant::is_pizza(string input, Menu &menu)
{
  for(int i = 0; i < menu.get_num_pizzas(); i++)
  {
    Pizza p = menu.get_pizzas()[i];
    if(input == p.get_name() && input != "")
      return true;
  }
  return false;
}

/******************************************************************************
** Function: Place Order
** Description: places order.
** Parameters: None.
** Pre-Conditions: None
** Post-Conditions: The pizza ordering site has been made.
******************************************************************************/
void Restaurant::place_order_info(string&name,string&size,string&num)
{
  cout << "What is the name of the pizza you would like to order? ";
  getline(cin, name);
  while(!is_pizza(name))
  {
    cout << "Sorry, that is not a pizza we can make." << endl;
    cout << "Please give the name of a pizza on our menu: ";
    getline(cin, name);
  }
  cout << "What is the size of pizza you want to order? "; getline(cin, size);
  while(size!="S"&&size!="s"&&size!="M"&&size!="m"&&size!="L"&&size!="l")
  {
    cout << "Invalid size. Give me a valid size: "; getline(cin, size);
  }
  cout << "How many of these pizzas do you want? "; getline(cin, num);
  while(!is_pos_int(num))
  {
    cout << "Thats not a positive number. Give me a valid number of pizzas: ";
    getline(cin, num);
  }
}

/******************************************************************************
** Function: Place Order
** Description: places order.
** Parameters: None.
** Pre-Conditions: None
** Post-Conditions: The pizza ordering site has been made.
******************************************************************************/
void Restaurant::place_order()
{
  string name = "", size = "", temp = "", num = "", cname, cc, address, phone;
  int count = 0;
  ifstream in("orders.txt"); ofstream out("temp.txt");
  while(!in.eof())
  {
    getline(in, temp);
    if(temp.length() > 2)
    {
      count++; out << temp << endl;
    }
  }
  place_order_info(name, size, num);
  cout << "What is the name for the order? "; getline(cin, cname);
  cout << "What is you credit card number? "; getline(cin, cc);
  cout << "What is your address? "; getline(cin, address);
  cout << "What is you phone number? "; getline(cin, phone);
  out << count + 1 <<" "<<  cname <<" "<< cc <<" "<< address <<" "<< phone
      <<" "<<  name <<" "<< size <<" "<< num <<" "<< endl;
  in.close(); out.close();
  remove("orders.txt"); rename("temp.txt", "orders.txt");
  cout << "\nYou Successfully placed your order!" << endl;
}

/******************************************************************************
** Function: Place Order
** Description: places order
** Parameters: None.
** Pre-Conditions: None
** Post-Conditions: The pizza ordering site has been made.
******************************************************************************/
void Restaurant::place_order(Menu &menu)
{
  string name = "", size = "", temp = "", num = "", cname, cc, address, phone;
  int count = 0;
  ifstream in("orders.txt"); ofstream out("temp.txt");
  while(!in.eof())
  {
    getline(in, temp);
    if(temp.length() > 2)
    {
      count++;
      out << temp << endl;
    }
  }
  place_order_info(name, size, num);
  cout << "What is the name for the order? "; getline(cin, cname);
  cout << "What is you credit card number? "; getline(cin, cc);
  cout << "What is your address? "; getline(cin, address);
  cout << "What is you phone number? "; getline(cin, phone);
  out << count + 1 <<" "<<  cname <<" "<< cc <<" "<< address <<" "<< phone
      <<" "<<  name <<" "<< size <<" "<< num <<" "<< endl;
  in.close(); out.close();
  remove("orders.txt"); rename("temp.txt", "orders.txt");
  cout << "\nYou Successfully placed your order!" << endl;
}

/******************************************************************************
** Function: Get menu info
** Description: get info from user.
** Parameters: None.
** Pre-Conditions: None
** Post-Conditions: info loaded.
******************************************************************************/
void Restaurant::get_menu_info(string&name, string&s, string&m, string&l, string&n)
{
  cout << "Give me the name of the pizza: ";
  getline(cin, name);
  while(!is_pos_int(s))
  {
    cout << "Give me the price for a small pizza: ";
    getline(cin, s);
  }
  while(!is_pos_int(m))
  {
    cout << "Give me the price for a medium pizza: ";
    getline(cin, m);
  }
  while(!is_pos_int(l))
  {
    cout << "Give me the price for a large pizza: ";
    getline(cin, l);
  }
  while(!is_pos_int(n))
  {
    cout << "Give me the number of ingredients: ";
    getline(cin, n);
  }
}

/******************************************************************************
** Function: Add To Menu
** Description: adds item to menu.
** Parameters: None.
** Pre-Conditions: None
** Post-Conditions: menu item added.
******************************************************************************/
void Restaurant::add_to_menu()
{
  string name, s, m, l, n, temp;
  int small, medium, large, num;
  string* ingredients;
  get_menu_info(name, s, m, l, n);
  small = get_int(s); medium = get_int(m); large = get_int(l); num = get_int(n);
  ingredients = new string[num];
  for(int i = 0; i < num; i++)
  {
    cout << "Give me the name for ingredient " << i+1 << ": ";
    getline(cin, ingredients[i]);
  }
  ifstream in("menu.txt"); ofstream out("temp.txt");
  while(!in.eof())
  {
    getline(in, temp);
    if(temp.length() > 2)
      out << temp << endl;
  }
  out << name <<" "<< small <<" "<< medium <<" "<< large <<" "<< num <<" ";
  for(int i = 0; i < num; i++){out << ingredients[i] << " ";}
  in.close(); out.close();
  remove("menu.txt"); rename("temp.txt", "menu.txt");
  Menu temp_menu; temp_menu.set_from_file();
  menu = temp_menu; delete [] ingredients;
}

/******************************************************************************
** Function: Remove Orders
** Description: deletes user inputed order.
** Parameters: None.
** Pre-Conditions: None
** Post-Conditions: order has been deleted.
******************************************************************************/
void Restaurant::remove_orders()
{
  view_orders();
  string input, temp;
  int num, count = 0, old_num;
  cout << "\nGive me the number of the order you want to remove: ";
  getline(cin, input);
  while(!is_pos_int(input))
  {
    cout << "Thats not a valid order number. Give me a valid number: ";
    getline(cin, input);
  }
  num = get_int(input);
  ifstream in("orders.txt"); ofstream out("temp.txt");
  while(!in.eof())
  {
    temp = ""; in >> old_num; getline(in, temp);
    if(temp.length() > 2 && old_num!=num) {count++;out<<count<<temp<<endl;}
  }
  in.close(); out.close();
  remove("orders.txt"); rename("temp.txt", "orders.txt");
  cout << "\nYou successfully remove order number " << num << "!" << endl;
}

/******************************************************************************
** Function: Remove From Menu
** Description: removes one item from menu.
** Parameters: None.
** Pre-Conditions: None
** Post-Conditions: item has been removed.
******************************************************************************/
void Restaurant::remove_from_menu()
{
  view_menu();
  string input, temp, name;
  cout << "\nGive me the name of the menu item you want to remove: ";
  getline(cin, input);
  ifstream in("menu.txt");
  ofstream out("temp.txt");
  while(!in.eof())
  {
    in >> name;
    getline(in, temp);
    if(temp.length() > 2 && name != input)
    {
      out << name << temp << endl;
    }
  }
  in.close();
  out.close();
  remove("menu.txt");
  rename("temp.txt", "menu.txt");
  cout << "You successfully removed the pizza " << input << endl;
  Menu temp_menu;
  temp_menu.set_from_file();
  menu = temp_menu;
  view_menu();
}

/******************************************************************************
** Function: Get Change Hours Info
** Description: changes store hour/ get input.
** Parameters: None.
** Pre-Conditions: None
** Post-Conditions: input gotten.
******************************************************************************/
void Restaurant::get_change_hour_info(string &day, string &open, string &close)
{
  cout << "Which day would you like to change the hours for? ";
  getline(cin, day);
  while(day!="S"&&day!="M"&&day!="T"&&day!="W"&&day!="R"&&day!="F")
  {
    cout << "Thats not a day. Enter a day: ";
    getline(cin, day);
  }
  cout << "What should the opening time be? ";
  getline(cin, open);
  while(!is_pos_int(open))
  {
    cout << "Thats not an hour. Give me an hour: ";
    getline(cin, open);
  }
  cout << "What should the closing time be? ";
  getline(cin, close);
  while(!is_pos_int(close))
  {
    cout << "Thats not an hour. Give me an hour: ";
    getline(cin, close);
  }
}

/******************************************************************************
** Function: Change Hours
** Description: changes store hour.
** Parameters: None.
** Pre-Conditions: None
** Post-Conditions: hours changed
******************************************************************************/
void Restaurant::change_hours()
{
  string day, open, close, temp, d, o, c;
  ifstream in("restaurant_info.txt");
  ofstream out("temp.txt");
  get_change_hour_info(day, open, close);
  for(int i = 0; i < 4; i++)
  {
    getline(in, temp);
    out << temp << endl;
  }
  for(int i = 0; i < num_days; i++)
  {
    in >> d >> o >> c;
    if(d == day)
      out << d << " " << open << " " << close << endl;
    else
      out << d << " " << o << " " << c << endl;
  }
  in.close();
  out.close();
  remove("restaurant_info.txt");
  rename("temp.txt", "restaurant_info.txt");
  cout << "You successfully changed the hours!" << endl;
  set_restaurant_info();
}

/******************************************************************************
** Function: Find Number Employees
** Description: finds number of employees.
** Parameters: None.
** Pre-Conditions: None
** Post-Conditions: num employees returned.
******************************************************************************/
int Restaurant::find_num_employees()
{
  ifstream e_file("employee.txt");
  int counter = 0;
  string input;
  while(!e_file.eof())
  {
    getline(e_file, input);
    if(input.length() > 4)
      counter++;
  }
  e_file.close();
  return counter;
}

//setters
/******************************************************************************
** Function: Set Menu
** Description: sets parameters.
** Parameters: new input.
** Pre-Conditions: None
** Post-Conditions: menu set
******************************************************************************/
void Restaurant::set_menu(Menu menu)
{
  this->menu = menu;
}

/******************************************************************************
** Function: Set employee
** Description: sets parameters.
** Parameters: new input.
** Pre-Conditions: None
** Post-Conditions: employee set.
******************************************************************************/
void Restaurant::set_employees(employee* employees)
{
  delete [] this->employees;
  this->employees = employees;
}

/******************************************************************************
** Function: Set Week
** Description: sets parameters.
** Parameters: new input.
** Pre-Conditions: None
** Post-Conditions: Tweek set.
******************************************************************************/
void Restaurant::set_week(hours* hours)
{
  delete [] week;
  week = hours;
}

/******************************************************************************
** Function: Set Name
** Description: sets parameters.
** Parameters: new input.
** Pre-Conditions: None
** Post-Conditions: name set.
******************************************************************************/
void Restaurant::set_name(string name)
{
  this->name = name;
}

/******************************************************************************
** Function: Set phone
** Description: sets parameters.
** Parameters: new input.
** Pre-Conditions: None
** Post-Conditions: phone set.
******************************************************************************/
void Restaurant::set_phone(string phone)
{
  this->phone = phone;
}

/******************************************************************************
** Function: set Address
** Description: sets parameters.
** Parameters: new input.
** Pre-Conditions: None
** Post-Conditions: Address set.
******************************************************************************/
void Restaurant::set_address(string address)
{
  this->address = address;
}

/******************************************************************************
** Function: Set Num Days
** Description: sets parameters.
** Parameters: new input.
** Pre-Conditions: None
** Post-Conditions: num days set.
******************************************************************************/
void Restaurant::set_num_days(int num_days)
{
  this->num_days = num_days;
}

/******************************************************************************
** Function: Set Number Employee
** Description: sets parameters.
** Parameters: new input.
** Pre-Conditions: None
** Post-Conditions: num Employee set.
******************************************************************************/
void Restaurant::set_num_employees(int num_employees)
{
  this->num_employees = num_employees;
}

//getters
/******************************************************************************
** Function: get menu
** Description: Returns Parameter.
** Parameters: None.
** Pre-Conditions: None
** Post-Conditions: Menu returned.
******************************************************************************/
const Menu Restaurant::get_menu()
{
  return menu;
}

/******************************************************************************
** Function: Get Employee
** Description: Returns Parameter.
** Parameters: None.
** Pre-Conditions: None
** Post-Conditions: employee returned.
******************************************************************************/
const employee* Restaurant::get_employee()
{
  return employees;
}

/******************************************************************************
** Function: get week
** Description: Returns Parameter.
** Parameters: None.
** Pre-Conditions: None
** Post-Conditions: week returned
******************************************************************************/
const hours* Restaurant::get_week()
{
  return week;
}

/******************************************************************************
** Function: get name
** Description: Returns Parameter.
** Parameters: None.
** Pre-Conditions: None
** Post-Conditions: name returned
******************************************************************************/
const string Restaurant::get_name()
{
  return name;
}

/******************************************************************************
** Function: get phone.
** Description: Returns Parameter.
** Parameters: None.
** Pre-Conditions: None
** Post-Conditions: phone returned.
******************************************************************************/
const string Restaurant::get_phone()
{
  return phone;
}

/******************************************************************************
** Function: get address
** Description: Returns Parameter.
** Parameters: None.
** Pre-Conditions: None
** Post-Conditions: address returned
******************************************************************************/
const string Restaurant::get_address()
{
  return address;
}

/******************************************************************************
** Function: get num_days
** Description: Returns Parameter..
** Parameters: None.
** Pre-Conditions: None
** Post-Conditions: number days returned
******************************************************************************/
const int Restaurant::get_num_days()
{
  return num_days;
}

/******************************************************************************
** Function: get number employees
** Description: creates a pizza ordering site.
** Parameters: None.
** Pre-Conditions: None
** Post-Conditions: num employees returned
******************************************************************************/
const int Restaurant::get_num_employees()
{
  return num_employees;
}
