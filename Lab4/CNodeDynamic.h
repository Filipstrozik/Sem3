#ifndef LAB_6_CNODEDYNAMIC_H
#define LAB_6_CNODEDYNAMIC_H

#include <vector>
#include <iostream>
#include <queue>
#include <string>
using namespace std;

template <typename T > class CNodeDynamic
{
public:
    CNodeDynamic();
    ~CNodeDynamic();

    void vSetValue(T tNewVal);
    void vAddNewChild();
    void vAddNewChild(CNodeDynamic *cNewChild);
    void vPrint();
    void vPrintAllBelow();
    void vPrintUp();
    void vPruneByVal(T tVal);
    void vRemoveChild(CNodeDynamic *cNodeToRemove);
    void vGType();

    void Concatenate(string* wynik); // modyfikacja

    CNodeDynamic* pcGetParent();
    CNodeDynamic* pcGetRoot(CNodeDynamic *cNodeDynamic);
    CNodeDynamic* pcGetChild(int iChildOffset);
    CNodeDynamic* pcGetElem(T tVal);
    int iGetChildrenNumber();
    int iGetChildPosition(CNodeDynamic *cNodeDynamic);
    void vAllBelowInBreadth();
    bool bSumAllBelow(T* result);
    int iGetDegree();
    int iNodesBelowCount();
    void vGetMax(T* oldMax);
    T* tGetValue();
private:
    vector<CNodeDynamic*> v_children;
    CNodeDynamic* pc_parent_node;
    T t_val;
};


template <typename T>
CNodeDynamic<T>::CNodeDynamic() {
    //t_val = {}; //c++11?
    t_val = T();
    pc_parent_node = NULL;
}

template <typename T>
CNodeDynamic<T>::~CNodeDynamic() {
    for (int i = 0; i < (int) iGetChildrenNumber(); i++)
        if (v_children[i] != NULL)
            delete v_children[i];
}

template <typename T>
void CNodeDynamic<T>::vAddNewChild() {
    CNodeDynamic* cNewNode = new CNodeDynamic;
    cNewNode->pc_parent_node = this;
    v_children.push_back(cNewNode);
}

template <typename T>
CNodeDynamic<T>* CNodeDynamic<T>::pcGetChild(int iChildOffset) {
    if (iChildOffset < iGetChildrenNumber()) {
        return v_children.at(iChildOffset);
    }
    return NULL;
}

template <typename T>
CNodeDynamic<T>* CNodeDynamic<T>::pcGetElem(T tVal) {
    
    if ((*this->tGetValue()) == tVal) {
        
        return this;
    }
    else {
        for (int i = 0; i < (int)this->iGetChildrenNumber(); i++) {
            if (this->pcGetChild(i) != NULL) {
                if (this->pcGetChild(i)->pcGetElem(tVal) != NULL) {
                    return this->pcGetChild(i)->pcGetElem(tVal);
                }
            }
        }
        return NULL;
    }
    
}



template <typename T>
void CNodeDynamic<T>::vPrintAllBelow() {
    vPrint();
    for (int i = 0; i < (int) iGetChildrenNumber(); i++)
        if (v_children.at(i) != NULL)
            v_children.at(i)->vPrintAllBelow();

}

template <typename T>
void CNodeDynamic<T>::vPrintUp() {
    vPrint();
    if (pc_parent_node != NULL) pc_parent_node->vPrintUp();

}

template<typename T>
void CNodeDynamic<T>::vAddNewChild(CNodeDynamic<T>* cNewChild) {
    cNewChild->pc_parent_node = this;
    v_children.push_back(cNewChild);
}

template<typename T>
int CNodeDynamic<T>::iGetChildPosition(CNodeDynamic<T>* cNodeDynamic) {
    for (int i = 0; i < (int) iGetChildrenNumber(); i++)
        if (v_children.at(i) == cNodeDynamic)
            return i;

    return -1;
}


template<typename T>
void CNodeDynamic<T>::vRemoveChild(CNodeDynamic<T>* cRemoveNode) {
    int iChildPosition = iGetChildPosition(cRemoveNode);
    if (cRemoveNode->pc_parent_node == this) {
        cRemoveNode->pc_parent_node = NULL;
        delete cRemoveNode;
    }


    if (iChildPosition >= 0) {
        v_children.erase(v_children.begin() + iChildPosition);
    }

}


template<>
void CNodeDynamic<string>::Concatenate(string *wynik) {
    vector<string*> wynikiDzieci;

    *wynik += this->t_val;

    *wynik += "";

    for (int i = 0; i < (int)iGetChildrenNumber(); i++) {
        wynikiDzieci.push_back(new string(""));
        if (pcGetChild(i) != NULL) {
            pcGetChild(i)->Concatenate(wynikiDzieci[i]);

        }
        *wynik += *wynikiDzieci[i];
    }
}




template <>
void CNodeDynamic<int>::vGType() {
    cout <<endl<< "INT" << endl;
}


template <>
void CNodeDynamic<double>::vGType() {
    cout <<endl<< "DOUBLE" << endl;
}

template <>
void CNodeDynamic<string>::vGType() {
    cout << endl << "String" << endl;
}


template <typename T>
void CNodeDynamic<T>::vGType() {
    cout << "UNKNOWN" << endl;
}

template<typename T>
void CNodeDynamic<T>::vPruneByVal(T tVal) {

    queue<CNodeDynamic<T>* > q;

    q.push(this);

    CNodeDynamic* currNode;

    while (!q.empty()) {
        currNode = q.front();//pobieranie z kolejki
        q.pop(); // usuwanie z kolejki
        //cout << currNode->t_val << endl;
        for (int i = 0; i < (int) currNode->v_children.size(); i++) {
            //cout << "\t" << currNode->v_children.at(i)->t_val << endl;
            bool flag = currNode->v_children.at(i)->t_val == tVal;
            if (flag) { // do usuniecia
                if (currNode->v_children.at(i)->iGetChildrenNumber() > 0) {
                    for (int ii = 0; ii < (int) currNode->v_children.at(i)->v_children.size(); ii++) {
                        if (currNode->v_children.at(i)->v_children.at(ii) != NULL) {
                           // cout << "\t\t" << currNode->v_children.at(i)->v_children.at(ii)->t_val << endl;
                            currNode->v_children.at(i)->v_children.at(ii)->pc_parent_node = currNode;
                            currNode->v_children.push_back(currNode->v_children.at(i)->pcGetChild(ii));
                            currNode->v_children.at(i)->v_children.at(ii) = NULL;
                        }
                    }
                }
                currNode->v_children.at(i)->pc_parent_node = NULL;
                delete currNode->v_children.at(i);
                currNode->v_children.erase(currNode->v_children.begin() + i);
                i--;
            }
        }
        for (int i = 0; i < (int)currNode->v_children.size(); i++) {
            q.push(currNode->v_children.at(i));
        }
    }
}

template<typename T>
CNodeDynamic<T>* CNodeDynamic<T>::pcGetParent() {
    return pc_parent_node;
}

template<typename T>
CNodeDynamic<T>* CNodeDynamic<T>::pcGetRoot(CNodeDynamic<T>* cNodeDynamic) {
    if (cNodeDynamic->pc_parent_node != NULL)
        pcGetRoot(cNodeDynamic->pc_parent_node);

    return cNodeDynamic;
}

template<typename T>
void CNodeDynamic<T>::vPrint() {
    std::cout << " " << t_val;
}

template<typename T>
int CNodeDynamic<T>::iGetChildrenNumber() {
    return v_children.size();
}

template<typename T>
void CNodeDynamic<T>::vSetValue(T tNewVal) {
    t_val = tNewVal;
}

template<typename T>
void CNodeDynamic<T>::vAllBelowInBreadth() {
    queue<CNodeDynamic<T>*> q;
    q.push(this);
    
    while (q.empty() == false) {
        
        CNodeDynamic* node = q.front();
        cout << node->t_val << " ";
        q.pop();
        for (int i = 0; i < (int) node->iGetChildrenNumber(); i++) {
            if (node->pcGetChild(i) != NULL) {
                q.push(node->pcGetChild(i));
            }
        }
    }
}


template <typename T>
bool CNodeDynamic<T>::bSumAllBelow(T* result) {
    return false;
}


template<>
bool CNodeDynamic<int>::bSumAllBelow(int* result) {
    vector<int*> results;
    for (int i = 0; i < (int)iGetChildrenNumber(); i++) { //tworzenie tablicy 
        results.push_back(new int(0));
    }
 
    *result += this->t_val;

    for (int i = 0; i < (int)iGetChildrenNumber(); i++) { //rozwin rekurencyjnie
        if (pcGetChild(i) != NULL) {
            pcGetChild(i)->bSumAllBelow(results[i]);
        }
        
    }

    for (int i = 0; i < (int)iGetChildrenNumber(); i++) {
        *result += *results[i];
    }

    return true;
}


template<>
bool CNodeDynamic<double>::bSumAllBelow(double* result) {
    vector<double*> results;
    for (int i = 0; i < (int)iGetChildrenNumber(); i++) { //tworzenie tablicy 
        results.push_back(new double(1.0)); // wa¿e co robisz jaka jest podstawoowy pierwszy wynik
    }
    *result *= this->t_val;

    for (int i = 0; i < (int)iGetChildrenNumber(); i++) { //rozwin rekurencyjnie
        if (pcGetChild(i) != NULL) {
            pcGetChild(i)->bSumAllBelow(results[i]);
        }
    }

    for (int i = 0; i < (int)iGetChildrenNumber(); i++) {
        *result *= *results[i];
    }

    return true;
}

template <>
bool CNodeDynamic<string>::bSumAllBelow(string* result) {
    vector<string*> results;
    for (int i = 0; i < (int) iGetChildrenNumber(); i++) {
        results.push_back(new string(""));
    }

    *result += this->t_val;
      
    *result += "";

    for (int i = 0; i < (int) iGetChildrenNumber(); i++) {
        if (pcGetChild(i) != NULL) {
            pcGetChild(i)->bSumAllBelow(results[i]);
        }
    }
    for (int i = 0; i < (int) iGetChildrenNumber(); i++) {
        *result += *results[i];
    }
    return true;
}

template <typename T>
int CNodeDynamic<T>::iGetDegree()
{
    int degree = 0;
    if (this->pc_parent_node != NULL) {
        degree += 1;
        degree += (*this->pc_parent_node).iGetDegree();
    }
    return degree;
}

template<typename T> 
int CNodeDynamic<T>::iNodesBelowCount() {
    int count = 1;
    for (int i = 0; i < (int)this->iGetChildrenNumber(); i++) {
        count += pcGetChild(i)->iNodesBelowCount();
    }
    return count;
}

template<typename T>
void CNodeDynamic<T>::vGetMax(T* oldMax) {
    if ((*oldMax) <= this->t_val) {
        (*oldMax) = this->t_val;
    }
    for (int i = 0; i < (int)this->iGetChildrenNumber(); i++) {
        pcGetChild(i)->vGetMax(oldMax);
    }
}

template<typename T>
T* CNodeDynamic<T>::tGetValue() {
    return &t_val;
}

#endif 