#include <iostream>
#include "Stack.h"
using namespace std;


//--- Definition of Defualt Stack constructor
Stack::Stack() : Stack(5){}

//--- Definition of parameterized constructor
Stack::Stack(int capacity)
{
  myTop = new int;
  *myTop = -1;
  myCapacity = capacity;
  myArray = new StackElement[myCapacity];
}

//Definiton of Destructor
Stack::~Stack()
{
  delete myTop;
  delete [] myArray;
}

//Definition of Copy Constructor
Stack::Stack(const Stack & source)
{
  myTop = new int;
  myCapacity = source.myCapacity;
  myArray = new StackElement[myCapacity];
  *myTop = (*source.myTop);
  for(int i = *myTop; i >= 0; i--)
  {
    myArray[i] = source.myArray[i];
  }

}

//--- Definition of Assignment Operator
Stack & Stack::operator=(const Stack & source)
{
  //u is like a local var, myTop, myCapacity
  //s is source, source.getCapacity()
if(this != & source){
  if (myCapacity != source.myCapacity){
    myCapacity = source.myCapacity;
    delete [] myArray; 
    myArray = new StackElement[myCapacity];
  }

  myTop = new int;
  *myTop = (*source.myTop);
  for(int i = *myTop; i >= 0; i--)
  {
    myArray[i] = source.myArray[i];
  }
}
  return *this;
}


//--- Definition of empty()
bool Stack::empty() const { 
    return (*myTop == -1); 
}


//--- Definition of push()
void Stack::push(StackElement value) {
    if (*myTop < STACK_CAPACITY - 1) {
        //Preserve stack invariant 
        ++(*myTop);
        myArray[*myTop] = value;
        myCapacity++; 
    } else {
        cerr << "*** Stack full -- can't add new value ***\n"
            "Must increase value of STACK_CAPACITY.\n";
        return;
    }
}


//--- Definition of display()
void Stack::display() const
{
    for (int i = *myTop; i >= 0; i--) {
        cout << myArray[i] << endl;
    }
}


//--- Definition of top()
StackElement Stack::top() const {
    if ( !empty()) {
        return (myArray[*myTop]);
    } else {
        cerr << "*** Stack is empty -- returning garbage value ***\n";
        StackElement garbage;
        return garbage;
    }
}


//--- Definition of pop()
void Stack::pop() {
    if ( !empty()) {
        (*myTop)--;
    } else {
        cerr << "*** Stack is empty -- can't remove a value ***\n";
    }
}

int Stack::getCapacity(){
  return myCapacity; 
}
