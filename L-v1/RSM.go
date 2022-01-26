/*
 ____  ____  __  __       _     
|  _ \/ ___||  \/  |     | |    
| |_) \___ \| |\/| |_____| |    
|  _ < ___) | |  | |_____| |___ 
|_| \_\____/|_|  |_|     |_____|
                          
RSM-Lampese version. V0.1
Copyright (c) 2022 Bluk Dev
*/
package main
import "fmt"
var Map [100][100]int
func fullcolor(fromx,fromy,tox,toy int){
	for i:=fromy;i<=toy;i++{
		for j:=fromx;j<=tox;j++{
			Map[i][j]=0
		}
	}
}
func RSM(n,m int){
	var rex,rey,lex,ley int
	var vis bool
	for i:=1;i<=n;i++{
		for j:=1;j<=m;j++{
			if Map[i][j]==0{continue;}
			for rex=j+1;rex<=m;rex++{
				if Map[i][rex]!=Map[i][j]{
					break;
				}
			}
			rex--
			vis=false
			for rey=i+1;rey<=n;rey++{
				for l:=j;l<=rex;l++{
					if Map[rey][l]!=Map[i][j]{
						vis=true;
						break;
					}
				}
				if vis{break;}
			}
			rey--;
			for ley=i+1;ley<=n;ley++{
				if Map[ley][j]!=Map[i][j]{
					break;
				}
			}
			vis=false;
			ley--;
			for lex=j+1;lex<=m;lex++{
				for l:=i;i<=ley;l++{
					if Map[l][lex]!=Map[i][j]{
						vis=true;
						break;
					}
				}
				if vis{break;}
			}
			lex--;
			if (rex-j+1)*(rey-i+1)<(lex-j+1)*(ley-i+1){
                fmt.Printf("[%d,%d]->[%d,%d]=[%d]\n",j,i,lex,ley,Map[i][j]);
                fullcolor(j,i,lex,ley);
            }else{
                fmt.Printf("[%d,%d]->[%d,%d]=[%d]\n",j,i,rex,rey,Map[i][j]);
                fullcolor(j,i,rex,rey);
            }
		}
	}
}
func main(){
    var n,m int
	fmt.Scan(&n);
	fmt.Scan(&m);
	for i:=1;i<=n;i++{
		for j:=1;j<=m;j++{
			fmt.Scan(&Map[i][j]);
		}
	}
	RSM(n,m);
}