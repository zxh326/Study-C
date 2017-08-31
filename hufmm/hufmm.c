#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define maxN 10
/*
Object
*/
typedef struct {
	char c; //字符
	int Weight;//权重
	int lc;//左孩子
	int rc;//游孩子
	int fc;//父节点
	char code[maxN];//编码
}huffm;

//比较森林中最小的两个
void compare(huffm data[],int n,int *s1,int *s2){
	int i;
	for (i = 1; i <= n && data[i].fc != 0; ++i){
	}
	*s1 = i;
	for (i = 1; i <= n; ++i){
      	if(data[i].fc==0 && data[i].Weight < data[*s1].Weight)
          	*s1 = i;
	}
    
    for(i = 1; i <= n; ++i){
        if(data[i].fc==0 && i!=*s1)  
        	break;  
    }

    *s2 = i;            
   	for(i = 1; i <= n; ++i){
        if(data[i].fc == 0 && i != *s1 && data[i].Weight < data[*s2].Weight) 
            *s2 = i;
   	}
    printf("%d %d \n",*s1,*s2);
}

//写入文件
void Writofile(huffm data[],int n){
	FILE *fp;
	FILE *fp1;
	fp = fopen("code.txt","w+");
	fp1 = fopen("uncode.txt","w+");
	for (int i = 1; i <= n; ++i){
		fprintf(fp, "%c--------->%s\n",data[i].c,data[i].code);
		fprintf(fp1,"%s",data[i].code);
	}
	fclose(fp);
	fclose(fp1);
}

//解码
void huffmUncod(huffm data[],int n){
	FILE *fp;
	fp = fopen("uncode.txt","r");
	char ch = fgetc(fp);

	int i = 2*n-1;
	while(ch != EOF){
			
		if(data[i].lc&&data[i].rc){
			if(ch == '0')
				i = data[i].lc;
			else
				i = data[i].rc;
		}
		if(data[i].lc==0 && data[i].rc==0){
			printf("%c ", data[i].c);
			i=2*n-1;
		}
		ch = fgetc(fp);
	}
	fclose(fp);
}

//编码
void huffmcod(huffm data[],int n){
	int start = 0,i = 0,tmp,f;
	char cd[maxN];
	cd [n - 1] = '\0';
	for (i = 1; i <= n; ++i){
		start = n - 1;
		tmp = i,f = data[i].fc;
		while(f){
			//左0 右1
			if(data[f].lc == tmp)
				cd[--start] = '0';
			else
				cd[--start] = '1';
		tmp = f;
		f = data[f].fc;
		}
		strcpy(data[i].code,&cd[start]);
	}
}

//建树
void Creathuff(huffm data[],int n){
	int jie = 2 * n - 1;																																									
	int i,tmp1 = 0,tmp2 = 0;
	for (i = 1; i <= jie; ++i){
		data[i].lc = 0;
		data[i].rc = 0;
		data[i].fc = 0;	
	}

	for (i = n + 1 ; i <= jie; ++i){
		compare(data,i - 1,&tmp1,&tmp2);
		data[tmp1].fc = i;
		data[tmp2].fc = i;
		data[i].lc = tmp1;
		data[i].rc = tmp2; 
		data[i].Weight = data[tmp1].Weight + data[tmp2].Weight;
	}

}

//初始化
void init(huffm data[],int n){
	int i = 0;
	char c;
	fflush(stdin);
	//录入数据
	for (i = 1; i <= n; ++i){
		c = getchar();
		if(c != ' ')
			data[i].c = c;
		else
			i--; 
	}

	for (i = 1; i <= n; ++i)
		scanf("%d",&data[i].Weight);
}

int calwpl(hufm data[],int n){

}

int main(){
	huffm data[maxN];
	int n;
	scanf("%d",&n);
	//初始化
	init(data,n);
	//建树
	Creathuff(data,n);
	//编码
	huffmcod(data,n);
	Writofile(data,n);
	huffmUncod(data,n);
}

//Cannot access memory at address 0xffffffff