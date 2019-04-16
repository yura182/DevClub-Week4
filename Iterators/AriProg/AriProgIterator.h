#ifndef ARIPROGITERATOR_H
#define ARIPROGITERATOR_H

class AriProgIterator {
    private:
        int first;
        int step;
        int last;
        int currentValue;
        int currentIndex;
    public:
        AriProgIterator(int first, int step, int last);
        ~AriProgIterator();
        
        int value() const;
        bool end() const;
        bool begin() const;
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
