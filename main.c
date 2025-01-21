#include <stdio.h>
#include "src/headers/Types.h" // This is a workaround and ideally only 1 import binarytree shd be enough
#include "src/headers/BinaryTree.h"

int test1()
{
    struct Data data1 = {1, '1', true};
    struct Data data2 = {2, '2', true};
    struct Data data3 = {3, '3', true};
    struct Data data4 = {4, '4', true};

    struct BinaryTree* tree = getTree(data1, INTEGER);
    addChildByData(tree->root, data2, true);
    addChildByData(tree->root, data3, false);
    // addChildByData((tree->root)->leftChild, data3, false);
    /*
        1
       / \
      2   3
    //  / 
    // 4
    */

    deleteSubtree(tree->root, true);

    /*
        1
         \
          3
    */

   viewTree(*tree, false); // TODO inadequete, need to iterate thru children
}

int main()
{
    test1();
    // TODO what if a node is added as its own child? or if same node is a child of different nodes?
    // TODO memory leaks?

    return 0;
}