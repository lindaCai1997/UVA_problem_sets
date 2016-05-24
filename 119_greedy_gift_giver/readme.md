# Problem #:110     Level: easy

## Description: 

Given a group of friends, calculate the money each person in the group spends on gifts, and a (sub)list of friends to whom each person gives gifts. You are to write a program that determines how much more (or less) each person in the group gives than they receive.

## Things to be careful about:
1) After the last set of input, don't print an additional line

2) When the amount of money someone give is not divisible by  # of people,  the  remainder still belongs to the originial owner

3) Someone might not give money to anyone 

4) Must clear the data structure used after each set of data


## My solution: 
I used 2 maps to store how much everyone gives and takes and an array to store names.

At the beginning of each set of data I initialized hen I looped through each person's line to modify eople's give and take value.

After each data set I cleared both maps.
