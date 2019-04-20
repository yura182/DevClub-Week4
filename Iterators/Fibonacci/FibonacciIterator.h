#ifndef FIBONACCIITERATOR_H
#define FIBONACCIITERATOR_H

class FibonacciIterator {
    private:
        int size;
        int firstIndex;
        int currentIndex;
        int currentValue;
        int prevValue;
        int fibonacci(int number);
    public:
        FibonacciIterator(int size=10, int firstIndex=0);
        ~FibonacciIterator();
        
        int value() const;
        bool start() const;
        bool end() const;
        void next();
        void prev();
        void move(int index);
        void reset();
        
        void operator++();
        void operator++(int);
        void operator--();
        void operator--(int);
        int operator*();
        int operator[](int index);
};

#endif // FIBONACCIITERATOR_H
