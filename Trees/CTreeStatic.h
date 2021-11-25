#pragma once
#include "CNodeStatic.h"
class CTreeStatic
{
public:
    CTreeStatic();
    ~CTreeStatic();
    CNodeStatic* pcGetRoot();
    bool bMoveSubtree(CNodeStatic* pcParentNode, CNodeStatic* pcNewChildNode);
    void  vPrintTree();
private:
    CNodeStatic c_root;
};

