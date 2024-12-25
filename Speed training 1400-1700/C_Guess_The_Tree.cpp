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
#define forn(begin,end) for(int i=begin;i<end;++i)
#define itr(a) a.begin(),a.end()
#define mod 1000000007

using namespace std;

ll query(ll a,ll b){
    cout<<"? "<<a<<" "<<b<<endl;
    cout.flush();
    ll output;
    cin>>output;
    return output;
}

void giveAnswer(vector<vector<bool>>& edgeExists,int n){
    cout<<"! ";
    ll start=0;
    forn(1,n+1){
        for(int j=1;j<(n+1);j++){
            if(edgeExists[i][j]==true){
                cout<<i<<" "<<j<<" ";
                edgeExists[i][j]=false;
                edgeExists[j][i]=false;
                start++;
            }
        }
    }
    cout<<endl;
    cout.flush();
}

void recurse(vector<vector<bool>>& edgeExists,ll a,ll b){
    
}

void solve(){
    ll n;
    cin>>n;
    vector<vector<bool>> edgeExists (n+1,vector<bool> (n+1,false));
    umll isPartOfComponent;
    queue<int> q;
    umll isTaken;
    forn(2,n+1)
        q.push(i);
    while(!q.empty()){
        ll a,b,c;
        a=1;
        if(isTaken[q.front()]==1){
            q.pop();
            continue;
        }
        b=q.front();
        c=query(a,b);
        while(c!=a && c!=b){
            if(isTaken[c]==1){
                a=c;
            }
            else{
                b=c;
            }
            c=query(a,b);
        }
        isTaken[b]=1;
        edgeExists[a][b]=true;
        edgeExists[b][a]=true;
    }
    giveAnswer(edgeExists,n);
}

int main()
{
    FASTIO
    
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}