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
Node *findClosest(Node *node, Node *root);
void removeNode(Node *node, Tree *tree);
Node *hFind(int x, Node *root);
Node *findNode(int x, Tree *tree);
void removeWith(int x, Tree *tree);
int calcChild(Node *node);
Node *Max(Node *root, Node *max);
Node *findMax(Tree *tree);
struct tree create(int x);
void hPrint(Node *node, int d);
void tprint(Tree *tree);
Node *findParent(Node *node, Tree *tree);

#endif //LABA5_STREE_H
