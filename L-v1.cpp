/*
 ____  ____  __  __       _     
|  _ \/ ___||  \/  |     | |    
| |_) \___ \| |\/| |_____| |    
|  _ < ___) | |  | |_____| |___ 
|_| \_\____/|_|  |_|     |_____|
                                
RSM-Lampese version. V0.1
Copyright (c) 2022 Bluk Dev
*/
#include<cstdio>
using namespace std;
int Map[105][105];
inline void fullcolor(int fromx,int fromy,int tox,int toy){
    for(int i=fromy;i<=toy;++i)
        for(int j=fromx;j<=tox;++j)
            Map[i][j]=0;
}
inline void RSM(int n,int m){
    int rex,rey,lex,ley;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            if(!Map[i][j])continue;
            for(rex=j+1;rex<=m;++rex)
                if(Map[i][rex]!=Map[i][j])
                    break;
            for(--rex,rey=i+1;rey<=n;++rey)
                for(int l=j;l<=rex;++l)
                    if(Map[rey][l]!=Map[i][j])
                        goto rout;
       rout:for(--rey,ley=i+1;ley<=n;++ley)
                if(Map[ley][j]!=Map[i][j])
                    break;
            for(--ley,lex=j+1;lex<=m;++lex)
                for(int l=i;l<=ley;++l)
                    if(Map[l][lex]!=Map[i][j])
                        goto lout;
       lout:--lex;
            if((rex-j+1)*(rey-i+1)<(lex-j+1)*(ley-i+1)){
                printf("[%d,%d]->[%d,%d]=[%d]\n",j,i,lex,ley,Map[i][j]);
                fullcolor(j,i,lex,ley);
            }else{
                printf("[%d,%d]->[%d,%d]=[%d]\n",j,i,rex,rey,Map[i][j]);
                fullcolor(j,i,rex,rey);
            }
        }
    }
}
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
            scanf("%d",&Map[i][j]);
    RSM(n,m);
}