#include <iostream>
#include <fstream>
#include <string>
#include "cards.h"
using namespace std;

//struct Node {
//    int num;
//    char suit;
//	Node *left, *right, * parent;
//	// useful constructor:
//    public:
//    Node(char m = 0, int v=0) : suit(m), num(v), left(0), right(0), parent(0) { }
//    bool operator==(const Node& x) const{
//        if(num == x.num && suit == x.suit) return true;
//        else return false;
//    };
//    bool operator>(const Node& x) const{
//        if(suit == x.suit){
//            if(num == 'a')return false; 
//            if(num == 'q' && x.num =='k')return false;
//            else if(num == 'k' && x.num == 'k')return false;
//            else if(num == 'k' && x.num =='q') return true;
//            else num > x.num;
//        }else{
//            if(suit == 'h')return true;
//            else if(suit == 's' && x.suit == 'h') return false;
//            else if(suit == 's' && x.suit == 'd') return true;
//            else if(suit == 's' && x.suit == 'c') return true;
//            else if(suit == 'd' && x.suit == 'h') return false;
//            else if(suit == 'd' && x.suit == 's') return false;
//            else if(suit == 'd' && x.suit == 'c') return true;
//            else if(suit == 'c') return false;
//        }
//    };
//    };

int main(){
  //Card Bob;
  //Bob.insert('s', '2');
  //Bob.insert('s', '2');
  //Bob.insert('h', '3');
  //Bob.insert('c', '4');
  //Bob.insert('d', '5');
  //Bob.insert('h', 'a');
  //Bob.insert('h', 'k');
  //Bob.insert('h', '10');
  //Bob.printInOrder();
  //cout << endl;
  //Bob.printPreOrder();
  //Bob.remove('h','3');
  //cout << endl;
  //Bob.printInOrder();
  //Bob.printPreOrder();
  //cout << "pre" << endl;
  //Bob.getPredecessor('h', '0');
  //Bob.getSuccessor('h','k');
  //Bob.getSuccessor('h','3'); 
  //char m = 'j';
  //char n = '0';
  //if(m > '0') cout << m  << endl;
  string line = "s 7";
  char s = 's';
  if(s == line[0]) cout << "666"  << endl;
  return 0;
}