#ifndef IDENTIFIABLE_H
#define IDENTIFIABLE_H

class Identifiable {
    private:
        int id;
        static int total;
        static int newId;
    public:
        Identifiable();
        Identifiable(const Identifiable& copy);
        ~Identifiable();
        
        Identifiable& operator=(const Identifiable& copy);
        
        int getId() const;
        static int getTotal();
};

#endif // IDENTIFIABLE_H
