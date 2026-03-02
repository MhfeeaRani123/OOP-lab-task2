#include <iostream>
using namespace std;

class Gadget {
private:
    string name;

public:
    // Default Constructor
    Gadget() {
        name = "Default";
        cout << "Constructor: " << name << endl;
    }

    // Parameterized Constructor
    Gadget(string n) {
        name = n;
        cout << "Constructor: " << name << endl;
    }

    // Destructor
    ~Gadget() {
        cout << "Destructor: " << name << endl;
    }
};

int main() {
    Gadget g1;
    Gadget g2("X");
    Gadget g3;
    Gadget g4("Y");
    return 0;
}
/*
Task 1: Exact Output

Constructor: Default
Constructor: X
Constructor: Default
Constructor: Y
Destructor: Y
Destructor: Default
Destructor: X
Destructor: Default

Objects are created in the same order in which they are declared inside the program. Therefore, constructors execute from top to bottom.

When the program ends, objects are destroyed automatically in reverse order because stack memory follows the Last In First Out (LIFO) rule. The type of constructor (default or parameterized) does not affect destruction order.
//Task 2
 Adding Gadget g5("Z")

If the following object is added after g4:

Gadget g5("Z");

Construction Order

g1 - g2 -g3 - g4 -g5

Destruction Order:

g5 - g4 -g3 - g2 - g1
This happens because the last created object is destroyed first according to the LIFO principle.
