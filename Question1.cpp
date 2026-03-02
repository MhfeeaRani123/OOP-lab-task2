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

    // Object g1 uses DEFAULT constructor
    Gadget g1;

    // Object g2 uses PARAMETERIZED constructor
    Gadget g2("Alpha");

    // Object g3 uses PARAMETERIZED constructor
    Gadget g3("Beta");

    return 0;
}

/*

task 1

 Expected Console Output:

Default Gadget created
Gadget Alpha created
Gadget Beta created
Gadget Beta destroyed
Gadget Alpha destroyed
Gadget Default destroyed

task 2
 Why destructors follow LIFO:

Objects are destroyed in reverse order of creation.
Last created object is destroyed first.
This behavior is called LIFO .
task 3
 If g2 and g3 are swapped:

Yes, destruction order changes because
destruction always happens opposite
to creation order.

Example:
If g3 created before g2,
then g2 will be destroyed first.
*/
