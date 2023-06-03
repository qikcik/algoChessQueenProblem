#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "board.hpp"


TEST(BoardTests, MultiTest_PuttingPieces)
{
    Board board {8};

    EXPECT_EQ(board.getPiecesPosition().size(),0);
    board.putOrOverrideInColumnPiece({0,0});
    EXPECT_EQ(board.getPiecesPosition().size(),1);
    ASSERT_THAT(board.getPiecesPosition(), testing::ElementsAre( Cords(0,0) ));

    board.putOrOverrideInColumnPiece({0,5});
    EXPECT_EQ(board.getPiecesPosition().size(),1);
    ASSERT_THAT(board.getPiecesPosition(), testing::ElementsAre( Cords(0,5) ));

    board.putOrOverrideInColumnPiece({0,100});
    EXPECT_EQ(board.getPiecesPosition().size(),1);
    ASSERT_THAT(board.getPiecesPosition(), testing::ElementsAre( Cords(0,5) ));

    board.putOrOverrideInColumnPiece({1,2});
    EXPECT_EQ(board.getPiecesPosition().size(),2);
    ASSERT_THAT(board.getPiecesPosition(), testing::ElementsAre( Cords(0,5),Cords(1,2) ));
}

TEST(BoardTests, MultiTest_IsPieceSeeAnother)
{
    Board board {8};
    EXPECT_EQ(Board::isFirstPieceSeeSecond({1,1},{0,1}),true);
    EXPECT_EQ(Board::isFirstPieceSeeSecond({1,1},{0,3}),false);

    EXPECT_EQ(Board::isFirstPieceSeeSecond({1,1},{0,0}),true);
    EXPECT_EQ(Board::isFirstPieceSeeSecond({1,1},{0,2}),true);
    EXPECT_EQ(Board::isFirstPieceSeeSecond({1,1},{0,3}),false);

    EXPECT_EQ(Board::isFirstPieceSeeSecond({0,0},{1,1}),true);
    EXPECT_EQ(Board::isFirstPieceSeeSecond({0,2},{1,1}),true);
    EXPECT_EQ(Board::isFirstPieceSeeSecond({0,3},{1,1}), false);
}

TEST(BoardTests, MultiTest_getAllPossibleValidPositionsInColumn)
{
    Board board {8};
    ASSERT_THAT(board.getAllPossibleValidCordsInColumn(0), testing::ElementsAre(Cords(0, 0), Cords(0, 1), Cords(0, 2), Cords(0, 3), Cords(0, 4), Cords(0, 5), Cords(0, 6), Cords(0, 7) ));

    board.putOrOverrideInColumnPiece({0,4});
    ASSERT_THAT(board.getAllPossibleValidCordsInColumn(1), testing::ElementsAre(Cords(1, 0), Cords(1, 1), Cords(1, 2), Cords(1, 6), Cords(1, 7) ));
    ASSERT_THAT(board.getAllPossibleValidCordsInColumn(2), testing::ElementsAre(Cords(2, 0), Cords(2, 1), Cords(2, 3), Cords(2, 5), Cords(2, 7) ));

    board.putOrOverrideInColumnPiece({1,6});
    ASSERT_THAT(board.getAllPossibleValidCordsInColumn(2), testing::ElementsAre(Cords(2, 0), Cords(2, 1), Cords(2, 3)));
}

