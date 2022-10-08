#! /usr/bin/env python

from typing import List

def valid(a: List[int]):
    for items in a:
        seen = set()
        for item in items:
            if item in seen:
                return False
            seen.add(item)
    return True

def fillerDot(a : List[int]):
    return [v for v in a if v != '.']

class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        validArray = []

        #  横向验证
        for row in board:
            validArray.append(fillerDot(row))

        #  纵向
        for i in range(9):
            col = [board[j][i] for j in range(9)]
            validArray.append(fillerDot(col))
        
        # 3x3
        for x in range(3):
            for y in range(3):
                block = []
                for i in range(3):
                    for j in range(3):
                        block.append(board[y * 3 + i][x * 3 + j])
                validArray.append(fillerDot(block))

        return valid(validArray)