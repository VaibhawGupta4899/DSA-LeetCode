/*
-------------------------------------------------------
Problem: Aggressive Cows

Approach:
1. Sort the stall positions.
2. Apply Binary Search on the answer (minimum distance).
3. For each candidate distance, greedily place the cows.
4. If all cows can be placed, try a larger distance.
5. Otherwise, search for a smaller distance.

Time Complexity: O(n log(maxDistance))
Space Complexity: O(1)
-------------------------------------------------------
*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<limits>
#include<numeric>
using namespace std;

// Checks whether all cows can be placed
// with at least 'd' distance between them.
bool plac(vector<int>&a,int c,int d){
    int n=a.size();
    int last=0;
    int cows=1;

    for(int i=1;i<n;i++){
        if(a[i]-a[last]>=d){
            cows++;
            last=i;

            if(cows==c) return true;
        }
    }
    return false;
}

// Returns the largest minimum distance possible.
int fnc(vector<int>&a,int c){
    int n=a.size();

    // Sort stall positions.
    sort(a.begin(),a.end());

    int ans=-1;
    int low=1,high=a[n-1]-a[0];

    // Binary Search on the answer.
    while(low<=high){
        int mid=low+(high-low)/2;

        if(plac(a,c,mid)==true){
            ans=mid;
            low=mid+1;
        }
        else high=mid-1;
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

        int c;
        cin>>c;

        int l=fnc(a,c);

        cout<<l;
        cout<<endl;
    }

    return 0;
}