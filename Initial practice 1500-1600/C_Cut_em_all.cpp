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

ll counti=0;

ll helper(unordered_map<ll,vecll>& childs,int root,int parent)
{
    if(childs[root].size()==1 && childs[root][0]==parent){
        return 1;
    }
    else{
        ll sum=0;
        vecll temp = childs[root];
        int n = temp.size();
        for(int i=0;i<n;i++){
            if(temp[i]!=parent){
                ll tempo=helper(childs,temp[i],root);
                if(tempo==0){
                    // cout<<root<<endl;
                    counti++;
                }
                sum+=tempo;
            }
        }
        sum+=1;
        if((sum)%2==0){
            // counti++;
            return 0;
        }
        else return sum;
    }
}

int main()
{
    FASTIO
    
    int n;
    cin>>n;
    counti=0;
    unordered_map<ll,vecll> childs;
    for(int i=0;i<n-1;i++){
        ll a,b;
        cin>>a>>b;
        childs[a].pb(b);
        childs[b].pb(a);
    }
    if(n%2!=0){
        cout<<-1<<endl;
        return 0;
    }
    helper(childs,1,-1);
    cout<<counti<<endl;
    return 0;
}
//2:4
//4:1,2
//3:1