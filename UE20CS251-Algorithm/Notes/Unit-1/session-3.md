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
//bad program : "The programming style by Kernighan and Plaughher"
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


