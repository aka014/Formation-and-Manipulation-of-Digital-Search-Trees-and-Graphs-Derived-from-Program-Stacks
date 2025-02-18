#include "../h/fileinput.h"
#include <iostream>
#include "../h/Tree.h"
#include "../h/Graph.h"


int main() {
    Queue<string> s1;
    Queue<string> s2;
    Queue<string> s3;
    string name1 = "UnesiStablo.txt";
    string name2 = "DodajStek.txt";
    string name3 = "ObrisiStek.txt";
    Tree t;
    Graph g;

    volatile bool flag = true;

    while (flag) {

        cout << "1. Napravi stablo" << endl << "2. Dodaj novi programski stek u stablo" << endl <<
             "3. Ukloni programski stek iz stabla" << endl << "4. Ispisi stablo" << endl <<
             "5. Ispisi stablo hijerarhijski" << endl << "6. Obrisi stablo" << endl << "7. Pretvori stablo u graf"
             << endl << "8. Ispisi graf" << endl << "9. Proveri postojanje rekurzivnih poziva"
             << endl << "10. Prekini program" << endl << endl;

        int num;
        cin >> num;

        switch (num) {
            case 1:
                cout << "a. Procitaj iz datoteke" << endl << "b. Unesi sa standardnog ulaza" << endl;
                char c;
                cin >> c;
                switch (c) {
                    case 'a': case 'A':
                        readFile(name1, &s1);
                        break;
                    case 'b': case 'B':
                        readCin(&s1);
                        break;
                    default:
                        cout << "Niste uneli validan ulaz"; exit(1);
                        break;
                }
                t.formTree(&s1);
                break;
            case 2:
                cout << "a. Procitaj iz datoteke" << endl << "b. Unesi sa standardnog ulaza" << endl;
                char b;
                cin >> b;
                switch (b) {
                    case 'a': case 'A':
                        readFile(name2, &s2);
                        break;
                    case 'b': case 'B':
                        readCin(&s2);
                        break;
                    default:
                        cout << "Niste uneli validan ulaz"; exit(1);
                }
                t.insertStack(&s2);
                break;
            case 3:
                cout << "a. Procitaj iz datoteke" << endl << "b. Unesi sa standardnog ulaza" << endl;
                char a;
                cin >> a;
                switch (a) {
                    case 'a': case 'A':
                        readFile(name3, &s3);
                        break;
                    case 'b': case 'B':
                        readCin(&s3);
                        break;
                    default:
                        cout << "Niste uneli validan ulaz"; exit(1);
                }
                t.deleteStack(&s3);
                break;
            case 4:
                t.traversal();
                cout << endl;
                cout << endl;
                break;
            case 5:
                t.traversal_hierarchy();
                cout << endl;
                cout << endl;
                break;
            case 6:
                t.deleteTree();
                break;
            case 7:
                g.transformTree(&t);
                break;
            case 8:
                int n;
                cout << "Unesite broj cvora od kojeg se pocinje: " << endl;
                cin >> n;
                g.traversal(g.getNode(n));
                cout << endl;
                cout << endl;
                break;
            case 9:
                g.detectRecursion();
                cout << endl;
                break;
            case 10:
                flag = false;
                break;
            default:
                cout << "Uneli ste nevalidan unos!" << endl;
                exit(1);
        }
    }
}
