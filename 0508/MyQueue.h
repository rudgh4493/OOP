class BaseArray {
private:
    int capacity; // 동적 할당된 메모리 용량 
    int* mem;
protected:
    BaseArray(int capacity = 100) {
        this->capacity = capacity; mem = new int[capacity];
    }
    ~BaseArray() { delete[] mem; }
    void put(int index, int val) { mem[index] = val; }
    int get(int index) { return mem[index]; }
    int getCapacity() { return capacity; }
};

class MyQueue : public BaseArray {
    int head, tail, size;
public:
    MyQueue(int c) :BaseArray(c) {
        size = 0; head = 0; tail = -1;
    }
    void enqueue(int n);
    int length();
    int dequeue();
    int capacity();
};


void MyQueue::enqueue(int n){
    if (size == capacity() ) return;
    put(head++, n);
    head = head % capacity();
    size++;
}

int MyQueue::length(){
    return this->size;
}

int MyQueue::dequeue(){
    if (size == 0)return -1;
    size--;
    tail++;
    tail = tail % capacity();
    return get(tail);
}

int MyQueue::capacity() {
    return getCapacity();
}