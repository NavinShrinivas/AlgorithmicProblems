#include "header.h"
#include <limits.h>

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
            if(connections[src][i].distance!= INT_MAX && connections[src][i].time!= INT_MAX && i!=src){
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
    /*
     *else if(src > n-1 || src < 0){ //Doing this cus i was getting seg faults
     *    return 0;
     *}
     */
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

//Shhhhhh...xD
static int self_strcmp(const char *a, const char *b)
{
    while (*a!='\0' && *a == *b){
        a++; b++; 
    }
    return (int)(*a) - (int)(*b);
}
static int self_strlen(const char* s){
    int i=0;
    while(s[i]!='\0'){
        i++;
    }
    return i;
}


static int alphabetical_predicate(const airport_t *x, const airport_t *y)
{
    return self_strcmp(x->airport_name, y->airport_name) < 0;
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

static void bad_shift_calculator(const char* pat,int* bad_shift_table){
    int i=0;
    int m = self_strlen(pat);
    while(i<m-1){ //have to omit last char
        bad_shift_table[(int)pat[i]] = m-i-1;
        i++;
    }
}

static int horsepool_check(int* bad_shift_table,const char* pat,const char* str){
    int m = self_strlen(pat);
    int n=self_strlen(str);
    int i=0;
    int found = 0;
    while(!found && i<n-m){
        int temp_i = i+m-1; //check from right side 
        int j=m-1;
        while(str[temp_i] == pat[j] && j>=0){
            j--;
            temp_i--;
        }
        if(j == -1){//found pat in str 
            found = 1;
        }else{//shift 
            i+=bad_shift_table[(int)str[temp_i]];
        }
    }
    return found;

}

static void edges_append(int n,pair_t edges[n-1],int src,int dest){
    for(int i=0;i<n-1;i++){
        if(edges[i].first == -1){
            edges[i].first = src;
            edges[i].second = dest;
            return;
        }
    }
}


static void prims_MST_finder(int n,const connection_t connections[n][n],connection_t path_conn[n][n],int src,int visited[n],int* visited_so_far,pair_t edges[n-1]){
    if(*visited_so_far == n-1){
        return;
    }
    else{
        (*visited_so_far)++;
        visited[src] = 1;
        int least_dest = INT_MAX;
        int least_dist = INT_MAX;
        int least_src = INT_MAX;
        for(int j=0;j<n;j++){
            for(int i=0;i<n;i++){ //finding least time unvisited node 
                if(( visited[i]!=1 && visited[j]==1) && (least_dist>connections[j][i].time && i!=j)){
                    least_dest = i;
                    least_src = j;
                    least_dist = connections[j][i].time;
                }
            }
        }
        path_conn[least_src][least_dest].time=connections[least_src][least_dest].time;
        path_conn[least_src][least_dest].distance=connections[least_src][least_dest].distance;
        edges_append(n,edges,least_src,least_dest);
        prims_MST_finder(n,connections,path_conn,least_dest,visited,visited_so_far,edges);
    }
}


static void dijk_greedy(int n,int src,int distances[n],int visited[n],int* visited_so_far,const connection_t connections[n][n]){
    if(*visited_so_far == n)
        return;
    else{
        int temp = *visited_so_far;
        *visited_so_far=temp+1;
        visited[src] = 1;
        int min_node = 0;
        int min_node_dist = INT_MAX;
        for(int i=0;i<n;i++){
            if(connections[src][i].time != INT_MAX && src!=i)
            {   
                int current_distance_to_prev_node = distances[src];
                int current_distance_to_current_node = distances[i];
                if(current_distance_to_prev_node+connections[src][i].time < current_distance_to_current_node)
                    distances[i] = current_distance_to_prev_node+connections[src][i].time; 
                if(min_node_dist > distances[i]){
                    min_node = i;
                    min_node_dist = distances[i];
                }
            }
        }
        dijk_greedy(n,min_node,distances,visited,visited_so_far,connections);
        return;
    }
}

static void append_route(int n,int routes[n-1],int k){
    for(int i=0;i<n-1;i++){
        if(routes[i] == -1)
        {
            routes[i] = k;
            return;
        }
    }
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
            if(connections[i][j].distance == INT_MAX || connections[i][j].time == __INT_MAX__){
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
    if(ans > n)
        ans --; //cus my logic for while loop give one extra when whole array is possible
    return ans;
}

void q7(int n, const char *pat, int contains[n], const airport_t airports[n])
{
    //Consider length of pat to be m 
    //My preprocessing stage runs in O(n)
    //As hashmaps (key-value) pairs do no exist in C im using ascii indexed key value pairs
    int m = self_strlen(pat);
    int bad_shift_table[123]={m}; //lets consider all shifts to be m before calc
    //122 is the last ascii value for alphabets, can also handle space of ascii 32
    for(int i=0;i<123;i++)
        bad_shift_table[i] = m;

    bad_shift_calculator(pat,bad_shift_table);
    for(int i=0;i<n;i++){
        int res = horsepool_check(bad_shift_table,pat,airports[i].airport_name);
        if(res == 1){
            contains[airports[i].num_id] = 1;
        }
    }

}


int q8(int n, int trip_order[n - 1], const connection_t connections[n][n])
{
    //Q8 turned out be challenging, yet i found a loopy way : 
    //Create new connectiosn with all possible avoidable nodes 
    //Using this new connections graph create an MST out of it 
    //Find weight of this MST and we are goodg

    //Creating new connections (all possible avoidances) using for loop : 
    int dist = INT_MAX;
    for(int i=0;i<n;i++){
        int temp_dist = 0;
        //say we are avoding 1, we need to avoid all connections from i and to i 
        connection_t avoid_connections[n-1][n-1];
        for(int j=0;j<n;j++){
            for(int k=0;k<n;k++){
                if(j != i && k!=i){
                    //copy to current node 
                    if(j>i && k>i)
                        avoid_connections [j-1][k-1] = connections[j][k];
                    else if(j>i)
                        avoid_connections[j-1][k] = connections[j][k];
                    else if (k>i)
                        avoid_connections[j][k-1] = connections[j][k];
                    else 
                        avoid_connections[j][k] = connections[j][k];

                }else{
                    //do not copy to new graph 
                    connection_t temp;
                    temp.distance = INT_MAX;
                    temp.time = INT_MAX;
                    avoid_connections[j][k] = temp;
                }
            }
        }
        //After creating new set of connections, need to find MST of this new connection graph
        int visited[n-1];
        for(int j=0;j<n-1;j++)
            visited[j] = 0;
        int visited_so_far = 0;
        connection_t path_conn[n-1][n-1];
        for(int i=0;i<n-1;i++){
            for(int j=0;j<n-1;j++){
                connection_t temp; 
                temp.time = 999999;
                temp.distance = 999999;
                path_conn[i][j] = temp;
            }
        }
        pair_t edges[n-1];
        prims_MST_finder(n-1,avoid_connections,path_conn,0,visited,&visited_so_far,edges);

        //mst with 2 rows of no outgoing connections can not form a cycle 
        int count = 0;int row = 0;
        for(int j=0;j<n-1;j++){
            int present = 0;
            for(int k=0;k<n-1;k++){
                if(path_conn[j][k].distance != 999999)
                {
                    temp_dist+=path_conn[j][k].distance;
                    present ++;
                }
            }
            if(present == 0)
            {
                count++;
                row = j;
            }
        }
        //If only 3 nodes and 1 avoided and MST has only 1 node then simply quit
        if(n == 3 && count == 1){
            return -1;
        }

        for(int j=0;j<n-1;j++){
            for(int k=0;k<n-1;k++){
                if(path_conn[j][k].distance != 999999){
                    if(k>=i)
                        append_route(n,trip_order,k+1);
                    else
                        append_route(n,trip_order,k);
                }
            }
        }
        if(count < 2){
            temp_dist +=  avoid_connections[row][0].distance;
            path_conn[row][0].distance = avoid_connections[row][0].distance;
            append_route(n,trip_order,1);

        }
        if(temp_dist < dist)
        {
            dist = temp_dist;

        }
    }
    return dist;
}

int q9(int n, pair_t edges[n - 1], const connection_t connections[n][n])
{ 
    int visited[n];
    for(int j=0;j<n;j++)
        visited[j] = 0;
    int visited_so_far = 0;
    connection_t path_conn[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            connection_t temp; 
            temp.time = 999999;
            temp.distance = 999999;
            path_conn[i][i] = temp;
        }
    }
    prims_MST_finder(n,connections,path_conn,0,visited,&visited_so_far,edges);
    int distance =0;
    for(int i=0;i<n-1;i++){
        distance+=connections[edges[i].first][edges[i].second].time;
    }
    return distance;
}
void q10(int n, int k, const airport_t *src,
        const connection_t connections[n][n], const int destinations[k],
        int costs[k])
{
    int distances[n];
    for(int i=0;i<n;i++)
        distances[i] = INT_MAX;
    distances[src->num_id] = 0;
    int visited[n];
    for(int i=0;i<n;i++)
        visited[i] = 0;
    int visited_so_far = 0;
    dijk_greedy(n,src->num_id,distances,visited,&visited_so_far,connections);
    for(int i=0;i<k;i++){
        costs[i] = distances[destinations[i]];
    }
}
// END
