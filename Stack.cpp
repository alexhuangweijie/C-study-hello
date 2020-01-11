//
// Created by hwj on 2020/1/9.
//
#include "Stack.h"
#include <string>
#include <vector>
bool Stack::pop(std::string &elem) {
    if(empty())
        return false;
    elem = _stack.back();
    _stack.pop_back();
    return true;
}

inline bool Stack::empty() {
    return _stack.empty();
}
bool Stack::push(const std::string &elem) {
    if ( empty())
        return false;
    _stack.push_back(elem);
    return true;
}

bool Stack::peek(string &elem) {
    if (empty())
        return false;
    elem = _stack.back();
    return true;
}
inline bool Stack::full() {
    return _stack.size() == _stack.max_size();
}