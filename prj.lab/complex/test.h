#include <cassert>
#include <exception>
#include <sstream> 
#include <string>

#include "complex.h"

inline void RunTest () {
    const std::string INPUT = "{42,228}";
    std::istringstream istrm(INPUT);

    Complex complex;
    istrm >> complex;
    assert(istrm.good());

    assert(complex == Complex(42, 228));
    std::cerr << "read input : OK" << std::endl;

    complex += 5;
    assert(complex == Complex(47, 228));
    std::cerr << "+= operator with real number : OK" << std::endl;

    complex -= 3;
    assert(complex == Complex(44, 228));
    std::cerr << "-= operator : OK" << std::endl;

    complex *= 10;
    assert(complex == Complex(440, 2280));
    std::cerr << "*= operator : OK" << std::endl;

    complex += Complex(1, -2);
    assert(complex == Complex(441, 2278));
    std::cerr << "+= operator with complex number : OK" << std::endl;

    complex /= 1;
    assert(complex == Complex(441, 2278));
    std::cerr << "/= operator with real number : OK" << std::endl;

    try {
        complex /= 0;
    }
    catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
}
