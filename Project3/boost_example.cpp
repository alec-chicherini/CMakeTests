#include "boost/type_index.hpp"//boost::type_index
#include <iostream>
#include <type_traits>

template<typename T>
std::string boost_type_name()
{
    return boost::typeindex::type_id_with_cvr<T>().pretty_name();
}

int main() {
    std::cout << boost_type_name<decltype(main)>()
              << std::endl;

}