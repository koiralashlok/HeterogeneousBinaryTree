#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "../src/headers/Types.h"
#include "../src/headers/BinaryTree.h"
#include "../src/headers/Node.h"

// Helper function to check if the tree is empty
int isTreeEmpty(struct BinaryTree* tree) {
    return (tree->root == NULL);
}

// Helper function to create a test tree
struct BinaryTree* createTestTree() {
    struct Data data1 = {1, '1', true};
    struct BinaryTree* tree = getTree(data1, INTEGER, true);
    return tree;
}

void testAddChildByNode() {
    struct BinaryTree* tree = createTestTree();
    struct Data data2 = {2, '2', true};
    struct Node* newNode = getNode(data2, INTEGER);

    // Add new node as left child of root
    int result = addChildByNode(tree->root, newNode, true);
    assert(result == 0);  // Should succeed

    // Verify if left child is correctly set
    assert(tree->root->leftChild == newNode);

    // Clean up
    free(tree);
    free(newNode);
}

void testDeleteSubtree() {
    struct BinaryTree* tree = createTestTree();
    struct Data data2 = {2, '2', true};
    struct Data data3 = {3, '3', true};
    
    // Add left and right children
    addChildByData(tree->root, data2, INTEGER, true);  // Left
    addChildByData(tree->root, data3, INTEGER, false); // Right

    // Now the tree looks like:
    //     1
    //   /   \
    //  2     3

    // Delete left subtree
    deleteSubtree(tree->root, true);

    // Verify if left child is deleted
    assert(tree->root->leftChild == NULL);

    // Clean up
    free(tree);
}

void testDFS() {
    struct BinaryTree* tree = createTestTree();
    struct Data data2 = {2, '2', true};
    struct Data data3 = {3, '3', true};
    
    // Add left and right children
    addChildByData(tree->root, data2, INTEGER, true);
    addChildByData(tree->root, data3, INTEGER, false);

    // Capture the DFS output
    // Expected order for DFS: 2 -> 3 -> 1
    viewTree(*tree, false);  // Should print: 2 3 1

    // Clean up
    free(tree);
}

void testTreeInitialization() {
    struct Data data1 = {1, '1', true};
    struct BinaryTree* tree = getTree(data1, INTEGER, true);

    // Verify the root node data
    assert(tree->root != NULL);
    assert(tree->root->data.integerData == 1);
    assert(tree->root->type == INTEGER);

    // Clean up
    free(tree);
}

void testIsTreeEmpty() {
    struct BinaryTree* tree = createTestTree();

    // Tree should not be empty after initialization
    assert(!isTreeEmpty(tree));

    // Clean up
    free(tree);
}

int main() {
    printf("Running testAddChildByNode...\n");
    testAddChildByNode();
    printf("testAddChildByNode passed.\n\n");

    printf("Running testDeleteSubtree...\n");
    testDeleteSubtree();
    printf("testDeleteSubtree passed.\n\n");

    printf("Running testDFS...\n");
    testDFS();
    printf("testDFS passed.\n\n");

    printf("Running testTreeInitialization...\n");
    testTreeInitialization();
    printf("testTreeInitialization passed.\n\n");

    printf("Running testIsTreeEmpty...\n");
    testIsTreeEmpty();
    printf("testIsTreeEmpty passed.\n\n");

    return 0;
}
