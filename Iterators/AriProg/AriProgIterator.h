#ifndef ARIPROGITERATOR_H
#define ARIPROGITERATOR_H

class AriProgIterator {
    private:
        int first;
        int step;
        int size;
        int currentValue;
        int currentIndex;
    public:
        AriProgIterator(int first, int step, int size);
        ~AriProgIterator();
        
        int value() const;
        bool end() const;
        bool start() const;
        void next();
        void prev();
        void move(int index);
        void reset();
        
        void operator++();
        void operator++(int);
        void operator--();
        void operator--(int);
        int operator*() const;
        int operator[](int index) const;
};

#endif // AROPROGITERATOR_H
