/*
-------------------------------------------------------
Problem: Capacity to Ship Packages Within D Days

Approach:
1. The minimum ship capacity is the maximum package weight.
2. The maximum ship capacity is the sum of all package weights.
3. Apply Binary Search on the ship capacity.
4. For each capacity, calculate the number of days required.
5. If the required days are within the given limit,
   try a smaller capacity.

Time Complexity: O(n * log(sumOfWeights))
Space Complexity: O(1)
-------------------------------------------------------
*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<limits>
using namespace std;

// Returns the number of days required
// to ship all packages with capacity 'c'.
int din(vector<int>&a,int c){
    int d=1,n=a.size(),e=0;

    for(int i=0;i<n;i++){
        if(e+a[i]<=c)
            e+=a[i];
        else{
            d++;
            e=a[i];
        }
    }

    return d;
}

// Returns the minimum ship capacity
// required to ship all packages within 'days'.
int fnc(vector<int>&a,int days){
    int n=a.size();
    int high=0,ans=-1;

    // Minimum possible capacity.
    int low=*max_element(a.begin(),a.end());

    // Maximum possible capacity.
    for(int i=0;i<n;i++)
        high+=a[i];

    // Binary Search on the ship capacity.
    while(low<=high){
        int mid=low+(high-low)/2;

        if(din(a,mid)<=days){
            ans=mid;
            high=mid-1;
        }
        else
            low=mid+1;
    }

    return ans;
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

        int d;
        cin>>d;

        int l=fnc(a,d);

        cout<<l;
        cout<<endl;
    }

    return 0;
}