#include <iostream>
#include "Observable.h"
#include "Observer.h"

using namespace std;

int main()
{
    cout << "Interface console"   << endl;
    Observable abalone;
    Observer view (abalone);
    abalone.attachObserver(view);
    abalone.run();
}
