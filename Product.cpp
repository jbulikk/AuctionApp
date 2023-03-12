#include <string>
#include "Product.h"

using namespace std;

string Product::get_auction_number(void) const { return m_auction_number; }
string Product::get_name(void) const { return m_name; }
string Product::get_price(void) const { return m_price; }


void Product::set_auction_number(string auction_number) { m_auction_number = auction_number; }
void Product::set_name(string name) { m_name = name; }
void Product::set_price(string price) { m_price = price; }


Product::Product(void)
{
	m_auction_number = "";
	m_name = "";
	m_price = "";

}

Product::Product(string auction_number, string name, string price)
{
	m_auction_number = auction_number;
	m_name = name;
	m_price = price;

}

//methods
//void Product::sell_product(void) { m_sold = true; }
//void Product::return_product(void) { m_sold = false; }
