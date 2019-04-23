#ifndef FILEITERATOR_H
#define FILEITERATOR_H

#include <fstream>

template <class T>
class FileIterator {
    private:
        ifstream in;
        std::string fileName;
        T data;
    public:
        FileIterator(std::string fileName);
        ~FileIterator();
        
        T value() const;
        bool start() const;
        bool end() const;
        void next();
        void prev();
        void reset();
        
        void operator++();
        void operator++(int);
        void operator--();
        void operator--(int);
        void operator*();
};

#endif // FILEITERATOR_H
