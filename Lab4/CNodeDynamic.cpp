#include "CNodeDynamic.h"
#include <queue>
using namespace std;

template <typename T>
CNodeDynamic<T>::CNodeDynamic() {
    t_val = 0;
    pc_parent_node = NULL;
}

template <typename T>
CNodeDynamic<T>::~CNodeDynamic() {
    for (int i = 0; i < iGetChildrenNumber(); i++)
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
CNodeDynamic<T> *CNodeDynamic<T>::pcGetChild(int iChildOffset) {
    if (iChildOffset < iGetChildrenNumber()) {
        return v_children.at(iChildOffset);
    }
    return NULL;
}

template <typename T>
void CNodeDynamic<T>::vPrintAllBelow() {
    vPrint();
    for (int i = 0; i < iGetChildrenNumber(); i++)
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
    for (int i = 0; i < iGetChildrenNumber(); i++)
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


template<typename T>
void CNodeDynamic<T>::vPruneByVal(T tVal) {

    queue<CNodeDynamic*> q;

    q.push(this);

    CNodeDynamic* currNode;

    while (!q.empty()) {
        currNode = q.front();//pobieranie z kolejki
        q.pop(); // usuwanie z kolejki
        cout << currNode->t_val << endl;
        for (int i = 0; i < currNode->v_children.size(); i++) {
            cout << "\t" << currNode->v_children.at(i)->t_val << endl;
            bool flag = currNode->v_children.at(i)->t_val == tVal;
            if (flag) { // do usuniecia
                if (currNode->v_children.at(i)->iGetChildrenNumber() > 0) {
                    for (int ii = 0; ii < currNode->v_children.at(i)->v_children.size(); ii++) {
                        if (currNode->v_children.at(i)->v_children.at(ii) != NULL) {
                            cout << "\t\t" << currNode->v_children.at(i)->v_children.at(ii)->t_val << endl;
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
        for (int i = 0; i < currNode->v_children.size(); i++) {
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