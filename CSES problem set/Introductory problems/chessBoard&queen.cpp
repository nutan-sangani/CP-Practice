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

using namespace std; //queen will be represented by #

ll countOfWays=0;

// bool checkRow(vector<vector<char>>& matrix,int row){
//     forn(0,8){
//         if(matrix[row][i]=='#'){
//             return false;
//         }
//     }
//     return true;
// }

bool checkCol(vector<vector<char>>& matrix,int col){
    forn(0,8){
        if(matrix[i][col]=='#'){
            return false;
        }
    }
    return true;
}

bool checkLeftToRightDownDiagonal(vector<vector<char>>& matrix,int row,int col){
    while(row<8 && col<8){
        if(matrix[row][col]=='#'){
            return false;
        }
        ++row;
        ++col;
    }
    return true;
}

bool checkLeftToRightUpDiagonal(vector<vector<char>>& matrix,int row,int col){
    while(row<8 && col<8 && row>=0){
        if(matrix[row][col]=='#'){
            return false;
        }
        --row;
        ++col;
    }
    return true;
}

void placeQueen(vector<vector<char>>& matrix,int row){
    if(row==8){
        countOfWays+=1;
        return;
    }
    forn(0,8){
        if(matrix[row][i]=='.'){
            int xUp,yUp,xDown,yDown;
            int mini = min<ll>(row,i);
            xUp = row - mini;
            yUp = i - mini;
            mini = min<ll>(7-row,i);
            xDown=row+mini;
            yDown=i-mini;
            if(checkCol(matrix,i) && checkLeftToRightUpDiagonal(matrix,xDown,yDown) && checkLeftToRightDownDiagonal(matrix,xUp,yUp)){
                matrix[row][i]='#';
                placeQueen(matrix,row+1);
                matrix[row][i]='.';
            }
        }
    }
}

void solve(){
    vector<vector<char>> matrix(8,vector<char> (8,'.'));
    forn(0,8){
        for(int j=0;j<8;j++){
            cin>>matrix[i][j];
        }
    }
    placeQueen(matrix,0);
    cout<<countOfWays<<endl;
}

int main()
{
    FASTIO
    {
        countOfWays=0;
        solve();
    }
    return 0;
}