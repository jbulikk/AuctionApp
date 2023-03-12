#pragma once
#include <string>
#include "Product.h"
#include "ClientData.h"
#include <memory>
#include <vector>
#include <fstream>
#include <stdio.h>


using namespace std;

class Sale : public ClientData
{
private:
	shared_ptr<Product> m_product;
	shared_ptr<ClientData> m_clientData;


public:
	shared_ptr<Product> get_product(void) const;
	shared_ptr<ClientData> get_clientData(void) const;


	void set_product(shared_ptr<Product>&);
	void set_clientData(shared_ptr<ClientData>&);


	Sale(void);

};