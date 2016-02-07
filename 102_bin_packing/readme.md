# Problem #:102     Level: easy

## Descirption: 
We have 3 bins with mixed kinds of bottles in it. The problem is to minimize the number of bottles moved to make  each bin contain same color of glasses. You may assume that the only problem is to minimize the number of movements between boxes.

Each bin has infinite capacity. The total number of bottles will never exceed 2^31.

## Things to take care of:
1) The priority of the "BCG" are decided by character order(e.g. B  has higher priority than C)
2) Be careful about the limit of bottle input (unsigned short is a bad idea)

## My solution: 
Brutal force. I used a string array to store the order of "GBC" strings to avoid having to think about it later. And then looped through each possibility (of bin orders). 

