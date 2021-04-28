#ifndef STACK_H
#define STACK_H
using namespace std;

const int STACK_CAPACITY = 20;
typedef int StackElement;

class Stack {
public:
    Stack();
    Stack(int capacity);
    ~Stack(); // Destructor
    Stack(const Stack & source); //Copy Constructor
    bool empty() const;
    void push(StackElement value);
    void display() const;
    StackElement top() const;
    void pop();
    int getCapacity();
    Stack & operator=(const Stack & source);

private:
    StackElement *myArray;
    int *myTop;
    int myCapacity; 
};
#endif