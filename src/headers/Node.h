#ifndef NODE
#define NODE
#include <stdbool.h>

struct Node
{
    struct Data data;
    struct Node* leftChild;
    struct Node* rightChild;
};

struct Node* getNode(struct Data data);
void printNodeData(struct Node node, enum DataType treeType);


#endif