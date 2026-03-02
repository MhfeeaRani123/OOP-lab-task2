#include <iostream>
using namespace std;
class Gadget {
private:
    string name;
public:
    Gadget() {
        name = "Default";
        cout << "Default Gadget created" << endl;
    }
 Gadget(string n) {
        name = n;
        cout << "Gadget " << name << " created" << endl;
    }

    ~Gadget() {
        cout << "Gadget " << name << " destroyed" << endl;
    }
};

int main() {

    Gadget g1("A");
    Gadget g2("B");

    g2 = g1;   // assignment (NOT construction)

    Gadget g3("C");

    return 0;
}
/*
//Task 1
Exact Console Output
Gadget B created
Gadget C created
Gadget C destroyed
Gadget A destroyed
Gadget A destroyed
//Task 2
Does g2 = g1 call constructor or destructor?
NO.It calls:
Default Assignment Operator  means Only data is copied.No new object created.
No destructor called.
What happens after assignment?
Before assignment:
g1 - A
g2 - B
After:
g2 = g1
Now
g2 - A   
So original "B" value is overwritten.
 Destructor Output Order
Objects destroy in reverse order:
g3 destroyed - C
g2 destroyed - A
g1 destroyed - A
 That is why A is destroyed twice.
//Task 3
 Constructor Calls vs Destructor Calls
Count Constructors=3
Destructors=3

 Yes - they are equal
(each object constructed once is destroyed once)
Construction ? happens during declaration
Assignment ? happens after object already exists
Destruction ? reverse order of creation (LIFO)
*/
