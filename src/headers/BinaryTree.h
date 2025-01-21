#ifndef BINARY_TREE
#define BINARY_TREE
#include <stdbool.h>

struct BinaryTree
{
    struct Node* root;
    enum DataType type;
};

struct BinaryTree* getTree(struct Data data, enum DataType treeDataType);
int deleteAllDescendents(struct Node* node);
int deleteSubtree(struct Node* node, bool deleteLeftSubtree);
int addChildByNode(struct Node* parent, struct Node* child, bool addLeftChild);
int addChildByData(struct Node* parent, struct Data data, bool addLeftChild);
void viewTree(struct BinaryTree tree, bool doBfs);

#endif