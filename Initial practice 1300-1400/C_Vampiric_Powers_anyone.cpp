#include <iostream>
#include<bits/stdc++.h>
#define ll long long
#define forLoop for(int i=0;i<n;i++)
#define pii pair<int,int>
#define pb push_back
#define pll pair<ll,ll>
#define mp make_pair
#define um unordered_map
#define us unordered_set
#define umll unordered_map<ll,ll>
#define omll map<ll,ll>
#define vecll vector<ll>
#define FASTIO  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

void helper(vecll& nums,int n)
{
    vector<bool> isPresent(512);
    vector<int> prefix(n);
    int maxi = INT_MIN;
    int continousXOR = 0;
    for(int i=0;i<n;i++)
    {
        continousXOR = continousXOR ^ nums[i];
        prefix[i]=continousXOR;
        isPresent[continousXOR]=true;
        maxi = max(continousXOR,maxi);
        // maxi = max<int>(nums[i],maxi);
    }
    for(int i=0;i<n;i++){
        int j=0;
        while(j<512){
            int k = j ^ prefix[i];
            if(isPresent[k]){
                maxi = max(maxi,j);
            }
            j++;
        }
    }
    cout<<maxi<<endl;
    return;
}

int main()
{
    FASTIO
    
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vecll nums(n);
        forLoop
            cin>>nums[i];
        helper(nums,n);
    }
    return 0;
}

// 3
// 0 0 0
// 3
// 0 0 1
// 3
// 0 0 2
// 3
// 0 0 3
// 3
// 0 0 4
// 3
// 0 0 5
// 3
// 0 0 6
// 3
// 0 0 7
// 3
// 0 1 0
// 3
// 0 1 1
// 3
// 0 1 2
// 3
// 0 1 3
// 3
// 0 1 4
// 3
// 0 1 5
// 3
// 0 1 6
// 3
// 0 1 7
// 3
// 0 2 0
// 3
// 0 2 1
// 3
// 0 2 2
// 3
// 0 2 3
// 3
// 0 2 4
// 3
// 0 2 5
// 3
// 0 2 6
// 3
// 0 2 7
// 3
// 0 3 0
// 3
// 0 3 1
// 3
// 0 3 2
// 3
// 0 3 3
// 3
// 0 3 4
// 3
// 0 3 5
// 3
// 0 3 6
// 3
// 0 3 7
// 3
// 0 4 0
// 3
// 0 4 1
// 3
// 0 4 2
// 3
// 0 4 3
// 3
// 0 4 4
// 3
// 0 4 5
// 3
// 0 4 6
// 3
// 0 4 7
// 3
// 0 5 0
// 3
// 0 5 1
// 3
// 0 5 2
// 3
// 0 5 3
// 3
// 0 5 4
// 3
// 0 5 5
// 3
// 0 5 6
// 3
// 0 5 7
// 3
// 0 6 0
// 3
// 0 6 1