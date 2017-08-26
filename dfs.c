#include <stdio.h>
int map[1000][1000]={0},M,N;
int count(int x,int y){
	if(x<0||x>M||y<0||y>N)
		return ;
	if(map[x][y]){
		map[x][y]=2;
		if(map[x-1][y]){
			map[x-1][y]=2;
			return count(x-1,y);
		}
		if(map[x+1][y]){
			map[x+1][y]=2;
			return count(x+1,y);
		}
		if(map[x][y-1]){
			map[x][y-1]=2;
			return count(x,y-1);
		}
		if(map[x][y+1]){
			map[x][y+1]=2;
			return count(x,y+1);
		}
	}
}
int res(){
	int res = 0;
	int i, j;
	for (i = 0; i < M;i++)
		for(j = 0; j < N;j++)
			if(map[i][j]==2)
				res++;
	return res;
}
int main(){
	int I,i,j;
	int k,tmp = 0;
	int x,y;
	scanf("%d",&k);
	while(tmp < k){
		scanf("%d%d%d",&M,&N,&I);
		for (i = 0; i < M;i++)
			for(j = 0; j < N;j++){
				scanf("%d",&map[i][j]);
			}
		scanf("%d%d",&x,&y);
		if(x<0||x>M||y<0||y>N){
			printf("-1");
			continue;
		}
		count(x,y);
		printf("%d\n", res());
		tmp++;
	}
}