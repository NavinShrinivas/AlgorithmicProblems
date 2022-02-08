#include <bits/stdc++.h>
#include <math.h>

typedef long long int ll;
#define intlimit 2147483647;
using namespace std;
// void swap(int a[],int i,int j)
// {
//     int temp=a[i];
//     a[i]=a[j];
//     a[j]=temp;
// }
int main() {
  cout << "Enter expression : ";
  string s;
  cin >> s;
  // string are subscriptagble in cpp
  stack<int> sp;
  for (int i = 0; i < s.length(); i++) {
    if (s[i] >= '0' && s[i] <= '9') {
      sp.push(s[i] - '0'); //-0 converts to int
    } else {
      if (s[i] == '*') {
        int ans = 0;
        ans += sp.top();
        sp.pop();
        ans *= s[i + 1] - '0';
        i++; // cus we are done processing this char as well.
        sp.push(ans);
      } else {
        int ans = 0;
        ans += sp.top();
        sp.pop();
        ans += s[i + 1] - '0';
        i++; // cus we are done processing this char as well.
        sp.push(ans);
      }
    }
  }
  cout << sp.top();
}
