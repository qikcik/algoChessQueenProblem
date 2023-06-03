#include "algorithm.hpp"

Algorithm::Algorithm(int p_boardSize)
: boardSize(p_boardSize)
{

}


void Algorithm::RecursivelyFoundPossibleCord(const Board& board,int insertingColumn)
{
    if(insertingColumn == board.boardSize)
    {
        possibleSolution.push_back(board);
        return;
    }

    for(const auto& cordIt : board.getAllPossibleValidCordsInColumn(insertingColumn))
    {
        Board boardCopy = board;
        boardCopy.putOrOverrideInColumnPiece(cordIt);
        RecursivelyFoundPossibleCord(boardCopy,insertingColumn+1);
    }
}

std::vector <Board> Algorithm::getAllPossibleSolution()
{
    possibleSolution.clear();
    RecursivelyFoundPossibleCord({boardSize},0);
    return std::move(possibleSolution);
}
