#include <iostream>
#include <fstream>
#include <string>
#include "cards.h"
#include "utility.h"
using namespace std;

int main(int argv, char** argc){
  if(argv < 3){
    cout << "Please provide 2 file names" << endl;
    return 1;
  }
  
  ifstream cardFile1 (argc[1]);
  ifstream cardFile2 (argc[2]);
  string line;

  if (cardFile1.fail() || cardFile2.fail() ){
    cout << "Could not open file " << argc[2];
    return 1;
  }
  Card Alice;
  Card Bob;
  //Read each file
  while (getline (cardFile1, line) && (line.length() > 0)){
    if(line[2] == '1'){
      Alice.insert(line[0], '0');
    }else{
      Alice.insert(line[0], line[2]);
    }
  }
  cardFile1.close();


  while (getline (cardFile2, line) && (line.length() > 0)){
    if(line[2] == '1'){
      Bob.insert(line[0], '0');
    }else{
      Bob.insert(line[0], line[2]);
    }
  }
  cardFile2.close();

 //void insrt(Card& A, char a, char b);
  //void play(Card& A, Card& B);
  Card * m = &Alice;
  Card * n = &Bob;
  //two choose cases in utitlity that returns true if card find false otherwise
  bool x = AliceChoose(*m,*n);
  bool y = BobChoose(*m,*n);
  int count = 0; //0 is alice turn and 1 is Bob turn
  while(x && y){
      if(count == 0){
          x = AliceChoose(*m,*n);
          count = 1;
      }
      else{
          y = BobChoose(*m,*n);
          count = 0;
      }
  }
  cout << endl;
  cout << "Alice's cards:" << endl;
  Alice.printInOrder();
  cout << endl;
  cout << "Bob's cards:" << endl;
  Bob.printInOrder();
  
  return 0;
  //insrt(*m, 's', 'a');
  //Alice.printInOrder();
  
}
//void insrt(Card& A, char a, char b){
//  A.insert(a,b);
//}
//void play(Card& A, Card& B){
//    Card* x = &A;
//    Card* y = &B;
//    bool m = AliceChoose(*x,*y);
//    bool n = BobChoose(*x,*y);
//    int count = 0; //0 is alice turn and 1 is Bob turn
//    while(m && n){
//        if(count == 0){
//            m = AliceChoose(*x,*y);
//            count = 1;
//        }
//        else{
//            n = BobChoose(*x,*y);
//            count = 0;
//        }
//    }
//}


