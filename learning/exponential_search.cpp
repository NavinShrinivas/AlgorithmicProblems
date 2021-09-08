//implementing exponential sort for learninig
//not any particular problem
#include<bits/stdc++.h>
using namespace std;

int binary_search(int a[],int L,int U,int x)
{
  if(L<=U)
  {
    int mid=(U+L)/2;
    if(a[mid]==x)
      return mid;
    else if(a[mid]>x)
      binary_search(a,L,mid-1,x);
    else
      binary_search(a,mid+1,U,x);
  }
  else
    return -1;
}
int exponential_sort(int a[],int n,int x)
{
  if (a[0]==x)
    return 0;
  int i=1;
  while(i<n && a[i]<=x)
    i=i*2;
  return binary_search(a,i/2,i,x);
}
int main()
{
  int n;
  cout<<"-----------------------------------PROGRAM STARTING-----------------------------------"<<"\n";
  cout<<"enter no. of elements in the array"<<"\n";
  cin>>n;
  cout<<"enter the elements"<<"\n";
  int a[n];
  for(int i=0;i<n;i++)
    cin>>a[i];
  cout<<"enter element to be found"<<"\n";
  int x;
  cin>>x;
  int pos=exponential_sort(a,n,x);
  if(pos==-1)
    cout<<"element not present"<<"\n";
  else
    cout<<"ement present in "<<(pos+1)<<"th posistion"<<"\n";
}
