#ifndef PRIMEITERATOR_H
#define PRIMEITERATOR_H

class PrimeIterator {
    private:
        int size;
        int currentIndex;
        int *primeNumbers;
        bool isPrime(int n);
    public:
        PrimeIterator(int size=10);
        ~PrimeIterator();
        
        int value() const;
        bool start() const;
        bool end() const;
        void next();
        void prev();
        void move();
        void reset();
        
        void operator++();
        void operator++(int);
        void operator--();
        void operator--(int);
        int operator*();
        int operator[]();
};

#endif // PRIMEITERATOR_H
