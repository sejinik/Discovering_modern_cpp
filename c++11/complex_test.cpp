#include <iostream>

class complex{
    public:
        complex(double r, double i) : r{r},i{i} {}

        complex(double r) :r{r} {}
        complex(){}
        
        complex& operator=(const complex&c){
            r=c.r; i=c.i;
            return *this;
        }

        complex& operator=(double rn){
            r=rn; i=0.0;
            return *this;
        }

    private:
        double r=0.0 , i=0.0;
};