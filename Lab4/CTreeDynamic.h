#ifndef LAB_6_CTREEDYNAMIC_H
#define LAB_6_CTREEDYNAMIC_H



#include <vector>
#include "CNodeDynamic.h"

template < typename T>
class CTreeDynamic
{
public:
    CTreeDynamic();

    ~CTreeDynamic();

    CNodeDynamic<T>* pcGetRoot();

    void vPrintTree();

    bool bMoveSubtree(CNodeDynamic<T>* pcParentNode, CNodeDynamic<T>* pcNewChildNode);

    void vGetType();

    T* Concatenate(); //modyfikacja

    void vPrintTreeInBreadth();

    T* vGetMax();

    CNodeDynamic<T>* pcGetByValue(T value);

private:

    CNodeDynamic<T>* pc_root;

};



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
    

template <typename T>
void CTreeDynamic<T>::vGetType() {
    pc_root->vGType();
}







template<typename T>
T* CTreeDynamic<T>::Concatenate() {
    return NULL;
}



template<>
string* CTreeDynamic<string>::Concatenate() {
    string* wynik = new string("");
    pc_root->Concatenate(wynik);
    return wynik;
}






template<typename T>
void CTreeDynamic<T>::vPrintTreeInBreadth() {
    pc_root->vAllBelowInBreadth();
}





template<typename T>
T* CTreeDynamic<T>::vGetMax() {// wez pierwszy domyslny dla typu 
    T* max = pc_root->tGetValue();
    pc_root->vGetMax(max);
    return max;
}





template<typename T>
CNodeDynamic<T>* CTreeDynamic<T> ::pcGetByValue(T value) {
    if (pc_root->pcGetElem(value) != NULL) {
        return pc_root->pcGetElem(value);
    }
    else {
        return NULL;
        //CNodeDynamic<T> pusty;
        //return &pusty;
    }
}

#endif