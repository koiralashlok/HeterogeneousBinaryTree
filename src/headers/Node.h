#ifndef NODE
#define NODE
#include <stdbool.h>

struct Node
{
    struct Data data;
    struct Node* leftChild;
    struct Node* rightChild;
    enum DataType type;
};

struct Node* getNode(struct Data data, enum DataType nodeDataType);
void printNodeData(struct Node node, enum DataType treeType, bool isHomogenous);

#endif