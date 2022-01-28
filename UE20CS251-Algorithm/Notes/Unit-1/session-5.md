# Session-5 


## Order of growth
Problems are present in complementary sheet.

if lt f(n)/g(n) => 

- 0 -> g(n) grows faster 
- inf -> f(n) grows faster 
- any constant value -> both grow at same rate

stirling formula to represent n! , jusr like your intuition

good problems : 

- n! vs 2^n 
- lon2n vs root(n)
- n^3 vs 2^n

## Analysis of Non Recursive Algorithm 

1) 

```
algo what(a[0..n-1])
sum<-0
for i<-0 to n-1 do     => n iterations , n+1 comparisions 
    sum <- sum+a[i]    => 1 addition -> n additions 
return sum
```

- input size : n
- number of cmparisions : n+1
- number of additions : n
- basic operations : addition 
- complixity : linear -> Theta(n)

2)
```
algo what(a[0..n-1],k)
pos <- -1 
for i<- 0 to n-1 do     ==> done n times, compared n+1 times
    if a[i] = k then    ==> done 1 times
        pos = i
return
```

Note : using breaks are a bad idea, use break only for switch conditions

By Dijkstra : structured programming, a algorithmmust have single entry and
a single exit.

- Retuns right most position of occurence of k 
- input size : n 
- basic operation : comparision of k
- complexity : linear Theta(n)

3)
```
algo what(a[0..n-1][0..n-1])
res <- true
for i<-0 to n-1 do                     => n times iteration 
    for j<- 0 to n-1 do                => n^2 times iteration 
        if a[i][j] != a[j][i] then     => 1 comparision, n^2 times 
            res <- false
return res
```
- The above checsk for symmetric matrix , propertise : 
- input size : order of matrix :- n 
- basic operation : comparision
- only one complexity 
- complexity : Quadractic -> O(n^2)

the above one can be much more efficient : 
```
algo what(a[0..n-1][0..n-1])
res <- true
for i<-0 to n-1 do                     => n times iteration 
    for j<- i+1 to n-1 do                => n^2 times iteration 
        if a[i][j] != a[j][i] then     => 1 comparision, n^2 times 
            res <- false
return res
```
one complexity 
summation : Theta(n^2)

how : 

![picture](./5_1.png)


it can still be better : 
```
res <- true 
i <- 0 
while res and (i<n) do 
    j <- i+1 
    while res and (j<n) do 
        res <- a[i][j] == a[j][i]
        j <- j+1
    i <- i+1 
return res
```

basic op : comparision 
diff complexity
best case : 1 
worst case : n^2 



