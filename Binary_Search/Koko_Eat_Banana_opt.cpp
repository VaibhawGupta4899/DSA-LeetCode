/*
-------------------------------------------------------
Problem: Koko Eating Bananas

Approach:
1. Use Binary Search on the answer (eating speed).
2. For each possible eating speed, calculate the total
   hours required to finish all banana piles.
3. If the required hours are within the given limit,
   try a smaller eating speed.
4. Otherwise, increase the eating speed.

Time Complexity: O(n * log(maxPile))
Space Complexity: O(1)
-------------------------------------------------------
*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<limits>
using namespace std;

// Calculates the total hours required
// to eat all banana piles at speed 'mid'.
int tim(vector<int>&a,int mid){
    int n=a.size();
    int sum=0;

    for(int i=0;i<n;i++){
        int r=ceil((double)a[i]/(double)mid);
        sum+=r;
    }

    return sum;
}

// Returns the minimum eating speed.
int fnc(vector<int>&a,int h){
    int n=a.size();

    // Find the maximum pile size.
    int high=INT_MIN;
    for(int i=0;i<n;i++)
        if(high<a[i]) high=a[i];

    int l=1,ans=high;

    // Binary Search on the eating speed.
    while(l<=high){
        int mid=l+(high-l)/2;

        if(tim(a,mid)<=h){
            ans=mid;
            high=mid-1;
        }
        else
            l=mid+1;
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

        int h;
        cin>>h;

        int l=fnc(a,h);

        cout<<l;
        cout<<endl;
    }

    return 0;
}