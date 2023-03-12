#include "Sale.h"
#include <string>


using namespace std;

shared_ptr<Product> Sale::get_product(void) const { return m_product; }
shared_ptr<ClientData> Sale::get_clientData(void) const { return m_clientData; }



void Sale::set_product(shared_ptr<Product>& product) { m_product = product; }
void Sale::set_clientData(shared_ptr<ClientData>& clientData) { m_clientData = clientData; }

Sale::Sale(void) {}