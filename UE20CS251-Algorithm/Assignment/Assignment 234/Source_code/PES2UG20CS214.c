#include "header.h"
#include <limits.h>
#include <stdlib.h>
#include<stdio.h>

// The Static Functions are the following


static int func8_a(int n,int selected[n])
{
    int i,count=0;
    for(i=0;i<n;i++)
    {
        if(selected[i]==1)
            count++;
    }
    return count;
}

static void func8_b(int n, int trip_order[n - 1], int temp[n-1],const connection_t connections[n][n], int selected[n],int *cost,int src, int src_temp, int index,int *min)
{
    int i;
    int value;
    selected[src] = 1;


    for(i=0;i<n;i++)
    {
        if(func8_a(n,selected) == n-1)
        {
            int temp_value = connections[src][src_temp].distance;
            if(temp_value != INT_MAX)
            {
                temp[index] = src;
                *cost += temp_value;

                if(*cost <= *min)
                {
                    *min = *cost;
                    for(int j=0;j<n-1;j++){
                        trip_order[j] = temp[j];
                    }


                }                
            }
            else
                temp_value = 0;

            *cost-= temp_value;
            i = n;

        }

        else if(connections[src][i].distance !=0 && connections[src][i].distance != INT_MAX && selected[i]==0) 
        {
            value = connections[src][i].distance;
            temp[index++] = src;    
            *cost+=value;     
            func8_b(n,trip_order,temp,connections,selected, cost,i,src_temp, index, min);
            *cost -= value;
            index--;
        }

    }

    selected[src] = 0;

}

static int func9(int n, const connection_t connections[n][n], pair_t edges[n-1] )
{
    int i,j, u,v, min_time=0, min, selected[n], ne=0;

    for(i=0;i<n;i++)
        selected[i] = 0;

    selected[0] = 1;
    while(ne < n-1)
    {   

        min = INT_MAX;
        for (i=0;i<n;i++)
        {

            if(selected[i])
            {
                for (j=0;j<n;j++)
                {
                    if(!selected[j] && connections[i][j].time != 0 && connections[i][j].time != INT_MAX)
                    {
                        if (min > connections[i][j].time) 
                        {
                            min = connections[i][j].time;
                            u =  i;
                            v = j;
                        }
                    }
                }
            }
        }

        edges[ne].first = u;
        edges[ne].second = v;
        selected[v] = 1;
        min_time+=min;
        ne++;

    }
    return min_time;
}

static int min(int num1, int num2) 
{
    return (num1 > num2 ) ? num2 : num1;
}

static void q1_dfs (int x , int vis[] , int n , const connection_t graph[n][n])
{
    vis[x] = 1;
    for(int r = x ; r < n ; r++)
    {
        for(int j = 0 ; j < n ; j++)
        {
            if (graph[r][j].distance != __INT_MAX__ && vis[j]!= 1)
            {
                q1_dfs(j , vis , n , graph);
            }
        }
    }
}

static int check(int vis[] , int n)
{

    for (int m = 0 ; m < n ; m++)
    {
        if (vis[m] != 1)
        {
            return 0;
        }
        vis[m] = 0;
    }
    return 1;
}

static void q2_dfs (int x , int vis[] , int n , const connection_t graph[n][n] , int dest , int num , int *ans)
{
    vis[x] = 1;
    if (x == dest)
    {

        int flag = 0;
        for (int i  = 0 ; i < n ; i++)
        {
            if (vis[i] == 1)
            {
                flag ++;
            }
        }
        if (flag <= num+1)
        {
            *ans = 1;
        }
    }
    for(int i = x ; i < n ; i++)
    {
        for(int j = 0 ; j < n ; j++)
        {
            if (graph[i][j].distance != __INT_MAX__ && vis[j]!= 1)
            {
                q2_dfs(j , vis , n , graph , dest , num , ans);
            }
        }
    }

}

static void q3_dfs (int x , int vis[] , int n , const connection_t matrix[n][n] , int s , int *ans)
{
    vis[x] = 1;
    for(int i = x ; i < n ; i++)
    {
        for(int j = 0 ; j < n ; j++)
        {
            if (matrix[i][j].distance != __INT_MAX__ && j == s)
            {
                *ans = 1;
            }
            if (matrix[i][j].distance != __INT_MAX__ && vis[j]!= 1)
            {
                q3_dfs(j , vis , n , matrix , s , ans);
            } 
        }
    }
}

static void swap(airport_t *a, airport_t *b)
{
    airport_t t = *a;
    *a = *b;
    *b = t;
}

static int partition(airport_t arr[], int start, int end,int (*predicate_func)(const airport_t *, const airport_t *))
{
    int pIndex = start;
    airport_t pivot = arr[end];
    int i;
    for(i = start; i < end; i++)
    {
        if(predicate_func(&arr[i] , &pivot))
        {
            swap(&arr[i], &arr[pIndex]);
            pIndex++;
        }
    }
    swap(&arr[end], &arr[pIndex]);
    return pIndex;
}

static void quickSort(airport_t arr[], int start, int end,int (*predicate_func)(const airport_t *, const airport_t *) )
{
    if(start < end)
    {
        int qIndex = partition(arr, start, end,predicate_func);
        quickSort(arr, start, qIndex-1,predicate_func);
        quickSort(arr, qIndex+1, end,predicate_func);
    }
}

static int len(airport_t airport1,airport_t airport2)
{
    int h=0;
    while(airport1.airport_name[h]!='\0' && airport2.airport_name[h]!='\0' && airport1.airport_name[h] == airport2.airport_name[h])
    {
        h++;
    }
    return h;
}

static void shifttable(const char p[],int t[])
{
    int i,j,m=0;
    for(int x = 0 ; p[x] != '\0';x++)
        m++;
    for(i=0;i<500;i++)
        t[i]=m;
    for(j=0;j<m-1;j++)
        t[p[j]-'0']=m-1-j;
}

static int horspool(const char src[],const char p[],int t[])
{
    int i,k,m=0,n=0;
    for(int x = 0 ; p[x] != '\0';x++)
        m++;
    for(int x = 0 ; src[x] != '\0';x++)
        n++;
    i=m-1;
    while(i<n)
    {
        k=0;
        while((k<m)&&(p[m-1-k]==src[i-k]))
            k++;
        if(k==m)
            return(i-m+1);
        else
            i+=t[src[i]-'0'];
    }
    return -1;
}

static int minKey(int V,int key[], int mstSet[])
{

    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++)
        if (mstSet[v] == 0 && key[v] < min)
            min = key[v], min_index = v;

    return min_index;
}

static void makeMST(int V,int parent[], const connection_t graph[V][V],pair_t edges[V - 1])
{
    for (int i = 1; i < V; i++)
    {    
        edges[i-1].first = parent[i];
        edges[i-1].second = i;
    }
}

static int minitime(int n,pair_t edges[],const connection_t graph[n][n],int parent[])
{
    int res = 0;
    for(int i=0;i<n-1;i++)
        res = res + graph[edges[i].first][edges[i].second].time;
    return res;
}

static void Dijkstra(int n,const connection_t Graph[n][n], int start,int *hash) {
    int cost[n][n], distance[n], pred[n];
    int visited[n], count, mindistance, nextnode, i, j;

    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            if (Graph[i][j].time == 0)
                cost[i][j] = INT_MAX;
            else
                cost[i][j] = Graph[i][j].time;

    for (i = 0; i < n; i++) {
        distance[i] = cost[start][i];
        pred[i] = start;
        visited[i] = 0;
    }

    distance[start] = 0;
    visited[start] = 1;
    count = 1;

    while (count < n - 1) {
        mindistance = INT_MAX;

        for (i = 0; i < n; i++)
            if (distance[i] < mindistance && !visited[i]) {
                mindistance = distance[i];
                nextnode = i;
            }

        visited[nextnode] = 1;
        for (i = 0; i < n; i++)
            if (!visited[i])
                if (mindistance + cost[nextnode][i] < distance[i]) {
                    distance[i] = mindistance + cost[nextnode][i];
                    pred[i] = nextnode;
                }
        count++;
    }

    for (i = 0; i < n; i++)
        if (i != start) {
            hash[i]  = distance[i];
        }
}

// The Main Functions are the following

int q1(int n, const connection_t connections[n][n])
{
    int vis[100000];

    for(int i = 0 ; i < n ; i++)
    {
        vis[i] = 0;
    }
    int ans = 1;

    for (int i = 0 ; i < n ; i++)
    {
        q1_dfs(i , vis , n , connections);
        ans = ans & check(vis , n);
    }
    return ans;

}

int q2(const airport_t *src, const airport_t *dest, int n, int k,const connection_t connections[n][n])
{
    int sval = src->num_id;
    int dval = dest->num_id;
    int vis[100000];
    int ans = 0;
    for(int i = 0 ; i < n ; i++)
    {
        vis[i] = 0;
    }
    q2_dfs(sval , vis , n , connections , dval , k , &ans);
    if(ans == 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int q3(const airport_t *src, int n, const connection_t connections[n][n])
{
    int s = src->num_id;
    int vis[100000];
    int ans = 0;
    for(int i = 0 ; i < n ; i++)
    {
        vis[i] = 0;
    }
    q3_dfs(s , vis , n , connections, s , &ans);
    return ans;
}

void q4(int n, int (*predicate_func)(const airport_t *, const airport_t *),airport_t airport_list[n])
{
    quickSort(airport_list,0,n-1,predicate_func);
}

pair_t q5(int n, airport_t airports[n])
{
    pair_t ans = {-1, -1};
    int max = 0;
    int a;
    for(int i=0; i<n; i++)
    {
        for(int j = i+1; j<n; j++)
        {
            a = len(airports[i],airports[j]);
            if(max < a)
            {
                max = a;
                ans.first = airports[i].num_id;
                ans.second = airports[j].num_id;
            }
        }
    }
    return ans;

}

int q6(int n, int amount, const int entry_fee[n])
{
    int si=0, ei=n-1;
    int mid;
    while(si <= ei) {

        mid = si + (ei-si)/2; 


        if(entry_fee[mid] == amount) {
            return mid+1;
        } else if(entry_fee[mid] < amount) {
            si = mid+1;
        } else { 
            ei = mid-1;
        }
    }

    return si;
}

void q7(int n, const char *pat, int contains[n], const airport_t airports[n])
{
    for(int i = 0;i<n;i++)
    {
        int t[500] = {0};
        shifttable(pat,t);
        if(horspool(airports[i].airport_name,pat,t)>=0)
        {
            contains[i] = 1;
        }
    }
}


int q8(int n, int trip_order[n - 1], const connection_t connections[n][n])
{
    int selected[n];
    int lowest = INT_MAX, min = INT_MAX,i,j,index=0,cost=0;
    int temp[n-1];

    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            selected[j] = 0;

        func8_b(n,trip_order,temp,connections,selected,&cost,i,i,index,&min);

        if(min < lowest)
            lowest = min;

        cost = 0;
    }  
    if(min == INT_MAX)
    {
        lowest = -1;
        for(i=0;i<n-1;i++)
            trip_order[i] = -1;
    }


    return lowest;
}

int q9(int n, pair_t edges[n - 1], const connection_t connections[n][n])
{
    int min_time = func9(n,connections, edges);
    return min_time;
}

void q10(int n, int k, const airport_t *src, const connection_t connections[n][n], const int destinations[k],int costs[k])
{
    int hash[n];
    Dijkstra(n,connections,src->num_id,hash);
    int i=0;
    while(i!=k)
    {
        costs[i] = hash[destinations[i]];
        i++;
    }
}

// END
//Name : Nandan
// SRN : PES2UG20CS214
