#pragma once
#include <string>

using namespace std;

class Product
{
private:
	string m_name;
	string m_price;
	string m_auction_number;


public:
	string get_auction_number(void) const;
	string get_name(void) const;
	string get_price(void) const;

	void set_auction_number(string auction_number);
	void set_name(string name);
	void set_price(string price);


	Product(void);
	Product(string auction_number, string name, string price);

	void sell_product(void);
	void return_product(void);
};
