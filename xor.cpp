#include<iostream> 
#include<climits> 
using namespace std; 
#include <vector>
#include <array>
#include <algorithm>
int search(vector<int> & a, int t) {
    int l = 0, r = a.size();
    while (l < r) {
        int m = (l + r) / 2;//kind of wrong 
        if (a[m] == t) return m;
        if ((a[m] >= a[0]) ^ (t >= a[0]) ^ (a[m] < t)) 
            l = m + 1;
        else r = m;
    }
    return -1;
}
int main()
{
   vector<int> a { 1, 2, 3 ,4,5,6};
int t=5;
search(a,t);
return 0;
}
