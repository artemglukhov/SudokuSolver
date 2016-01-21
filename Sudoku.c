#include<stdio.h>
#include<stdlib.h>
int check(int **m,int x,int y,int val);
int solve(int **m, int x, int y, int val);
int p=1,n=1;
int main(void){
	int **matrix;
    // int m[81]={18,0,0,0,0,0,0,0,14,
    //            0,12,0,0,14,0,0,15,0,
    //            0,0,0,13,19,16,0,0,0,
    //            0,0,19,16,0,17,12,0,0,
    //            0,14,12,0,0,0,13,17,0,
    //            0,0,17,11,0,14,18,0,0,
    //            0,0,0,19,18,11,0,0,0,
    //            0,13,0,0,16,0,0,12,0,
    //            15,0,0,0,0,0,0,0,16};
    int m[81]={14,0,0,18,0,19,0,0,13,
               0,0,11,0,12,0,17,0,0,
               0,18,0,13,0,14,0,19,0,
               18,0,13,0,0,0,15,0,11,
               0,11,0,0,0,0,0,17,0,
               12,0,16,0,0,0,19,0,18,
               0,12,0,14,0,13,0,11,0,
               0,0,18,0,15,0,12,0,0,
               11,0,0,17,0,12,0,0,16};
	int x,y,i,p=0;
    matrix=calloc(9,sizeof(int*));
    for(i=0;i<9;i++)    matrix[i]=calloc(9,sizeof(int));
	for(x=0;x<9;x++){
		for(y=0;y<9;y++){
			matrix[x][y]=m[p++];
		}
	}
    for(x=0;x<9;x++){
		for(y=0;y<9;y++)  printf("%d ",matrix[x][y]%10);
        printf("\n");
	}
    printf("\n");
	solve(matrix,0,0,1);
    for(x=0;x<9;x++){
		for(y=0;y<9;y++){
            if(matrix[x][y]==0) printf("9 ");
            else printf("%d ",matrix[x][y]%10);
        }
        printf("\n");
	}
	return 0;
}      
int solve(int **m, int x, int y, int val){
    int t=0,c=0;
    printf("   %d %d %d\n",x,y,val);
    if(m[x][y]>=10){          /******** IF THERE IS ALREADY A NUMBER *******/
        printf("4- %d %d %d <---\n",x,y,val);
        t=1;    // GO ON
        c=1;    // FOR WHEN IT RETURNS
        if(y==8&&x==8){
            n=0;
            return 0;
        }
    }
    else if(p==0){
        if(val==9){
            p=1;
            return 0;
        }
        else{
            val++;
            p=1;
            goto iniz;
        }
    }
    else if(m[x][y]<10&&p==1){
        iniz:
        if(check(m,x,y,val)==0){        // RIGHT, GO ON
            t=1;
            m[x][y]=val;
            printf("1- %d %d %d <-- right\n",x,y,val);
        }
        else{
            if(val==9){     // WRONG, GO BACK 
                t=0;
                p=0;
                printf("3- %d %d %d <--go back\n",x,y,val);
                if (n==1) m[x][y]=0;
                return 0;
            }
            else if(n==1){
                printf("2- %d %d %d\n",x,y,val);
                val++;
                goto iniz;
            }
        }
        
    }
    if(y!=8&&t==1){
        solve(m,x,y+1,1);
        if(c==0&&p==0&&val!=9&&m[x][y]<=10){
            val++;
            p=1;
            goto iniz;
        }
        else if(val==9) m[x][y]=0;
    }
    else if(y==8&&x!=8&&t==1){
        solve(m,x+1,0,1);
        if(c==0&&p==0&&val!=9&&m[x][y]<=10){
            val++;
            goto iniz;
        }
        else if(val==9) m[x][y]=0;
    }
    else if(y==8&&x==8) n=0;
    else return 0;
}
    
int check(int **m,int x,int y,int val){
    int i,j;
    //horizontal check
    for(i=0;i<9;i++){
        if(val==m[x][i]%10) return 1;
    }
    //vertical check
    for(i=0;i<9;i++){
        if(val==m[i][y]%10) return 1;
    }
    //square check
    if(x<3&&y<3){
        for(i=0;i<3;i++){
            for(j=0;j<3;j++){
                if(val==m[i][j]%10)    return 1;
            }
        }
    }
    if(x>=3&&x<6&&y>=3&&y<6){
        for(i=3;i<6;i++){
            for(j=3;j<6;j++){
                if(val==m[i][j]%10)    return 1;
            }
        }
    }
    if(x>=6&&x<9&&y>=6&&y<9){
        for(i=6;i<9;i++){
            for(j=6;j<9;j++){
                if(val==m[i][j]%10)    return 1;
            }
        }
    }
    if(x<3&&y>=3&&y<6){
        for(i=0;i<3;i++){
            for(j=3;j<6;j++){
                if(val==m[i][j]%10)    return 1;
            }
        }
    }
    if(x<3&&y>=6&&y<9){
        for(i=0;i<3;i++){
            for(j=6;j<9;j++){
                if(val==m[i][j]%10)    return 1;
            }
        }
    }
    if(x>=3&&x<6&&y<3){
        for(i=3;i<6;i++){
            for(j=0;j<3;j++){
                if(val==m[i][j]%10)    return 1;
            }
        }
    }
    if(x>=3&&x<6&&y>=6&&y<9){
        for(i=3;i<6;i++){
            for(j=6;j<9;j++){
                if(val==m[i][j]%10)    return 1;
            }
        }
    }
    if(x>=6&&x<9&&y<3){
        for(i=6;i<9;i++){
            for(j=0;j<3;j++){
                if(val==m[i][j]%10)    return 1;
            }
        }
    }
    if(x>=6&&x<9&&y>=3&&y<6){
        for(i=6;i<9;i++){
            for(j=3;j<6;j++){
                if(val==m[i][j]%10)    return 1;
            }
        }
    }
    return 0;
}
