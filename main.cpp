#include <iostream>
#include "Table_functions.h"
#include "CTable.h"

using namespace std;

void v_mod_tab(CTable* pcTab, int iNewSize) {
	pcTab->vSetName("zmodyfikowana tablica - wskaznik?");
	pcTab->vClearElements();
}

void v_mod_tab(CTable cTab, int iNewSize) {
	cTab.vSetName("zmodyfikowana tablica - kopia?");
	cTab.vPrint();
	cTab.vClearElements();
	cTab.vPrint();
}


int main()
{ 
	{
		//cout << "Zadanie 1:" << endl;
		//cout << b_alloc_table_add_5(5) << endl;
		//cout << b_alloc_table_add_5(0) << endl;
		//cout << b_alloc_table_add_5(-3) << endl;
		//cout << "Zadanie 2:" << endl;;
		//int** pi_table;
		//cout << b_alloc_table_2_dim(&pi_table, 10, 5) << endl;
		//v_show_table_2_dim(&pi_table, 10, 5);
		//int** pi_table2;
		////cout << b_alloc_table_2_dim(pi_table2, -3, -2) << endl;
		//cout << b_alloc_table_2_dim(&pi_table2, 2, 9) << endl;
		//v_show_table_2_dim(&pi_table2, 2, 9);

		//char ***pc_char;
		//cout << b_alloc_table_3_dim_of_char(pc_char, 8, 7, 5) << endl;

		//char*** pc_char2;
		//cout << b_alloc_table_3_dim_of_char(pc_char2, 0, 7, 5) << endl;


		//cout << "Zadanie 3:" << endl;;
		//cout << b_dealloc_table_2_dim(&pi_table, 10) << endl;
		//cout << b_dealloc_table_2_dim(&pi_table2, 2) << endl;

		//cout << "Zadanie 4:" << endl;;


		//CTable my_tab("tablica_1",2);
		//my_tab.fill();
		//my_tab.show();

		//CTable my_2tab("tab2",5);
		//my_2tab.fill();
		//my_tab.clear_elements();
		//my_tab.show();
		//my_2tab.show();

		//CTable* pc_new_tab;
		//pc_new_tab = my_2tab.pcClone();
		//pc_new_tab->show();

		//v_mod_tab(pc_new_tab, 5);
		//pc_new_tab->show();

		//v_mod_tab(my_2tab, 5);
		//my_2tab.show();

		//pc_new_tab->bSetNewSize(10);
		//pc_new_tab->show();

		//delete pc_new_tab;

		//CTable c_tab_0, c_tab_1;
		//c_tab_0.bSetNewSize(6);
		//c_tab_1.bSetNewSize(4);
		//c_tab_0 = c_tab_1;

		//cout << endl;
		//cout << "etap 1" << endl;
		//cout << endl;
	}
	CTable ctab;
	cout<< ctab.bSetNewSize(3) << endl;
	ctab.vPrint();
	cout << ctab.bSetValueAt(1, 1001) << endl;
	ctab.vPrint();

	cout << endl;
	cout << "etap 2 - alokacja dwóch tablic" << endl;
	cout << endl;


	CTable c_tab_0, c_tab_1,c_tab_2;
	c_tab_0.bSetNewSize(6);
	cout << "tab_0 - wypisanie" << endl;
	c_tab_0.vPrint();

	c_tab_1.bSetNewSize(4);
	c_tab_2.bSetNewSize(2);
	c_tab_2.vFill();
	cout << "tab_1 - wypisanie" << endl;
	c_tab_1.vPrint();
	/* initialize table */
	//cout << "c_tab_0 = c_tab_1; - operator" << endl;
	//c_tab_0 = c_tab_1; // maj¹ te sam¹ nerkê!1!
	cout << "zmiana tab_1 3 elementu" << endl;
	c_tab_1.bSetValueAt(2, 123);
	c_tab_1.vFill();

	cout << "zmiana tab_0 2 elementu" << endl;
	c_tab_0.bSetValueAt(1,321);
	c_tab_0.vFill();
	cout << "c_tab_0 = " << endl;
	c_tab_0.vPrint();
	cout << "c_tab_1 = " << endl;
	c_tab_1.vPrint();
	c_tab_0 = c_tab_1 = c_tab_2; // gdyby = by³ void to nie da³oby siê czegoœ takiego wykonaæ! dlatego jest & bo nadpisujesz pola i zwracasz
	//ten sam obiekt. c_tab_0 = (c_tab_1 = (c_tab_2))!!
	c_tab_1 = c_tab_0 + c_tab_1 + c_tab_2; // dodawanie ma zwracaæ nowy obiekt, nie zmienij¹c sk³adników.
	c_tab_1.vPrint();
	
	c_tab_1.vFill();
	c_tab_1.vPrint();
	//c_tab_1 << (2);
	//c_tab_1 = c_tab_1 << (2);
	//c_tab_1 << (2) << (1);
	//(c_tab_1 << (2) ) << (1) ; to wi¹¿e w lewo.

	//c_tab_1.vPrint();

	//v_mod_tab(CTable cTab, int iNewSize) otrzymuje obiekt i tworzy jego kopie w scopie procedury, na niej dziala, jak wychodzi 
	//z funkcji to zwalnia pamiec, nie modyfikuje rzeczywistego obiektu w pamieci.


	//Ctable ct[3];
	//for (int i = 0; i < 3; i++) {
	//	string s;
	//	cout << "podaj nazwe tablicy" << endl;
	//	cin >> s;
	//	ct[i].vsetname(s);
	//}


	//Ctable *pct[3];
	//for (int i = 0; i < 3; i++) {
	//	string s;
	//	int size;
	//	cout << "podaj nazwe tablicy i  rozmiar" << endl;
	//	cin >> s >> size;
	//	pct[i] = new ctable(s,size);
	//}

	return 0;
}