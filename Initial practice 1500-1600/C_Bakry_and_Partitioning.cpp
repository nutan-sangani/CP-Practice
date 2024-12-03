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

ll subTreeCount=0;
bool isPossible = false;

ll helper(um<ll,vecll>& tree,ll root,ll parent,umll& weights,ll xorTarget)
{
    if(isPossible==true) return 0;
    if(tree[root].size()==1 && parent==tree[root][0]) return weights[root];
    else{
        ll allXor = 0;
        vecll childs = tree[root];
        for(ll child : childs){
            if(child!=parent){
                ll tempXor = helper(tree,child,root,weights,xorTarget);
                if(tempXor==xorTarget){
                    subTreeCount++;
                    if(subTreeCount>1){
                        isPossible=true;
                    }
                }
                else allXor^=tempXor;
            }
        }
        if(subTreeCount<2){
            allXor^=weights[root];
            if(allXor==xorTarget){
                subTreeCount++;
                if(subTreeCount>1){
                    isPossible=true;
                }
                return 0;
            }
            else return allXor;
        }
        else return allXor;
    }
}

int main()
{
    FASTIO
    
    int t;
    cin>>t;
    while(t--)
    {
        ll n,k;
        isPossible=false;
        subTreeCount=0;
        umll weights;
        um<ll,vecll> tree;
        cin>>n>>k;
        ll allXor = 0;
        forn(1,n+1){
            ll a;
            cin>>a;
            allXor^=a;
            weights[i]=a;
        }
        forn(0,n-1){
            ll a,b;
            cin>>a>>b;
            tree[a].pb(b);
            tree[b].pb(a);
        }
        if(allXor==0){
            cout<<"YES"<<endl;
            continue;
        }
        else if(k==2){
            cout<<"NO"<<endl;
            continue;
        }
        else{
            helper(tree,1,-1,weights,allXor);
            if(isPossible==true){
                cout<<"YES"<<endl;
                continue;
            }
        }
        cout<<"NO"<<endl;
    }
    return 0;
}