#include <iostream>
#include "Stack.h"
using namespace std;

int main() {
  cout << "Create Stack s with 5 capacity: ";
  Stack s(5);
  cout << "Pushing 100, 200, 300... ";
  for (int i = 1; i <= 3; i++)
  s.push(100*i);
  cout << "Contents of stack s (should be 300, 200, 100):\n";
  s.display();
  cout << endl;
  cout << "\nCreate Stack t with the copy constructor and push 77 on it.\n";
  Stack t(s);
  cout << "Push 77 into t only.\n";
  t.push(77);
  cout << "Contents of stack s (should be 300, 200, 100):\n";
  s.display();
  cout << "Contents of stack t (should be 77, 300, 200, 100):\n";
  t.display();
  cout << endl;
  cout << "\nCreate Stack u with the copy constructor and push 88 and 99 on it.\n";
  Stack u(2);
  u.push(88);
  u.push(99);
  cout << "Contents of stack u (should be 99, 88):\n";
  u.display();
  cout << endl;
  cout << "Assign u to s.\n";
  u = s;
  cout << "Contents of stack u (should be 300, 200, 100):\n";
  u.display();
  cout << endl;
  cout << "Push 222 into u only.\n\n";
  u.push(222);
  cout << "Push 111 into s only.\n";
  s.push(111);
  cout << "Contents of stack u (should be 222, 300, 200, 100):\n";
  u.display();
  cout << "Contents of stack s (should be 111, 300, 200, 100):\n";
  s.display();
  cout << endl;
return 0;
}

