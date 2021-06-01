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
typedef struct tree Tree;

Node *addNode(int x, Node *node);
extern Node *findClosest(Node *node, Node *root);
void removeNode(Node *node, Tree *tree);
Node *findNode(int x, Node *root);
void removeWith(int x, Tree *tree);
int calcChild(Node *node);
extern Node *Max(Node *root, Node *max);
Node *findMax(Tree *tree);
struct tree create(int x);
extern void hPrint(Node *node, int d);
void tprint(Tree *node, int d);

#endif //LABA5_STREE_H
