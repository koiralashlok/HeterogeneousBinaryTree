#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "headers/Types.h"
#include "headers/Node.h"

struct Node* getNode(struct Data data)
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

    return newNode;
}

void printNodeData(struct Node node, enum DataType treeType)
{
    struct Data data = node.data;
    switch (treeType)
    {
        case INTEGER:
            printf("%d", data.integerData);
            break;
        case CHARACTER:
            printf("%c", data.charData);
            break;
        case BOOLEAN:
            printf("%s", data.booleanData ? "true" : "false");
            break;
        default:
            // TODO SOEMTHING!!!
            printf("%d is not a valid enum value for DataType!\n", treeType);
            printf("Skipping print...\n");
            break;
    }
}