#ifndef ASP_DOMACI_REWORK_GRAPH_H
#define ASP_DOMACI_REWORK_GRAPH_H

/*Klasa koja predstavlja graf pomocu matrica susednosti. Graf se obilazi upotrebom DFS algoritma. Takodje, u grafu
 * postoji pomocna struktura string* array u kojoj se vodi evidencija o imenima svih cvorova u grafu.*/

#include <string>
using namespace std;

class Tree;

class Graph {
public:
    Graph& transformTree(Tree* tree);

    Graph& traversal(bool* cvor);

    Graph& detectRecursion();

    bool* getNode(int num) const;

protected:
    int getMaxNum() const { return max_num; }

    int findPosition(string s) const;

    bool** copyMatrix() const;

    bool checkRecursion(bool** m) const;

private:
    int max_num = 30;
    bool** matrix;
    int size = 0;
    string* array = nullptr;
};

#endif //ASP_DOMACI_REWORK_GRAPH_H
