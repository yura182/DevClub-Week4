#ifndef FILEITERATOR_H
#define FILEITERATOR_H

#include <fstream>

template <class T>
class FileIterator {
    private:
        std::ifstream in;
        T data;
        bool endOfFile;
    public:
        FileIterator(std::string fileName);
        ~FileIterator();
        
        T value() const;
        bool end() const;
        void next();
        void reset();
        
        void operator++();
        void operator++(int);
        T operator*();
};

#endif // FILEITERATOR_H
