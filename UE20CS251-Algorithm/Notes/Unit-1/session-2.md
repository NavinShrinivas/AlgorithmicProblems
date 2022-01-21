# Session-2 

## Different step sin solving a problem

- Analyse the problem domain
- Check resources  :Computational, data, time, memory. An exact/Approximate method

> The Elurian problem : (the bridge problem)[https://mathworld.wolfram.com/KoenigsbergBridgeProblem.html#:~:text=The%20K%C3%B6nigsberg%20bridge%20problem%20asks,that%20the%20trip%20ends%20in]
> Solution : Even number of edges for each node, i.e the degree must be even.
> 
> Hamiltoniain problem : visit each node once and come back to the starting node without repeating
the vertex.
> Soltuion : number of edges = number of nodes.But computationally, it's hard to 
> 
> Travelling slesman : Optimization problem, an approximation would be to be greedy.

- develop the algorithm
- prove the algorithm : DAFNY
- Implment
- Testing


As for this course, we analyze algorthim, but what are the parameters for analysis? :

- Time
- Space
- Redability - simple, easy to undestand.
- Flexibility or generality.


 Generic programming elective, A book for stl libraries .

 > One more puzzel : There are 4 pepople. There is a bridge,It is dark and you have a single torch
 > at most 2 can walk at a time.
 > 1 takes 10 mins, another ones takes 5,2,1. Minimum amount of time for every one to corss the 
 > bridge?
 > Solution : 17 mins

## Sorting and searching: 
- Arraging th elements in a particular order
- examples [Commong alogrithm]:
    insertion sort
    bubble sort
    selection sort
- how is is sorted?
    ascending
    descending
    user specified
- Types that can be sorted : 
    Numeric
    String
    Fields
- Why sorting?
    It can help with seraching : Binary search [log2n]

> What should a search return?
> Solution :
>   on a array : true or false, NEVER PRINT FROM FN, -1 if not found else returnindex
>   on a linked list : we could return a reference to node.
>   But that a big mistake, this could give the client a chance to change the implmentation.
>   hence one should return an opaque object [Iterator].
>   
>
> Find middle of a singly linked list , this also explains why no binary search on list:
> Solution : hare and tortoise solution, 1 pointer goes ahead 1 step, the other goes ahead by 2.

- sorting concepts : 
     pre sorting
     min cost spannig tree
     topological sort
     travelling salesman problem
     knn : k nearest neighbours
     Knuth : sorting and searching


## Strings
Used in :
    what is the input to the compiler? program is a sequence of char
    regex
    string matching

## Graph
- coloring graphs :
    4 color conjecture

## Assumption in analysis : 
Von Neumann architechture
- single CPU
- linear memory
- every operation takes about the same time

## measurement 

array : # of elements 
matrix : # of rows and cols
string : # of char 
int : # of the bit for the value

