//
// Created by eke_l on 2021/4/21.
//

#ifndef BINARYSORTTREE_BINARY_SORT_TREE_H
#define BINARYSORTTREE_BINARY_SORT_TREE_H


#define Status int

typedef int ElemType;

typedef struct Node {
    ElemType value;
    struct Node* left, * right;
}Node, * NodePtr;

typedef struct BinarySortTree {
    NodePtr root = nullptr;
    int nodenum = 0;
} BinarySortTree, * BinarySortTreePtr;

extern bool isinit;
/**
 * BST initialize
 * @param BinarySortTreePtr BST
 * @return is complete
 */
Status BST_init(BinarySortTreePtr tree);

/**
 * BST insert
 * @param BinarySortTreePtr BST
 * @param ElemType value to insert
 * @return is successful
 */
Status BST_insert(BinarySortTreePtr tree, ElemType value);

/**
 * BST delete
 * @param BinarySortTreePtr BST
 * @param ElemType the value for Node which will be deleted
 * @return is successful
 */
Status BST_delete(BinarySortTreePtr tree, ElemType value);

/**
 * BST search
 * @param BinarySortTreePtr BST
 * @param ElemType the value to search
 * @return is exist
 */
Status BST_search(BinarySortTreePtr tree, ElemType value);

Status BST_preorderI(BinarySortTreePtr tree);

Status BST_preorderR(BinarySortTreePtr tree);

Status BST_inorderI(BinarySortTreePtr tree);

Status BST_inorderR(BinarySortTreePtr tree);

Status BST_postorderI(BinarySortTreePtr tree);

Status BST_postorderR(BinarySortTreePtr tree);

Status BST_levelOrder(BinarySortTreePtr tree);

/**
 * BST preorder traversal without recursion
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
Status BST_preorderI(BinarySortTreePtr tree );

/**
 * BST preorder traversal with recursion
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
Status BST_preorderR(BinarySortTreePtr tree );

/**
 * BST inorder traversal without recursion
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
Status BST_inorderI(BinarySortTreePtr tree );

/**
 * BST inorder traversal with recursion
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
Status BST_inorderR(BinarySortTreePtr tree );

/**
 * BST preorder traversal without recursion
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
Status BST_postorderI(BinarySortTreePtr tree );

/**
 * BST postorder traversal with recursion
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
Status BST_postorderR(BinarySortTreePtr tree );

/**
 * BST level order traversal
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
Status BST_levelOrder(BinarySortTreePtr tree );

void preorder(Node* p);

void inorder(Node* p);

void postorder(Node* p);

#endif //BINARYSORTTREE_BINARY_SORT_TREE_H
