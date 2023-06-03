#include "cords.hpp"

bool Cords::isValidInBoardSize(int boardSize) const
{
    return col < boardSize and row < boardSize;
}

bool Cords::operator==(const Cords &rhs) const
{
    return col == rhs.col &&
           row == rhs.row;
}

bool Cords::operator!=(const Cords &rhs) const
{
    return !(rhs == *this);
}

std::ostream &operator<<(std::ostream &os, const Cords &cords)
{
    os << "(col: " << cords.col << " row: " << cords.row << ")";
    return os;
}
