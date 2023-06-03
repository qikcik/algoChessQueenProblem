#include <iostream>

#include "algorithm.hpp"
int main() {

    Algorithm algorithm(8);

    //for(auto& solIt : algorithm.getAllPossibleSolution() )
    //    std::cout << solIt;

    std::cout << "number of possible solution:" << algorithm.getAllPossibleSolution().size();
    return 0;
}
