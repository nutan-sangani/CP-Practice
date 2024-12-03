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

pll getNextPosition(int n,int m,pll& dir,int i,int j){
    pll p;
    //dekh if row me -1 to 0 lese n, if col me -1 to 0 else m
    int endR,endC;
    if(dir.first==-1) endR=1;
    else endR=n;
    if(dir.second==-1) endC=1;
    else endC=m;
    int diff1 = abs(i-endR);
    int diff2 = abs(j-endC);
    int mini = min(diff1,diff2);
    i+=(dir.first*mini);
    j+=(dir.second*mini);
    p.first=i;
    p.second=j;
    if(diff1==diff2){
        dir.first = dir.first==1 ? -1 : 1;
        dir.second = dir.second==1 ? -1 : 1;
    }
    else if(mini==diff1){ //means row was limiting
        dir.first = dir.first==1 ? -1 : 1;
    }
    else{ //means col was limiting
        dir.second = dir.second==1 ? -1 : 1;
    }
    return p;
}
bool inbetweenJump(pll& start,pll& end,int x,int y,pll& dir){
    int diffX = x - start.first;
    int diffY = y - start.second;
    diffX*=dir.first;
    diffY*=dir.second;
    if(diffX==diffY && diffX>=0) return true;
    return false;
}

int getDirection(pll& dir){
    if(dir.first==-1 && dir.second==1) return 1;
    else if(dir.first==1 && dir.second==1) return 2;
    else if(dir.first==1 && dir.second==-1) return 3;
    else return 4;
}

int main()
{
    FASTIO
    
    int t;
    cin>>t;
    int copyT = t;
    int z=1;
    while(t--)
    {
        int n,m;
        int i,j;
        int x,y;
        string d;
        cin>>n>>m>>i>>j>>x>>y>>d;
        vector<vector<vecll>> grid(n+1,vector<vecll> (m+1,vecll(5,0)));
        pll dir;
        if(d[0]=='D') dir.first=1;
        else dir.first=-1;
        if(d[1]=='L') dir.second=-1;
        else dir.second=1;
        ll count=0;
        int flag=0;
        pll curr,next;
        curr.first=i;
        curr.second=j;
        int dirNo = getDirection(dir);
        grid[curr.first][curr.second][dirNo]=1;
        //-1,1 = 1
        //-1,-1 = 2
        //1,1 = 3
        //1,-1 = 4
        while(1){
            pll dirCopy = dir; 
            next = getNextPosition(n,m,dir,curr.first,curr.second);
            dirNo = getDirection(dir);
            if(inbetweenJump(curr,next,x,y,dirCopy)){
                flag=1;
                break;
            }
            if(grid[next.first][next.second][dirNo]==1){
                break;
            }
            grid[next.first][next.second][dirNo]=1;
            curr = next;
            ++count;
        }
        z++;
        if(flag==1)
            cout<<count<<endl;
        else cout<<-1<<endl;
    }
    return 0;
}