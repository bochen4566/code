#include <iostream>
#include <cstring>
#include <set>
#include "movies.h"
#include <queue>
#include <vector>
using namespace std;
class myFunctor{
    public:
        bool operator()(movies a, movies b){
            if(a.getMoRate() < b.getMoRate()) return true;
            else if(a.getMoRate() == b.getMoRate()) return a < b;
            else return false;
        };
        
};

int main(){
    set<string> bst;
    string a = "dad";
    string b = "bobo";
    string c = "hooo";
    string d = "apple";
    string e = "dbb";
    bst.insert(a);
    bst.insert(b);
    bst.insert(c);
    bst.insert(d);
    bst.insert(e);
    for(auto item: bst){
        cout << item << endl;
    }
    movies mm(a, 3.3);
    mm.print();
    vector<movies> bst1;
    bst1.push_back(movies(a, 3.3));
    bst1.push_back(movies("dadd", 4.4));
    bst1.push_back(movies("daa", 3.3));
    priority_queue<movies, vector<movies>, myFunctor> pq;
    for(auto m:bst1){
        pq.push(m);
    }
    while(!pq.empty()){
        (pq.top()).print();
        pq.pop();
    }
    return 0;
}
