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

void solve(){
    ll b,c,d;
    cin>>b>>c>>d;
    ll a=0;
    int i=0;
    while(i<63){
        bool isB,isC,isD;
        isB = (b & 1LL<<i);
        isC = (c & 1LL<<i);
        isD = (d & 1LL<<i);
        if(isB && isC && !isD){
            a = (a | 1LL<<i);
        }
        else if(!isB && isC && !isD){
            i+=1;
            continue;
        }
        else if(!isB && !isC && !isD){
            i+=1;
            continue;
        }
        else if(isB && !isC && !isD){
            cout<<-1<<endl;
            return;
        }
        else if(isB && isC && isD){
            i+=1;
            continue;
        }

        else if(!isB && isC && isD){
            cout<<-1<<endl;
            return;
        }
        else if(!isB && !isC && isD){
            a=(a | 1LL<<i);
        }
        else if(isB && !isC && isD){
            i+=1;
            continue;
        }
        ++i;
    }
    cout<<a<<endl;
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