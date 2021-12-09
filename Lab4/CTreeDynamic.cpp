#include "CTreeDynamic.h"
#include <iostream>


template<typename T>
CTreeDynamic<T>::CTreeDynamic() {
    pc_root = new CNodeDynamic<T>();
}


template <typename T>
CTreeDynamic<T>::~CTreeDynamic() {
    delete pc_root;
}


template <typename T>
void CTreeDynamic<T>::vPrintTree() {
    pc_root->vPrintAllBelow();
}


template <typename T>
bool CTreeDynamic<T>::bMoveSubtree(CNodeDynamic<T>* pcParentNode, CNodeDynamic<T>* pcNewChildNode) {
    cout << "przenoszenie:" << endl;
    if (pcParentNode != NULL && pcNewChildNode != NULL) {
        if (pcParentNode->pcGetRoot(pcParentNode) == pcNewChildNode->pcGetRoot(pcNewChildNode)) {
            return false;

        }

        CNodeDynamic* pc_parent_temp = pcNewChildNode->pcGetParent();
        if (pc_parent_temp == NULL) {
            return false;

        }

        pcParentNode->vAddNewChild(pcNewChildNode);
        pc_parent_temp->vRemoveChild(pcNewChildNode);
        return true;
    }
    return false;
}



template<typename T>
CNodeDynamic<T>* CTreeDynamic<T> ::pcGetRoot() {
    return pc_root;
}