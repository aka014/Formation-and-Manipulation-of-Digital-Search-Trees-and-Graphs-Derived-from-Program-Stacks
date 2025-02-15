#ifndef ASP_FILEINPUT_H_
#define ASP_FILEINPUT_H_

/*Deklaracije funkcija koje proveravaju ispravnost imena funkcije, citaju programski stek iz fajla ili sa standardnog
 * ulaza.*/

#include <string>
#include "queue.h"
using namespace std;


bool isOk(string s);

void readFile(string name, Queue<string>* q);

void readCin(Queue<string>* q);

#endif