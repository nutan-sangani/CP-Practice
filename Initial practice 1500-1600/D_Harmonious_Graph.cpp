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

int findRoot(vecll& parents,int root){
    if(parents[root]==root){
        return root;
    }
    return parents[root]=findRoot(parents,parents[root]);
    // return findRoot(parents,parents[root]);
}

void unionRoots(int aRoot,int bRoot,vecll& parents){
    parents[aRoot] = bRoot;
    return;
}

void helper(vecll& parents,int n,int m)
{
    int ans=0;
    stack<int> st;
    int count=1;
    umll map; //root : count
    umll reverseMap;
    forn(1,n+1){
        int rootOfI = findRoot(parents,i);
        if(map[rootOfI]==0){
            map[rootOfI] = count;
            reverseMap[count] = rootOfI;
            count++;
        }
        while(!st.empty() && st.top()>map[rootOfI]){
            int topi = st.top();
            int rootOfTop = reverseMap[topi];
            unionRoots(rootOfTop,rootOfI,parents);
            st.pop();
            ++ans;
        }
        if(st.empty()){
            st.push(map[rootOfI]);
            continue;
        }
        else if(!st.empty() && st.top()!=map[rootOfI])
            st.push(map[rootOfI]);
    }
    cout<<ans<<endl;
}


int main()
{
    FASTIO

    {
        int n,m;
        cin>>n>>m;
        vecll parents(n+1,0);
        forn(0,n+1) parents[i]=i;
        forn(0,m){
            int a,b;
            cin>>a>>b;
            int aRoot,bRoot;
            aRoot = findRoot(parents,a);
            bRoot = findRoot(parents,b);
            if(aRoot!=bRoot)
                unionRoots(aRoot,bRoot,parents);
        }
        helper(parents,n,m);
    }
    return 0;
}