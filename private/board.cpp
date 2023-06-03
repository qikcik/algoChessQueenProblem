#include "board.hpp"
#include <iostream>

Board::Board(int p_boardSize)
: boardSize(p_boardSize)
{
    columns.reserve(boardSize);
    for(int it=0;it!=boardSize;it++)
    {
        columns.emplace_back(EMPTY_ROW);
    }
}

void Board::putOrOverrideInColumnPiece(const Cords& cord)
{
    if(!cord.isValidInBoardSize(boardSize))
        return;

    columns[cord.col] = cord.row;
}

std::vector<Cords> Board::getPiecesPosition() const
{
    std::vector<Cords> result;
    for(int it=0;it!=boardSize;it++)
    {
        if(columns[it] == EMPTY_ROW)
            continue;
        result.push_back({it,columns[it]});
    }

    return result;
}


bool Board::isFirstPieceSeeSecond(const Cords& first, const Cords& second)
{
    if(first.row == second.row)
        return true;

    int distanceInCol = second.col - first.col;

    if(second.row == first.row - distanceInCol )
        return true;
    if(second.row == first.row + distanceInCol )
        return true;

    return false;
}

std::vector<Cords> Board::getAllPossibleValidCordsInColumn(int column) const
{
    std::vector<Cords> possibleCords;
    for(int it=0;it!=boardSize;it++)
        possibleCords.push_back({column,it});

    auto existingPieces = getPiecesPosition();

    for(auto existingPieceIt : existingPieces)
    {
        std::vector<Cords> possibleCordsToReplacement;

        for(const auto& possibleCordIt : possibleCords)
            if(!isFirstPieceSeeSecond(existingPieceIt,possibleCordIt))
                possibleCordsToReplacement.push_back(possibleCordIt);

        possibleCords = std::move(possibleCordsToReplacement);
    }

    return possibleCords;
}

std::ostream &operator<<(std::ostream &os, const Board &board)
{
    for(int rowIt=0;rowIt!=board.boardSize*2;rowIt++)
        std::cout << '-';
    std::cout << '\n';

    for(int rowIt=0;rowIt!=board.boardSize;rowIt++)
    {
        auto pos = board.columns[rowIt];

        for(int it=0;it<=pos-1;it++)
            std::cout << 'O';
        std::cout << 'X';

        for(int it=pos;it<=board.boardSize;it++)
            std::cout << 'O';
        std::cout << '\n';
    }
    return os;
}
