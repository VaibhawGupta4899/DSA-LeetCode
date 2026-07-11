/*
-------------------------------------------------------
Problem: Minimum Number of Days to Make m Bouquets

Approach:
1. If the total number of flowers is less than m × k,
   it is impossible to make the required bouquets.
2. Apply Binary Search on the answer (number of days).
3. For each candidate day, count the maximum number of
   bouquets that can be formed using adjacent flowers.
4. If at least m bouquets can be made, try fewer days.
5. Otherwise, increase the number of days.

Time Complexity: O(n * log(maxBloomDay))
Space Complexity: O(1)
-------------------------------------------------------
*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<limits>
using namespace std;

// Counts the number of bouquets that can be made
// on or before the given day.
int boq(vector<int>&a,int mid,int k){
    int n=a.size();
    int cnt=0,r=0;

    for(int i=0;i<n;i++){
        if(a[i]<=mid){
            cnt++;

            if(cnt==k){
                r++;
                cnt=0;
            }
        }
        else
            cnt=0;
    }

    return r;
}

// Returns the minimum number of days required
// to make 'm' bouquets.
int fnc(vector<int>&a,int m,int k){
    int n=a.size();

    // Not enough flowers to make the required bouquets.
    if(n<m*k) return -1;

    int ans=INT_MAX;

    // Search space: minimum to maximum bloom day.
    int low=*min_element(a.begin(),a.end());
    int high=*max_element(a.begin(),a.end());

    // Binary Search on the answer.
    while(low<=high){
        int mid=low+(high-low)/2;

        if(boq(a,mid,k)>=m){
            ans=min(ans,mid);
            high=mid-1;
        }
        else
            low=mid+1;
    }

    if(ans!=INT_MAX)
        return ans;
    else
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

        int m,k;
        cin>>m>>k;

        int d=fnc(a,m,k);

        cout<<d;
        cout<<endl;
    }

    return 0;
}