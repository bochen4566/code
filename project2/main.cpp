// Spring'22
// Instructor: Diba Mirza
// Student name: Bochen Wang
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <vector>
#include <cstring>
#include <algorithm>
#include <limits.h>
#include <iomanip>
#include <set>
#include <queue>
#include "movies.h"
using namespace std;

bool parseLine(string &line, string &movieName, double &movieRating);

class myFunctor{//functor for the priority queue
    public:
        bool operator()(movies a, movies b){
            if(a.getMoRate() < b.getMoRate()) return true;
            else if(a.getMoRate() == b.getMoRate()) return a > b;
            else return false;
        };
        
};

class bestMovie{
    public:
        bestMovie(movies a, string pre){
            mo = a;
            prefix = pre;
        }
        void print(){
            cout << "Best movie with prefix " << prefix << " is: " << mo.getMoName() << " with rating " << std::fixed << std::setprecision(1) << mo.getMoRate()<< endl;
        }

    private:
        movies mo;
        string prefix;
};


int main(int argc, char** argv){
    if (argc < 2){
        cerr << "Not enough arguments provided (need at least 1 argument)." << endl;
        cerr << "Usage: " << argv[ 0 ] << " filename prefix1 prefix2 ... prefix n " << endl;
        exit(1);
    }

    ifstream movieFile (argv[1]);
 
    if (movieFile.fail()){
        cerr << "Could not open file " << argv[1];
        exit(1);
    }
  
  // Create an object of a STL data-structure to store all the movies
    set<movies> movie;
  string line, movieName;
  double movieRating;
  // Read each file and store the name and rating
  while (getline (movieFile, line) && parseLine(line, movieName, movieRating)){
        // Use std::string movieName and double movieRating
        // to construct your Movie objects
        // cout << movieName << " has rating " << movieRating << endl;
        // insert elements into your data structure
        movie.insert(movies(movieName, movieRating));
  }

  movieFile.close();
    //part 1
  if (argc == 2){
        //print all the movies in ascending alphabetical order of movie names
        for(auto item : movie){
            item.print();
        }
        return 0;
  }

  //  For each prefix,
  //  Find all movies that have that prefix and store them in an appropriate data structure
  //  If no movie with that prefix exists print the following message
  //cout << "No movies found with prefix "<<"<replace with prefix>" << endl << endl;

  //  For each prefix,
  //  Print the highest rated movie with that prefix if it exists.
  //cout << "Best movie with prefix " << "<replace with prefix>" << " is: " << "replace with movie name" << " with rating " << std::fixed << std::setprecision(1) << "replace with movie rating" << endl;
    
    //part 2
    
    if(argc > 2){
        vector<bestMovie> best;//use to store and print best movie
        for(int i = 2; i < argc; i++){
            string key = argv[i];
            vector<movies> mov;//get a vector for the priority queue to use for matching max
            for(auto m:movie){
                if(m.getMoName().substr(0, key.size()) == key){//find the movie with prefix
                    mov.push_back(m);
                }
            }
            if(mov.empty()){
               cout << "No movies found with prefix "<< key << endl << endl; 
            }
            else{// find a vector contains the prefix then use the priority queue to order and print
                priority_queue<movies, vector<movies>, myFunctor> pq;
                for(auto n:mov){//get the data from the movie vector
                    pq.push(n);
                }
                //then get the best movie
                best.push_back(bestMovie(pq.top(), key));
                while(!pq.empty()){//print the pq
                    (pq.top()).print();
                    pq.pop();
                }

                cout << endl;
            }

        }
        for(auto au:best){
            au.print();
        }
    }
  return 0;
}

/* Add your run time analysis for part 3 of the assignment here as commented block
3a :
For time complexity the part 2 have T = n*O(n+n) since they will have n the largest that T = O(n^2logn)
3b :
For space complaxity have O(n*k*logn) for the worst case
3c :
1 for low time complexity comes with the low space comlexity that for this comes with the number of input in file that checks the arguments
so this time complexity is able to make space compexity smaller
2 for low space complexity have the dependency on the num of input so for this worst case for my program is the same as the movie list
low space complexity did not affect time complexity that the time complexity is defined by algorithm
3 I am able to achieve low space complexity also maybe I reduce the time of the loops that will help my algorithm to achieve better and also for searching the 
part I can use the more adcanced searching method for my algorithm to work. low time complexity is harder to achieve because that it requires more searching
efficiently not just simply iterate through the whole data set.
*/

bool parseLine(string &line, string &movieName, double &movieRating) {
    if (line.length() <= 0) return false;
    string tempRating = "";

    bool flag = false;
    movieName = tempRating = "", movieRating = 0.0, flag = false;

    for (int i = 0; i < line.length(); i++){
        if(flag) tempRating += line[i];
        else if(line[i]==','&& line[0]!='"') flag = true;
        else {
            if(i==0 && line[0]=='"') continue;
            if(line[i]=='"'){ i++; flag=true; continue;}
            movieName += line[i];
        }
    }
    
    movieRating = stod(tempRating);
    return true;
}
