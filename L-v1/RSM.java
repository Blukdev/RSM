/*
 ____  ____  __  __       _
|  _ \/ ___||  \/  |     | |
| |_) \___ \| |\/| |_____| |
|  _ < ___) | |  | |_____| |___
|_| \_\____/|_|  |_|     |_____|

RSM-Lampese version. V0.1
Copyright (c) 2022 Bluk Dev
*/
import java.util.Scanner;
public class RSM{
    static int Map[][]=new int[105][105];
    public static void fullcolor(int fromx,int fromy,int tox,int toy){
        for(int i=fromy;i<=toy;++i)
            for(int j=fromx;j<=tox;++j)
                Map[i][j]=0;
    }
    public static void search(int n,int m){
        int rex,rey,lex,ley;
        boolean vis;
        for(int i=1;i<=n;++i)
            for(int j=1;j<=m;++j){
                if(Map[i][j]==0)continue;
                for(rex=j+1;rex<=m;++rex)
                    if(Map[i][rex]!=Map[i][j])
                        break;
                vis=false;
                for(--rex,rey=i+1;rey<=n;++rey){
                    for(int l=j;l<=rex;++l)
                        if(Map[rey][l]!=Map[i][j]){
                            vis=true;
                            break;
                        }
                    if(vis)break;
                }
                rout:for(--rey,ley=i+1;ley<=n;++ley)
                    if(Map[ley][j]!=Map[i][j])
                        break;
                vis=false;
                for(--ley,lex=j+1;lex<=m;++lex) {
                    for (int l = i; l <= ley; ++l)
                        if (Map[l][lex] != Map[i][j]) {
                            vis = true;
                            break;
                        }
                    if(vis)break;
                }
                --lex;
                if((rex-j+1)*(rey-i+1)<(lex-j+1)*(ley-i+1)){
                    System.out.printf("[%d,%d]->[%d,%d]=[%d]\n",j,i,lex,ley,Map[i][j]);
                    fullcolor(j,i,lex,ley);
                }else{
                    System.out.printf("[%d,%d]->[%d,%d]=[%d]\n",j,i,rex,rey,Map[i][j]);
                    fullcolor(j,i,rex,rey);
                }
            }
    }
    public static void main(String[] args){
        Scanner input=new Scanner(System.in);
        int n,m;
        n=input.nextInt();
        m=input.nextInt();
        for(int i=1;i<=n;++i)
            for(int j=1;j<=m;++j)
                Map[i][j]=input.nextInt();
        search(n,m);
    }
}