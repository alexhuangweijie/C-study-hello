//
// Created by hwj on 2020/1/9.
//

#ifndef HELLO_STACK_H
#define HELLO_STACK_H
#include <string>
#include <vector>

class Stack {
public:
    bool push( const string& );
    bool pop( string &elem );
    bool peek( string &elem );
    bool empty();
    bool full();
    int size(){ return _stack.size();}
private:
    vector<string> _stack;
};



#endif //HELLO_STACK_H
