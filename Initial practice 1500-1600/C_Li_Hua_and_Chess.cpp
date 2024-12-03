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

ll query(ll a,ll b){
    cout<<"? "<<a<<" "<<b<<endl;
    cout.flush();
    ll ans;
    cin>>ans;
    return ans;
}

void printAns(ll a,ll b){
    cout<<"! "<<a<<" "<<b<<endl;
    cout.flush();
    return;
}

void helper(ll n,ll m)
{
    //first query at 0,0
    ll ans1 = query(0+1,0+1);
    if(ans1==0){
        printAns(1,1);
        return;
    }
    if(ans1>=n || ans1>=m){
        if(ans1>=n){
            //ie answer definetely in that column
            ll ans2 = query(1,ans1+1);
            printAns(ans2+1,ans1+1);
            return;
        }
        else{
            ll ans2 = query(ans1+1,1);
            printAns(ans1+1,ans2+1);
            return;
        }
    }
    else{
        //second query at ans1,ans1
        ll ans2 = query(ans1+1,ans1+1);
        pair<ll,ll> pos1,pos2;
        pos1 = mp(ans1-ans2,ans1);
        pos2 = mp(ans1,ans1-ans2);
        //query 3 at pos1
        ll ans3 = query(pos1.first+1,pos1.second+1);
        if(ans3==0){
            printAns(pos1.first+1,pos1.second+1);
        }
        else printAns(pos2.first+1,pos2.second+1);
    }
    return;
}
//3,4
//0 1 2 3 
//1 1 2 3
//2 1 2 3

int main()
{
    FASTIO
    
    int t;
    cin>>t;
    while(t--)
    {
        ll n,m;
        cin>>n>>m;
        helper(n,m);
    }
    return 0;
}