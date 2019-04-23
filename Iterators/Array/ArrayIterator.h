#ifndef ARRAYITERATOR_H
#define ARRAYITERATOR_H

template <class T>
class ArrayIterator {
    private:
        int size;
        int currentIndex;
        T *array;
    public:
        ArrayIterator(T *array, int size);
        ~ArrayIterator();
        
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
        T operator*();
        T operator[](int index);
};

#endif // ARRAYITERATOR_H
