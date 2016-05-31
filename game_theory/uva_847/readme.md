# Cheat sheet:
## 1. Strategy: 

a) if p <= 9, Stan can multiply n by 9, and win
             
b) if p > 9 && <= 2*9, Stan cannot reach p by multiplying once. And even if Stan multiply n by 2, Ollie can multiply n by 9 and win

c) if p > 2*9 && p < 9*2*9 Stan can now reach p without allowing Ollie to reach p 

...

## 2. Pattern:

Assume b is largest number for which 18^b < p, p = 18^b*res

if res <= 9, then Stan wins, otherwise Ollie wins
