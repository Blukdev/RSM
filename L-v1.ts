/*
 ____  ____  __  __       _     
|  _ \/ ___||  \/  |     | |    
| |_) \___ \| |\/| |_____| |    
|  _ < ___) | |  | |_____| |___ 
|_| \_\____/|_|  |_|     |_____|
                                
RSM-Lampese version. V0.1
Copyright (c) 2022 Bluk Dev
*/
var ColorMaps:number[][]=[[0,0,0,0],[0,1,1,1],[0,1,1,2],[0,1,1,2]];
function fullcolor(fromx:number,fromy:number,tox:number,toy:number):void{
    for(let i:number=fromy;i<=toy;++i)
        for(let j:number=fromx;j<=tox;++j)
            ColorMaps[i][j]=0;
}
function RSM(n:number,m:number):void{
    let rex:number,rey:number,lex:number,ley:number,vis:boolean;
    for(let i:number=1;i<=n;++i){
        for(let j:number=1;j<=m;++j){
            if(!ColorMaps[i][j])continue;
            for(rex=j+1;rex<=m;++rex)
                if(ColorMaps[i][rex]!=ColorMaps[i][j])
                    break;
            vis=false;
            for(--rex,rey=i+1;rey<=n;++rey){
                for(let l:number=j;l<=rex;++l)
                    if(ColorMaps[rey][l]!=ColorMaps[i][j]){
                        vis=true;
                        break;
                    }
                if(vis)break;
            }
            for(--rey,ley=i+1;ley<=n;++ley)
                if(ColorMaps[ley][j]!=ColorMaps[i][j])
                    break;
            vis=false;
            for(--ley,lex=j+1;lex<=m;++lex){
                for(let l:number=i;l<=ley;++l)
                    if(ColorMaps[l][lex]!=ColorMaps[i][j]){
                        vis=true;
                        break;
                    }
                if(vis)break;
            }
            --lex;
            if((rex-j+1)*(rey-i+1)<(lex-j+1)*(ley-i+1)){
                console.log("[%d,%d]->[%d,%d]=[%d]",j,i,lex,ley,ColorMaps[i][j]);
                fullcolor(j,i,lex,ley);
            }else{
                console.log("[%d,%d]->[%d,%d]=[%d]",j,i,rex,rey,ColorMaps[i][j]);
                fullcolor(j,i,rex,rey);
            }
        }
    }
}
RSM(3,3);