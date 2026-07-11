/*
-------------------------------------------------------
Problem: Find First and Last Occurrence of an Element

Approach:
1. Sort the given array.
2. Use Binary Search to find the first occurrence.
3. Use another Binary Search to find the last occurrence.
4. Print both indices.

Time Complexity: O(n log n) + O(log n)
Space Complexity: O(1)
-------------------------------------------------------
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// Returns the index of the last occurrence of x.
int lsbs(vector<int> &a,int x){
    int n=a.size();
    int l=0;
    int ans=-1;
    int h=n-1;

    // Binary Search for the last occurrence.
    while(l<=h){
        int mid=l+(h-l)/2;

        if(a[mid]==x){
            ans=mid;
            l=mid+1;
        }
        else if(a[mid]<x) l=mid+1;
        else h=mid-1;
    }

    return ans;
}

// Returns the index of the first occurrence of x.
int fibs(vector<int> &a,int x){
    int n=a.size();
    int l=0;
    int ans=-1;
    int h=n-1;

    // Binary Search for the first occurrence.
    while(l<=h){
        int mid=l+(h-l)/2;

        if(a[mid]==x){
            ans=mid;
            h=mid-1;
        }
        else if(a[mid]<x) l=mid+1;
        else h=mid-1;
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

        int x;
        cin>>x;

        // Sort the array before applying Binary Search.
        sort(a.begin(),a.end());

        int l=fibs(a,x);
        int m=lsbs(a,x);

        cout<<l<<" "<<m;
        cout<<endl;
    }

    return 0;
}