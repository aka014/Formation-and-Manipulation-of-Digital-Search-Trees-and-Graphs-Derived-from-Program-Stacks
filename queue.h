#ifndef ASP_QUEUE_H_
#define ASP_QUEUE_H_

/*Genericka klasa FIFO reda koja je implementirana pomocu ulancane liste.*/

template <typename T>
class Queue {
public:
    Queue<T>& insertQueue(T& d);

    T deleteQueue();

    bool queueEmpty() const;

private:
    struct Element {
        Element* next;
        T data;

        Element(T& d, Element* n = nullptr) : data(d), next(n) {}
    };

    Element* front = nullptr;
    Element* rear = nullptr;
};

template <typename T>
Queue<T>& Queue<T>::insertQueue(T& d) {
    Element* novi = new Element(d);

    if (queueEmpty()) {
        rear = novi;
        front = rear;
    }
    else {
        rear->next = novi;
        rear = novi;
    }

    return *this;
}

template <typename T>
T Queue<T>::deleteQueue() {
    if (queueEmpty()) return nullptr;
    T info = front->data;
    Element* old = front;
    front = front->next;
    if (front == nullptr) rear = nullptr;
    delete old;
    return info;
}

template <typename T>
bool Queue<T>::queueEmpty() const {
    if (front == nullptr) return true;
    return false;
}

#endif