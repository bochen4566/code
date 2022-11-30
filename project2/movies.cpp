#include "movies.h"

#include <string>
#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;

movies::movies(){
    mo = "";
    ra = 0.0;
};
movies::movies(string name, double rating){
    mo = name;
    ra = rating;
};
string movies::getName() const{
    return mo;
};
double movies::getRating() const{
    return ra;
};
bool movies::operator>(const movies& rhs) const{
    return getName() > rhs.getName();
};
bool movies::operator<(const movies& rhs) const{
    return getName() < rhs.getName();
    
};
bool movies::operator==(const movies& rhs) const{
    return (getName() == rhs.getName()) && (getRating() == rhs.getRating());
};
void movies::print() const{
    cout << mo << ", " << std::fixed << std::setprecision(1) << ra << endl;
};