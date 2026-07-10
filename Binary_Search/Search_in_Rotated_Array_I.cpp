/*
problem : search in rotated sorted array

approach :
- use binary search
- identify which half of the array is sorted
- check whether the target lies in the sorted half
- continue searching in the appropriate half

time complexity : o(log n)
space complexity : o(1)
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// binary search on a rotated sorted array
int search(vector<int>& a, int x) {

    int n=a.size();
    int l=0;
    int h=n-1;

    while(l<=h){

        // middle index
        int mid=l+(h-l)/2;

        // target found
        if(a[mid]==x)
            return mid;

        // left half is sorted
        if(a[l]<=a[mid]){

            // target lies in the left half
            if(a[l]<=x && a[mid]>x)
                h=mid-1;
            else
                l=mid+1;
        }

        // right half is sorted
        else{

            // target lies in the right half
            if(a[mid]<x && a[h]>=x)
                l=mid+1;
            else
                h=mid-1;
        }
    }

    // target not found
    return -1;
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

        int l=search(a,x);

        // print index of target element
        cout<<l;
        cout<<endl;
    }

    return 0;
}