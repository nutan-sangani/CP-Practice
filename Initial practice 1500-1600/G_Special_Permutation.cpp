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

void helper(int n)
{
    if(n<4){
        cout<<-1<<endl;
        return;
    }
    vecll ans;
    int i=0;
    int first;
    if(n%2==0) first=2;
    else first=1;
    while(first<=n){
        ans.pb(first);
        first+=2;
    }
    first-=2;
    first-=3;
    ans.pb(first);
    first+=2;
    ans.pb(first);
    first-=4;
    while(first>0){
        ans.pb(first);
        first-=2;
    }
    forLoop
        cout<<ans[i]<<" ";
    cout<<endl;
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
        helper(n);
    }
    return 0;
}