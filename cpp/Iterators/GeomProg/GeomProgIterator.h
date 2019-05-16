#ifndef GEOMPROGITERATOR_H
#define GEOMPROGITERATOR_H

class ZeroRatio {};

template <class T>
class GeomProgIterator {
    private:
        T first;
        T ratio;
        int size;
        T currentValue;
        int currentIndex;
    public:
        GeomProgIterator(T first=1, T ratio=2, int size=10);
        ~GeomProgIterator();
        
        T value() const;
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
        T operator*() const;
        T operator[](int index) const;
};

#endif // GEOMPROGITERATOR_H
