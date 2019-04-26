#ifndef IDENTIFIABLE_H
#define IDENTIFIABLE_H

class Identifiable {
    private:
        int id;
        static int newId;
    public:
        Identifiable();
        ~Identifiable();
        
        int getId() const;
};

#endif // IDENTIFIABLE_H
