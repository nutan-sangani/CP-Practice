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

ll ways=0;
int rowOption[]={0,0,-1,1};
int colOption[]={-1,1,0,0};

vector<vector<int>> visited(7,vector<int> (7,0));

bool inBound(int row,int col){
    if(row<7 && row>=0 && col<7 && col>=0) return true;
    return false;
}

bool partitionCondition(int row,int col){
    if(col==0 && row>0 && row<6 && visited[row+1][col]==0 && visited[row-1][col]==0) return true;
    else if(col==6 && row>0 && row<6 && visited[row+1][col]==0 && visited[row-1][col]==0) return true;
    else if(row==0 && col>0 && col<6 && visited[row][col-1]==0 && visited[row][col+1]==0) return true;
    else if(row==6 && col>0 && col<6 && visited[row][col-1]==0 && visited[row][col+1]==0) return true;
    else return false;
}

bool specialCondition(int row,int col){
    int presentCount=0;
    forn(0,4){
        int nextRow = row+rowOption[i];
        int nextCol = col+colOption[i];
        if(inBound(nextRow,nextCol) && visited[nextRow][nextCol]==1) presentCount+=1;
    }
    if(presentCount>=3) return true;
    return false;
}

void recurse(int row,int col,int index,string& s){
    if(index==48){
        if(row==6 && col==0 && visited[6][0]==0) ways+=1;
        return;
    }
    else if(row==6 && col==0){
        return;
    }
    else{
        visited[row][col]=1;
        int move=-1;
        forn(0,4){
            int nextRow = row+rowOption[i];
            int nextCol = col+colOption[i];
            if(inBound(nextRow,nextCol) && visited[nextRow][nextCol]==0 && specialCondition(nextRow,nextCol)){
                if(move==-1)
                    move=i;
            }
        }
        if(s[index]=='?'){
            forn(0,4){
                int nextRow = row+rowOption[i];
                int nextCol = col+colOption[i];
                if(move!=-1){
                    if(i!=move) continue;
                }
                if(inBound(nextRow,nextCol) && visited[nextRow][nextCol]==0 && !partitionCondition(nextRow,nextCol)){
                    recurse(nextRow,nextCol,index+1,s);
                }
            }
            visited[row][col]=0;
            return;
        }
        if(s[index]=='R' 
        && (move==-1 || move==1)
        ){
            int nextRow = row;
            int nextCol = col+1;
            if(inBound(nextRow,nextCol) && visited[nextRow][nextCol]==0 && !partitionCondition(nextRow,nextCol)){
                recurse(nextRow,nextCol,index+1,s);
            }
        }
        else if(s[index]=='L'
        && (move==-1 || move==0)
        ){
            int nextRow = row;
            int nextCol = col-1;
            if(inBound(nextRow,nextCol) && visited[nextRow][nextCol]==0 && !partitionCondition(nextRow,nextCol)){
                recurse(nextRow,nextCol,index+1,s);
            }
        }
        else if(s[index]=='U' 
        && (move==-1 || move==2)
        ){
            int nextRow = row-1;
            int nextCol = col;
            if(inBound(nextRow,nextCol) && visited[nextRow][nextCol]==0 && !partitionCondition(nextRow,nextCol)){
                recurse(nextRow,nextCol,index+1,s);
            }
        }
        else if(s[index]=='D' 
        && (move==-1 || move==3)
        ){
            int nextRow = row+1;
            int nextCol = col;
            if(inBound(nextRow,nextCol) && visited[nextRow][nextCol]==0 && !partitionCondition(nextRow,nextCol)){
                recurse(nextRow,nextCol,index+1,s);
            }
        }
        visited[row][col]=0;
    }
}

void solve(){
    string s;
    cin>>s;
    recurse(0,0,0,s);
    cout<<ways<<endl;
}

int main()
{
    FASTIO
    ways=0;
    solve();
    return 0;
}

//backtracking me, chote chote optimizations are very useful and state space tree me
//jitna jaldi koi call rokega, utna better.