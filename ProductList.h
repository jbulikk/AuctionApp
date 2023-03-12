#pragma once
#include "Product.h"
#include <vector>
#include <memory>

using namespace std;

class ProductList
{
private:
	vector<shared_ptr<Product>> m_data;

public:
	ProductList(void);

	bool conv_str_to_bool(string line);

	void add_product(shared_ptr<Product>& product, string filename);
	void remove_product(string name, string filename);
	void add_product2(string auction_code, string filename);
	void show_products(void);
	void get_data(string filename);
	shared_ptr<Product>& get_product(int i) { return m_data.at(i); }
	size_t get_data_size() { return m_data.size(); }
};