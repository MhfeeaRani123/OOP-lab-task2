#include <iostream>
using namespace std;

class Gadget {
private:
    string name;
public:
    Gadget() {
        name = "Unknown";
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
    {
        Gadget g1("BlockA1");
     {
            Gadget g2("BlockB1");
            Gadget g3("BlockB2");
            // ---- Line Y
        }
 Gadget g4("BlockA2");
        // ---- Line Z
    }
    return 0;
}
/*
//Task 1
Exact Console Output
Gadget BlockA1 created
Gadget BlockB1 created
Gadget BlockB2 created
Gadget BlockB2 destroyed
Gadget BlockB1 destroyed
Gadget BlockA2 created
Gadget BlockA2 destroyed
Gadget BlockA1 destroyed
//Task 2
 Object Lifetime Rule
Objects are destroyed in reverse order (LIFO) of creation.
Objects inside an inner block die when that block ends.
 At Line Y
Alive objects:
g1 (BlockA1)
g2 (BlockB1)
g3 (BlockB2)
 Total = 3 objects alive
After Inner Block Ends
Inner block closes .
g3 destroyed first, then g2.
 At Line Z:
Alive objects:
g1 (BlockA1)
g4 (BlockA2)
Total = 2 objects alive
//Task 3
 Why g4 is created after g2 and g3 are destroyed?
Because g2 and g3 belong to the inner scope
Their lifetime ends immediately when { } finishes
Program execution then continues in outer block where g4 is created.
 
