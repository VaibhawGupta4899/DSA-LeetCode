/*
    Minimize the Maximum Distance Between Gas Stations

    Problem:
    Given the positions of existing gas stations and 'k' additional stations,
    place the new stations such that the maximum distance between any two
    consecutive stations is minimized.

    Approach:
    - Use a Max Heap (Priority Queue) to always split the largest interval.
    - Initially, each interval has zero additional stations.
    - Repeatedly:
        1. Extract the interval with the largest current section length.
        2. Add one gas station to that interval.
        3. Recalculate its maximum section length.
        4. Push the updated interval back into the heap.
    - After placing all 'k' stations, the top of the heap represents the
      minimum possible maximum distance.

    Time Complexity:
    O((n + k) * log n)

    Space Complexity:
    O(n)
*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<limits>
#include<numeric>
#include<queue>
using namespace std;

// Returns the minimum possible maximum distance
// after placing k additional gas stations.
long double fnc(vector<int>&a,int k){

    int n=a.size();

    // Stores the number of extra stations
    // placed in each interval.
    vector<int> h(n-1);

    // Max Heap:
    // {current maximum section length, interval index}
    priority_queue<pair<long double,long double>> pq;

    // Push all initial intervals.
    for(int j=0;j<n-1;j++)
        pq.push({a[j+1]-a[j],j});

    // Place k additional gas stations.
    for(int i=1;i<=k;i++){

        auto tp=pq.top();
        pq.pop();

        int secInd=tp.second;

        // Add one station to this interval.
        h[secInd]++;

        long double intiDiff=a[secInd+1]-a[secInd];

        // New maximum section length after splitting.
        long double newSeclen=intiDiff/(long double)(h[secInd]+1);

        pq.push({newSeclen,secInd});
    }

    // Largest remaining section length.
    return pq.top().first;
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

        int k;
        cin>>k;

        cout<<fnc(a,k)<<endl;
    }

    return 0;
}