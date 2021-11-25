#include "CTreeStatic.h"
using namespace std;

CTreeStatic::CTreeStatic() {
 
}

CTreeStatic::~CTreeStatic() {

}

void CTreeStatic::vPrintTree() {
    c_root.vPrintAllBelow();
}

bool CTreeStatic::bMoveSubtree(CNodeStatic* pcParentNode, CNodeStatic* pcNewChildNode) {
    if (pcParentNode != NULL && pcNewChildNode != NULL) {
        if (pcParentNode->pcGetRoot(pcParentNode) == pcNewChildNode->pcGetRoot(pcNewChildNode)) { // czy te same drzewo
            return false;
        }

        CNodeStatic* pc_parent_temp = pcNewChildNode->pcGetParent(); // czy root drzewa
        if (pc_parent_temp == NULL) {
            return false;
        }

        pcParentNode->vAddNewChild(pcNewChildNode);

        pc_parent_temp->vRemoveChild(pcNewChildNode);

        pcParentNode->vRepairParent();

        return true;
    }

    return false;
}

CNodeStatic* CTreeStatic::pcGetRoot() {
    return(&c_root);
}
