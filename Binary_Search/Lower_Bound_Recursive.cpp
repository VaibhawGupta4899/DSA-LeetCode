/*
problem : lower bound using recursive binary search

approach :
- sort the array
- recursively search for the first index where value is greater than or equal to x
- store the current answer and continue searching on the left side

time complexity : o(n log n) + o(log n)
space complexity : o(log n)
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// stores the current lower bound index
int ans=-1;

// recursive binary search
int rect(vector<int> &a,int l,int h,int x){

    // middle index
    int mid=l+(h-l)/2;

    // search completed
    if(l>h) return ans;

    // possible lower bound found
    if(a[mid]>=x){
        h=mid-1;
        ans=mid;
    }
    else{
        // move to the right half
        l=mid+1;
    }

    return rect(a,l,h,x);
}

// sorts the array and finds lower bound
int bs(vector<int> &a,int x){
    sort(a.begin(),a.end());
    int n=a.size();
    int l=0;
    int h=n-1;

    int p=rect(a,l,h,x);

    return p;
}

int main(){

    int t,n;
    cin>>t;

    for(int i=0;i<t;i++){

        cin>>n;

        vector<int> a(n);

        // input array
        for(int j=0;j<n;j++){
            cin>>a[j];
        }

        int x;
        cin>>x;

        int l=bs(a,x);

        // print lower bound index
        cout<<l<<" ";
        cout<<endl;
    }

    return 0;
}