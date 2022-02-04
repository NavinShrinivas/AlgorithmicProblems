# Session-08

Yeah let's hope that sir doesn't rage quit today as well.

## More analysis of recursive algorithms 


1)

```
   T(n) = 3T(n-1) n>0 
        = 1 n = 0 
```

```
   T(n) = 3T(n-1) 
        = 3(3T(n-2))
        = 3^2 T(n-2)
        ..
        ith term 
        = 3^i T(n-i)
        .. i=n 
        = 3^n T(n-n)
        = 3^n * 1 
        = 3^n (Exponential) | Theta(3^n)
```

2)
```
   if n = 1 => 1
   else => Q(n) = Q(n-1) + 2n -1 
```
```
   Q(n) = [ Q(n-2) + 2(n-1) -1 ] + 2n -1 
        = Q(n-2) + 2n -1 -2 + 2n 
        = Q(n-2) + 4n - 4 
        = Q(n-3) + 6n - 
        ..
        = Q(n-i) + 2*i*n - i^2
        .. i = n-1
        Q(1) + 2*(n-1)*n - (n-1)^2 
        = … n^2 
        Q(n) = n^2 , this question is tricky one and 
        can't be decided just by looking at the question
```
   - Basic Operation : multiplication 
   - Number of operations : 
   - ```
     T(1) => 0 multiplication 
     T(n) => 1 + T(n-1) multiplication
          => i + T(n-i) .. i=n-1 
          => n-1 + T(1)
          => n-1 
     ```
3)
Gate paper : 
```
   T(n) = 2T(n-1) - 1
   T(0) = 1 
```
```
   T(n) = 2T(n-1) - 1
        = 2[2T(n-2) - 1] - 1
        = 2^2T(n-2) - 2 - 1 
        = 2^2 [2T(n-3) - 1] - 2 - 1 
        = 2^3 T(n-3) - 4 - 2 - 1 
        .. 
        = 2^i T(n-i) - (1+2+4...+(i-1)) 
        .. i - n 
        = 2^n T(n-n) - (1+2+4...n)
        = 2^n - 2^n = 1 
```

2)
find sum of cubes of n terms 
```c
algo sum(n)
  if n == 0 
    return 0 
  else 
    return sum(n-1) + n*n*n
```
- Basic Operation : Multiplication 
- Recurrence : 
```
   M(n) = 0 if 0 
        = 2 + M(n-1)
```
```
   M(n) = 2 + M(n-1)
        = 2 + (M(n-2) + 2)
        = M(n-2) + 4 
        = M(n-3) + 6
        .. i 
        = M(n-i) + 2*i
        .. i = n
        = M(n-n) + 2*n 
        = 2*n
```

## Sequential search using recurrence

Say you wanna find minimum in an array 
Comparison :  n - 1, 
let's compare the first and the last elements of 
the array on each step, let's maintain a window 

```
algo min(a[l..r])
  if l == r then
    return a[l]
  else if a[l] < a[r] then 
    return min(a[l..r-1])
  else
    return min(a[l+1 .. r])
```
- Basic operation : key comparison 
- C(1) = 0 
- C(n) = 1 + C(n-1)
- solving recursion : 
```
   C(n) = 1 + C(n-1)
        = 1 + [1 + C(n-2)]
        = 2 + C(n-2)
        ..
        = i + C(n-i)
        .. i = n - 1
        = n-1 + C(n - n + 1)
        = n -1 + C(1)
        =  n - 1      => O(n) | linear time
```
any other recursive solutions for the same?
Check text book page 104 [literal pdf] and do it's 
analysis.

The same can be done using a divide and conquer
algorithm.

```
algo from : 
question 9 in page 104
```

- Basic  operation : key comp 
- recurrence : 
```
  C(1) = 0 
  C(n) = 2C(n/2) + 1 
       = 2[2C(n/2^2) + 1] +1
       = 2^2C(n/2^2) + 2 + 1 
       = 2^2[2C(n/2^3) + 1] + 2 + 1
       = 2^3 C(n/2^3) + 4 + 2 +1 
       .. i 
       = 2^i C(n/2^i) + 1 + 2 + 4 + … i-1 terms 
       let i = k  and 2^i = n => k=log n 
       = 2^k C(n/2^k) + 1 +2 +4 + … log(n-1)
       = nC(1) + 2^log(n-1,2)
       = 0 + n-1 = > n - 1 
```

## Some other problems : 

```
for i<- 1 to n/2
  <Something>

Theta(n)
```
```
for i<- 1 to n/2
  for i<- 1 to n 
    <Something>

Theta(n^2
# of operations : n^2/2
```
```
for i<- 1 to n/2 
  for j<- 1 to i 
    <Something>
Theta(n/2)
# of operations : 1 + 2+ 3 … n/2 terms : n(n+1)/2 
=> n/2((n/2)+1)/2
```

```
i<-0
while i<=n 
  i<-i*2
  <Something>

Theta : O(log(n,2))
```

```
i <- 1
while i<= n 
  i<-i*2
  j<-i
  while j<=n 
    j<-j*2 
    <Something> 

Theta((log n)^2)
```

Try looking into more asymptotic analysis problems

---End of Session-8---
