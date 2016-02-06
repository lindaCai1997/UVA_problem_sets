# Problem #:UVA Problem Set Volume1 102
# Level: easy

#Descirption: 
Recycling glass requires that the glass be separated by color into one of three categories: brown glass, green glass, and clear glass. In this problem you will be given three recycling bins, each containing a specified number of brown, green and clear bottles. In order to be recycled, the bottles will need to be moved so that each bin contains bottles of only one color.

The problem is to minimize the number of bottles that are moved. You may assume that the only problem is to minimize the number of movements between boxes.

For the purposes of this problem, each bin has infinite capacity and the only constraint is moving the bottles so that each bin contains bottles of a single color. The total number of bottles will never exceed 2^31.

# My solution: 
Brutal force. I used a string array to store the order of "GBC" strings to avoid having to think about it later. And then looped through each possibility (of bin orders). 

