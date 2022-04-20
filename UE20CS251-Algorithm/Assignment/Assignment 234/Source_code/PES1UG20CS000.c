#include "header.h"
#include <limits.h>
#include <stdio.h>
#include<string.h>

// ANY STATIC FUNCTIONS ARE UP HERE

static int recurse_jump_find(int n,int visited[n],const connection_t connections[n][n], int src,int dest,int jumps){
    //the visited array is to avoid visting and looping paths, kinda like the concept of dynamic programming
    visited[src] = 1;
    if(src == dest)
        return jumps;
    else if(src > n-1 || src < 0){
        return INT_MAX;
    }
    else{
        for(int i=0;i<n;i++){
            if(connections[src][i].distance!=INT_MAX && connections[src][i].time!=INT_MAX && i!=src){
                if(visited[i]!=1){
                    int inter_jump = recurse_jump_find(n,visited,connections,i,dest,jumps+1);
                    if(inter_jump<jumps)
                        jumps=inter_jump;
                }
            }
        }
    }
    return jumps;
}


static int recurse_loop_find(int n,const connection_t connections[n][n], int src,int dest){
    int ret = 0;
    if(src == dest)
        return 1;
    else if(src > n-1 || src < 0){
        return 0;
    }
    else{
        for(int i=0;i<n;i++){
            if(connections[src][i].distance!=INT_MAX && connections[src][i].time!=INT_MAX && i!=src){
                int ret_reach = recurse_loop_find(n,connections,i,dest);
                if(ret_reach == 1)
                    ret = 1;
            }
        }
    }
    return ret;
}

static void swap(int n,airport_t airport_list[n],int i,int j){
    airport_t temp = airport_list[i];
    airport_list[i] = airport_list[j];
    airport_list[j] = temp;
}

static int hoare_partition(int n,airport_t airport_list[n],int (*predicate_func)(const airport_t *, const airport_t *),int l, int r){ 
    airport_t pivot = airport_list[l];
    int i=l-1;
    int j=r+1;
    while(1){
        do{
            i++;

        }while(predicate_func(&airport_list[i],&pivot));
        do {
            j--;
        } while (predicate_func(&pivot,&airport_list[j]));
        if(i>=j)
            return j;
        swap(n,airport_list,i,j);
    }
}


static void quick_sort(int n,airport_t airport_list[n],int (*predicate_func)(const airport_t *, const airport_t * ),int l,int r)
{
    if(l>=r){
        return;     
    }
    int part_index = hoare_partition(n,airport_list,predicate_func,l,r);
    quick_sort(n,airport_list,predicate_func,l,part_index);
    quick_sort(n,airport_list,predicate_func,part_index+1,r);
}


static int alphabetical_predicate(const airport_t *x, const airport_t *y)
{
    return strcmp(x->airport_name, y->airport_name) < 0;
}

static int prefix_length_finder(const char* s1,const char* s2){
    int ans = 0;
    int i=0,j=0;
    int done = 0;
    while(!done && (s1[i]!='\0' || s2[j]!='\0')){
        if(s1[i] == s2[j]){
            i++;
            j++;
            ans++;
        }else{
            done = 1;
        }
    }
    return ans;
}

// YOUR SOLUTIONS BELOW

int q1(int n, const connection_t connections[n][n])
{
    //The question states that every airport should be acessible from every other 
    //Meaning even if one edge has INT_MAX, we can return 0 
    //If none of the edges are "not servicible", we can return 1 
    int is_true = 1;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            //INT_MAX is imported as part of limits.h in main file. 
            if(connections[i][j].distance == INT_MAX || connections[i][j].time == INT_MAX){
                is_true = 0;
            }
        }
    }
    return is_true;
}

int q2(const airport_t *src, const airport_t *dest, int n, int k,
        const connection_t connections[n][n])
{
    int visited[999999]={0}; //Considering 999999 to be large enuf and max number of airports
    int ans_k = recurse_jump_find(n,visited,connections,src->num_id,dest->num_id,0);
    int ans;
    if(ans_k < k)
        ans = 1;
    else 
        ans = 0;
    return ans;
}

int q3(const airport_t *src, int n, const connection_t connections[n][n])
{

    //Using same logic as q2 but allowing loops.
    return recurse_loop_find(n,connections,src->num_id,src->num_id);
}

void q4(int n, int (*predicate_func)(const airport_t *, const airport_t *),
        airport_t airport_list[n])
{
    //Using quick sort for nlogn complexity and inplace
    quick_sort(n,airport_list,predicate_func,0,n-1);
}

pair_t q5(int n, airport_t airports[n])
{
    pair_t ans = {-1, -1};
    //My solution : I plan on sorting all the airports based on name (nlogn) and if we want to find the longest prefixes, they have to be near by.
    //Often times we see longest commong prefix across all elements in the array making out complexity to O(MAX*nlogn)
    //But here we need to select 2, and the two have to be near by, hence complexity of O(nlogn)+O(n+1)
    quick_sort(n,airports,alphabetical_predicate,0,n-1);
    int f_res = 0;
    for(int i=0;i<n-1;i++){
        int res = prefix_length_finder(airports[i].airport_name,airports[i+1].airport_name);
        if(res!=0 && res > f_res ){
            f_res = res;
            ans.first = airports[i].num_id;
            ans.second = airports[i+1].num_id;
        }
    }
    return ans;
}

int q6(int n, int amount, const int entry_fee[n])
{
    //This question seems suspisously easy :eyes:
    //Any whooo, the only "Non brute force" i see is to quit the loop once the values become higher, cus wwe are given an sorted arrray 
    int ans = 0;
    while(entry_fee[ans]<=amount){
        ans++;
    }
    return ans;
}

void q7(int n, const char *pat, int contains[n], const airport_t airports[n])
{

}

int q8(int n, int trip_order[n - 1], const connection_t connections[n][n])
{
    return 0;
}

int q9(int n, pair_t edges[n - 1], const connection_t connections[n][n])
{
    return 0;
}

void q10(int n, int k, const airport_t *src,
        const connection_t connections[n][n], const int destinations[k],
        int costs[k])
{

}

// END
