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

vecll multiples;

void findMultiples(ll n){
    forn(1,sqrt(n)+1){
        if(n%i==0){
            multiples.pb(i);
            if(i!=(n/i))
                multiples.pb(n/i);
        }
    }
}

void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    multiples.clear();
    findMultiples(n);
    int size = multiples.size();
    sort(itr(multiples));
    forn(0,size){
        int diff = multiples[i];
        int k=0;
        int wrongCount = 0;
        while(k<diff){
            int j=k;
            umll count;
            while(j<n){
                count[s[j]]++;
                j+=diff;
            }
            if(count.size()>2) break;
            if(count.size()==2){
                int mini=2;
                for(auto it : count){
                    mini = min<ll>(mini,it.second);
                }
                if(mini>1){
                    break;
                }
                wrongCount+=1;
                if(wrongCount>1) break;
            }
            k++;
            if(k==diff){
                cout<<diff<<endl;
                return;
            }
        }
    }
}
//4
//1,2,4


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