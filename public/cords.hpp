#pragma once

#include <ostream>

struct Cords
{
    int col;
    int row;

    [[nodiscard]] bool isValidInBoardSize(int boardSize) const;

    bool operator==(const Cords &rhs) const;
    bool operator!=(const Cords &rhs) const;

    friend std::ostream &operator<<(std::ostream &os, const Cords &cords);
};
