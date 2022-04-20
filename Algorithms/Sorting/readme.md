## Before sorting algorithms : 
An algorithm can be made faster by a few methods :
- Input enhancement : [counting, string match]
- Structuring : [hashmaps, btree]
- DP : Dynamic programming

First we shall look into few o(n^2) algorithms: 
- Bubble sort 
- Improved bubble sort 
- Insertion sort 

and few O(nlogn) algorithms are : 
- Merge sort 
- Quick sort 

So what is this counting sort then? More like a cheat type sorting algorithm: 
Why is it cheating? cus n^2 applies only if one is comparing key values, count sorts dont! 

## Counting sort 

There are two ways to make this happen : 
- Counting by comparision : Make a count table of number of elements less than a given element, at the end of this process we have the needed indexes for these elements.O(n^2) 
- Book-keeping / counting sort : this algorithm is better implemented using a haspmap, the index of the new "array" reps the element, the value of this index shows the frequency of this element. Sorts elements in O(n) time!!!

The second one however needs to know the "domain" of elements to be sorted. The second count sorting is very efficient, but isnt used as much cus if the domain of elements is very large we are required to maintain huge counting arrays leading to space wastage.
