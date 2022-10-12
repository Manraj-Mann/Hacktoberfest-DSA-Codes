// Circular Queue implementation

class Queue
{
private:
    int *arr;
    int front, cap, size;
public:
    Queue(int c) // pass capacity of queue
    {
        cap = c;
        front = 0;
        size = 0;
        arr = new int[cap];
    }
    bool isFull() // return true if queue is full
    {
        return (size==cap);
    }
    bool isEmpty() // return true if queue is empty
    {
        return (size==0);
    }
    int getFront() // return front of queue
    {
        if(isEmpty()) {
            cout << "Queue is empty";
            return -1;
        }
        return arr[front];
    }
    int getRear() // return back of queue
    {
        if(isEmpty()) {
            cout << "Queue is empty";
            return -1;
        }
        return arr[(front+size-1)%cap];
    }
    void deque() // pop back element from queue
    {
        if(isEmpty()) {
            cout << "Queue Underflow" << endl;
            return;
        }
        front = (front+1)%cap;
        size--;
    }
    void enque(int x) // push the element to the front of queue
    {
        if(isFull()) {
            cout << "Queue Overflow" << endl;;
            return;
        }
        int rear = (front+size-1)%cap;
        rear = (rear+1)%cap;
        arr[rear] = x;
        size++;
    }
};
