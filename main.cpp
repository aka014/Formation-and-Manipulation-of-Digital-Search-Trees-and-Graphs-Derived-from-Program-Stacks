#include "fileinput.h"
#include <iostream>

//razmisli gde ces da zatvaras fajlove

int main() {
    Queue<string> red;
    string s = "UnesiStablo.txt";
    //readFile(s, &red);
    readCin(&red);

    while (!red.queueEmpty()) {
        cout << red.deleteQueue() << endl;
    }
}
