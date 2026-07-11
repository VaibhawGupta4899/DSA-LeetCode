/*
-------------------------------------------------------
Problem: Single Element in a Sorted Array

Approach:
1. Handle the edge cases where the array contains only
   one element or the unique element is at either end.
2. Apply Binary Search on the remaining part of the array.
3. If the middle element is different from both its
   neighbours, it is the required single element.
4. Otherwise, use the index parity to determine which
   half contains the single element.

Time Complexity: O(log n)
Space Complexity: O(1)
-------------------------------------------------------
*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<limits>
using namespace std;

// Returns the single element that appears only once.
int fnc(vector<int>&a){
    int n=a.size();

    int l=1;
    int h=n-2;

    while(l<=h){

        int mid=l+(h-l)/2;

        // Edge case: Only one element.
        if(n==1) return a[0];

        // Check if the first element is unique.
        if(a[0]!=a[1]) return a[0];

        // Check if the last element is unique.
        if(a[n-1]!=a[n-2]) return a[n-1];

        // Unique element found.
        if(a[mid]!=a[mid-1] && a[mid]!=a[mid+1])
            return a[mid];

        // Unique element lies on the right half.
        if((mid%2==1 && a[mid-1]==a[mid]) || (mid%2==0 && a[mid+1]==a[mid]))
            l=mid+1;

        // Unique element lies on the left half.
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