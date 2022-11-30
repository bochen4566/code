// cards.cpp
// Author: Your name Bochen Wang
// Implementation of the classes defined in cards.h
#include "cards.h"
#include <iostream>
using std::cout;

// constructor sets up empty tree
Card::Card() { 
    root = nullptr;
}

// destructor deletes all nodes
Card::~Card() {
    clear(root);
}


// recursive helper for destructor
void Card::clear(Node *n) {
    if(n == nullptr) return;
    clear(n->left);
    clear(n->right);
    delete n;
}

// insert value in tree; return false if duplicate
bool Card::insert(char type, char value) {
    return insert(type, value, root); // REPLACE THIS NON-SOLUTION
}
//find max;
string Card::max(){
    Node* m = root;
    string res = "";
    if(m == NULL) return res;
    while(m->right){
        m = m->right;
    }
    res += m->suit;
    res += m->num;
    return res;
}

//find min
string Card::min(){
    Node* m = root;
    string res = "";
    if(m == NULL) return "";
    while(m->left){
        m = m->left;
    }
    res += m->suit;
    res += m->num;
    return res;
}

// recursive helper for insert (assumes n is never 0)
bool Card::insert(char type, char value, Node *n) {
    Node* m = new Node;
    m->num = value;
    m->suit = type;
    if(n == nullptr){
        root = m;
        return true;
    }
    if(*n == *m) return false;//n->num == value && n->suit == type
    if((*n > *m) && (n->left != nullptr)) return insert(type, value, n->left);
    if((*n < *m) && (n->right != nullptr)) return insert(type, value, n->right);
    if((n->left == nullptr) && (*n > *m) ){
            n->left = m;
            m->parent = n;
            return true;
        }
    if((*n < *m) && (n->right == nullptr)){
            n->right = m;
            m->parent = n;
            return true;
        }
    return true;
}
    //return true;
     // REPLACE THIS NON-SOLUTION
    //if(n == nullptr){
    //    Node* m = new Node;
    //    m->info = value;
    //    return true;
    //}
    //if(n->info == value) return false;
    //if(n->info > value) return insert(value, n->left);

// print tree data in-order, with helper
void Card::printInOrder() const {
    //cout << "IMPLEMENT printInOrder public method"; // IMPLEMENT HERE
    printInOrder(root);
}
void Card::printInOrder(Node *n) const {
    if(n == nullptr) return;
    printInOrder(n->left);
    if(n->num == '0')cout << n->suit<< " " << 10 << endl;
    else cout << n->suit<< " " << n->num << endl;;//"IMPLEMENT IMPLEMENT printInOrder private helper method"; // IMPLEMENT HERE
    printInOrder(n->right);
}

//// print tree data pre-order
void Card::printPreOrder() const {
    //cout << "IMPLEMENT printPreOrder public method";; // IMPLEMENT HERE
    printPreOrder(root);
}

// recursive helper for printPreOrder()
void Card::printPreOrder(Node *n) const {
    //cout << "IMPLEMENT printPreOrder private helper method"; // IMPLEMENT HERE
    if(n == nullptr) return;
    if(n->num == '0')cout << n->suit<< " " << 10 << endl;
    else cout << n->suit<< " " << n->num << endl;
    printPreOrder(n->left);
    printPreOrder(n->right);
}
//
//

//// return count of values
int Card::count() const {
    return count(root); // REPLACE THIS NON-SOLUTION
}

// recursive helper for count
int Card::count(Node *n) const {
    if(n == nullptr) return 0; 
    //return 1+sum(n->left);
    return 1+count(n->left)+count(n->right);// REPLACE THIS NON-SOLUTION
}
//
//// IMPLEMENT THIS FIRST: returns the node for a given value or NULL if none exists
//// Parameters:
//// int value: the value to be found
//// Node* n: the node to start with (for a recursive call)
//// Whenever you call this method from somewhere else, pass it
//// the root node as "n"
Card::Node* Card::getNodeFor(char type, char value, Node* n) const{
    if(n == nullptr) return NULL;
    Node* temp = new Node;
    temp->suit = type;
    temp->num = value;
    if(*n == *temp) return n;
    else if(*n > *temp)return getNodeFor(type,value, n->left);
    else if(*n < *temp)return getNodeFor(type,value, n->right);
    else return nullptr;
//return NULL; // REPLACE THIS NON-SOLUTION
}

// returns true if value is in the tree; false if not
bool Card::contains(char type, char value) const {
    if(getNodeFor(type, value, root) == NULL) return false;
    else return true; // REPLACE THIS NON-SOLUTION
}
//
// returns the Node containing the predecessor of the given value
Card::Node* Card::getPredecessorNode(char type, char value) const{
    Node* m = getNodeFor(type, value, root);
    if(m->left != nullptr){
        if(m->left->right == nullptr) return m->left;
        else{
            m = m->left->right;
            while(m->right){
                m = m->right;
            }
            return m;
        }
    }
    else{
        if(m->parent == nullptr) return NULL;
        Node* temp = m;
        m = m->parent;
        if(m == nullptr) return NULL;
        while(*m > *temp){
            m = m->parent;
            if(m == nullptr) return NULL;
        }
        return m;
        
    }// REPLACE THIS NON-SOLUTION
}
//
//// returns the predecessor value of the given value or 0 if there is none
string Card::getPredecessor(char type, char value) const{
    string res = "";
    //string res0 = "0";
    if(getPredecessorNode(type,value) != NULL){
        res += getPredecessorNode(type, value)->suit;
        res += getPredecessorNode(type, value)->num;
        return res;
    } 
    return res;
}

// returns the Node containing the successor of the given value
Card::Node* Card::getSuccessorNode(char type, char value) const{
    Node* m = getNodeFor(type, value, root);
    if(m->right != nullptr){
        if(m->right->left == nullptr) return m->right;
        else{
            m = m->right->left;
            while(m->left){
                m = m->left;
            }
            return m;
        }
    }
    else{
        if(m->parent == nullptr) return NULL;
        Node* temp = m;
        m = m->parent;
        if(m == nullptr) return NULL;
        while(*m < *temp){
            m = m->parent;
            if(m == nullptr) return NULL;
        }
        return m;
        }
     
}

// returns the successor value of the given value or 0 if there is none
string Card::getSuccessor(char type, char value) const{
    //Node* m = getSuccessorNode(type, value);
    string res = "";
    //string res0 = "0";
    //string x = "";
    //x += type;
    //x += value;
    //if(x == *this.max())
    if(getSuccessorNode(type, value) != NULL){
        res += getSuccessorNode(type, value)->suit;
        res +=  getSuccessorNode(type, value)->num;
        return res;
    } 
    return res;// REPLACE THIS NON-SOLUTION
}

// deletes the Node containing the given value from the tree
// returns true if the node exist and was deleted or false if the node does not exist
bool Card::remove(char type, char value){
    Node* n = getNodeFor(type, value, root);
    if(n == NULL) return false;
    else{
        if((n->parent == nullptr) && n->left == nullptr && n->right == nullptr){
            delete n;
            root = nullptr;
            return true;
        }
        if(((n->parent == nullptr) && (n->left != nullptr)) && (n->right == nullptr)){
            root = n->left;
            n->left->parent = nullptr;
            delete n;
            return true;
        }
        if(((n->parent == nullptr) && (n->left == nullptr)) && (n->right != nullptr)){
            root = n->right;
            n->right->parent = nullptr;
            delete n;
            return true;
        }
        if(((n->parent == nullptr) && (n->left != nullptr)) && (n->right != nullptr)){
            Node* m = getPredecessorNode(type, value);
            if(m == nullptr){
                m = getSuccessorNode(type,value);
            }
                char tempsuit = m->suit;
                char tempnum = m->num;
                remove(m->suit, m->num);
                n->suit = tempsuit;
                n->num = tempnum;
            return true;
        }
        if(n->left == nullptr && n->right == nullptr){//case with no child
            if(n->parent->left == n){
                n->parent->left = nullptr;
                delete n;
                return true;
            }else{
                n->parent->right = nullptr;
                delete n;
                return true;
            }

        }
        //case with one child
        if(n->left != nullptr && n->right == nullptr){
            if(n->parent->left == n){
                n->parent->left = n->left;
                n->left->parent = n->parent;
                delete n;
                return true;
            }else{
                n->parent->right = n->left;
                n->left->parent = n->parent;
                delete n;
                return true;
            }            
        }
        if(n->left == nullptr && n->right != nullptr){
            if(n->parent->left == n){
                n->parent->left = n->right;
                n->right->parent = n->parent;
                delete n;
                return true;
            }else{
                n->parent->right = n->right;
                n->right->parent = n->parent;
                delete n;
                return true;
            }            
        }
        //case with two child do it recersively in case there is preddecessor or successor with child
        if(n->left != nullptr && n->right != nullptr){
            Node* m = getPredecessorNode(type, value);
            if(m == nullptr){
                m = getSuccessorNode(type,value);
            }
                char tempsuit = m->suit;
                char tempnum = m->num;
                remove(m->suit, m->num);
                n->suit = tempsuit;
                n->num = tempnum;
                return true;
        
        }
        return false;   
    }
}