#ifndef ASP_NODE_H_
#define ASP_NODE_H_

/*Klasa koja predstavlja cvor stabla.*/

#include <string>
using namespace std;

class Elem {
public:
    Elem* left, *right, *parent;
    string data;

    Elem(string s, Elem* l = nullptr, Elem* r = nullptr, Elem* p = nullptr)
     : data(s), left(l), right(r), parent(p) {}
};


#endif