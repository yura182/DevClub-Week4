#ifndef ARIPROGITERATOR_H
#define ARIPROGITERATOR_H

template <class T>
class AriProgIterator {
    private:
        T first;
        T step;
        int size;
        T currentValue;
        int currentIndex;
    public:
        AriProgIterator(T first=1, T step=2, int size=10);
        ~AriProgIterator();
        
        T value() const;
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
        T operator*() const;
        T operator[](int index) const;
};

#endif // AROPROGITERATOR_H
