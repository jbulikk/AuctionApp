#include "ClientsList.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <algorithm>

using namespace std;

ClientsList::ClientsList(void) {}

void ClientsList::add_client(shared_ptr<ClientData>& client, string filename)
{
	m_data.push_back(client);



	fstream file;
	file.open(filename, ios::app);
	if (file.is_open())
	{
		file << endl << client->get_name();
		file << endl << client->get_sname();
		file << endl << client->get_adress();
		file << endl << client->get_adress_number();
		file << endl << client->get_mail();
		file << endl << client->get_phone_number();


	}

	file.close();
}



void ClientsList::remove_client(string phone_number, string filename)
{

	auto it = remove_if(m_data.begin(), m_data.end(), [&](const shared_ptr<ClientData>& product) { return product->get_phone_number() == phone_number; });
	m_data.erase(it);

	ofstream file(filename);

	if (file.is_open())
	{
		for (auto v : m_data)
		{
			file << v->get_name() << endl;
			file << v->get_sname() << endl;
			file << v->get_adress() << endl;
			file << v->get_mail() << endl;
			file << v->get_phone_number() << endl;
		}
	}

	file.close();
}

void ClientsList::show_clients(void)
{
	for (int i = 0; i < m_data.size(); ++i)
	{
		cout << "\t\t" << i + 1 << ". " << "Imie:" << m_data[i]->get_name() << " Nazwisko: " << m_data[i]->get_sname() << " Numer:" << m_data[i]->get_phone_number() << endl;
	}
}


void ClientsList::get_data(string filename)
{
	fstream file(filename);
	string line;

	if (file.is_open() == true)
	{
		while (!file.eof())
		{
			shared_ptr<ClientData> client = make_shared<ClientData>();

			getline(file, line);
			client->set_name(line);
			getline(file, line);
			client->set_sname(line);
			getline(file, line);
			client->get_adress();
			getline(file, line);
			client->get_adress_number();
			getline(file, line);
			client->get_mail();
			client->get_phone_number();

			m_data.push_back(client);
		}
	}

	file.close();
}
