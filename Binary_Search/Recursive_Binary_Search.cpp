/*
problem : binary search
approach : sort the array first and then apply recursive binary search
time complexity : o(n log n) + o(log n)
space complexity : o(log n)   // recursion stack
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// recursive binary search
int rect(vector<int> &a,int l,int h,int x){
    // element not found
    if(l>h) return -1;

    // middle index
    int mid=l+(h-l)/2;

    // target found
    if(a[mid]==x) return mid;

    // search in left half
    else if(a[mid]>x) h=mid-1;

    // search in right half
    else l=mid+1;

    // continue searching
    return rect(a,l,h,x);
}

// sorts the array and calls binary search
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

    while(t--){
        cin>>n;

        vector<int> a(n);

        // input array
        for(int j=0;j<n;j++){
            cin>>a[j];
        }

        int x;
        cin>>x;

        int l=bs(a,x);

        cout<<l<<" ";
        cout<<endl;
    }

    return 0;
}