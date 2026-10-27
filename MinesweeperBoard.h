#pragma once

enum GameMode
{
    DEBUG,
    EASY,
    NORMAL,
    HARD
};

struct Field
{
    bool hasMine;
    bool hasFlag;
    bool isRevealed;
};

class MinesweeperBoard
{
private:
    Field board[100][100];
    int width;
    int height;

    void clearBoard();

public:
    MinesweeperBoard();

    void debug_display() const;
};
