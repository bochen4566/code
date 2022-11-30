#include "utility.h"
#include <iostream>
#include <cstring>
#include "cards.h"
using namespace std;
bool AliceChoose(Card& A, Card& B){
    //cout<<"1" << endl;
    string min = A.min();
    //cout<<"2" << endl;
    int count = 0;
    while(count < A.count()){
        //cout << "before contains" << endl;
        if(B.contains(min[0], min[1])){
            if(min[1] == '0'){
                cout << "Alice picked matching card " << min[0] << " " << 10 << endl;
                A.remove(min[0], min[1]);
                B.remove(min[0], min[1]);
                return true;
            }else{
                
                A.remove(min[0], min[1]);
                B.remove(min[0], min[1]);
                //B.printInOrder();
                cout << "Alice picked matching card " << min[0] << " " << min[1] << endl;
                return true;
            }
        }
        //cout << "before get successor" << endl;
        min = A.getSuccessor(min[0], min[1]);
        //cout << "after get successor" << endl;
        //cout << min << endl;
        count++;
        //cout << "3" << count << endl;
    }
    //cout << "Alice choose nothing" << endl;
    return false;
}
bool BobChoose(Card& A, Card& B){
    string max = B.max();
    //cout << "max here" << max << endl;
    int count = 0;
    while(count < B.count()){
        if(A.contains(max[0], max[1])){
            if(max[1] == '0'){
                cout << "Bob picked matching card " << max[0] << " " << 10 << endl;
                A.remove(max[0], max[1]);
                B.remove(max[0], max[1]);
                return true;
            }else{
                
                //if(max == "dj") cout << "before" << endl;
                A.remove(max[0], max[1]);
                //if(max == "dj") cout << "middle" << endl;
                B.remove(max[0], max[1]);
                //B.printInOrder();
                cout << "Bob picked matching card " << max[0] << " " << max[1] << endl;
                //if(max == "dj") cout << "here" << endl;
                return true;
            }
        }
        max = B.getPredecessor(max[0], max[1]);
        count++;
    }
    //cout << "Bob choose nothing" << endl;
    return false;
}


