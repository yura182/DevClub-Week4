#ifndef OBSERVABLE_H
#define OBSERVABLE_H

#include "../Helpers/Debug.h"
#include "Observer.h"

class Observable {
    public:
        Observable() { debugPrint("Observable created"); };
        ~Observable() { debugPrint("Observable destroyed"); };
        
        virtual void addObserver(Observer *observer) = 0;
        virtual void removeObserver(Observer *observer) = 0;
        virtual void notify() = 0;
};

#endif // OBSERVABLE_H
