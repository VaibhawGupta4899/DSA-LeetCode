/*
-------------------------------------------------------
Problem: Find Peak Element

Approach:
1. Handle the edge cases where the array has only one
   element or the peak lies at either end.
2. Apply Binary Search on the remaining portion.
3. If the middle element is greater than both its
   neighbours, it is the peak.
4. Otherwise, move towards the side where a larger
   element exists.

Time Complexity: O(log n)
Space Complexity: O(1)
-------------------------------------------------------
*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<limits>
using namespace std;

// Returns the peak element in the array.
int fnc(vector<int> &a){
    int n=a.size();

    int l=1;
    int h=n-2;

    // Edge case: Only one element.
    if(n==1) return a[0];

    // Check if the first element is the peak.
    if(a[1]<a[0]) return a[0];

    // Check if the last element is the peak.
    if(a[n-2]<a[n-1]) return a[n-1];

    // Binary Search for the peak element.
    while(l<=h){
        int mid=l+(h-l)/2;

        // Peak element found.
        if(a[mid]>a[mid-1] && a[mid]>a[mid+1])
            return a[mid];

        // Peak lies on the right side.
        else if(a[mid]>a[mid-1])
            l=mid+1;

        // Peak lies on the left side.
        else
            h=mid-1;
    }

    return -1;
}

int main(){
    int t,n;
    cin>>t;

    for(int i=0;i<t;i++){
        cin>>n;

        vector<int> a(n);

        for(int j=0;j<n;j++){
            cin>>a[j];
        }

        int l=fnc(a);

        cout<<l;
        cout<<endl;
    }

    return 0;
}