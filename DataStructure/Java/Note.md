# 1

# 第二章 基本数据类型、数组、枚举

## 标识符

命名规则：  
- 字母、下划线_、美元符号`$`，阿拉伯数字，长度不限  
- 第一个字符非数字  
- 不能是关键字、true、false、null  
- 区分大小写  

## 基本数据类型

### 逻辑类型：boolean  

可取值：true、false  
```java
boolean condition = true, x = false;
```

### 整数类型：byte、short、int、long

int：4个字节，范围$-2^{31}\sim2^{31}-1$  
```java
int dec = 114; // 十进制
int bin = 0b1110010; // 二进制使用0b前缀
int oct = 0162; // 八进制使用0前缀
int dex = 0x72; // 十六进制使用0x前缀
```

byte：1个字节，范围$-2^{7}\sim2^{7}-1$  
```java
byte x = -12;
```

short：2个字节，范围$-2^{15}\sim2^{15}-1$  
```java
short x = 12;
```

long：8个字节，范围$-2^{63}\sim2^{63}-1$，需要加后缀L  
```java
long width = 12L;
```
若不加L，编译器会默认把一串数字认为是int类型，若其超过int的表示范围就会报错   

### 字符类型：char  

java使用unicode编码，兼容ascii码。 
char类型分配2个字节，范围$0\sim65525$，在内存中存储的是字符对应的unicode（utf）码 
```java
char ch1 = 'A', ch2 = '国', ch3 = '\\', ch4 = 'の';
```

可以用int显式转换char类型以查看字符对应的unicode码：  
```java
public class
```

### 浮点类型：float、double  

