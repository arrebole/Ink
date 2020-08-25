#! /usr/bin/env python

from typing import List

class Solution:
    def __init__(self):
        self.stack = []
        self.result = []

    def has(self, char: str):
        return len(self.stack) == 0 or char in self.stack

    def settle(self, index: int):
        if len(self.stack) >= 3:
            self.result.append([index - len(self.stack), index-1])
        self.stack.clear()

    def largeGroupPositions(self, S: str) -> List[List[int]]:
        for i, char in enumerate(S):
            if  not self.has(char):
                self.settle(i)
            self.stack.append(char)
        self.settle(len(S))
        return self.result
