#include <stdio.h>
#include <stdlib.h>
#include "src/headers/Types.h" // This is a workaround and ideally only 1 import binarytree shd be enough
#include "src/headers/Node.h"
#include "src/headers/BinaryTree.h"

void sample1()
{
    printf("\n");
    struct Data data1 = {1, '1', true};
    struct Data data2 = {2, '2', true};
    struct Data data3 = {3, '3', true};
    struct Data data4 = {4, '4', true};
    struct Data data5 = {5, '5', true};

    struct BinaryTree* tree = getTree(data1, INTEGER, true);
    addChildByData(tree->root, data2, INTEGER, true);
    addChildByData(tree->root, data3, INTEGER, false);
    addChildByData((tree->root)->leftChild, data4, INTEGER, true);
    addChildByData(((tree->root)->leftChild)->leftChild, data5, INTEGER, false);
    /*
         1
        / \
       2   3
      / 
     4
      \
       5
    */
    viewTree(*tree, false);

    deleteSubtree(tree->root->leftChild, true);
     /*
         1
        / \
       2   3
    */
    viewTree(*tree, false);


    deleteSubtree(tree->root, true);
    /*
        1
         \
          3
    */
   viewTree(*tree, false);
}

void sample2()
{
    printf("\n");
    struct Data data1 = {1, '1', true};
    struct Data data2 = {2, '2', true};
    struct Data data3 = {3, '3', true};
    struct Data data4 = {4, 'f', true};
    struct Data data5 = {5, '5', true};

    struct BinaryTree* tree = getTree(data1, INTEGER, false);
    addChildByData(tree->root, data2, INTEGER, true);
    addChildByData(tree->root, data3, BOOLEAN, false);
    addChildByData((tree->root)->leftChild, data4, CHARACTER, true);
    addChildByData(((tree->root)->leftChild)->leftChild, data5, INTEGER, false);
    /*
         1
        / \
       2   3
      / 
     4
      \
       5
    */
    viewTree(*tree, false);

    deleteSubtree(tree->root->leftChild, true);
     /*
         1
        / \
       2   3
    */
    viewTree(*tree, false);


    deleteSubtree(tree->root, true);
    /*
        1
         \
          3
    */
   viewTree(*tree, false);
}


int main()
{
    sample1();
    sample2();
    // TODO what if a node is added as its own child? or if same node is a child of different nodes?
    // TODO memory leaks?
    // TODO show error when user tries to add a child to a node that is null using the addchild functions

    return 0;
}