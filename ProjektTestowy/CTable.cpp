#include "CTable.h"
#include <iostream>
using namespace std;

const string CTable::DEFAULT_NAME = "default";
const int CTable::DEFAULT_SIZE = 10;

CTable::CTable() {
	s_name = DEFAULT_NAME;
	i_table_length = DEFAULT_SIZE;
	pi_table = new int[i_table_length];
	for (int i = 0; i < i_table_length; i++) {
		pi_table[i] = NULL;
	}
	cout << "bezp: " << s_name << endl;
}

CTable::CTable(string sName, int iTableLen) {
	s_name = sName;
	i_table_length = iTableLen; 
	pi_table = new int[i_table_length];
	cout << "parametr: " << s_name << endl;
}

CTable::CTable(const CTable &pcOther) {
	s_name = pcOther.s_name + "_copy";
	i_table_length = pcOther.i_table_length;
	pi_table = new int[i_table_length];
	int *temp = pcOther.pi_table;
	for (int i = 0; i < i_table_length; i++) {
		pi_table[i] = temp[i];
	}
	cout << "kopiuj: " << s_name << endl;
}
	
CTable::~CTable() {
	delete [] pi_table;
	cout << "usuwam: " << s_name << endl;
}

CTable CTable::operator+(const CTable &pcOther) {

	CTable newCT("kopia w operatorze", i_table_length + pcOther.i_table_length);
	// nie tak CTable newCT = CTable(DEFAULT_NAME, i_table_length + pcOther.i_table_length);

	for (int i = 0; i < i_table_length + pcOther.i_table_length; i++) {
		if (i < i_table_length) {
			newCT.pi_table[i] = this->pi_table[i];
		}
		else
		{
			newCT.pi_table[i] = pcOther.pi_table[i - i_table_length];
		}
	}
	return newCT;
}


CTable& CTable::operator=(const CTable& pcOther) {
	this->vSetName(pcOther.s_name);
	this->bSetNewSize(pcOther.i_table_length);

	for (int i = 0; i < i_table_length; i++) {
		pi_table[i] = pcOther.pi_table[i];
	}

	return *this;
}

CTable& CTable::operator--(int) {
	this->bSetNewSize(i_table_length - 1);
	return *this;
}


void CTable::vSetName(string sName) {
	s_name = sName;
}

string CTable::sGetName() {
	return s_name;
}

bool CTable::bSetNewSize(int iTableLen) {
	if (iTableLen > 0) {
		int* temp_pi_table = new int[iTableLen];
		int temp_counter = 0;
		if (iTableLen <= i_table_length) {
			temp_counter = iTableLen;
		}
		else {
			temp_counter = i_table_length;
		}
		for (int i = 0; i < temp_counter; i++) {  // w dalszych komórkach s¹ jakies nieprzypisane wartosci
			temp_pi_table[i] = pi_table[i];
		}

		delete[] pi_table;
		
		pi_table = temp_pi_table;
		//i_table_length = temp_counter;;
		i_table_length = iTableLen;;
		return true;
	}
	else {
		return false;
	}
}

//void CTable::vEnsureCapacity(const int& minCapacity) {
//	if (i_table_length < minCapacity) {
//		this->bSetNewSize(minCapacity + minCapacity / 2);
//	}
//}
//
//void CTable::vAdd(const int& elem) {
//	this->vEnsureCapacity(i_table_length + 1);
//	pi_table[i_table_length] = elem;
//	i_table_length++;
//}

int CTable::iGetSize() {
	return i_table_length;
}

void CTable::vFill() {
	for (int i = 0; i < i_table_length; i++) {
		pi_table[i] = i;
	}
}

void CTable::vClearElements() {
	for (int i = 0; i < i_table_length; i++) {
		pi_table[i] = 0;
	}
}

bool CTable::bSetValueAt(int Offset, int iNewVal) {
	if (Offset < i_table_length) {
		pi_table[Offset] = iNewVal;
		return true;
	}
	else {
		return false;
	}
}

void CTable::vPrint() {
	cout << "show: \t" << s_name << endl;
	for (int i = 0; i < i_table_length; i++) {
		cout <<"[" << pi_table[i] <<"] ";
	}
	cout << endl;
}

CTable* CTable::pcClone() const {
	CTable* ret =  new CTable(*this);
	ret->vSetName(this->s_name + "_clone");
	return ret;
}
