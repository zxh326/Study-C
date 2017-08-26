/*
Input
输入数据的第一行是整数K，表示后面有K组测试数据，每组测试数据的第一行有M、N和I三个整数，M、N表示矩阵的行列数（M、N<1000），I表示有几个询问。接下来的M行数据是矩阵的数据，再接下来的I行是询问，每个询问是一个坐标。
Output
输出数据每行是一个整数，对应一次询问，表示该次打击能够烧毁船只的数量。打到边界外输出-1。

*/


#include <stdio.h>
int a[1000][1000]={0};
int f(int m,int n,int i,int j){
    int count=0;
    if(i<0||j<0||i>=m||j>=n) 
        return -1;
    if(a[i][j]==0)
        return 0;
    ++count;
    a[i][j]=2;
    if(i-1>=0&&a[i-1][j]==1)
        count+=f(m,n,i-1,j); 
    if(i+1<m&&a[i+1][j]==1)
        count+=f(m,n,i+1,j); 
    if(j-1>=0&&a[i][j-1]==1)
        count+=f(m,n,i,j-1);
    if(j+1<n&&a[i][j+1]==1)
        count+=f(m,n,i,j+1); 
         
    a[i][j]=1; 
    return count; 
 
}
 
int main() {
    int m,n,k,i,j,I; 
    scanf("%d",&k); 
    while(k--) {
        scanf("%d%d%d",&m,&n,&I); 
        for(i=0;i<m;i++) 
            for(j=0;j<n;j++)
                scanf("%d",&a[i][j]); 
        while(I--) {
            scanf("%d%d",&i,&j);
            printf("%d\n",f(m,n,i,j)); 
        }
    } 
}