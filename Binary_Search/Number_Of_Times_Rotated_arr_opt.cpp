/*
-------------------------------------------------------
Problem: Find the Number of Times an Array Has Been Rotated

Approach:
1. The index of the minimum element represents the
   number of rotations.
2. Use Binary Search to find the minimum element.
3. At each step, determine which half of the array is
   sorted and discard it while keeping track of the
   smallest element found.

Time Complexity: O(log n)
Space Complexity: O(1)
-------------------------------------------------------
*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<limits>
using namespace std;

// Returns the index of the minimum element,
// which is equal to the number of rotations.
int search(vector<int>& a){
    int n=a.size();

    int l=0;
    int h=n-1;

    int ans=INT_MAX;
    int ind=-1;

    // Binary Search to find the minimum element.
    while(l<=h){

        int mid=l+(h-l)/2;

        // If the current search space is already sorted.
        if(a[l]<=a[h]){
            if(ans>a[l]){
                ans=a[l];
                ind=l;
                break;
            }
        }

        // Left half is sorted.
        if(a[l]<=a[mid]){
            if(ans>a[l]){
                ans=a[l];
                ind=l;
            }
            l=mid+1;
        }

        // Right half is sorted.
        else{
            if(ans>a[mid]){
                ans=a[mid];
                ind=mid;
            }
            h=mid-1;
        }
    }

    return ind;
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

        int l=search(a);

        cout<<l;
        cout<<endl;
    }

    return 0;
}