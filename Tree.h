#ifndef ASP_DOMACI_REWORK_TREE_H
#define ASP_DOMACI_REWORK_TREE_H

/*Klasa koja predstavlja m-arno stablo. Stablo se gradi po principu "najlevlji sin - desni brat."*/

#include "queue.h"
#include <string>

class Elem;

using namespace std;

class Tree {
public:
    Tree();

    Tree& formTree(Queue<string>* q);

    Tree& insertStack(Queue<string>* q);

    Tree& deleteStack(Queue<string>* q);

    Tree& traversal();

    Tree& deleteTree();

    ~Tree();

    friend class Queue<Elem>;

    Elem* root = nullptr;
};


#endif //ASP_DOMACI_REWORK_TREE_H
