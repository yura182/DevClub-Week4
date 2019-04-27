#ifndef MOHICAN_H
#define MOHICAN_H

#include <string>

class Mohican {
    private:
        std::string name;
        Mohican *prev;
        Mohican *next;
        static Mohican *last;
        static int total;
    public:
        Mohican(std::string name);
        Mohican(const Mohican& copy);
        ~Mohican();
        
        Mohican& operator=(const Mohican& copy);
        
        const std::string& getName() const;
        static Mohican& getLast();
        static int getTotal();
};

#endif // MOHICAN_H
