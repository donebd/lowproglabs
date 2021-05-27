#include <stdio.h>
#include "stdlib.h"
#include "stree.h"

Node *addNode(int x, Node *tree) {//возвращает адрес ребенка
    Node *new;
    if (tree == NULL) {
        tree = (Node *) malloc(sizeof(Node));
        tree->data = x;
        tree->down = tree->right = NULL;
        new = tree;
    } else {
        if (tree->down == NULL) {
            tree->down = (Node *) malloc(sizeof(Node));
            tree->down->data = x;
            tree->down->down = tree->down->right = NULL;
            new = tree->down;
        } else {
            Node *child = tree->down;
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

Node *findClosest(Node *node, Node *root) {//найти или брата слева или предка
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

void removeNode(Node *node, Node *root) {
    if (node == NULL)return;
    removeNode(node->down, root);
    if (node->right != NULL) {
        node->data = node->right->data;
        node->down = node->right->down;
        node->right = node->right->right;
    } else {
        Node *closest = findClosest(node, root);
        if (closest == NULL) {
            removeNode(node->down, root);
            root->data = -1;
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

Node *findNode(int x, Node *root) {//найти первый узел с параметром
    if (root == NULL) return NULL;
    Node *findRight = NULL;
    Node *findDown = NULL;
    if (root->data == x) {
        return root;
    }
    if (root->right != NULL) findRight = findNode(x, root->right);
    if (root->down != NULL) findDown =  findNode(x, root->down);
    if (findRight != NULL) return findRight;
    if (findDown != NULL) return findDown;
    return NULL;
}

void removeWith(int x, Node *node, Node *root) {//удалить первый узел с параметром
    removeNode(findNode(x, node), root);
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

Node *Max(Node *root, Node *max) {
    if (max->data < root->data) max = root;
    if (root->right != NULL) max = Max(root->right, max);
    if (root->down != NULL) max = Max(root->down, max);
    return max;
}

Node *findMax(Node *root) {
    if (root == NULL) return NULL;
    Node *max = Max(root, root);
    return max;
}

struct tree create(int x) {
    Node *root = addNode(x, NULL);
    struct tree new;
    new.root = root;
    return new;
}

void tPrint(Node *node, int d) {
    if (node == NULL) return;
    for (int i = 0; i < d; i++)
        printf(" ");
    printf("%d\n", node->data);
    tPrint(node->down, d + 3);
    tPrint(node->right, d);
}

void f_print(Node *node, int d) {//вывод дерева в консоль
    if (node == NULL) return;
    printf("---------Tree----------\n");
    tPrint(node,d);
    printf("-----------------------\n");
}
