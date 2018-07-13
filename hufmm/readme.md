### 哈夫曼树的构造

> * 录入权值
> * 构造一棵哈夫曼树；
> * 利用该哈夫曼树对文件正文进行编码，将编码保存在文件中；
> * 利用该哈夫曼树将编码结果进行译码，得到的结果保存在文件中；


## 构造哈夫曼树
> * 初始化： 根据给定的n个权值{w1,w2,…wn}构成n棵二叉树的集合F={T1,T2,..,Tn},其中每棵二叉树Ti中只有一个带权wi的根结点,左右子树均空.
> * 找最小树：在F中选择两棵根结点权值最小的树作为左右子树构造一棵新的二叉树,且至新的二叉树的根结点的权值为其左右子树上根结点的权值之和.
> * 删除与加入：在F中删除这两棵树,并将新的二叉树加入F中.
> * 判断：重复前两步（2和3）,直到F中只含有一棵树为止.该树即为哈夫曼树



```c
//比较森林中最小的两个
void compare(huffm data[],int n,int *s1,int *s2);

//写入文件
void Writofile(huffm data[],int n);

//解码
void huffmUncod(huffm data[],int n);

//编码
void huffmcod(huffm data[],int n);

//建树
void Creathuff(huffm data[],int n);

//初始化
void init(huffm data[],int n);

int calwpl(hufm data[],int n);

//Cannot access memory at address 0xffffffff
```
[blog][1]





[1]: http://blog.zxh326.cn
