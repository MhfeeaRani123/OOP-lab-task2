#include <iostream>
#include <string>
using namespace std;
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
// Function
void createGadgets() {
    Gadget g1("Func1");
    Gadget g2("Func2");
}
int main() {
   Gadget gMain1("Main1");
 createGadgets();
 Gadget gMain2("Main2");
  return 0;
}
/*

//Task 1
Exact Constructor and Destructor Output
Constructor: Main1 created
Constructor: Func1 created
Constructor: Func2 created
Destructor: Func2 destroyed
Destructor: Func1 destroyed
Constructor: Main2 created
Destructor: Main2 destroyed
Destructor: Main1 destroyed
//Task 2
 Why are Func1 and Func2 destroyed before gMain2 is created?
Func1 and Func2 are local objects inside the createGadgets() function.When the function execution finishes, its scope ends and all local objects are automatically destroyed before returning to main().Therefore, g1 and g2 are destroyed before the statement creating gMain2 is executed.
//Task 3
 At what point are the maximum number of objects alive? Name them.
The maximum number of objects alive simultaneously is 3.They are:
1.gMain1
2.g1 (Func1)
3.g2 (Func2)
This occurs inside the createGadgets() function after g2 is created and before the function ends.


