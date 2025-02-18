#include "../h/Tree.h"
#include <iostream>
#include "../h/node.h"

Tree::Tree() {
    root = nullptr;
}

Tree& Tree::formTree(Queue<std::string> *q) {

    if (root != nullptr) {
        cout << "Stablo vec postoji!" << endl;
        return *this;
    }

    if (q->queueEmpty()) return *this;

    //Citam prvi programski stek, formiram stablo i zatim ubacujem pozivom funkcije ostale stekove
    string curr = q->deleteQueue();
    while (curr != " ") {
        if (root == nullptr) {
            root = new Elem(curr);
        }
        else {
            Elem* tek = root;
            while (tek->left != nullptr) tek = tek->left;
            tek->left = new Elem(curr);
            tek->left->parent = tek;
        }

        curr = q->deleteQueue();
    }

    while (!q->queueEmpty()) insertStack(q);

    return *this;
}

Tree& Tree::insertStack(Queue<std::string> *q) {
    if (root == nullptr) {
        cout << "Prvo formatirajte stablo!" << endl;
        return *this;
    }
    if (q->queueEmpty()) return *this;
    string curr = q->deleteQueue(); //Da sklonim koren (receno je da mozemo pretpostaviti da ce koren uvek biti isti).
    curr = q->deleteQueue();
    Elem* tek = root;
    while (curr != " ") {
        //Prvi slucaj - cvor do sada nema sina.
        if (tek->left == nullptr) {
            tek->left = new Elem(curr);
            tek->left->parent = tek;
            tek = tek->left;
        }
        else {
            //Drugi slucaj - cvor ima odgovarajuceg sina, samo nije najlevlji.
            Elem* pom = tek->left;
            while (pom != nullptr) {
                if (pom->data == curr) {
                    tek = pom;
                    break;
                }
                else pom = pom->right;
            }
            //Treci slucaj - cvor nema takvog sina, a vec ima neke sinove.
            if (pom == nullptr) {
                Elem* father = tek;
                tek = tek->left;
                while (tek->right != nullptr) tek = tek->right;
                tek->right = new Elem(curr);
                tek = tek->right;
                tek->parent = father;
            }
        }
        curr = q->deleteQueue();
    }
    return *this;
}

Tree& Tree::deleteStack(Queue<std::string> *q) {
    if (root == nullptr) {
        cout << "Prvo formirajte stablo!" << endl;
        return *this;
    }
    string curr = q->deleteQueue();
    Elem* tek = root;
    if (curr != tek->data) {
        //Stek ne pocinje istim korenom.
        cout << "Uneli ste stek koji ne postoji u stablu!" << endl;
        return *this;
    }
    curr = q->deleteQueue();
    while (curr != " ") {
        Elem* pom = tek->left;
        while (pom != nullptr) {
            if (pom->data == curr) {
                tek = pom;
                break;
            }
            pom = pom->right;
        }
        if (pom == nullptr) {
            cout << "Uneli ste stek koji ne postoji u stablu!" << endl;
            return  *this;
        }

        curr = q->deleteQueue();
    }

    //Tek sada je sigurno da je zadati stek validan.
    while (tek != nullptr) {
        if (tek->left != nullptr) break;
        else {
            Elem* old = tek;
            if (tek->parent->left == tek) tek->parent->left = tek->right;
            else {
                Elem* pom = tek->parent->left;
                while (pom->right != tek) pom = pom->right;
                pom->right = tek->right;
            }

            tek = tek->parent;
            delete old;
            old = nullptr;
        }
    }
    return *this;
}

Tree& Tree::traversal() {
    if (root == nullptr) {
        cout << "Prvo formirajte stablo!" << endl;
        return *this;
    }
    Queue<Elem*> nq;
    nq.insertQueue(root);
    while (!nq.queueEmpty()) {
        Elem* curr = nq.deleteQueue();
        if (curr->data == root->data) cout << curr->data;
        else cout << ' ' << curr->data;
        if (curr->left != nullptr) {
            curr = curr->left;
            while (curr != nullptr) {
                nq.insertQueue(curr);
                curr = curr->right;
            }
        }
    }
    return *this;
}

Tree& Tree::traversal_hierarchy() {
    if (root == nullptr) {
        cout << "Prvo formirajte stablo!" << endl;
        return *this;
    }
    Queue<Elem*> nq;
    nq.insertQueue(root);
    while (!nq.queueEmpty()) {
        int levelSize = nq.size();

        for (int i = 0; i < levelSize; i++) {
            Elem* tek = nq.deleteQueue();
            cout << tek->data << " ";

            Elem* pom = tek->left;
            while (pom) {
                nq.insertQueue(pom);
                pom = pom->right;
            }

        }

        cout << endl;

    }
    return *this;
}

Tree& Tree::deleteTree() {
    if (root == nullptr) {
        cout << "Prvo formirajte stablo!" << endl;
        return *this;
    }

    Queue<Elem*> nq;
    nq.insertQueue(root);
    while (!nq.queueEmpty()) {
        Elem* curr = nq.deleteQueue();
        Elem* old = curr;
        if (curr->left != nullptr) {
            curr = curr->left;
            while (curr != nullptr) {
                nq.insertQueue(curr);
                curr = curr->right;
            }
        }
        old->parent = old->right = old->left = nullptr;
        delete old;
        old = nullptr;
    }
    root = nullptr;
    return *this;
}

Tree::~Tree() {
    this->deleteTree();
}

