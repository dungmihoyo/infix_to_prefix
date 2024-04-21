#include<iostream> 
#include"node.h" 

#ifndef QUENCE_H 
#define QUENCE_H

using namespace std; 

template<class T> 
class Quence { 
    private: 
    Node<T>* head; 
    Node<T>* tail; 

    public: 
    Quence() { 
        head = NULL; 
        tail = NULL ; 
    }

    void EnQuence (T value) { 
        Node<T>* newNode = new Node<T> ; 
        newNode -> value = value ; 
        newNode -> next = NULL ; 
        if ( head == NULL) { 
            head = newNode; 
            tail = newNode; 
        } 
        else { 
            tail -> next = newNode; 
            tail = newNode; 
        }
    }

    T DeQuence () {
        T value = head -> value; 
        Node<T> * temp = head ; 
        head = head -> next ; 
        delete temp; 
        return value;
    }

    bool IsEmpty( ) const { 
        return (head == NULL ) ; 
    }

    T GetHead () const { 
        return head -> value ; 
    }
};

#endif