#ifndef OBSERVER_H
#define OBSERVER_H

#include "../Helpers/Debug.h"

class Observer {
    public:
        Observer() { debugPrint("Observer created"); };
        ~Observer() { debugPrint("Observer destroyed"); };
        
        virtual void update(int hp) = 0;
};

#endif // OBSERVER_H
