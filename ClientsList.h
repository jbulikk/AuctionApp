#pragma once
#include <vector>
#include "ClientData.h"
#include <memory>


using namespace std;


class ClientsList
{
private:
	vector<shared_ptr<ClientData>> m_data;

public:
	ClientsList(void);


	void add_client(shared_ptr<ClientData>& client, string filename);
	void remove_client(string name, string filename);

	void show_clients(void);
	void get_data(string filename);
	shared_ptr<ClientData>& get_client(int i) { return m_data.at(i); }
	size_t get_data_size() { return m_data.size(); }
};