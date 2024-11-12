import sys
import os

class Treasure:
    def __init__(self, x, y, value):
        self.x = x
        self.y = y
        self.value = value
    def __getitem__(self, item):
        return self.value[item]

def compare(Treasure1, Treasure2):
    if Treasure1.x == Treasure2.x:
        return Treasure1.y < Treasure2.y
    return Treasure1.x < Treasure2.x



if __name__ == '__main__':
    n = int(input())
    result = 0
    lst = []
    for i in range(n):
        x, y, value = map(int, input().split())
        treasure = Treasure(x, y, value)
        lst.append(treasure)
    # Sort the list, first is x-coordinates, second is y-coordinates
    sorted_lst = sorted(lst, key = lambda treasure: (treasure.x, treasure.y))
    dp = [0 for _ in range (n)]
    for i in range (0, len(sorted_lst)):
        dp[i] = sorted_lst[i].value
        for j in range (0, i):
            if sorted_lst[j].x <= sorted_lst[i].x and sorted_lst[j].y <= sorted_lst[i].y:
                dp[i] = max(dp[i], dp[j] + sorted_lst[i].value)
        result = max(result, dp[i])
    print(result)
