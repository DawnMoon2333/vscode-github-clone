# ASCII码
| 字符 | ASCII码 |
|:---:|:---:|
| 0 | 48 |
| 1 | 57 |
| A | 65 |
| Z | 90 |
| a | 97 |
| z | 122 |

<br/>
<br/>

# 转义字符  
| 转义字符 | 含义      |
|:-:|:-:|
| \n       | 换行       |
| \t       | 水平制表符 |
| \\\\       | 反斜杠     |
| \\\'       | 单引号     |
| \\\"       | 双引号     |
| \\\'0'     | 空字符     |

<br/>
<br/>

# printf
printf中format的部分标签属性为：``%[width][.precision]specifier``
| 格式字符 | 含义 |
|:-:|:-:|
| d | 带符号的十进制整数 |
| ld | 带符号的十进制长整型 |
| o | 无符号的八进制整数，开头没有0 |
| x | 无符号的十六进制整数，开头没有0x |
| u | 无符号的十进制整数 |
| f | 六位小数的浮点数 |
| e | 科学计数法 |
| g | 输出f和e中宽度较短的 |
| c | 一个字符 |
| s | 一个字符串 |
| p | 指针 |

<br/>

宽度：输出字符的最小长度，若小于设定的宽度则在左侧以空格补全，若大于设定的宽度，结果 **不会** 被截断。对于f，宽度包括了整数、小数点、小数位数、负号，如“12.400”的宽度为6。

精度：对e和f，精度为小数点后小数位数；对g，为有效位数；若值的精度小于设定的精度则以0补全，若大于设定的精度，结果 **不会** 被截断。  

e.g.
```c
float num=12.4;
printf("%10.3d",num);
//输出：(四个空格)12.400
```

<br/>
<br/>

# scanf

| 类型说明符 | 输入 |
|:---:|:---:|
| %d | 十进制整数 |
| %e,%f,%g | 十进制浮点数 |
| %o | 八进制整数 |
| %x | 十六进制整数 |
| %c | 一个字符 |
| %s | 连续读取字符为字符串直至遇到空格，换行符，制表符 |
| %p | 指针 |
| %u | 无符号的十进制整数 |

<br/>

scanf读取浮点数 **不可以指定精度**  

<br/>
<br/>

# 强制转换类型
```c
int a,b;
(double)a;
//将整型a强制转换为double型
(double)a+b;
//将a转换为double后与整型b相加
(double)(a+b);
//将整型a与整型b相加后转换为double

int* p;
(double *)p;
//将整型指针p转换为double型指针
```

<br/>
<br/>

# 字符串函数
需要使用 ``#include <string.h>``  
```c
puts(字符数组)
//输出一个字符串
char str1[10]={"China"};
puts(str1);
puts("Chi\nna");

gets(字符数组)
//输入一个字符串，可以包含空格，遇到换行符停止，换行符不包括在读入的字符串中，返回值为字符串的首地址
char str2[10]={"0"};
char* p;
p=gets(char);
//从键盘输入一段字符串，储存到str2中，并把字符串的首地址赋值给p

strcat(str1,str2)
//将str2直接追加到str1的尾部，修改了str1，返回值为str1的地址
char dest[] = "Hello, ";
char src[] = "World!";
char *result = strcat(dest, src);

strcpy(str1目标,str2源)
//将str2的值复制给str1，包括\0，str1超过str2的部分不变，但实际上已经不被视为str1的一部分了，因为将str2复制给str1的时候包含了str1尾部的\0。
char str1[10]={"123456"};
char str2[10]={"789"};
strcpy(str1,str2);
原先str1为：  '1' '2' '3' '4'  '5'  '6'  '\0' '\0' '\0' '\0'
原先str1为：  '7' '8' '9' '\0' '\0' '\0' '\0' '\0' '\0' '\0'
复制后str1为：'7' '8' '9' '\0' '5'  '6'  '\0' '\0' '\0' '\0'
strcpy(str1,str2,2)
//将str2中前n个字符复制到str1的前n个字符中，不包括\0。

strcmp(str1,str2)
//从左至右依次对比str1和str2每个元素的ASCII码，若直到'\0'所有字符都相同则返回0，若str1第n个字符的ascii码大于str2则返回一个正整数，反之返回负整数。
char str1[10]={"123"};
char str2[10]={"152"};
char str3[10]={"123"};
if (strcmp(str1,str2)!=0) printf("str1和str2不同");
if (strcmp(str1,str3)==0) printf("str1和str3相同");

strlen(str)
//测量str的长度，包括空格，不包括\0
char str[10]{"A BC"};
printf("%d",strlen(str));
//输出：4

strlwr(str) //将全部字母转换为小写
strupr(str) //将全部字母转换为大写
```

<br/>
<br/>

# 动态内存分配
```c
p = (struct student*)malloc(sizeof(struct student));   
//分配大小是名为student的结构体的空间，并把指向这个空间的首地址强制转换为这个结构体的类型后赋值给p  

free(p)
//释放指针指向的动态分配的空间
```

<br/>
<br/>

# switch语法
```c
switch (input) {
case 1:
	printf("case1");
	break;
case 2:
	printf("case2");
    //如果执行完case2后不break出去就会继续执行case3
case 3:
	printf("case3");
	break;
default:
	printf("default");
}
```