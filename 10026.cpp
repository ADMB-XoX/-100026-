#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

char arr[101][101];
int n;
int check[101][101];
int dw[4]={-1,1,0,0},dh[4]={0,0,-1,1};
int cnt;
vector<int>v;
int normal=0,odd=0;

void dfs(int h, int w){
    for(int i=0;i<4;i++){
        int new_h = h + dh[i];
        int new_w = w + dw[i];
        if( 0 <= new_w && new_w <n && new_h < n && 0 <= new_h){
            if(arr[new_h][new_w] == arr[h][w] && check[new_h][new_w]==0){
                check[new_h][new_w] = 1;
                dfs(new_h,new_w);
            }
        }
    }
}

int main()
{
    cin >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> arr[i][j];
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(check[i][j]==0){
                cnt++;
                check[i][j] = 1;
                dfs(i,j);
                normal+=cnt;
                cnt=0;
            }
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            check[i][j] = 0;
            if(arr[i][j]=='G'){
                arr[i][j] = 'R';
            }
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(check[i][j]==0){
                cnt++;
                check[i][j] = 1;
                dfs(i,j);
                odd+=cnt;
                cnt=0;
            }
        }
    }

    cout << normal << " " << odd;
}
