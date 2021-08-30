#include<bits/stdc++.h>
#include<math.h>

typedef long long int ll;
#define intlimit 2147483647;
using namespace std;

// void swap(int a[],int i,int j)
// {
//     int temp=a[i];
//     a[i]=a[j];
//     a[j]=temp;
// }
void tower_of_hanoi(int n , string from , string between , string to)
{
    if(n==1)
    {
        cout<<from<<" "<<to<<"\n";
        return;
    }
    tower_of_hanoi(n-1,from,to,between);
    cout<<from<<" "<<to<<"\n";
    tower_of_hanoi(n-1,between,from,to);
}
int main()
{
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    
    //the number fo moves needed by n disks is 2^n-1 always
    int n;
    cin>>n;
    int ans=pow(2,n)-1;
    cout<<ans<<"\n";
    tower_of_hanoi(n,"1","2","3");
    //i : 1->ans
    //I writing down nice interative solution
    //S-Source , D-Destination , A-Auxilary
    //if i%3==1 : S <-> D 
    //if i%3==2 : S <-> A
    //if i%3==0 : A <-> S
    //but a interative solution needs a stack imple sadly , as this % logic can
    //tell between what towers the operation is , but cant tell which direction
    //and that need a comparision of sizes on both towers , hence the "<->"
    //let's implement recursive solution
}

