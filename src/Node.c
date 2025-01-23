#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "headers/Types.h"
#include "headers/Node.h"

/**
 * Get a new node
 * 
 * @param data data for new node
 * @param nodeDataType data type for new node
 * 
 * @returns a node initialized using given parameters
 */
struct Node* getNode(struct Data data, enum DataType nodeDataType)
{
    // struct Data dataForNode = {typeOfData, 0, 0, false};
    
    // switch (typeOfData)
    // {
    //     case 'i':
    //         dataForNode.integerData = *(int*)data;
    //         break;
    //     case 'c':
    //         dataForNode.charData = *(char*)data;
    //         break;
    //     case 'b':
    //         dataForNode.booleanData = *(bool*)data;
    //         break;
    //     default:
    //         // TODO SOEMTHING!!!
    //         printf("%c is not a type!\n", typeOfData);
    //         printf("Expect erroneous behavior\n", typeOfData);
    //         break;
    // }

    struct Node* newNode = malloc(sizeof (struct Node));
    newNode->data = data;
    newNode->leftChild = newNode->rightChild = NULL;
    newNode->type = nodeDataType;

    return newNode;
}

/**
 * Print the data stored in the node depending on tree type or its data type
 * 
 * @param node node whose data is to be printed
 * @param treeType data type of tree of @param node
 * @param isHomogenous true if @param node's tree is homogenous
 */
void printNodeData(struct Node node, enum DataType treeType, bool isHomogenous)
{
    struct Data data = node.data;
    switch (isHomogenous ? treeType : node.type)
    {
        case INTEGER:
            printf("%d\t", data.integerData);
            break;
        case CHARACTER:
            printf("%c\t", data.charData);
            break;
        case BOOLEAN:
            printf("%s\t", data.booleanData ? "true" : "false");
            break;
        default:
            // TODO SOEMTHING!!!
            printf("%d is not a valid enum value for DataType!\n", treeType);
            printf("Skipping print...\n");
            break;
    }
}