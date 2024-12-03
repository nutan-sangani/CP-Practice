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
    vector<pll> ans;
    if(n==2){
        cout<<"1 1"<<endl;
        cout<<"2 2"<<endl;
        cout<<endl;
        return;
    }
    for(int i=1;i<n-1;i++){
        ans.pb(mp(i,1));
    }
    ans.pb(mp(n,n));
    if(ans.size()!=n){
        ans.pb(mp(n,2));
    }
    for(int i=0;i<ans.size();i++)
        cout<<ans[i].first<<" "<<ans[i].second<<endl;
    cout<<endl;
}
//4*4
//1,1 2,1 4,4 
//0 1 2 3 4 5 6
//y y y y y y y
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