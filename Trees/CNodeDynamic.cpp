#include "CNodeDynamic.h"
#include <queue>
using namespace std;

CNodeDynamic::CNodeDynamic() {
    i_val = 0;
    pc_parent_node = NULL;
}

CNodeDynamic::~CNodeDynamic() {
    for (int i = 0; i < iGetChildrenNumber(); i++)
        if (v_children[i] != NULL)
            delete v_children[i];
}

void CNodeDynamic::vAddNewChild() {
    CNodeDynamic* cNewNode = new CNodeDynamic;
    cNewNode->pc_parent_node = this;
    v_children.push_back(cNewNode);
}

CNodeDynamic* CNodeDynamic::pcGetChild(int iChildOffset) {
    if (iChildOffset < iGetChildrenNumber()) {
        return v_children.at(iChildOffset);
    }
    return NULL;
}

void CNodeDynamic::vPrintAllBelow() {
    vPrint();
    for (int i = 0; i < iGetChildrenNumber(); i++)
        if (v_children.at(i) != NULL)
            v_children.at(i)->vPrintAllBelow();

}
void CNodeDynamic::vPrintUp() {
    vPrint();
    if (pc_parent_node != NULL) pc_parent_node->vPrintUp();

}

void CNodeDynamic::vAddNewChild(CNodeDynamic* cNewChild) {
    cNewChild->pc_parent_node = this;
    v_children.push_back(cNewChild);
}

int CNodeDynamic::iGetChildPosition(CNodeDynamic* cNodeDynamic) {
    for (int i = 0; i < iGetChildrenNumber(); i++)
        if (v_children.at(i) == cNodeDynamic)
            return i;

    return -1;
}

void CNodeDynamic::vRemoveChild(CNodeDynamic* cRemoveNode) {
    int iChildPosition = iGetChildPosition(cRemoveNode);
    if (cRemoveNode->pc_parent_node == this) {
        cRemoveNode->pc_parent_node = NULL;
        delete cRemoveNode;
    }
    
    
    if (iChildPosition >= 0) {
       v_children.erase(v_children.begin() + iChildPosition);
    }
        
}
//naprawid
void CNodeDynamic::vPruneByVal(int iVal) {

    queue<CNodeDynamic*> q;

    q.push(this);

    CNodeDynamic* currNode;

    while (!q.empty()) {
        currNode = q.front();//pobieranie z kolejki
        q.pop(); // usuwanie z kolejki
        cout << currNode->i_val << endl;
        for (int i = 0; i < currNode->v_children.size(); i++) {
            cout << "\t" << currNode->v_children.at(i)->i_val << endl;
            bool flag = currNode->v_children.at(i)->i_val == iVal;
            if (flag) { // do usuniecia
                if (currNode->v_children.at(i)->iGetChildrenNumber() > 0) {
                    for (int ii = 0; ii < currNode->v_children.at(i)->v_children.size(); ii++) {
                        if (currNode->v_children.at(i)->v_children.at(ii) != NULL) {
                            cout << "\t\t" << currNode->v_children.at(i)->v_children.at(ii)->i_val << endl;
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


CNodeDynamic* CNodeDynamic::pcGetParent() {
    return pc_parent_node;
}

CNodeDynamic* CNodeDynamic::pcGetRoot(CNodeDynamic* cNodeDynamic) {
    if (cNodeDynamic->pc_parent_node != NULL)
        pcGetRoot(cNodeDynamic->pc_parent_node);

    return cNodeDynamic;
}

void CNodeDynamic::vPrint() {
    std::cout << " " << i_val;
}

int CNodeDynamic::iGetChildrenNumber() {
    return v_children.size();
}

void CNodeDynamic::vSetValue(int iNewVal) {
    i_val = iNewVal;
}