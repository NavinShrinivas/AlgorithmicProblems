# Session-5 : All about recursion 

## a new way of definfning data structures : 

- list : node followed by a list, or a empty list.
- tree : node followed by n number of trees or a empty tree.
- binary tree : node followed by atmost 2 trees or a empty tree.

If the data sctruture is defined by recursion, a recursive function makes
it far easier than iterative.

> Tail recursion optimisation.


## About recursion : 

All recursion have an activation record, a stack space

so what does an activation record contain : 
- parameters 
- local variable 
- temporary varaibles
- return address [To go back]
- return location (Temporary)

```
int what(int n){
    if(n == 0){
        return 0;
    }else if(n % 2){
        return 1 + what(n%2);
    }else{
        return what(n/2);
    }
}

what(25);
```
The above function calculates the number of bits that are set to one in 
binary
Assignment : tower of Hanoi stack frame send it to him

## Program : sum of all elements in a array using recursion 

```c
int sumofarr(int *a, int i, int n) {
  if (i == n)
    return 0;
  else {
    return a[i] + sumofarr(a, i + 1, n);
  }
}
```

Evaluvation : a+b*c 
- Eval of operands : fetching of opearnds to the register of the CPU
- Order of eval : precendence 
a+b+c : left->right postfix==> ab+c+
a=b=c : left->right postfix==> abc==

int a=10;
int b;
b = a * a++; //can be 11 * 10 or 10 * 10, this depends on compiler options

for more explaination look into sequence point, this leads us to the example 
below

```
int sumofarr(int *a, int i, int n) {
  if (i == n)
    return 0;
  else {
    return a[i] + sumofarr(a, ++i, n);
    //return a[i] + sumofarr(a, i++ , n); //also wrong
  }
}
```

hece this may work, but IT IS WRONG

Write program with recusion for : 
- string length
- string compare
- string copy
- A list implementation
    init list
    insert node
    disp list, recursive
    find number of nodes in the list , recursive
    copy the list, recursive 
    reverse a given list, recursive

//all the above mentioned programs have been coded
//ok so i saw this new coding style and naming variables in his coding,
imma follow that from today
