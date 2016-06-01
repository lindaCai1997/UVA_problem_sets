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
#### 1) If k = 1, heaps = {n1}, n1 != 0, player1 should win
      the first player can remove n1 elements from the first group and win, {n1} is a win state

#### 2) If k = 2, heaps = {n1, n2},
      2.1) n1^n2 = 0, then n1 = n2, assume i, j ∈ {1, 2}, i != j
             a) If player1 removes ni elements from ni, heaps = {nj}, a win state for player2
             
             b) If player1 removes s elements from ni (s < ni), player2 can remove k elements from nj. 
                  Because every time player1 must remove >= 1 element, eventually heaps = {1,1}
                  Player1 is forced to remove all elements from ni, heaps = {1}, player2 wins
                  
             Therefore, {n1, n2}, n1^n2 = 0 is a lose state
             
      2.2) n1^n2 != 0, assume n1 < n2, then player1 can remove n2 - n1 elements from n2
             This results in {n1, n1}, a lose state for player2
             Therefore, {n1, n2}, n1 != n2 is a win state
            
#### 3) (induction on k) when k > 2, heaps = {n1, n2, ...,nk}
            Assume m >= 2, and when k = m, if n1^n2^...^nm = 0, heaps is a lose state, else heaps is a win state
            
            When k = m + 1, 
            3.1) n1^n2^...^nk = 0, assume i, j ∈ {1, 2, ..., k}, i != j
                  We know that n1^n2...^ni-1^ni+1^...^nk = ni
                  
                  a) If player1 removes ni elements from ni, heaps = {n1, n2, ..., ni-1, ni+1, ..., nk}
                        n1^n2...^ni-1^ni+1^...^nk = ni != 0, 
                        From induction hypothesis, heaps is now a win state for player2
                        
                  b) If player1 removes s elements from ni(s < ni), heaps = {n1, n2, ..., ni-1, ni', ni+1, ..., nk}
                        note that by flipping bits of nj, 
                        player2 can manipulate the result of n1^n2...^ni-1^ni+1^...^nk to be ni'
                              if nj' = 0, heap = {n1, n2, ..., ni-1, ni', ni+1, ...,nj-1, nj+1, ... nk}
                              ∵ n1^n2...^ni-1^ni+1^...^nj-1^nj+1^...^nk = ni'
                              ∴ n1^n2...^ni-1^ni'^ni+1^...^nj-1^nj+1^...^nk = 0, heap is a lost state for player1
                        Assume player1 repeats this step and nj' != 0 for all cases, 
                        within finite steps, player1 will be forced to remove a 1, 
                        similar to a), heaps is now a win state for player2
                        
                  conclusion: player1 lose
            
            3.2) n1^n2^...^nk != 0, assume i, j ∈ {1, 2, ..., k}, i != j
                  assume ni is the biggest number on heaps, s = n1^n2...^nk-1
                  player1 can remove nk-s elements from nk, 
                  if nk = s, then by induction hypothesis, heap is now a lose state for player2
                  if nk > s, then by 3.1) heap is also a lose state for player2
                  
                  conclusion: player1 win
                              
                        
            
            
      
             
             

        
