#include <stdio.h>
/*
0	0	0	1	0	0	0       0  n  
0	0	1	0	1	0	0       1  n-1  n+1   
0	1	0	2	0	1	0
1	0	3	0	3	0	1

*/
int main(){
	int data[100][100]={0};
	int n,i,j;
	scanf("%d",&n);
	for(i = 0;i<n;i++)
		for(j=0;j<2*n;j++)
			data[i][j] = 0;
	
	for(i = 0;i < n;i++){
		data[i][n-i] = 1;
		data[i][n+i] = 1;
	}
	
	for(i = 1; i < n;i++)
		for(j=0;j<2*n;j++){
			if(i-1>0&&j-1>0&&j+1<2*n)
				data[i][j] = data[i-1][j-1]+data[i-1][j+1];
		}
	for(i = 0; i < n;i++){
		for(j=0;j<2*n;j++){
			if(data[i][j]==0)
				printf("%4c",' ');
			else
				printf("%4d",data[i][j]);
		}
		printf("\n");
	}

}