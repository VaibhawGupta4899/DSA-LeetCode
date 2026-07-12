/*
    Painter's Partition Problem

    Problem:
    Given the lengths of boards and 'p' painters, find the minimum time
    required to paint all boards such that:
    1. Each painter paints only contiguous boards.
    2. Every board is painted by exactly one painter.
    3. All painters work at the same rate.

    Approach:
    - Binary Search on the answer.
    - The minimum possible answer is the length of the largest board.
    - The maximum possible answer is the sum of all board lengths.
    - For each candidate answer (mid), greedily assign contiguous boards
      to painters and count how many painters are required.
    - If the required painters are within the limit, try a smaller answer;
      otherwise, increase the answer.

    Time Complexity:
    O(n * log(sum of board lengths))

    Space Complexity:
    O(1)
*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<limits>
#include<numeric>
using namespace std;

// Returns the number of painters required
// if each painter can paint at most 'mid' units.
int paint(vector<int>&a,int mid){
    int pt=1,ar=0;
    for(int i=0;i<a.size();i++){
        if(a[i]+ar<=mid){
            ar+=a[i];
        }
        else {
            pt++;
            ar=a[i];
        }
    }
    return pt;
}

// Binary Search on Answer
// Returns the minimum possible maximum workload.
int fnc(vector<int>&a,int p){
    int n=a.size();

    // More painters than boards.
    if(p>n) return -1;

    int low=*max_element(a.begin(),a.end());
    int high=accumulate(a.begin(),a.end(),0);

    while(low<=high){
        int mid=low+(high-low)/2;

        if(paint(a,mid)<=p)
            high=mid-1;
        else
            low=mid+1;
    }

    return low;
}

int main(){
    int t,n;
    cin>>t;

    while(t--){
        cin>>n;

        vector<int> a(n);
        for(int j=0;j<n;j++){
            cin>>a[j];
        }

        int p;
        cin>>p;

        cout<<fnc(a,p)<<endl;
    }

    return 0;
}