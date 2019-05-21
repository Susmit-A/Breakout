//
// Created by susmit on 21/5/19.
//

#include "levels.h"

Level::Level(int r=5, int c=10) {
    rows = r;
    cols = c;
    blocks = (Block***)malloc(rows * cols * sizeof(Block));

    for(int i=0;i<rows;i++) {
        blocks[i] = new Block *[cols];
        for (int j = 0; j < cols; j++) {
            blocks[i][j] = new Block(Block::len * j, 550 - (Block::wid * i));
        }
    }
}

Block*** Level::getBlockMatrix() {
    return blocks;
}

int Level::getColumnCount() {
    return cols;
}

int Level::getRowCount() {
    return rows;
}

