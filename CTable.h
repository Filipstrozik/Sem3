#pragma once
#include <string>
using namespace std;

class CTable {
public:
	static const string DEFAULT_NAME;
	static const int DEFAULT_SIZE;


	CTable();
	CTable(string sName, int iTableLen);
	CTable(const CTable& pcOther);
	~CTable();

	CTable operator+(const CTable &pcOther);
	CTable& operator=(const CTable &pcOther);
	
	void vSetName(string sName);
	string sGetName();
	bool bSetNewSize(int iTableLen);
	int iGetSize();
	//void vEnsureCapacity(const int& minCapacity);
	//void vAdd(const int& elem);
	void vFill();
	void vClearElements();
	bool bSetValueAt(int iOffset, int iNewVal);
	void vPrint();
	CTable* pcClone() const;

private:
	string s_name;
	int i_table_length;
	//int i_capacity;
	int* pi_table;
};












//CTable& operator<<(const int iOffset);