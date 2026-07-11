/*
-------------------------------------------------------
Problem: Find Nth Root of M

Approach:
1. Apply Binary Search on the possible values of the
   nth root.
2. For each candidate value, calculate its nth power.
3. If the power equals m, return the value.
4. If the power exceeds m, search in the left half.
5. Otherwise, search in the right half.

Time Complexity: O(n * log(m))
Space Complexity: O(1)
-------------------------------------------------------
*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<limits>
using namespace std;

// Returns:
// 1 -> if x^n == m
// 2 -> if x^n > m
// Otherwise, x^n < m.
int power(int x,int n,int m){
    long long j=1;

    for(int i=1;i<=n;i++){
        j=j*x;

        // Stop early if the value exceeds m.
        if((int)j>m) return 2;
    }

    if((int)j==m) return 1;
}

// Returns the nth root of m if it exists;
// otherwise returns -1.
int fnc(int n,int m){
    int l=1,h=m;
    int ans=INT_MIN;

    // Binary Search on the possible root values.
    while(l<=h){
        int mid=l+(h-l)/2;

        int p=power(mid,n,m);

        if(p==1)
            return mid;
        else if(p==2)
            h=mid-1;
        else
            l=mid+1;
    }

    return -1;
}

int main(){
    int t,n,m;
    cin>>t;

    for(int i=0;i<t;i++){
        cin>>n>>m;

        int l=fnc(n,m);

        cout<<l;
        cout<<endl;
    }

    return 0;
}