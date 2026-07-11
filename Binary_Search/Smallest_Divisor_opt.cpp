/*
-------------------------------------------------------
Problem: Find the Smallest Divisor Given a Threshold

Approach:
1. If the number of elements is greater than the
   threshold, no valid divisor exists.
2. Apply Binary Search on the divisor.
3. For each divisor, calculate the sum of
   ceil(nums[i] / divisor) for all elements.
4. If the sum is within the threshold, try a
   smaller divisor.
5. Otherwise, increase the divisor.

Time Complexity: O(n * log(maxElement))
Space Complexity: O(1)
-------------------------------------------------------
*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<limits>
using namespace std;

// Returns the sum of ceil(a[i] / mid)
// for all elements in the array.
int hold(vector<int>&a,int mid){
    int sum=0;

    for(int i=0;i<a.size();i++)
        sum+=(a[i]+mid-1)/mid;

    return sum;
}

// Returns the smallest divisor such that
// the computed sum does not exceed the threshold.
int fnc(vector<int>&a,int m){
    int n=a.size(),ans=-1;

    // No valid divisor exists.
    if(n>m) return ans;

    int low=1;
    int high=*max_element(a.begin(),a.end());

    // Special case.
    if(n==m && m==high) return high;

    // Binary Search on the divisor.
    while(low<=high){
        int mid=low+(high-low)/2;

        if(hold(a,mid)<=m){
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

        int m;
        cin>>m;

        int d=fnc(a,m);

        cout<<d;
        cout<<endl;
    }

    return 0;
}