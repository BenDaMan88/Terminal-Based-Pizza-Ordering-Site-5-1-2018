/******************************************************************************
** Program Filename: Restaurant.h
** Author: Ben Johnson
** Date: April 30, 2018
** Description: pizza ordering site, terminal based.
** Inpupt: data read in from premade file and user input.
** Output: results printed to file or terminal depending on user's choice.
******************************************************************************/

#ifndef RESTAURANT
#define RESTAURANT

#include <iostream>

using namespace std;

class Restaurant {

  private:

    Menu menu;
    employee* employees;
    hours* week;
    int num_days;
    int num_employees;
    string name;
    string phone;
    string address;

  public:

    void load_data(); 
    bool login(int& i);
    void view_menu();
    void view_hours();
    void view_address();
    void view_phone();
    void search_menu_by_price();
    void search_by_ingredients();
    void place_order();
    void change_hours();
    void add_to_menu();
    void remove_from_menu();
    void view_orders();
    void remove_orders();

    int find_num_employees();
    bool is_pos_int(string input);
    int get_int(string input);
    bool is_pizza(string input);
    void set_restaurant_info();
    void place_order(Menu &menu);
    bool is_pizza(string input, Menu &menu);
    void get_change_hour_info(string &day, string &open, string &close);
    void get_menu_info(string&name, string&s, string&m, string&l, string&n);
    void get_ingredients_info(string&num,string*&ingredients,int&num_ingredients);
    void place_order_info(string&name,string&size,string&num);

    //setters
    void set_menu(Menu menu);
    void set_employees(employee* employees);
    void set_week(hours* hours);
    void set_name(string name);
    void set_phone(string phone);
    void set_address(string address);
    void set_num_days(int num_days);
    void set_num_employees(int num_employees);

    //getters
    const Menu get_menu();
    const employee* get_employee();
    const hours* get_week();
    const string get_name();
    const string get_phone();
    const string get_address();
    const int get_num_days();
    const int get_num_employees();

    Restaurant();
    ~Restaurant();
    Restaurant(const Restaurant &copy);
    const Restaurant& operator=(const Restaurant &copy);

};

#endif
