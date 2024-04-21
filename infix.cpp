#include<iostream> 
#include"quence.h"

using namespace std;

string DeleteSpace (string expresion) { 
    string temp = expresion; 
    int i = temp.length() ; 
    while ( i >= 0 ){
        if (expresion[i] == ' ') { 
           temp.erase(temp.begin() +i) ; 
        }
        i--; 
    }
    return temp ; 
}



void TransformToPrefix( string infix, string &prefix) { 

    Quence<char> number ; 
    infix = DeleteSpace(infix) ; 
    cout << infix << endl ;
    int length = infix.length() ; 
    char element ; 
    for( int i = 0; i < length; i++ ) {
        element = infix[i] ; 
        if ( !isdigit(element) ) { 
            
            prefix.push_back(element) ; 
            prefix.push_back( ' ' ) ;
            number.EnQuence( ' ' ) ; 
        }
        else { 
            number.EnQuence(element) ; 
        }
    }
    while (!number.IsEmpty()) { 
        prefix.push_back(number.DeQuence()) ; 
    }
}



int main(int argc, char** argv) { 
     
    string infix_expression ; 

    string prefix_expression ; 

    cout << "Enter infix expression: " ; 
    getline(cin, infix_expression) ; 

    TransformToPrefix( infix_expression, prefix_expression) ; 
    cout << "infix: " << infix_expression << endl; 
    cout << "prefix : " << prefix_expression << endl; 

}
