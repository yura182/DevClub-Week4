#ifndef PRIMEITERATOR_H
#define PRIMEITERATOR_H

class OutOfMemoryException {};

class PrimeIterator {
    private:
        int size;
        int currentIndex;
        int *primeNumbers;
        int nextNumber;
        bool isPrime(int *numbers, int n) const;
    public:
        PrimeIterator(int size=5);
        ~PrimeIterator();
        
        int value() const;
        bool start() const;
        bool end() const;
        void next();
        void prev();
        void reset();
        
        void operator++();
        void operator++(int);
        void operator--();
        void operator--(int);
        int operator*();
};

#endif // PRIMEITERATOR_H
