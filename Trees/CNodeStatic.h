#pragma once

#include <iostream>
#include <vector>

class CNodeStatic
{
public:
    CNodeStatic();
    ~CNodeStatic();
    CNodeStatic(CNodeStatic* CNodeStatic);
    void vSetValue(int iNewVal);
    int iGetChildrenNumber();
    void vAddNewChild();
    void vRepairParent();
    void vAddNewChild(CNodeStatic* CNewNode);
    void vRemoveChild(CNodeStatic* cNodeToRemove);
    void vPrint();
    void vPrintAllBelow();
    void vPrintUp();
    int iGetChildPosition(CNodeStatic& cNodeStatic);
    CNodeStatic* pcGetParent() const;
    CNodeStatic* pcGetChild(int iChildOffset);
    CNodeStatic* pcGetRoot(CNodeStatic* cNodeStatic);
private:
    std::vector<CNodeStatic> v_children;
    CNodeStatic* pc_parent_node;
    int i_val;
};

