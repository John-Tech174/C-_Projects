#include "math.hpp"

int main()
{
    Custom object1("Hello");
    Custom object2("Embedded_Linux");

    std::cout<<"maximum value = "<<numeric::max(11,5,-3,12.5,-18,100,16)<<std::endl;
    std::cout<<"minimum value = "<<numeric::min(11,5,-3,12.5,-18,100,16)<<std::endl;
    std::cout<<"difference = "<<numeric::sub(11,5,-3,12.5,-18,100,16)<<std::endl;

    std::cout<<numeric::sub(object1,object2)<<std::endl;
    return EXIT_SUCCESS;
}