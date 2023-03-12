#include <iostream>
#include <Windows.h>
#include <locale.h>
#include "ClientsList.h"
#include "ProductList.h"
#include "Sale.h"
#include <ctime>
#include <string>


using namespace std;

bool check_option(string choice, vector<string> options)
{
	bool value = false;

	for (size_t i = 0; i < options.size(); ++i)
	{
		if (choice == options[i])
		{
			value = true;
		}
	}

	if (value == false)
	{
		system("CLS");
		cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
		cout << "\t\t\t\t\tProszę wybrać poprawną opcję z menu";
		cout << endl << endl << endl << endl << endl;
		Sleep(1000);
	}

	return value;
}

void first_menu(void) {

	system("CLS");

	cout << endl << endl << endl << endl;
	cout << "\t\t\t\t            _ _ _   _                           " << endl;
	cout << "\t\t\t\t           | | | | (_)                         " << endl;
	cout << "\t\t\t\t  ___   ___| | | |_ _ _ __   ___ ___  _ __ ___ " << endl;
	cout << "\t\t\t\t / __| / _ | | | __| | '_ | / __/ _ || '_ ` _  | " << endl;
	cout << "\t\t\t\t |__ ||  __/ | | |_| | |_) | (_| (_) | | | | | |" << endl;
	cout << "\t\t\t\t |___/|___| _|_|___|_| .__(_)__|___/|_||_| |_| |" << endl;
	cout << "\t\t\t\t                                               " << endl;
	cout << endl << endl << endl;
	cout << endl << endl << endl;
	cout << "\t\t\t\t 1. ZAKUPY" << endl;
	cout << "\t\t\t\t 2. SPRZEDAŻ" << endl;
	cout << "\t\t\t\t " << endl;
	cout << "\t\t\t\t " << endl;
	cout << "\t\t\t\t  Wyjście(q)" << endl;

}
void sell_menu(void) {

	system("CLS");

	cout << endl << endl << endl << endl;
	cout << "\t\t\t\t  " << endl;
	cout << "\t\t\t\t  " << endl;
	cout << "\t\t\t\t  " << endl;
	cout << endl << endl << endl;
	cout << endl << endl << endl;
	cout << "\t\t\t\t Wystaw Przedmiot!(+) | Wyjście(q)" << endl;
	cout << "\t\t\t\t " << endl;

}


void add_auction(ProductList& productList)
{
	shared_ptr<Product> product = make_shared<Product>();
	string line;
	string confirm;
	string auction_code;

	srand(time(NULL));

	for (int i = 0; i < 3; i++) {
		int los = rand() % 36;
		if (los < 10) {
			auction_code.push_back('0' + los);
		}
		else {
			auction_code.push_back('a' + los - 10);
		}
	}

	while (true)
	{
		product->set_auction_number(auction_code);

		system("CLS");
		cout << endl << endl << endl << endl;
		cout << "\t\t\t\t Uzupelnij dane ogloszenia:" << endl;
		cout << endl << "Produkt:";
		cin >> line;
		product->set_name(line);
		cout << endl << "Cena:" << endl;
		cin >> line;
		product->set_price(line);

		cout << endl << "Zatwiedz(z) | Powtorz(r) | Wyjdz bez zapisywania(q)" << endl;

		cin >> confirm;

		if (confirm == "z")
		{
			productList.add_product(product, "ProductList.txt");
			break;
		}
		else if (confirm == "r")
		{
			continue;
		}
		else if (confirm == "q")
			break;
		else
			check_option(confirm, { "r","z" });
	}

}

bool isletter(const string& str) {
	for (char c : str) {
		if (std::isalpha(c)) {
			return true;
		}
	}
	return false;
}

bool check_code(const string& fileName, const string& str) {
	ifstream file(fileName);
	string line;

	while (getline(file, line)) {
		if (line.find(str) != string::npos) {
			return true;
		}
	}
	cout << "Proszę podać poprawny kod aukcji." << endl;
	return false;
}



int remove_auction(ProductList& list)
{
	string name;
	string confirm;
	bool check = 0;

	while (true)
	{


		cout << endl << endl << endl << endl;
		

		while (check != true) {
			cout << "\t\t\t\t Podaj kod:" << endl << endl;
			cin >> name;

			check = check_code("ProductList.txt", name);


		}
		
		

		cout << endl << "Zatwiedź(z) | Wyjdź(q)" << endl;

		cin >> confirm;

		if (confirm == "z")
		{
			list.add_product2(name, "CompletedTransactions.txt");
			list.remove_product(name, "ProductList.txt");
			return 1;
			break;
			
		}
		else if (confirm == "q") {
			break;
			return 0;
		}

		else
			check_option(confirm, { "r","z" });
	}


}void product_base(ProductList list)
{
	system("CLS");

	cout << endl << endl << endl << endl;
	cout << "\t\t\t\t\t\t Aukcje:";
	cout << endl << endl;

	list.show_products();

	cout << endl << "\t\t (+) KUP PRODUKT." << endl;

	cout << endl << endl << endl << "\t\tPowrót(q)" << endl << endl;
}

void step_2(ClientsList& list) {

	string line;
	shared_ptr<ClientData> client = make_shared<ClientData>();
	system("CLS");



	cout << endl << endl << endl << endl;
	cout << "\t\t\t\t\t\t FORMULARZ" << endl;
	cout << endl << endl;
	cout << "Imie:" << endl;
	cin >> line;
	client->set_name(line);
	cout << endl << "Nazwisko:" << endl;
	cin >> line;
	client->set_sname(line);
	cout << endl << "Adres(Miejscowość):" << endl;
	cin >> line;
	client->set_adress(line);
	cout << endl << "Adres(Numer domu):" << endl;
	cin >> line;
	client->set_adress_number(line);
	while (true) {

		cout << endl << "Mail:" << endl;
		cin >> line;

		if (line.find('@') != std::string::npos) {
			client->set_mail(line);
			break;
		}
		else {
			std::cout << "Błąd. Upewnij się, że wpisany e-mail jest poprawny" << std::endl;
		}
	}

	while (true) {
		cout << endl << "Numer Telefonu:" << endl;

		cin >> line;

		if (isletter(line)) {
			cout << "Błąd. Upewnij się, że wpisany numer telefonu jest poprawny." << endl;
		}
		else {
			client->set_phone_number(line);
			break;
		}

	}


	list.add_client(client, "CompletedTransactions.txt");



}

int main()
{
	int a;
	string kod = "000";
	string option = "0";
	string option2 = "0";
	setlocale(LC_CTYPE, "Polish");

	ProductList list = ProductList();
	ClientsList clist = ClientsList();
	list.get_data("ProductList.txt");

	while (true)
	{
		if (option == "0")
		{
			first_menu();

			while (true)
			{
				cin >> option;
				if (check_option(option, { "1","2","3","4","5","q" }) == true)
					break;
				else
				{
					check_option(option, { "1","2","3","4","5","q" });
					first_menu();
				}
			}
		}
		if (option == "1")
		{
			while (true)
			{
				product_base(list);

				while (true)
				{
					cin >> option;
					if (check_option(option, { "+","q" }) == true)
						break;
					else
					{
						check_option(option, { "+","q" });
						product_base(list);
					}
				}

				if (option == "+")
				{
					product_base(list);
					a = remove_auction(list);	
					if (a == 1) {
						step_2(clist);
					}
					else if (a == 0) {
						option = "1";
					}
					
				}		


				else if (option == "q")
				{
					option = "0";
					break;
				}
			}
		}		
		if (option == "2")
		{
			while (true)
			{
				sell_menu();

				while (true)
				{
					cin >> option;
					if (check_option(option, { "-","+","q" }) == true)
						break;
					else
					{
						check_option(option, { "-","+","q" });
						product_base(list);
					}
				}

				if (option == "+")
				{
					add_auction(list);

				}

				else if (option == "q")
				{
					option = "0";
					break;
				}
			}
		}
	}



	return 0;
}

