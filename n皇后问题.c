#include<stdio.h>
#include<stdlib.h>
 
//存放皇后节点的队列
int queen[5] = {0};  //line和list的映射
int n =4 ;
int counts = 0;
//跟该行以前的行的皇后作比较看是否可以放置
int checkQueen(int line,int list){
        int BeforeLine;
        for(BeforeLine = 1; BeforeLine < line; BeforeLine++){
                if(queen[BeforeLine] == list) return 0;
                else if(line+queen[BeforeLine]== BeforeLine+list || line-queen[BeforeLine]== BeforeLine-list) return 0;
        }
        return 1;
}
 
//打印输出结果
void print(){
        int line, list;
        for(line = 1;line <= n; line++){
                for(list = 1; list <= n; list++){
                        if(queen[line] == list) printf("#");
                        else printf("0");
                }
                printf("\n");
        }
        printf("\n");
        printf("*********************************");
        printf("\n");
 
}
void Queen(int line){  //寻找可以放置皇后的该行对应的列
        int list;
        for(list = 1;list <= n; list++){
                //判断该行该列可以放置皇后？
                if(checkQueen(line,list)){  //可以放置皇后
                    queen[line] = list;
		   if(line == n){ //遍历完了
                       //解法增加
                        counts++;
                        print();
                        //将数组清空
                        queen[line] = 0;
                        return;
                     }
                    //递归
                    Queen(line+1);
                    //无论找到与否，都将该位置清空，已被再用
                    queen[line] = 0;
		}
        }
}
int main(){
        //从第一行开始遍历，保证行是逐次增加的，列随之增加就行了
        Queen(1);
	printf("count = %d\n",counts);
        return 0;
 
}
 
