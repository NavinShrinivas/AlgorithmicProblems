# Session-3 : Lab

what does this function in C do?

```c
// a: matrix [1 .. n][1 .. n]
void what(int n, int a[n + 1][n + 1])
{
	for(int i = 1; i <= n; ++i)
	{
		for(int j = 1; j <= n; ++j)
		{
			a[i][j] = (i/j) * (j/i);
		}
	}
}
//all elements with one : LMAO, this answer is wrong
//instead its 0 in every non diagonal posistion, why? C aproximates to 0 if float is the result
//and all diagonals are one, hence it generates a identity matrix.
//bad program : "The programming style by Kernighan and Plaughher", bad cus it depdends on a rather
//weird behaviour of the C language.
// "The C programming Language" : Kernighan and Ritchie
```

instead : 
```c
// a: matrix [1 .. n][1 .. n]
void what(int n, int a[n + 1][n + 1])
{
	for(int i = 1; i <= n; ++i)
	{
        if(i==j)
            a[i][j]=1
        else
            a[i][j]=0;
	}
}
//# of comparision : n^2
//# of assigments : n^2
```
another : 
```
// a: matrix [1 .. n][1 .. n]
void what(int n, int a[n + 1][n + 1])
{
	for(int i = 1; i <= n; ++i)
	{
        a[i][j]=0;
	}
    a[i][i]=1;
}
//# of comparision : 0
//# of comparision : n^2+n
//inheritly better, by Kernighan
```

After this we moved onto timing and matrix program, which have been written and implemented in the
parent directory.


## lab progs :

- Timing problem
- Matrix stuff : 
b) time the program
c) create a matrix : populate with random values
d) matrix addition : n X n
   time the program 
   n = 32
   n = 64
   n = 128
   n = 256
   n = 512
e) matrix multiplication
	fill a
	fill b
	init C to 0
	time this 
	mult a b giving c
f) looping order :
	can we change the looping order?
    Yes, indeed it works.
	i j k
	i k j
	j i k
	j k i
	k i j
	k j i
	if these work, would all take same amount of time? Why?
    NO, the amount of operations and iterations is the same no matter the order, n^3 hence they 
    all take same amount of time.
g) multiple identity matrix
   check the result programmatically
   
   


