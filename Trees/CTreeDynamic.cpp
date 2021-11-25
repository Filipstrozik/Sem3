#include "CTreeDynamic.h"

CTreeDynamic::CTreeDynamic() {
    pc_root = new CNodeDynamic();
}

CTreeDynamic::~CTreeDynamic() {
    delete pc_root;
}

void CTreeDynamic::vPrintTree() {
    pc_root->vPrintAllBelow();
}

bool CTreeDynamic::bMoveSubtree(CNodeDynamic* pcParentNode, CNodeDynamic* pcNewChildNode) {
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

CNodeDynamic* CTreeDynamic::pcGetRoot() {
    return pc_root;
}