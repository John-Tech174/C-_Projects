// File Guard
#ifndef _MATH_HPP_
#define _MATH_HPP_

// Includes
#include <iostream>
#include <string>
#include "custom.hpp"

// Namespace and Functions
namespace numeric
{
    // Implementing max function using tail recursion method
    template < typename T, typename U, typename ... types >
    auto max(const T& argument1, const U& argument2, const types& ... arguments){
        static_assert(std::is_arithmetic_v<T> && std::is_arithmetic_v<U>,"Arguments passed must be arithmetic");
        if constexpr (sizeof...(types) == 0){
            if(argument1 >= argument2){
                return argument1;
            }
            else if(argument1 < argument2){
                return argument2;
            }
            else {/* Do Nothing */}
        }
        else if constexpr (sizeof...(types) > 0){
            auto maximum = 0;
            if(argument1 >= argument2){
                maximum = argument1;
            }
            else if(argument1 < argument2){
                maximum = argument2;
            }
            else { /* Do Nothing */}
            return max(maximum,arguments ...);
        }
    }

    // Template data type specialization for the data type custom

    /***********************************************************************************/

    // Single argument min function used for folding expression method
    template < typename T >
    auto min(const T& argument){
        static_assert(std::is_arithmetic_v<T>);
        return argument;
    }

    // Implementing min function using folding expression
    template < typename T, typename U, typename ... types >
    auto min(const T& argument1, const U& argument2, const types& ... arguments){
        static_assert((std::is_arithmetic_v<T> && std::is_arithmetic_v<U>),"Arguments passed must be arithmetic");
        auto minimum = 0;
        if (argument1 <= argument2){
            minimum = argument1;
        }
        else if (argument1 > argument2){
            minimum = argument2;
        }
        else {/* Do Nothing */}
        return min(minimum,arguments ...);
    }
    /***********************************************************************************/

    // Implementing sub function using tail recursion method
    template < typename T, typename U, typename ... types >
    auto sub(const T& argument1, const U& argument2, const types& ... arguments){
        static_assert(std::is_arithmetic_v<T> && std::is_arithmetic_v<U>,"Arguments passed must be arithmetic");
        if constexpr (sizeof...(types) == 0){
            return (argument1 - argument2);
        }
        else if constexpr (sizeof...(types) > 0){
            auto difference = argument1 - argument2;
            return sub(difference,arguments ...);
        }
        else {/* Do Nothing */}
    }

    signed int sub(Custom& argument1, Custom& argument2){
        return (argument1 - argument2);
    }
    /***********************************************************************************/
}

#endif