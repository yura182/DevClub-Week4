#ifndef FACTORIALITERATOR_H
#define FACTORIALITERATOR_H

class FactorialIterator {
    private:
        int size;
        int currentValue;
        int currentIndex;
        int factorial(int number);
    public:
        FactorialIterator(int size=10);
        ~FactorialIterator();
        
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
        int operator[](int idex);
};

#endif // FACTORIALITERATOR_H
