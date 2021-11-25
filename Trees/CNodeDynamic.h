#pragma once
#include <vector>
#include <iostream>
using namespace std;

class CNodeDynamic
{
public:
    CNodeDynamic();
    ~CNodeDynamic();
    void vSetValue(int iNewVal);
    void vAddNewChild();
    void vAddNewChild(CNodeDynamic* cNewChild);
    void vPrint();
    void vPrintAllBelow();
    void vPrintUp();
    void vPruneByVal(int iVal);
    void vRemoveChild(CNodeDynamic* cNodeToRemove);
    CNodeDynamic* pcGetParent();
    CNodeDynamic* pcGetRoot(CNodeDynamic* cNodeDynamic);
    CNodeDynamic* pcGetChild(int iChildOffset);
    int iGetChildrenNumber();
    int iGetChildPosition(CNodeDynamic* cNodeDynamic);
private:
    vector<CNodeDynamic*> v_children;
    CNodeDynamic* pc_parent_node;
    int i_val;
};

