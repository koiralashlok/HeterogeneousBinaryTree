#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include "headers/Types.h"
#include "headers/Node.h"
#include "headers/BinaryTree.h"

/**
 * Get a new BinaryTree
 * 
 * @param data Data struct to initialize the root node
 * @param treeDataType Data type for the tree
 * @param isHomogenous Should the tree be homogenous
 * 
 * @returns a BinaryTree with given parameters
 */
struct BinaryTree* getTree(struct Data data, enum DataType treeDataType, bool homogenousTree)
{
    // First node will be of the same data type as the tree
    struct Node* root = getNode(data, treeDataType);
    struct BinaryTree* btree = malloc(sizeof (struct BinaryTree));
    btree->root = root;
    btree->type=treeDataType;
    btree->isHomogenous = homogenousTree;

    return btree;
}

/**
 * Deletes and frees all descendents of @param node
 * 
 * @returns error code
 */
int deleteAllDescendents(struct Node* node)
{
    // Reached children of a leaf
    if(node == NULL)
        return 0;
    
    // Recursively delete left and right descendants
    deleteAllDescendents(node->leftChild) + deleteAllDescendents(node->rightChild);

    // These will have been freed in the previous call in the stack
    node->leftChild = NULL;
    node->rightChild = NULL;
    free(node);

    return 0;
}

/**
 * Deletes subtree rooted at @param node
 * 
 * @param deleteLeftSubtree true if left subtree should be deleted, false for right subtree
 * 
 * @returns error code
 */
int deleteSubtree(struct Node* node, bool deleteLeftSubtree)
{
    int retval = 1;
    switch (deleteLeftSubtree)
    {
    case true:
        retval = deleteAllDescendents(node->leftChild);
        node->leftChild = NULL;
        break;
    
    default:
        retval = deleteAllDescendents(node->rightChild);
        node->rightChild = NULL;
        break;
    }
    return retval;
}
/**
 * Add @param child node to be child of @param parent node
 * Can add entire subtree rooted at @param child node
 * 
 * @param addLeftChild true if @param child should be a left child false if right child
 * 
 * @returns error code
 */
int addChildByNode(struct Node* parent, struct Node* child, bool addLeftChild)
{
    switch (addLeftChild)
    {
    case true:
        if(parent->leftChild != NULL)
            {
                // TODO: Is this totally mem safe
                if(deleteSubtree(parent, addLeftChild))
                    return 1;
            }

        // Set left child pointer to be newly created child
        parent->leftChild = child;
        break;
        
    default:
        if(parent->rightChild != NULL)
            {
                // TODO: Is this totally mem safe
                if(deleteSubtree(parent, addLeftChild))
                    return 1;
            }

        // Set right child pointer to be newly created child
        parent->rightChild = child;
        break;
    }
    return 0;
}

/**
 * Overwrites already existent child and descendants
 * 
 * @param parent node to add child to
 * @param data data for new child node
 * @param type provided only used if tree is not homogenous
 * @param childDataType data type for new child node
 * @param addLeftChild true if @param child should be a left child false if right child
 * 
 * @returns error code
 */
int addChildByData(struct Node* parent, struct Data data, enum DataType childDataType, bool addLeftChild)
{
    // Allocate memory for the new child
    struct Node* newChild = malloc(sizeof (struct Node));
    if(newChild == NULL)
        return 1;
    
    // Set data
    // does this work if data is not a pointer? is it possible that it will update locally but not to the caller?
    newChild->data = data;
    newChild->type = childDataType;

    // Start out as a leaf
    newChild->leftChild = newChild->rightChild = NULL;

    return addChildByNode(parent, newChild, addLeftChild);
}

/**
 * Traverse tree rooted at @param root in DFS order
 * 
 * @param treeType to use if tree is homogenous
 * @param isHomogenous true if tree to be traversed is homogenous
 */
static void dfs(struct Node* root, enum DataType treeType, bool isHomogenous)
{
    if(root == NULL)
        return;
    
    if(root->leftChild != NULL)
        dfs(root->leftChild, treeType, isHomogenous);
    if(root->rightChild != NULL)
        dfs(root->rightChild, treeType, isHomogenous);

    printNodeData(*root, treeType, isHomogenous);
}

/**
 * View @param tree
 * 
 * @param doBFS true for BFS traversal, false for DFS
 * @note BFS is still unimplemented so only DFS traversal is done
 */
void viewTree(struct BinaryTree tree, bool doBfs)
{
    switch(doBfs)
    {
        case true:
            dfs(tree.root, tree.type, tree.isHomogenous);
            break;

        default:
            // rip queues lol
            // shd be bfs
            dfs(tree.root, tree.type, tree.isHomogenous);
    }
    printf("\n");
}