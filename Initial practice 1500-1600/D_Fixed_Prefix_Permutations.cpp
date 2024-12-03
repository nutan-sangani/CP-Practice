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

int main()
{
    FASTIO
    
    int t;
    cin>>t;
    set<vecll> set;
    while(t--)
    {   
        set.clear();
        int n,m;
        cin>>n>>m;
        vector<vecll> matrix2(n,vecll (m,0));
        umll map;
        vecll temp;
        forn(0,n){
            map.clear();
            for(int j=0;j<m;j++){
                ll a;
                cin>>a;
                map[a]=j+1;
                matrix2[i][j]=a;
            }
            temp.clear();
            for(int j=1;j<=m;j++){
                temp.pb(map[j]);
                set.insert(temp);
            }
        }
        forn(0,n){
            int j=0;
            int maxScore=0;
            temp.clear();
            while(j<m){
                temp.pb(matrix2[i][j]);
                if(set.find(temp)!=set.end()){
                    maxScore = j+1;
                }
                ++j;
            }
            cout<<maxScore<<" ";
        }
        cout<<endl;
    }
    return 0;
}