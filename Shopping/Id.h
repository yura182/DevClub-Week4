#ifndef ID_H
#define ID_H

template <class T>
class Id {
    private:
        int id;
        static int nextId;
    public:
        Id();
        virtual ~Id();
        
        int getId() const;
};

#endif // ID_H
