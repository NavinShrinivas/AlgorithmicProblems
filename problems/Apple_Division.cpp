#include <bits/stdc++.h>
#include <math.h>

typedef long long int ll;
#define intlimit 2147483647;
using namespace std;
#define loop(n)                                                                \
  for (int i = 0; i < n; i++)                                                  \
    ;
#define maploop(m)                                                             \
  for (auto it = m.begin(); it != m.end(); it++)                               \
    ;

// void swap(int a[],int i,int j)
// {
//     int temp=a[i];
//     a[i]=a[j];
//     a[j]=temp;
// }
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll n;
  cin >> n;
  ll arr[n];
  for (int i = 0; i < n; i++) {
    int c;
    cin >> c;
    arr[i] = c;
  }
  // its given that n value cant go above 20
  // hence a expnential soltion for creation of one of the bins seem possible
  // as max size of bin is 2^19 it seems viable
  if (n == 1)
    cout << a[0];
  else if (n == 2)
    cout << abs(a[1] - a[0]);
  else {
    // resaonalble assumption that other bin is atleast of size 1
    for (int i = 1; i < n - 1; i++) {
    }
  }
}
