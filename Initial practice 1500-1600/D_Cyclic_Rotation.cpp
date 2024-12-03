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

void solve()
{
    int n;
    cin>>n;
    vecll a(n,0);
    vecll b(n,0);
    forn(0,n){
        cin>>a[i];
    }
    forn(0,n){
        cin>>b[i];
    }
    int i,j;
    i=j=n-1; //i for a and j for b.
    umll takenCount;
    while(i>=0){
        if(a[i]==b[j]){
            --i;
            --j;
        }
        else{
            int prev;
            if(i<n-1)
                prev=i+1;
            else{
                cout<<"NO"<<endl;
                return;
            }
            if(b[j]==a[prev]){
                --j;
                takenCount[a[prev]]-=1;
                continue;
            }
            else{
                if(takenCount[a[i]]<0){
                    takenCount[a[i]]+=1;
                    --i;
                    continue;
                }
                else{
                    cout<<"NO"<<endl;
                    return;
                }
            }
        }
    }
    cout<<"YES"<<endl;
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