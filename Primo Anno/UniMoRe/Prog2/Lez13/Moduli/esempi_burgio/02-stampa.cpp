#include <iostream>
//using namespace std;

// Generate C linkage
// //extern "C"
// void stampa(int a)
// {
//     std::cout << "Hello World! a is " << a << std::endl;
// }


// Namespaces only work in C++ (and the linkage is generated accordingly)
namespace paolo { namespace v1 {
void stampa(int a)
{
    std::cout << "Hello World! a is " << a << std::endl;
}
}}

namespace paolo { namespace v2 {

void stampa(int a)
{
    std::cout << "Ciao Mondo! a e " << a << std::endl;
}
}}