#ifndef LABA5_STREE_H
#define LABA5_STREE_H

#define Node struct node
Node {
    int data;
    Node *down;//самый левый ребенок
    Node *right;//брат справа
};

struct tree {
    Node *root;
};
typedef struct tree tree;

Node *addNode(int x, Node *tree);
Node *findClosest(Node *node, Node*root);
void removeNode(Node *node, Node *root);
Node *findNode(int x, Node *root);
void removeWith(int x, Node *node, Node *root);
int calcChild(Node *node);
Node *Max(Node *root, Node *max);
struct node *findMax(Node *root);
struct tree create(int x);
void f_print(Node *node, int d);
void tPrint(Node *node, int d);

#endif //LABA5_STREE_H
