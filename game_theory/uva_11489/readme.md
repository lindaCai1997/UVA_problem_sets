# Cheat sheet:
## 1. If N only has one digit, S wins

## 2. S might not be able to make the first move(e.g. 58), in this case, S loses

## 3. When S can make first move, observe after first move all subsequent number N' % 3 = 0. 

    Assume total # of 3/6/9s in N is THREES, then 
    
    a. if N % 3 = 0, S wins when THREES is odd, T wins otherwise
    
    b. if N % 3 != 0, S wins when THREES is even, T wins otherwise
