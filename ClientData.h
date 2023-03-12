#pragma once
#include <string>

using namespace std;

class ClientData
{
private:
	string m_name;
	string m_sname;
	string m_adress;
	string m_adress_number;
	string m_mail;
	string m_phone_number;

public:

	string get_name(void) const;
	string get_sname(void) const;
	string get_adress(void) const;
	string get_adress_number(void) const;
	string get_mail(void) const;
	string get_phone_number(void) const;

	void set_name(string name);
	void set_sname(string sname);
	void set_adress(string adress);
	void set_adress_number(string adress_number);
	void set_mail(string mail);
	void set_phone_number(string phone_number);

	ClientData(void);
	ClientData(string name, string sname, string adress,string adress_number, string mail, string phone_number);
};