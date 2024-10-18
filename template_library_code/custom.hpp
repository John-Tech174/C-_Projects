// File Guard
#ifndef _CUSTOM_HPP_
#define _CUSTOM_HPP_

// Includes
#include <iostream>
#include <string>

// User-Defined Data Type
class Custom {
public:
    Custom(std::string b) : m_b{b} {}
    signed int operator-(Custom &object_b){
        return (this->m_b.length() - object_b.m_b.length());
    }
private:
    std::string m_b;
};

#endif