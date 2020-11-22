#include <iostream>
#include <boost/python.hpp>

using namespace boost::python;

int printHello()
{
    std::cout << "Hello, World! from C++" << std::endl;
}

BOOST_PYTHON_MODULE(hello)
{
        def("print_hello", printHello);
}