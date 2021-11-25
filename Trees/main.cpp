#include <iostream>
#include "CTreeStatic.h"
#include "CTreeDynamic.h"


void vTestStatic() {
    
    CTreeStatic c_tree;
    CNodeStatic* c_root = c_tree.pcGetRoot();
    c_root->vAddNewChild();
    c_root->vAddNewChild();
    c_root->pcGetChild(0)->vSetValue(1);
    c_root->pcGetChild(1)->vSetValue(2);
    c_root->pcGetChild(0)->vAddNewChild();
    c_root->pcGetChild(0)->vAddNewChild();
    c_root->pcGetChild(0)->pcGetChild(0)->vSetValue(11);
    c_root->pcGetChild(0)->pcGetChild(1)->vSetValue(12);
    c_root->pcGetChild(1)->vAddNewChild();
    c_root->pcGetChild(1)->vAddNewChild();
    c_root->pcGetChild(1)->pcGetChild(0)->vSetValue(21);
    c_root->pcGetChild(1)->pcGetChild(1)->vSetValue(22);
    c_tree.vPrintTree();
}

void vTestDynamic() {
    CTreeDynamic c_tree;
    CNodeDynamic* c_root = c_tree.pcGetRoot();
    c_root->vAddNewChild();
    c_root->vAddNewChild();
    c_root->pcGetChild(0)->vSetValue(1);
    c_root->pcGetChild(1)->vSetValue(2);
    c_root->pcGetChild(0)->vAddNewChild();
    c_root->pcGetChild(0)->vAddNewChild();
    c_root->pcGetChild(0)->pcGetChild(0)->vSetValue(11);
    c_root->pcGetChild(0)->pcGetChild(1)->vSetValue(12);
    c_root->pcGetChild(1)->vAddNewChild();
    c_root->pcGetChild(1)->vAddNewChild();
    c_root->pcGetChild(1)->pcGetChild(0)->vSetValue(21);
    c_root->pcGetChild(1)->pcGetChild(1)->vSetValue(22);
    c_tree.vPrintTree();
}

void vTestStaticMoveSubTree() {

    CTreeStatic c_tree1;
    CNodeStatic* c_root1 = c_tree1.pcGetRoot();
    c_root1->vAddNewChild();
    c_root1->vAddNewChild();
    c_root1->pcGetChild(0)->vSetValue(1);
    c_root1->pcGetChild(1)->vSetValue(2);
    c_root1->pcGetChild(0)->vAddNewChild();
    c_root1->pcGetChild(0)->pcGetChild(0)->vSetValue(3);
    c_tree1.vPrintTree();
    cout << endl;
    CTreeStatic c_tree2;
    CNodeStatic* c_root2 = c_tree2.pcGetRoot();
    c_root2->vAddNewChild();
    c_root2->vAddNewChild();
    c_root2->pcGetChild(0)->vSetValue(54);
    c_root2->pcGetChild(1)->vSetValue(55);
    c_root2->pcGetChild(0)->vAddNewChild();
    c_root2->pcGetChild(0)->vAddNewChild(); 
    c_root2->pcGetChild(0)->pcGetChild(0)->vSetValue(56);
    c_root2->pcGetChild(0)->pcGetChild(1)->vSetValue(57);
    c_root2->pcGetChild(0)->pcGetChild(0)->vAddNewChild();
    c_root2->pcGetChild(0)->pcGetChild(0)->pcGetChild(0)->vSetValue(58);

    c_tree2.vPrintTree();

    c_tree1.bMoveSubtree(c_root1->pcGetChild(0), c_root2->pcGetChild(0));
    cout << endl;
    c_tree1.vPrintTree();
    cout << endl;
    c_tree2.vPrintTree();
    cout <<"w gore_1: " << endl;
    c_tree1.pcGetRoot()->pcGetChild(0)->pcGetChild(1)->pcGetChild(0)->pcGetChild(0)->vPrintUp();
    cout << "w gore_2: " << endl;
    c_tree2.pcGetRoot()->pcGetChild(0)->vPrintUp();
    cout << "parent wezla do usuniecia:" << endl;
    c_tree1.pcGetRoot()->pcGetChild(0)->pcGetChild(1)->vPrint();
    cout << endl;
    cout << "wezel do usuniecia:" << endl;
    c_tree1.pcGetRoot()->pcGetChild(0)->pcGetChild(1)->pcGetChild(0)->vPrint();
    cout << endl;
    c_tree1.pcGetRoot()->pcGetChild(0)->pcGetChild(1)->vRemoveChild(c_tree1.pcGetRoot()->pcGetChild(0)->pcGetChild(1)->pcGetChild(0));

    cout << endl;
    c_tree1.vPrintTree();

}

void vTestDynamicMoveSubTree() {

    CTreeDynamic c_tree1;
    CNodeDynamic* c_root1 = c_tree1.pcGetRoot();
    c_root1->vAddNewChild();
    c_root1->vAddNewChild();
    c_root1->pcGetChild(0)->vSetValue(1);
    c_root1->pcGetChild(1)->vSetValue(2);
    c_root1->pcGetChild(0)->vAddNewChild();
    c_root1->pcGetChild(0)->pcGetChild(0)->vSetValue(3);
    c_tree1.vPrintTree();
    cout << endl;
    CTreeDynamic c_tree2;
    CNodeDynamic* c_root2 = c_tree2.pcGetRoot();
    c_root2->vAddNewChild();
    c_root2->vAddNewChild();
    c_root2->pcGetChild(0)->vSetValue(54);
    c_root2->pcGetChild(1)->vSetValue(55);
    c_root2->pcGetChild(0)->vAddNewChild();
    c_root2->pcGetChild(0)->vAddNewChild();
    c_root2->pcGetChild(0)->pcGetChild(0)->vSetValue(56);
    c_root2->pcGetChild(0)->pcGetChild(1)->vSetValue(57);
    c_root2->pcGetChild(0)->pcGetChild(0)->vAddNewChild();
    c_root2->pcGetChild(0)->pcGetChild(0)->pcGetChild(0)->vSetValue(58);

    c_tree2.vPrintTree();
    cout << endl;
    c_root2->pcGetChild(0)->vPrintUp();
    cout << endl;
    c_tree1.bMoveSubtree(c_root1->pcGetChild(0), c_root2->pcGetChild(0));

    c_tree1.vPrintTree();
    cout << endl;
    c_tree2.vPrintTree();
    cout <<"going up from :" << endl;
    c_root1->pcGetChild(0)->pcGetChild(1)->pcGetChild(0)->pcGetChild(0)->vPrintUp();
    cout << endl;

    c_root1->pcGetChild(0)->pcGetChild(0)->vPrintUp();
    cout << endl;
    c_root1->pcGetChild(0)->pcGetChild(1)->vPrintUp();
    cout << endl;
    cout << endl;
    c_root1->pcGetChild(0)->pcGetChild(1)->pcGetChild(0)->vPrintUp();
    c_root1->pcGetChild(0)->pcGetChild(1)->vRemoveChild(c_root1->pcGetChild(0)->pcGetChild(1)->pcGetChild(0));
    c_tree1.vPrintTree();

}
void vTestDynamicSubTreeOther()
{
    cout << endl << "vMoveSubTreeTest() - dynamic nodes" << endl;
    CTreeDynamic c_tree_dyn1, c_tree_dyn2;

    c_tree_dyn1.pcGetRoot()->vSetValue(0);
    c_tree_dyn1.pcGetRoot()->vAddNewChild();
    c_tree_dyn1.pcGetRoot()->vAddNewChild();
    c_tree_dyn1.pcGetRoot()->vAddNewChild();
    c_tree_dyn1.pcGetRoot()->pcGetChild(0)->vSetValue(1);
    c_tree_dyn1.pcGetRoot()->pcGetChild(1)->vSetValue(2);
    c_tree_dyn1.pcGetRoot()->pcGetChild(2)->vSetValue(3);
    c_tree_dyn1.pcGetRoot()->pcGetChild(2)->vAddNewChild();
    c_tree_dyn1.pcGetRoot()->pcGetChild(2)->pcGetChild(0)->vSetValue(4);

    c_tree_dyn2.pcGetRoot()->vSetValue(50);
    c_tree_dyn2.pcGetRoot()->vAddNewChild();
    c_tree_dyn2.pcGetRoot()->vAddNewChild();
    c_tree_dyn2.pcGetRoot()->pcGetChild(0)->vSetValue(54);
    c_tree_dyn2.pcGetRoot()->pcGetChild(1)->vSetValue(55);
    c_tree_dyn2.pcGetRoot()->pcGetChild(0)->vAddNewChild();
    c_tree_dyn2.pcGetRoot()->pcGetChild(0)->vAddNewChild();
    c_tree_dyn2.pcGetRoot()->pcGetChild(0)->pcGetChild(0)->vSetValue(56);
    c_tree_dyn2.pcGetRoot()->pcGetChild(0)->pcGetChild(1)->vSetValue(57);
    c_tree_dyn2.pcGetRoot()->pcGetChild(0)->pcGetChild(0)->vAddNewChild();
    c_tree_dyn2.pcGetRoot()->pcGetChild(0)->pcGetChild(0)->pcGetChild(0)->vSetValue(58);

    cout << "Before moving subtree" << endl;
    c_tree_dyn1.vPrintTree();
    cout << endl;
    c_tree_dyn2.vPrintTree();

    CNodeDynamic* pcParent = c_tree_dyn1.pcGetRoot()->pcGetChild(2);
    CNodeDynamic* pcChild = c_tree_dyn2.pcGetRoot()->pcGetChild(0);
    c_tree_dyn1.bMoveSubtree(pcParent, pcChild);
    cout << endl << "After moving subtree" << endl;

    c_tree_dyn1.vPrintTree();
    cout << endl;
    c_tree_dyn2.vPrintTree();
} //void vMoveSubTreeDynamic()

void vTesting() {
    CTreeStatic c_tree1,c_tree2;
    
    c_tree1.pcGetRoot()->vSetValue(1);

    c_tree2.pcGetRoot()->vSetValue(50);
    c_tree2.pcGetRoot()->vAddNewChild();
    c_tree2.pcGetRoot()->vAddNewChild();
    c_tree2.pcGetRoot()->pcGetChild(0)->vSetValue(54);
    c_tree2.pcGetRoot()->pcGetChild(1)->vSetValue(55);
    c_tree2.pcGetRoot()->pcGetChild(0)->vAddNewChild();
    c_tree2.pcGetRoot()->pcGetChild(0)->vAddNewChild();
    c_tree2.pcGetRoot()->pcGetChild(0)->pcGetChild(0)->vSetValue(56);
    c_tree2.pcGetRoot()->pcGetChild(0)->pcGetChild(1)->vSetValue(57);
    c_tree2.pcGetRoot()->pcGetChild(0)->pcGetChild(0)->vAddNewChild();
    c_tree2.pcGetRoot()->pcGetChild(0)->pcGetChild(0)->pcGetChild(0)->vSetValue(58);
    cout << endl << endl;
    c_tree1.vPrintTree();
    cout << endl << endl;
    c_tree2.vPrintTree();
    cout << endl << endl;
    c_tree2.pcGetRoot()->pcGetChild(0)->pcGetChild(0)->pcGetChild(0)->vPrintUp();
    cout << endl << endl;
    cout << "przenoszenie" << endl;
    c_tree1.bMoveSubtree(c_tree1.pcGetRoot(), c_tree2.pcGetRoot()->pcGetChild(0));


    cout << endl << endl;
    c_tree1.vPrintTree();
    cout << endl << endl;
    c_tree2.vPrintTree();
    cout << endl << endl;

    cout << "w gore i w dol" << endl;
    cout << endl;
    c_tree1.pcGetRoot()->pcGetChild(0)->vPrintUp();
    cout << endl;
    c_tree1.pcGetRoot()->pcGetChild(0)->pcGetChild(0)->vPrintUp();
    cout << endl;
    c_tree1.pcGetRoot()->pcGetChild(0)->pcGetChild(1)->vPrintUp();
    cout << endl;
    c_tree1.pcGetRoot()->pcGetChild(0)->pcGetChild(0)->pcGetChild(0)->vPrintUp();


}

void vKonstruktoryDestruktory() {
    cout << "debug 1" << endl;
    CNodeStatic nowyNode;
    cout << "debug 2" << endl;
    nowyNode.vSetValue(1);
    cout << "debug 3" << endl;
    nowyNode.vAddNewChild();
    cout << "debug 4" << endl;
    nowyNode.pcGetChild(0)->vSetValue(2);
    cout << "debug 5" << endl;
    nowyNode.pcGetChild(0)->vAddNewChild();
    cout << "debug 6" << endl;
    nowyNode.pcGetChild(0)->pcGetChild(0)->vSetValue(3);
    cout << "debug 7" << endl;

    cout << "debug 11" << endl;
    CNodeDynamic nowyNodeD;
    cout << "debug 12" << endl;
    nowyNodeD.vSetValue(1);
    cout << "debug 13" << endl;
    nowyNodeD.vAddNewChild();
    cout << "debug 14" << endl;
    nowyNodeD.pcGetChild(0)->vSetValue(2);
    cout << "debug 15" << endl;
    nowyNodeD.pcGetChild(0)->vAddNewChild();
    cout << "debug 16" << endl;
    nowyNodeD.pcGetChild(0)->pcGetChild(0)->vSetValue(3);
    cout << "debug 17" << endl;
}
void vModyfikacja() {
    CTreeDynamic c_tree;
    c_tree.pcGetRoot()->vSetValue(0);
    c_tree.pcGetRoot()->vAddNewChild();
    c_tree.pcGetRoot()->vAddNewChild();
    c_tree.pcGetRoot()->pcGetChild(0)->vSetValue(1);
    c_tree.pcGetRoot()->pcGetChild(1)->vSetValue(0);
    c_tree.pcGetRoot()->pcGetChild(0)->vAddNewChild();
    c_tree.pcGetRoot()->pcGetChild(0)->vAddNewChild();
    c_tree.pcGetRoot()->pcGetChild(1)->vAddNewChild();
    c_tree.pcGetRoot()->pcGetChild(1)->vAddNewChild();
    c_tree.pcGetRoot()->pcGetChild(0)->pcGetChild(0)->vSetValue(2);
    c_tree.pcGetRoot()->pcGetChild(0)->pcGetChild(1)->vSetValue(3);
    c_tree.pcGetRoot()->pcGetChild(1)->pcGetChild(0)->vSetValue(1);
    c_tree.pcGetRoot()->pcGetChild(1)->pcGetChild(1)->vSetValue(0);

    c_tree.vPrintTree();
    cout << endl;

    c_tree.pcGetRoot()->vPruneByVal(1);
    cout << endl;
    cout << endl;

    c_tree.vPrintTree();


}

int main() {
    //cout << "Test drzewa statycznego:" << endl;
    //vTestStatic();
    //cout << "Test drzewa dynamicznego:" << endl;
    //vTestDynamic();
    //cout << "Test drzewa statycznego przenoszenie:" << endl;
    //vTestStaticMoveSubTree();
    //cout << "Test drzewa dynamicznego przenoszenie:" << endl;
    //vTestDynamicMoveSubTree();
    //cout << "dodatkowy test" << endl;
    //vTestDynamicSubTreeOther();
    //cout << "TESTING.." << endl;
    //vTesting();

    //vKonstruktoryDestruktory();
    vModyfikacja();
    return 0;
}