#include <iostream>
#include "Super.h"

using namespace std;

class Sub: public Super  {
public:
    
};
void Super::doTest(void) {
    Super object;

    object.put(100);
    object.put(object.get() + 1);
    cout << "data in object " <<object.get() << endl;
    
    
    Sub s;
    cout << "data in sub object " <<s.get() << endl;
    
    return;
}

