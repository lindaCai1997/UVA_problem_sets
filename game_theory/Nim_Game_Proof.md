# The Nim Game
## Problem Description:
      In Nim game, two players take turns to remove objects from distinct heaps. On each turn, a player must remove 
      at least one object and may remove any number of objects provided that they all come from the same heap. The 
      initial state of the game is the number of objects ni at each of the k heaps: {n1, n2, ..., nk}

## Solution:
      define player1 = player who plays first
      define player2 = player who plays next
      
      if n1^n2^n3...^nk = 0, player1 lose
      else player2 win

## Proof
1) if k = 1, heaps = {n1}, n1 != 0, player1 should win
      the first player can remove n1 elements from the first group and win, {n1} is a win state

2) if k = 2, heaps = {n1, n2}
      2.1) n1^n2 = 0, then n1 = n2, assume i,j ∈ {1, 2}, i != j
             If player1 removes ni elements from ni, heaps = {nj}, a win state for player2
             
             If player1 removes k elements from ni (k < ni), player2 can remove k elements from nj. 
                  Because every time player1 must remove >= 1 element, eventually heaps = {1,1}
                  player1 is forced to remove all elements from ni, heaps = {1}, player2 wins
                  
             Therefore, {n1, n2}, n1^n2 = 0 is a lose state
             
      2.2) n1^n2 != 0, assume n1 < n2, then player1 can remove n2 - n1 elements from n2
             This results in {n1, n1}, a lose state for player2
             Therefore, {n1, n2}, n1 != n2 is a win state
            
            
            
      
             
             

        
