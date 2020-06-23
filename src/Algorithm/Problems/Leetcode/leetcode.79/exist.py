from typing import List

class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        for i in range(len(board)):
            for j in range(len(board[0])):
                if self.dfsSearch(board,word, i, j, 0):
                    return True
    
        return False

    def dfsSearch(self, board: List[List[str]], word:str, i:int, j:int, k:int)->bool:
        if k >= len(word):
            return True
        
        if i < 0 or j < 0 or i > len(board) -1 or j > len(board[0]) -1 or board[i][j] != word[k]:
            return False

        temp, board[i][j] = board[i][j], ""
        result = self.dfsSearch(board, word, i, j+1, k+1) \
              or self.dfsSearch(board, word, i+1, j, k+1) \
              or self.dfsSearch(board, word, i, j-1, k+1) \
              or self.dfsSearch(board, word, i-1, j, k+1)
        board[i][j] = temp
        
        return result