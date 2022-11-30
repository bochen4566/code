// Spring'22
// Instructor: Diba Mirza
// Student name: Bochen Wang
#ifndef MOVIES_H
#define MOVIES_H

#include <string>

#include <cstring>

using namespace std;

class movies{
    public:
        movies();
        movies(string name, double rating);
        string getMoName() const{
            return getName();
        };
        double getMoRate() const{
            return getRating();
        };
        bool operator>(const movies& rhs) const;
        bool operator<(const movies& rhs) const;
        bool operator==(const movies& rhs) const;
        void print() const;
        movies& operator=(const movies& rhs){
            this->mo = rhs.getName();
            this->ra = rhs.getRating();
            return *this;
        }
    private:
        string mo;
        double ra;
        string getName() const;
        double getRating() const;
};
#endif
