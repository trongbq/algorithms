#import <iostream>

using namespace std;

const int DEFAULT_MAX_SIZE = 100;
const int ABSENT_VALUE = -1;

struct CircularBuffer {
    int *arr;
    unsigned int begin; // Start position of the buffer
    unsigned int end; // Hold position for next value
    unsigned int size; // Current size of the buffer
    unsigned int maxSize;

    CircularBuffer(const int maxSize) 
    : arr(new int[maxSize])
    , begin(0)
    , end(0)
    , size(0)
    , maxSize(maxSize) {
        cout << "Creating new circular buffer..." << endl;
    }

    bool isEmpty() {
        return size == 0;
    }

    bool isFull() {
        return size == maxSize;
    }

    void enqueue(int val) {
        if (isFull()) {
            cout << "Buffer is full, overwrite oldest value..." << endl;
            // Increase begin position because oldest position will be pushed out of buffer
            begin = ++begin % maxSize;
        } else {
            size++;
        }

        *(arr + end) = val;
        end = ++end % maxSize;

        cout << "Enqueued value " << val << " into buffer" << endl;
    }

    int dequeue() {
        if (!isEmpty()) {
            int val = *(arr + begin);
            *(arr + begin) = ABSENT_VALUE; // Reset value at dequeuing position
            
            begin = ++begin % maxSize; // Move begin positio to next one
            size--;

            return val;
        }

        return -1;
    }

    void display() {
        cout << "Current value: ";
        for (int i = 0; i < maxSize; i++) {
            cout << "[" << *(arr + i) << "]";
        }
        cout << ", size: " << size << ", begin: " << begin << ", end: " << end << endl;;
    }
};



int main() {
    CircularBuffer cb = CircularBuffer(5);

    cout << "Created a circular buffer!" << endl;
    if (cb.isEmpty()) {
        cout << "It is empty now!" << endl;
    }

    cb.enqueue(4);
    cb.enqueue(45);
    cb.enqueue(8);
    cb.enqueue(12);
    cb.enqueue(94);

    cb.display(); // Current value: [4][45][8][12][94], size: 5, begin: 0, end: 0

    cout << "Dequeued with value: " << cb.dequeue() << endl;
    cout << "Dequeued with value: " << cb.dequeue() << endl;
    cb.display(); // Current value: [-1][-1][8][12][94], size: 3, begin: 2, end: 0

    cb.enqueue(55);
    cb.enqueue(16);
    cb.enqueue(7);
    cb.display(); // Current value: [55][16][7][12][94], size: 5, begin: 3, end: 3

    cout << "Dequeued with value: " << cb.dequeue() << endl;
    cout << "Dequeued with value: " << cb.dequeue() << endl;
    cb.enqueue(42);
    cout << "Dequeued with value: " << cb.dequeue() << endl;
    cb.display(); // Current value: [-1][16][7][42][-1], size: 3, begin: 1, end: 4

    return 0;
}