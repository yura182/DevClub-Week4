#ifndef COUNTABLE_H
#define COUNTABLE_H

class Countable {
    private:
        static int total;
    public:
        Countable();
        ~Countable();
        static int getTotal();
};

#endif // COUNTAVLE_H
