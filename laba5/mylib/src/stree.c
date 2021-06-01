#include <stdio.h>
#include "stdlib.h"
#include "stree.h"

Node *addNode(int x, Node *node) {//возвращает адрес ребенка
    Node *new;
    if (node == NULL) {
        node = (Node *) malloc(sizeof(Node));
        node->data = x;
        node->down = node->right = NULL;
        new = node;
    } else {
        if (node->down == NULL) {
            node->down = (Node *) malloc(sizeof(Node));
            node->down->data = x;
            node->down->down = node->down->right = NULL;
            new = node->down;
        } else {
            Node *child = node->down;
            while (child->right != NULL) {//двигаемся в право
                child = child->right;
            }
            child->right = (Node *) malloc(sizeof(Node));
            child->right->data = x;
            child->right->down = child->right->right = NULL;
            new = child->right;
        }
    }
    return new;
}

extern Node *findClosest(Node *node, Node *root) {//найти или брата слева или предка
    if (node == NULL || root == NULL) return NULL;
    if (root->right == node) return root;
    if (root->down == node) return root;
    Node *findRight = NULL;
    Node *findDown = NULL;
    if (root->right != NULL) findRight = findClosest(node, root->right);
    if (root->down != NULL) findDown = findClosest(node, root->down);
    if (findRight != NULL) return findRight;
    if (findDown != NULL) return findDown;
    return NULL;
}

void removeNode(Node *node, Tree *tree) {
    if (node == NULL)return;
    removeNode(node->down, tree);
    if (node->right != NULL) {
        node->data = node->right->data;
        node->down = node->right->down;
        node->right = node->right->right;
    } else {
        Node *closest = findClosest(node, tree->root);
        if (closest == NULL) {
            removeNode(node->down, tree);
            free(tree->root);
            tree->root = NULL;
            return;
        }
        if (closest->right == node) {
            free(closest->right);
            closest->right = NULL;
        }
        if (closest->down == node) {
            free(closest->down);
            closest->down = NULL;
        }
    }
}

extern Node *hFind(int x, Node *root){
    if (root == NULL) return NULL;
    Node *findRight = NULL;
    Node *findDown = NULL;
    if (root->data == x) {
        return root;
    }
    if (root->right != NULL) findRight = hFind(x, root->right);
    if (root->down != NULL) findDown =  hFind(x, root->down);
    if (findRight != NULL) return findRight;
    if (findDown != NULL) return findDown;
    return NULL;
}

Node *findNode(int x, Tree *tree) {//найти первый узел с параметром
    return hFind(x, tree->root);
}

void removeWith(int x, Tree *tree) {//удалить первый узел с параметром
    removeNode(findNode(x, tree), tree);
}

int calcChild(Node *node) {//посчитать число детей узла
    int cnt = 0;
    if (node->down == NULL) return 0;
    Node next = *node->down;
    cnt++;
    while (next.right != NULL) {
        cnt++;
        next = *next.right;
    }
    return cnt;
}

extern Node *Max(Node *root, Node *max) {
    if (max->data < root->data) max = root;
    if (root->right != NULL) max = Max(root->right, max);
    if (root->down != NULL) max = Max(root->down, max);
    return max;
}

Node *findMax(Tree *tree) {
    if (tree->root == NULL) {
        printf("404 Tree not found\n");
        return NULL;
    }
    Node *max = Max(tree->root, tree->root);
    return max;
}

struct tree create(int x) {
    Node *root = addNode(x, NULL);
    struct tree new;
    new.root = root;
    return new;
}

extern void hPrint(Node *node, int d) {
    if (node == NULL) return;
    for (int i = 0; i < d; i++)
        printf(" ");
    printf("%d\n", node->data);
    hPrint(node->down, d + 4);
    hPrint(node->right, d);
}

void tprint(Tree *tree, int d) {//вывод дерева в консоль
    if (tree->root == NULL) {
        printf("404 Tree not found\n");
        return;
    }
    printf("---------Tree----------\n");
    hPrint(tree->root,d);
    printf("-----------------------\n");
}
