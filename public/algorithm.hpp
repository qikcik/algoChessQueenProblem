#pragma once
#include <vector>
#include "board.hpp"

class Algorithm
{
public:
    Algorithm(int boardSize);
    std::vector<Board> getAllPossibleSolution();

protected:
    void RecursivelyFoundPossibleCord(const Board& , int insertingColumn);

private:
    const int boardSize;
    std::vector<Board> possibleSolution;
};

