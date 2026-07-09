/*
problem : count occurrences of an element using binary search

approach :
- sort the array
- find the first occurrence
- find the last occurrence
- count = last index - first index + 1

time complexity : o(n log n) + o(log n)
space complexity : o(1)
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// finds the last occurrence of x
int lsbs(vector<int> &a,int x){
    int n=a.size();
    int l=0;
    int ans=-1;
    int h=n-1;

    while(l<=h){
        int mid=l+(h-l)/2;

        if(a[mid]==x){
            ans=mid;
            l=mid+1;
        }
        else if(a[mid]<x)
            l=mid+1;
        else
            h=mid-1;
    }

    return ans;
}

// finds the first occurrence of x
int fibs(vector<int> &a,int x){
    int n=a.size();
    int l=0;
    int ans=-1;
    int h=n-1;

    while(l<=h){
        int mid=l+(h-l)/2;

        if(a[mid]==x){
            ans=mid;
            h=mid-1;
        }
        else if(a[mid]<x)
            l=mid+1;
        else
            h=mid-1;
    }

    return ans;
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

        // binary search requires sorted array
        sort(a.begin(),a.end());

        int l=fibs(a,x);
        int m=lsbs(a,x);

        // total occurrences
        int d=m-l+1;

        cout<<d;
        cout<<endl;
    }

    return 0;
}