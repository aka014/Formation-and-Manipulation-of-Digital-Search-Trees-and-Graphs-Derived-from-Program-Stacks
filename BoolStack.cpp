#include "BoolStack.h"

BoolStack::BoolStack() {
    stack = new bool* [30];
    top = stack;
}

BoolStack& BoolStack::push(bool *cvor) {
    *top = cvor;
    top++;
    return *this;
}

bool* BoolStack::pop() {
    if (stackEmpty()) return nullptr;
    top--;
    bool* cvor = *top;
    return cvor;
}

bool BoolStack::stackEmpty() const {
    if (top == stack) return true;
    return false;
}

BoolStack::~BoolStack() {
    delete stack;
    top = stack = nullptr;
}
