#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define   maxN 20
typedef struct {
	char c;   //字符
	int Weight;   //权重
	int lc;    //左孩子
	int rc;    //右孩子
	int fc;   //父节点
	char code[maxN];  //编码cnm
}huffm;
//写入文件
void WritoFile(huffm data[],int n){
	FILE *fp;
	int i = 1;
	fp = fopen("code.txt","w+");
	printf("编码结果 ：\n");
	for (i = 1; i <= n; ++i){
		printf("%c----->%s\n",data[i].c,data[i].code);
		fprintf(fp,"%s",data[i].code);
	}
	printf("编码 ：");
	for (i = 1; i <= n; ++i)
		printf("%s", data[i].code);
	printf("\n");
	fclose(fp);
}
//解码
void HuffmUncod(huffm data[],int n){
	FILE *fp;
	FILE *fp1;
	fp = fopen("code.txt","r");
	fp1 = fopen("uncode.txt","w+");	

	int i = 2*n-1;
	printf("译码结果： ");
	char ch = fgetc(fp);
	while(ch != EOF){
			
		if(data[i].lc&&data[i].rc){
			if(ch == '0')
				i = data[i].lc;
			else
				i = data[i].rc;
		}
		if(data[i].lc==0 && data[i].rc==0){
			fprintf(fp1,"%c", data[i].c);
			printf("%c ", data[i].c);
			i=2*n-1;
		}
		ch = fgetc(fp);
	}
	fclose(fp);
	fclose(fp1);
}
//编码
void Huffmcod(huffm data[],int n){
	int start = 0,i = 0,tmp,f;
	char cd[maxN];
	cd [n - 1] = '\0';
	for (i = 1; i <= n; ++i){
		start = n - 1;
		tmp = i;f = data[i].fc;
		while(f){
			//左0 右1
			--start;
			if(data[f].lc == tmp)
				cd[start] = '0';
			else
				cd[start] = '1';
			tmp = f;
			f = data[f].fc;
		}
		printf("%s\n", &cd[start]);
		strcpy(data[i].code,&cd[start]);
	}
}
//比较森林中最小的两个
void compare(huffm data[],int n,int *s1,int *s2){
	int i;
	for (i = 1; i <= n && data[i].fc != 0; ++i);
	
	*s1 = i;
	
	for (i = 1; i <= n; ++i)
      	if(data[i].fc == 0 && data[i].Weight < data[*s1].Weight)
          	*s1 = i;
   
    for(i = 1; i <= n; ++i)
        if(data[i].fc==0 && i!=*s1)  
        	break;  

    *s2 = i;            
   	for(i = 1; i <= n; ++i)
        if(data[i].fc == 0 && i != *s1 && data[i].Weight < data[*s2].Weight) 
            *s2 = i;
}
//建树
void Creathuff(huffm data[],int n){
	int jie;
	jie = 2 * n - 1;																																									
	int i,tmp1 = 0,tmp2 = 0;
	for (i = 1; i <= jie; ++i)
		data[i].lc = data[i].rc  = data[i].fc = 0;

	for (i = n + 1; i <= jie; ++i){
		compare(data,i - 1,&tmp1,&tmp2);
//		printf("%d %d \n", tmp1,tmp2);
		data[tmp1].fc = i;
		data[tmp2].fc = i;
		data[i].lc = tmp1;
		data[i].rc = tmp2; 		
		data[i].Weight = data[tmp1].Weight + data[tmp2].Weight;
	}
}
//初始化
int init(huffm data[]){
	int i = 0;
	char ch;
	fflush(stdin);
	//录入数据
	FILE *fp;
	fp=fopen("chars.txt","r");
	printf("需要编码的字符为 ： ");
	ch = fgetc(fp);
	for (i = 1; ch!=EOF; ++i){
		data[i].c = ch;
		printf("%c ", ch);
		ch = fgetc(fp);
	}
	fclose(fp);
	printf("\n");
	printf("分别输入他们的权重 ：\n");
	int n = i - 1;
	for (i = 1; i <= n; ++i)
		scanf("%d",&data[i].Weight);
	return n ;
}
int main(){
	huffm data[maxN];
	int n;
	//初始化
	n = init(data);
	//建树
	Creathuff(data,n);
	//编码
	Huffmcod(data,n);

	//写入文件
	WritoFile(data,n);
	system("pause");
	//解码
	HuffmUncod(data,n);
}