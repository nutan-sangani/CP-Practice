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

void helper(ll n,ll m,ll k,vecll& a)
{
    umll map;
    stack<ll> st;
    for(int i=k-1;i>=0;i--){
        st.push(a[i]);
    }
    ll totalLeft = m*n-3; //ye zero se niche nhi hona chahiye.
    for(int i=k;i>=1;i--){
        if(map[i]==0){
            while(map[i]==0){
                totalLeft--;
                map[st.top()]++;
                st.pop();
            }
            if(totalLeft>=0){
                totalLeft++;
                continue;
            }
            else{
                cout<<"TIDAK"<<endl;
                return;
            }
        }
        else{
            totalLeft++;
            continue;
        }
    }
    cout<<"YA"<<endl;
}

int main()
{
    FASTIO
    
    int t;
    cin>>t;
    while(t--)
    {
        ll n,m,k;
        cin>>n>>m>>k;
        vecll a(k);
        for(int i=0;i<k;i++){
            cin>>a[i];
        }
        helper(n,m,k,a);
    }
    return 0;
}