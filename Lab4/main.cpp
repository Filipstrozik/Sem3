
#include <iostream>
#include "CTreeDynamic.h"
#include "CNodeDynamic.h"
#include <string>
using namespace std;

void vTesting() {
    CTreeDynamic<string> c_tree;
    c_tree.pcGetRoot()->vSetValue("fff");
    c_tree.pcGetRoot()->vAddNewChild();
    c_tree.pcGetRoot()->vAddNewChild();
    c_tree.pcGetRoot()->pcGetChild(0)->vSetValue("aaf");
    c_tree.pcGetRoot()->pcGetChild(1)->vSetValue("ffff");
    c_tree.pcGetRoot()->pcGetChild(0)->vAddNewChild();
    c_tree.pcGetRoot()->pcGetChild(0)->vAddNewChild();
    c_tree.pcGetRoot()->pcGetChild(1)->vAddNewChild();
    c_tree.pcGetRoot()->pcGetChild(1)->vAddNewChild();
    c_tree.pcGetRoot()->pcGetChild(0)->pcGetChild(0)->vSetValue("basf");
    c_tree.pcGetRoot()->pcGetChild(0)->pcGetChild(1)->vSetValue("csa");
    c_tree.pcGetRoot()->pcGetChild(1)->pcGetChild(0)->vSetValue("dasfhhh");
    c_tree.pcGetRoot()->pcGetChild(1)->pcGetChild(1)->vSetValue("eafs");

    c_tree.vPrintTree();
    cout << endl;




    cout << endl;
    cout << *c_tree.Concatenate() << endl;
   
 

}


void vModyfikacja() {
    CTreeDynamic<int> c_tree;
    c_tree.pcGetRoot()->vSetValue(0);
    c_tree.pcGetRoot()->vAddNewChild();
    c_tree.pcGetRoot()->vAddNewChild();
    c_tree.pcGetRoot()->pcGetChild(0)->vSetValue(1);
    c_tree.pcGetRoot()->pcGetChild(1)->vSetValue(0);
    c_tree.pcGetRoot()->pcGetChild(0)->vAddNewChild();
    c_tree.pcGetRoot()->pcGetChild(0)->vAddNewChild();
    c_tree.pcGetRoot()->pcGetChild(1)->vAddNewChild();
    c_tree.pcGetRoot()->pcGetChild(1)->vAddNewChild();
    c_tree.pcGetRoot()->pcGetChild(0)->pcGetChild(0)->vSetValue(2);
    c_tree.pcGetRoot()->pcGetChild(0)->pcGetChild(1)->vSetValue(3);
    c_tree.pcGetRoot()->pcGetChild(1)->pcGetChild(0)->vSetValue(1);
    c_tree.pcGetRoot()->pcGetChild(1)->pcGetChild(1)->vSetValue(0);

    c_tree.vPrintTree();
 

    c_tree.pcGetRoot()->vPruneByVal(1);
    cout << endl;
    //cout << endl;

    c_tree.vPrintTree();

    //int* result = new int(0);

    //c_tree.pcGetRoot()->bSumAllBelow(result);
    //cout << endl;
    //cout << *c_tree.bSum() << endl;

    c_tree.pcGetRoot()->vAllBelowInBreadth();
    cout << endl;
    cout << c_tree.pcGetRoot()->pcGetChild(0)->pcGetChild(0)->iGetDegree() << endl;

    cout << endl;
    int* max = c_tree.vGetMax();
    cout << *max << endl;

    c_tree.vPrintTree();

}


void vModyfikacja2() {
    CTreeDynamic<double> c_tree;
    double val = 0.5;
    c_tree.pcGetRoot()->vSetValue(1.0);
    c_tree.pcGetRoot()->vAddNewChild();
    c_tree.pcGetRoot()->vAddNewChild();
    c_tree.pcGetRoot()->pcGetChild(0)->vSetValue(1.5);
    c_tree.pcGetRoot()->pcGetChild(1)->vSetValue(0.5);
    c_tree.pcGetRoot()->pcGetChild(0)->vAddNewChild();
    c_tree.pcGetRoot()->pcGetChild(0)->vAddNewChild();
    c_tree.pcGetRoot()->pcGetChild(1)->vAddNewChild();
    c_tree.pcGetRoot()->pcGetChild(1)->vAddNewChild();
    c_tree.pcGetRoot()->pcGetChild(0)->pcGetChild(0)->vSetValue(2.5);
    c_tree.pcGetRoot()->pcGetChild(0)->pcGetChild(1)->vSetValue(3.5);
    c_tree.pcGetRoot()->pcGetChild(1)->pcGetChild(0)->vSetValue(1.5);
    c_tree.pcGetRoot()->pcGetChild(1)->pcGetChild(1)->vSetValue(0.5);

    c_tree.vPrintTree();
    cout << endl;

    c_tree.pcGetRoot()->vPruneByVal(val);
    cout << endl;
    cout << endl;

    c_tree.vPrintTree();
    cout << endl;
    double* result = new double(1.0);

    c_tree.pcGetRoot()->bSumAllBelow(result);

    cout << *result << endl;

    cout << "countNodes= " << c_tree.pcGetRoot()->iNodesBelowCount() << endl;


    cout << endl;
    double* max = c_tree.vGetMax();
    cout << *max << endl;
}

int main() {
    cout << "Test " << endl;

    vTesting();

   // vModyfikacja();

    //vModyfikacja2();
 

    return 0;
}