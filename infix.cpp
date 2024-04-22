#include<iostream> 
#include"quence.h"
#include"stack.h"
using namespace std ; 

string DeleteSpace ( string expression ) { 
    string temp = expression ; 
    int length = temp.length( ) ; 

    for (int i = length; i >= 0 ; i--) { 
        if (expression[i] == ' ') { 
            temp.erase(temp.begin() + i) ; 
        }
    }
    return temp ; 
}
int Prioritize( char token){

    if ( token == '('){ 
        return 0 ; 
    }
    if ( token == '+' || token == '-' ){ 
        return 1 ; 
    }
    if ( token == '*' || token == '/' || token == '%'){ 
        return 2 ; 
    }
}

void TransformToPrefix (string infix, string &prefix ) { 
    
    infix = DeleteSpace(infix) ; 
    
    int length = infix.length( ) ; 

    Quence<char> number ; 
    Stack<char> token ; 
    char element ; 

    for ( int i = 0; i < length; i ++) { 

        element = infix[i] ; 

        if (!isdigit(element)) { 
            if ( token.IsEmpty()) { 
                token.Push(element) ;
            }
            if (element == '(') { 
                token.Push(element) ; 
            }
            else {
                if (element == ')')
                { 
                    while (token.GetTop() != '('){ 
                        
                        prefix.push_back(token.Pop()) ; 
                        prefix.push_back( ' ' ) ;
                    }
                }
                else { 
                    if ( Prioritize(element) > Prioritize(token.GetTop()) && token.GetTop() != '(') { 
                        while (number.GetHead() != ' ') { 
                            prefix.push_back(number.Dequence()) ;
                        }
                        prefix.push_back( ' ') ;
                        prefix.push_back(element) ;  
                        number.EnQuence(' ') ;
                    }
                    else { 
                        prefix.push_back(element);
                        prefix.push_back(' ') ; 
                        number.EnQuence(' ') ;  
                    }
                }
            }
            token.Push(element) ; 
        }    
        else { 
            number.EnQuence(element) ; 
        }
    }
    while (!number.IsEmpty()) { 
        prefix.push_back(number.Dequence()) ; 
    }
}
int main ( ) {

    string infix_expression ; 

    string prefix_expression ; 

    cout << "Enter Infix Expression : " ; 
    getline ( cin, infix_expression) ; 
    
    TransformToPrefix(infix_expression, prefix_expression) ; 
    cout << "infix: " << infix_expression << endl; ; 
    cout << "prefix: " << prefix_expression << endl; 
     
    return 0 ; 
}
