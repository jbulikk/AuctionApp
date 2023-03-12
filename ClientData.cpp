#include "ClientData.h"
#include <string>


string ClientData::get_name(void) const { return m_name; }
string ClientData::get_sname(void) const { return m_sname; }
string ClientData::get_adress(void) const { return m_adress; }
string ClientData::get_adress_number(void) const { return m_adress_number; }
string ClientData::get_mail(void) const { return m_mail; }
string ClientData::get_phone_number(void) const { return m_phone_number; }


void ClientData::set_name(string name) { m_name = name; }
void ClientData::set_sname(string sname) { m_sname = sname; }
void ClientData::set_adress(string adress) { m_adress = adress; }
void ClientData::set_adress_number(string adress_number) { m_adress_number = adress_number; }
void ClientData::set_mail(string mail) { m_mail = mail; }
void ClientData::set_phone_number(string phone_number) { m_phone_number = phone_number; }

ClientData::ClientData(void)
{
	m_name = "";
	m_sname = "";
	m_adress = "";
	m_mail = "";
	m_phone_number = "";
}

ClientData::ClientData(string name, string sname, string adress, string adress_number, string mail, string phone_number)
{
	m_name = name;
	m_sname = sname;
	m_adress = adress;
	m_adress_number = adress_number;
	m_mail = mail;
	m_phone_number = phone_number;
}