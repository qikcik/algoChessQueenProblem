#pragma once
#include <vector>
#include <ostream>
#include "cords.hpp"

class Board
{
public:
    Board(int boardSize);

    void putOrOverrideInColumnPiece(const Cords& cor);
    [[nodiscard]] std::vector<Cords> getPiecesPosition() const;

    static bool isFirstPieceSeeSecond(const Cords& first,const Cords& second);
    [[nodiscard]] std::vector<Cords> getAllPossibleValidCordsInColumn(int column) const;

    friend std::ostream &operator<<(std::ostream &os, const Board &board);

public:
    const int boardSize;

protected:
    using rowPosition = int;
    const rowPosition EMPTY_ROW = -1;
    std::vector<rowPosition> columns;
};