#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
int colors[105][105];
bool vis[105][105];
inline void fullcolor(int fromx,int fromy,int tox,int toy){
    for(int i=fromy;i<=toy;++i)
        for(int j=fromx;j<=tox;++j)
            vis[i][j]=true;
}
inline void RSM(int n,int m){
    int right_end_x,right_end_y,left_end_x,left_end_y,rightsize,leftsize,blockvis;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            if(colors[i][j]==0||vis[i][j])continue;
            blockvis=false;
            for(right_end_x=j+1;right_end_x<=m;++right_end_x)
                if(colors[i][right_end_x]!=colors[i][j]||vis[i][right_end_x])
                    break;
            --right_end_x;
            for(right_end_y=i+1;right_end_y<=n;++right_end_y){
                for(int l=j;l<=right_end_x;++l)
                    if(colors[right_end_y][l]!=colors[i][j]||vis[right_end_y][l]){
                        blockvis=true;
                        break;
                    }
                if(blockvis)break;
            }
            --right_end_y;
            for(left_end_y=i+1;left_end_y<=n;++left_end_y)
                if(colors[left_end_y][j]!=colors[i][j]||vis[left_end_y][j])
                    break;
            --left_end_y;
            blockvis=false;
            for(left_end_x=j+1;left_end_x<=m;++left_end_x){
                for(int l=i;l<=left_end_y;++l){
                    if(colors[l][left_end_x]!=colors[i][j]||vis[l][left_end_x]){
                        blockvis=true;
                        break;
                    }
                }
                if(blockvis)break;
            }
            --left_end_x;
            rightsize=(right_end_x-j+1)*(right_end_y-i+1);
            leftsize=(left_end_x-j+1)*(left_end_y-i+1);
            if(rightsize<leftsize){
                fullcolor(j,i,left_end_x,left_end_y);
                printf("[%d,%d]->[%d,%d]=[%d] size=[%d]\n",j,i,left_end_x,left_end_y,colors[i][j],leftsize);
            }else{
                fullcolor(j,i,right_end_x,right_end_y);
                printf("[%d,%d]->[%d,%d]=[%d] size=[%d]\n",j,i,right_end_x,right_end_y,colors[i][j],rightsize);
            }
        }
    }
}
int main(){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
            cin>>colors[i][j];
    RSM(n,m);
}