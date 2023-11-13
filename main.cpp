/*Să se creeze clasa Queue – coadă. Cîmpurile – numărul de elemente şi un pointer pentru
        alocarea dinamică a memoriei. Să se definească constructorii: implicit, de copiere şi cu un
        parametru – numărul necesar de elemente; funcţiile add şi get pentru punerea unui element în
        coadă şi pentru scoaterea unui element din coadă respectiv; funcţiile: isEmpty, care returnează
valoarea 1 dacă coada este vidă şi zero în caz contrar, şi isFull care returnează valoarea 1 dacă
        coada este plină şi zero în caz contrar*/


#include <iostream>
using namespace std;

class Queue {
private:
    int count;
    int size;
    int *queue;

public:
    // Implicit
    Queue() : count(0), size(10) {
        queue = new int[size];
    }

    // constructorul de copiere
    Queue(const Queue &q) : count(q.count), size(q.size) {
        queue = new int[size];
        for (int i = 0; i < count; i++) {
            queue[i] = q.queue[i];
        }
    }

    // constructor cu aprametru
    Queue(int s) : count(0), size(s) {
        queue = new int[size];
    }

    // functia de addaugare
    void add(int val) {
        if (!isFull()) {
            queue[count++] = val;
        } else {
            cout << "Coada este plina!" << endl;
        }
    }

    // functia get
    int get() {
        if (!isEmpty()) {
            return queue[--count];
        } else {
            cout << "Coada este goala!" << endl;
            return -1;
        }
    }

    // functia isEmpty
    int isEmpty() {
        return count == 0;
    }

    // IsFull function
    int isFull() {
        return count == size;
    }
};
int main() {
    // Create an empty queue
    Queue q;

    // Add some elements to the queue
    q.add(10);
    q.add(20);
    q.add(30);
    q.add(40);
    q.add(10);
    q.add(10);
    q.add(10);
    q.add(10);
    q.add(10);
    q.add(10);
    q.add(10);
    q.add(10);


    // Print the front element of the queue
    cout << "verificare functie get: " << q.get() << endl;
    cout << "Scoaterea elementului din coada: " << q.get() << endl;

    cout << "Is the queue empty? " << (q.isEmpty() ? "Yes" : "No") << endl;
    // Print whether the queue is full or not
    cout << "Is the queue full? " << (q.isFull() ? "Yes" : "No") << endl;
    return 0;
}