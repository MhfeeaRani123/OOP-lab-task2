#include <iostream>
#include <string>
using namespace std;

// Gadget class
class Gadget {
private:
    string name;

public:

    // Default Constructor
    Gadget() {
        name = "Default";
        cout << "Default Gadget created" << endl;
    }

    // Parameterized Constructor
    Gadget(string n) {
        name = n;
        cout << "Gadget " << name << " created" << endl;
    }

    // Destructor
    ~Gadget() {
        cout << "Gadget " << name << " destroyed" << endl;
    }
};

int main() {

    Gadget g1("Outer1");

    {
        Gadget g2("Inner1");
        Gadget g3("Inner2");
    }   // ---- Line X

    Gadget g4("Outer2");

    return 0;
}
//Task 1
/*

Which objects are alive just before Line X?
Which are destroyed at Line X and in what order?:
Just before Line X, the following objects are alive:
g1 (Outer1)
g2 (Inner1)
g3 (Inner2)
When execution reaches Line X (end of the inner block), the objects created inside the block are destroyed automatically.
Objects are destroyed in LIFO (Last In First Out) order.
Destruction order at Line X:
g3 (Inner2) - destroyed first
g2 (Inner1) - destroyed second
Object g1 remains alive because it belongs to the outer scope.
//Task 2
Is g4 ever alive at the same time as g2? Why or why not?
No, g4 is never alive at the same time as g2.
Because g2 is created inside the inner block { }.
It is destroyed when the block ends at Line X.
g4 is created after Line X.
Therefore, the lifetime of g2 ends before g4 is created, so both objects never exist simultaneously.
//Task 3
What is the maximum number of objects alive simultaneously? At which line?
Answer:
The maximum number of objects alive at the same time is:
 3 objects
These objects are:
g1
g2
g3
This occurs immediately after the statement:
Gadget g3("Inner2");
At this moment, all three objects have been constructed and none have been destroyed yet.
/*
