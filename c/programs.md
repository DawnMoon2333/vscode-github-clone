# 链表 malloc申请空间
```c
struct student {
	int num;
	float score;
	struct student* next;
};

struct student* set_node(int n){
	int time = 1;
	struct student* head, * p, * temp=NULL;
	//若不给temp赋初值会报错：使用了可能未初始化的局部指针变量
	p = (struct student*)malloc(sizeof(struct student));

	//判断是否成功申请空间
	if (p == NULL) {
		printf("out of memory");
		exit(1);
	}

	head = p;

	while (n>0) {
		//赋值
		printf("请输入第%d个结构体的num：", time);
		scanf("%d", &(p->num));

		// 清空输入缓冲区
		while (getchar() != '\n');

		printf("请输入第%d个结构体的score：", time);
		scanf("%f", &(p->score));

		// 清空输入缓冲区
		while (getchar() != '\n');

		//建立下一个结点并把他的值赋给当前结点的next
		temp = p;
		p = (struct student*)malloc(sizeof(struct student));
		if (p == NULL) {
			printf("out of memory");
			exit(1);
		}
		temp->next = p;
		time++; n--;
	}
	temp->next = NULL;
	return head;
}

void print_node(struct student* head) {
	struct student* p = head;
	while (p!= NULL) {
		printf("num=%d,score=%f\n", p->num, p->score);
		p = p->next;
	}
}

int main() {
	int n = 0;
	printf("请输入要建立链表的结点数量：");
	scanf("%d", &n);

	//建立链表
	struct student* head = set_node(n);

	//输出链表
	print_node(head);
}
```
<br/>
<br/>

# 冒泡排序
```c
int i, j, k, a[10] = { 0 };
for (i = 0; i <= 9; i++) {
	printf("请输入第%d个整数：", i + 1);
	scanf("%d", &a[i]);
}
for (j = 0; j <= 9; j++) {
    // 遍历所有数字，除了最后一个
	for (i = 0; i <= 8 - j; i++) {
        //依次对比相邻的两个数字，若前面的大于后面的就交换位置，依次类推
		if (a[i] > a[i + 1]) {
			k = a[i];
			a[i] = a[i + 1];
			a[i + 1] = k;
		}
	}
}
printf("排序后的数组为：");
for (i = 0; i <= 9; i++) {
	printf("%d ", a[i]);
}
```

# malloc建立动态数组
```c
char* input = (char*)malloc(5 * sizeof(char));
free(input);
```
<br/>
<br/>

# 清空输入缓冲区
```c
while (getchar() != '\n');
```
<br/>
<br/>

# 判断素数
```c
int prime(int input) {
	for (int i = 2; i <= sqrt(input); i++) {
		if (input % i == 0) { return 0; }
	}
	return 1;
}

int main() {
	int input;
	while (1) {
		printf("请输入一个正整数：");
		scanf("%d", &input);
		if (input == -1) break;
		if (prime(input) == 1) printf("%d是素数\n", input);
		else printf("%d不是素数\n", input);
	}
	system("pause");		//按任意键继续
}
```
<br/>
<br/>

# 九九乘法表
```c
void print99() {
	int i, j;
	for (i = 1; i <= 9; i++) {
		for (j = 1; j <= i; j++) {
			printf("%dx%d=%d  ", j, i, i * j);
		}
		printf("\n");
	}
}
```
<br/>
<br/>

# 杨辉三角
```c
int main() {
    //在7x7数组中建立杨辉三角
	int num[7][7] = { {0} }, i, j;
	for (i = 0; i <= 6; i++) {
		for (j = 0; j <= i; j++) {
			if (j == 0 || i == j) {
				num[i][j] = 1;
			}
			else {
				num[i][j] = num[i - 1][j - 1] + num[i - 1][j];
			}
		}
	}
	//输出
	for (i = 0; i <= 6; i++) {
		for (j = 0; j <= i; j++) {
			printf("%4d", num[i][j]);
		}
		printf("\n");
	}
}
```
输出
```
   1
   1   1
   1   2   1
   1   3   3   1
   1   4   6   4   1
   1   5  10  10   5   1
   1   6  15  20  15   6   1
```
<br/>
<br/>

# 递归求阶乘
```c
unsigned long long factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
        //0和1的阶乘都是1
    } else {
        return n * factorial(n - 1);
    }
}

void main() {
    int num;
    printf("请输入一个正整数: ");
    scanf("%d", &num);

    if (num < 0) {
        printf("负数无法求阶乘\n");
    } else {
        printf("%d 的阶乘是 %llu\n", num, factorial(num));
    }
}
```

<br/>
<br/>

# 九九乘法表
```c
void print99() {
	int i, j;
	for (i = 1; i <= 9; i++) {
		for (j = 1; j <= i; j++) {
			printf("%dx%d=%d\t", i, j, i * j);
		}
		printf("\n");
	}
}
```

<br/>
<br/>

# 取个位十位百位
```c
void pick(int input) {
	int num1 = input % 10,
		num2 = (input / 10) % 10,
		num3 = (input / 100) % 10,
		num4 = input / 1000;
	printf("%d的个位是%d，十位是%d，百位是%d，千位是%d\n", input, num1, num2, num3, num4);
}
```