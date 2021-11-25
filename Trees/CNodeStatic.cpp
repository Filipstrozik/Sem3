#include "CNodeStatic.h"
using namespace std;
CNodeStatic::CNodeStatic() {
    i_val = 0;
    pc_parent_node = NULL;
}

CNodeStatic::~CNodeStatic() {
    
}

CNodeStatic::CNodeStatic(CNodeStatic* CNodeOther) {
    i_val = CNodeOther->i_val;
    pc_parent_node = CNodeOther->pcGetParent();
}

void CNodeStatic::vAddNewChild() {
    CNodeStatic cNewNode;
    cNewNode.pc_parent_node = this;
    v_children.push_back(cNewNode);
} // dlatego jest nowy i usuwanie go

CNodeStatic* CNodeStatic::pcGetChild(int iChildOffset) {
    if (iChildOffset < iGetChildrenNumber()) {
        return &v_children.at(iChildOffset);
    }
    else {
        return NULL;
    }
}


void CNodeStatic::vPrintAllBelow() {
    vPrint();
    for (int i = 0; i < iGetChildrenNumber(); i++) {
        if (pcGetChild(i) != NULL) pcGetChild(i)->vPrintAllBelow();
    }
}

void CNodeStatic::vPrintUp() {
    vPrint();
    if (pc_parent_node != NULL) {
        if (pc_parent_node != NULL) pc_parent_node->vPrintUp();
    }
}

void CNodeStatic::vRepairParent() {
    for (int i = 0; i < iGetChildrenNumber(); i++) {
        if (pcGetChild(i) != NULL) {
            pcGetChild(i)->pc_parent_node = this;
            pcGetChild(i)->vRepairParent();
        }
    }
}

void CNodeStatic::vAddNewChild(CNodeStatic* cNewNode) {
    v_children.push_back(*cNewNode);
    (*cNewNode).pc_parent_node = this;
}

void CNodeStatic::vRemoveChild(CNodeStatic* cNodeToRemove) {
    for (int i = 0; i < this->iGetChildrenNumber(); i++) {
        if (this->pcGetChild(i)->i_val == cNodeToRemove->i_val) {
            v_children.erase(v_children.begin() + i);
        }
    }
}

int CNodeStatic::iGetChildPosition(CNodeStatic& cNodeStatic) {
    for (int i = 0; i < v_children.size(); i++) {
        cout << v_children.at(i).i_val << endl;
        if (v_children.at(i).i_val == cNodeStatic.i_val)
            return i;
    }
    return -1;
} // patrzymy na wartosc wezla nie na adres

CNodeStatic* CNodeStatic::pcGetParent() const {
    return pc_parent_node;
}

CNodeStatic* CNodeStatic::pcGetRoot(CNodeStatic* cNodeStatic) {
    if (cNodeStatic->pc_parent_node != NULL) {
        pcGetRoot(cNodeStatic->pc_parent_node);
    }
    else {
        return cNodeStatic;
    }
}

void CNodeStatic::vSetValue(int iNewVal) {
    i_val = iNewVal;
}

int CNodeStatic::iGetChildrenNumber() {
    return (v_children.size());
}

void CNodeStatic::vPrint() {
    std::cout << " " << i_val;
}