#include "fileinput.h"
#include <iostream>
#include <fstream>
#include <sstream>

bool isOk(string s) {
    if (s[0] == '\n') return false;
    else {
        for (int i = 0; i < s.size(); i++) {
            if (!islower(s[i])) return false;
        }
        return true;
    }
}

void readFile(string path, Queue<string>* q) {

    ifstream file;
    file.open(path);
    if (!file.is_open()) {
        cout << "Greska pri otvaranju fajla!" << endl;
        exit(1);
    }

    string line, s;
    string granicnik = " ";
    while (getline(file, line)) {
        stringstream x(line);
        while (getline(x, s, ' ')) {
            if (isOk(s)) q->insertQueue(s);
        }
        q->insertQueue(granicnik);
    }
}

void readCin(Queue<string>* q) {
    string line, s;
    string granicnik = " ";

    while (true) {
        //cin.ignore();
        getline(cin, line);
        if (line == "") break;
        stringstream x(line);
        while (getline(x, s, ' ')) {
            if (isOk(s)) q->insertQueue(s);
        }
        q->insertQueue(granicnik);
    }
}