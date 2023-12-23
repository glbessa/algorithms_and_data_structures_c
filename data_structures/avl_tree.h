#ifndef AVL_TREE_H
#define AVL_TREE_H

#include <stdlib.h>
#include <stdio.h>

typedef struct AVLNode AVLNode;
struct AVLNode {
    void *value;
    AVLNode *left;
    AVLNode *right;
};

// Encapsulate all need to perform operations
typedef struct AVLTree AVLTree;
struct AVLTree {
    AVLNode *root;
    int (*cmp)(const void *a, const void *b);
};

// Create a new avl tree with a compare function
AVLTree *avl_tree_create(int (*cmp)(const void *a, const void *b)) {
    AVLTree *tree = (AVLTree *) malloc(sizeof(AVLTree));
    if (tree == NULL) {
        fprintf(stderr, "Error while creating avl tree!\n");
        return NULL;
    }

    tree->root = NULL;
    tree->cmp = cmp;

    return tree;
}

AVLNode *_avl_tree_create_node() {
    AVLNode *node = (AVLNode *) malloc(sizeof(AVLNode));
    if (node == NULL) {
        fprintf(stderr, "Error while creating node!\n");
    }

    return node;
}

void *avl_tree_search(AVLTree *tree, void *value) {
    AVLNode *actual = tree->root;
    int r;

    while ((r = tree->cmp(actual->value, value)) != 0) {
        if (r == -1)
            actual = actual->left;
        else
            actual = actual->right;

        if (actual == NULL)
            return NULL;
    }

    return NULL;
}

void *avl_tree_search2(AVLTree *tree, void *value) {
    if (tree == NULL)
        return NULL;
    
    return _avl_tree_search_step(tree->root, value, tree->cmp);
}

void *_avl_tree_search_step(AVLNode *node, void *value, int (*cmp)(const void *a, const void *b)) {
    if (node == NULL)
        return NULL;

    int r = cmp(node->value, value);
    if (r == 0)
        return node->value;
    else if (r == -1)
        return _avl_tree_search_step(node->left, value, cmp);
    
    return _avl_tree_search_step(node->right, value, cmp);
}

void avl_tree_insert(AVLTree *tree, void *value) {

}

void avl_tree_remove(AVLTree *tree, void *value) {

}

void _avl_node_right_rotation(AVLNode **root) {
    AVLNode *pivot = (*root)->left;
    (*root)->left = pivot->right;
    pivot->right = (*root);
    *root = pivot;
}

void _avl_node_left_rotation(AVLNode **root) {
    AVLNode *pivot = (*root)->right;
    (*root)->right = pivot->left;
    pivot->left = (*root);
    *root = pivot;
}

void _avl_node_double_right_rotation(AVLNode **root) {
    _avl_node_left_rotation(&((*root)->left));
    _avl_node_right_rotation(root);
}

void _avl_node_double_left_rotation(AVLNode **root) {
    _avl_node_right_rotation(&((*root)->right));
    _avl_node_left_rotation(root);
}

int _tree_height(AVLNode *node) {
    if (node == NULL)
        return 0;

    int left = _tree_height(node->left);
    int right = _tree_height(node->right);

    if (left > right)
        return left + 1;
    
    return right + 1;
}

#endif