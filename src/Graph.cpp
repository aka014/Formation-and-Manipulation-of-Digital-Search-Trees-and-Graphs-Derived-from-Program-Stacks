#include "../h/Graph.h"
#include "../h/Tree.h"
#include "../h/BoolStack.h"
#include "../h/node.h"

bool* Graph::getNode(int num) const {
    if (!array) {
        cout << "Prvo napravite graf!" << endl;
        exit(2);
    }
    if (num >= size) return matrix[0];
    return matrix[num];
}

int Graph::findPosition(std::string s) const {
    for(int i = 0; i < size; i++) {
        if (array[i] == s) return i;
    }
    exit(3);
}

bool** Graph::copyMatrix() const {
    if (matrix == nullptr) return nullptr;
    bool** copy = new bool* [size];
    for (int i = 0; i < size; i++) {
        copy[i] = new bool[size];
        for (int j = 0; j < size; j++) {
            copy[i][j] = this->matrix[i][j];
        }
    }
    return copy;
}

bool Graph::checkRecursion(bool **m) const {
    for (int h = 0; h < size; h++) {
        if (m[h][h]) {
            cout << "Postoji bar jedan rekurzivni poziv u grafu." << endl;
            return true;
        }
    }
    return false;
}

Graph& Graph::detectRecursion() {
    if (checkRecursion(this->matrix)) return *this;
    bool** p = this->copyMatrix();
    //Trazenje rekurzivnih poziva primenom Warshall-ovog algoritma.
    for (int k = 0; k < size; k++) {
        for (int i = 0; i < size; i++) {
            if (p[i][k]) {
                for (int j = 0; j < size; j++) {
                    p[i][j] = p[i][j] || p[k][j];
                }
            }
        }
        if (checkRecursion(p)) return *this;
    }
    cout << "Nema rekurzivnih poziva u grafu." << endl;
    return *this;
}

Graph& Graph::traversal(bool *cvor) {
    cout << "Redosled elemenata po vrstama i kolonama kvadratne matrice susednosti:" << endl << endl;
    for (int i = 0; i < size; i++) cout << array[i] << ' ';
    cout << endl;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout << matrix[i][j] << ' ';
        }
        cout << endl;
    }
    cout << endl << "Obilazak grafa: ";

    bool* visit = new bool[size];
    for (int i = 0; i < size; i++) visit[i] = false;
    BoolStack stack;
    stack.push(cvor);
    while (!stack.stackEmpty()) {
        bool* tek = stack.pop();

        int j = 0;
        for (int i = 0; i < size; i++) {
            if (tek == matrix[i]) j = i;
        }
        if (!visit[j]) {
            visit[j] = true;
            cout << array[j] << ' ';

            for (int i = 0; i < size; i++) {
                if (matrix[j][i] == true && visit[i] == false) stack.push(matrix[i]);
            }
        }
    }
    return *this;
}

Graph& Graph::transformTree(Tree *tree) {
    int max = getMaxNum();
    array = new string[max];
    for (int i = 0; i < max; i++) array[i] = ""; //Ovo ce oznacavati kraj niza.

    if (tree->root == nullptr) return *this;
    Queue<Elem*> q;
    q.insertQueue(tree->root);
    while (!q.queueEmpty()) {
        Elem* curr = q.deleteQueue();
        //Provera da li funkcija vec postoji u nizu.
        int flag = 0;
        for (int i = 0; i < size; i++) {
            if (array[i] == curr->data) flag++;
        }
        if (flag == 0) array[size++] = curr->data;
        //Nastavak level ordera.
        if (curr->left != nullptr) {
            curr = curr->left;
            while (curr) {
                q.insertQueue(curr);
                curr = curr->right;
            }
        }
    }

    this->matrix = new bool* [size];
    for (int i = 0; i < size; i++) matrix[i] = new bool [size];
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) matrix[i][j] = false;
    }

    q.insertQueue(tree->root);
    while (!q.queueEmpty()) {
        Elem* curr = q.deleteQueue();

        Elem* help = curr;
        if (help->left != nullptr) {
            help = help->left;
            while (help != nullptr) {
                matrix[findPosition(curr->data)][findPosition(help->data)] = true;
                help = help->right;
            }
        }

        //Level order deo.
        if (curr->left != nullptr) {
            curr = curr->left;
            while (curr != nullptr) {
                q.insertQueue(curr);
                curr = curr->right;
            }
        }
    }

    return *this;
}