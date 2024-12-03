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

class MyComp{
    public:
    bool operator()(const pair<int,int>& a,const pair<int,int>& b){
        if(a.second!=b.second)
            return a.second<b.second;
        return a.first<b.first;
    }
};

int main()
{
    FASTIO
    
    int t;
    cin>>t;
    while(t--)
    {
        int n,remaining;
        cin>>n>>remaining;
        vecll count(n,0);
        vector<pair<int,int>> timeRequired;
        umll map;
        umll visited;
        forn(0,n){
            int a;
            cin>>a;
            timeRequired.pb(mp(i,a));
            map[i]=a;
            count[i]=(i+1);
        }
        sort(itr(timeRequired),MyComp());
        int winCount=0;
        int last = -1;
        int miniRank = n+1;
        int lastIndex=-1;
        forn(0,n){
            if(timeRequired[i].second>remaining){
                break;
            }
            else{
                visited[timeRequired[i].first]=1;
                last = timeRequired[i].second;
                ++winCount;
                remaining-=timeRequired[i].second;
                count[timeRequired[i].first]--;
            }
        }
        if(last!=-1)
            forn(0,n){
                if(count[i]<=winCount){
                    miniRank = n-i;
                    continue;
                }
                else{
                    int req = map[i];
                    req -= remaining;
                    if(req<=last && count[i]==winCount+1 && visited[i]!=1){
                        miniRank-=1;
                    }
                    break;
                }
            }
        cout<<miniRank<<endl;
    }
    return 0;
}