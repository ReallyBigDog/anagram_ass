# Creating new anagrams
## Using hash tables to implement dictionaries

An <em>anagram</em> is a word formed by rearranging the letters of a different word, using all the original letters exactly once. In this assignment you are given a file with 1000 most common English words, and you need to uncover all the anagrams in this file.

The starter code includes the basic implementation of a map abstract data type, where the key is of type string, and the value is a list of strings. Use this data structure and some ideas discussed in class to find all the anagrams in expected time O(n): by scanning the input file only once and then by iterating over the entire dictionary only once.

The first task is to implement a polynomial hashing for strings - in file `dictionary.c`. After that the dictionary is ready to be used for your anagram discovery algorithm.

Your program should print all the words that are anagrams of each other on a separate line, and it should also print the total number of such anagram lists.
