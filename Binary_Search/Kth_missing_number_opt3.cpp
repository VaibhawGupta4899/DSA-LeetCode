/*
-------------------------------------------------------
Problem: Kth Missing Positive Number

Approach:
1. Use Binary Search to find the first index where the
   number of missing positive integers is greater than
   or equal to k.
2. At each index, calculate the missing numbers as:
      missing = a[mid] - (mid + 1)
3. Once the search ends, the answer is:
      low + k

Time Complexity: O(log n)
Space Complexity: O(1)
-------------------------------------------------------
*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<limits>
#include<numeric>
using namespace std;

// Returns the kth missing positive number.
int fnc(vector<int>&a,int k){
    int n=a.size();

    int low=0,high=n-1;
    int ans=-1;

    // Binary Search on the array indices.
    while(low<=high){
        int mid=low+(high-low)/2;

        // Number of missing positive integers till index 'mid'.
        int mis=a[mid]-(mid+1);

        if(mis>=k)
            high=mid-1;
        else
            low=mid+1;
    }

    // Compute the kth missing positive number.
    return low+k;
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

        int k;
        cin>>k;

        int l=fnc(a,k);

        cout<<l;
        cout<<endl;
    }

    return 0;
}