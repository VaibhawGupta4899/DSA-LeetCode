/*
-------------------------------------------------------
Problem: Find the Floor Value of the Square Root

Approach:
1. Apply Binary Search on the range [1, n].
2. For each middle value, check whether its square is
   less than or equal to n.
3. If it is, store it as the current answer and search
   for a larger value.
4. Otherwise, search in the left half.
5. The final stored value is the floor of √n.

Time Complexity: O(log n)
Space Complexity: O(1)
-------------------------------------------------------
*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<limits>
using namespace std;

// Returns the floor value of the square root of n.
int fnc(int n){
    int l=1,h=n;
    int ans=INT_MIN;

    // Binary Search on the possible square root values.
    while(l<=h){

        int mid=l+(h-l)/2;

        // mid can be a possible answer.
        if(mid*mid<=n){
            if(ans<mid)
                ans=mid;
            l=mid+1;
        }

        // Search in the left half.
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

        int l=fnc(n);

        cout<<l;
        cout<<endl;
    }

    return 0;
}