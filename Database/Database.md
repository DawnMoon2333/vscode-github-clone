<!-- markdownlint-disable -->

# 数据库系统概论

## SQL语句

### 数据定义

| 操作对象 | 创建 | 删除 | 修改 |
| :---: | :---: | :---: | :---: |
| 数据库 | CREATE DATABASE | DROP DATABASE |  |
| 模式 | CREATE SCHEMA | DROP SCHEMA |  |
| 表 | CREATE TABLE | DROP TABLE | ALTER TABLE |
| 视图 | CREATE VIEW | DROP VIEW |  |
| 索引 | CREATE INDEX | DROP INDEX | ALTER INDEX |

> 在MySQL中，`database` 就相当于 `schema`，因此只需要创建 `database` 即可。  

#### 模式

模式是数据库中的一个命名空间，用于存放数据库对象，如表、视图、索引等。    

```sql
CREATE SCHEMA <模式名> [AUTHORIZATION <用户名>];
DROP SCHEMA <模式名> <CASCADE|RESTRICT>;
```

- `<>`表示必填内容，`[]`表示可选内容。   
- `CASCADE`（级联）表示删除模式时，该模式中的所有数据库对象会被全部删除；  
- `RESTRICT`（限制）表示删除模式时，如果模式中有对象（如表、视图等）则不删除。  

eg.
```sql
CREATE SCHEMA mydb;
DROP SCHEMA mydb CASCADE;
```

#### 基本表

```sql
CREATE TABLE <表名> (
    <列名1> <数据类型1> [列级完整性约束条件1],
    <列名2> <数据类型2> [列级完整性约束条件2],
    ...
    [, <表级完整性约束条件>]
);
```

- 数据类型   

| 数据类型 | 说明 |
| :---: | :---: |
| CHAR(n) | 定长为n的字符串 |
| VARCHAR(n) | 长度最大为n的字符串 |
| INT | 长整数，4字节 |
| SMALLINT | 短整数，2字节 |
| BIGINT | 长整数，8字节 |
| FLOAT(n) | 精度至少为n的浮点数 |
| DECIMAL(p, q) | 定点数，p为总位数，q为小数位数 |
| BLOB | 二进制大对象 |
| BOOLEAN | 布尔 |
| DATE | 日期，YYYY-MM-DD |
| TIME | 时间，HH:MM:SS |
| TIMESTAMP | 时间戳 |


- 列级完整性约束条件：  
  - `NOT NULL`：非空；  
  - `UNIQUE`：唯一；
  - `PRIMARY KEY`：主键；  
- 表级完整性约束条件：  
  - `FOREIGN KEY`：外键；   
  - `PRIMARY KEY`：主键（可以有多个，此时只能定义在表级中）；  

eg.
```sql
CREATE TABLE departments (
    dept_id INT AUTO_INCREMENT PRIMARY KEY,
    dept_name VARCHAR(100) NOT NULL UNIQUE,
    PRIMARY KEY (dept_id)
);

CREATE TABLE employees (
    emp_id INT AUTO_INCREMENT PRIMARY KEY,
    emp_name VARCHAR(100) NOT NULL,
    department_id INT,   
    FOREIGN KEY (department_id) REFERENCES departments(dept_id) 
);
```
在该例子中，`employees.department_id` 是 `departments.dept_id` 的外键，即 `employees.department_id` 为 `departments.dept_id` 的引用。  

对基本表的修改：  

```sql
ALTER TABEL <表名>
[ADD [COLUMN] <新列名> <数据类型> [完整性约束条件]]
[ADD <表级完整性约束条件>]
[DROP [COLUMN] <列名> [CASCADE|RESTRICT]]
[DROP CONSTRAINT <完整性约束条件> [CASCADE|RESTRICT]]
[ALTER [COLUMN] <列名> <数据类型> [完整性约束条件]];
```

eg.

```sql
ALTER TABLE employees ADD COLUMN salary DECIMAL(10, 2);
ALTER TABLE employees ADD UNIQUE(emp_id);
ALTER TABLE employees DROP COLUMN salary CASCADE;
ALTER TABLE employees ALTER emp_name VARCHAR(200);
```

对基本表的删除：  

```sql
DROP TABLE <表名> [CASCADE|RESTRICT];
```

#### 索引

为基本表建立索引可以加速对数据的查询。  

```sql
CREATE [UNIQUE] [CLUSTER] INDEX <索引名> ON <表名> (<列名1> [ASC|DESC] [, <列名2> [ASC|DESC], ...]);
```

- `UNIQUE`：索引的每一个索引值只对应唯一的数据记录  
- `CLUSTER`：建立**聚簇索引**，要求表中数据按指定的聚簇属性值的升序/降序排序。  
  - 每个基本表至多创建一个聚簇索引  
  - 聚簇索引比一般索引的查询速度更快，但是插入、删除、更新的速度更慢。  
  - 适用于很少对基表进行增删操作，但是经常查询的情况。  
- 索引建立后会由系统自行维护，但是多个索引会减慢数据库更新的速度。  

eg.

```sql
CREATE INDEX idx_emp_id ON employees(emp_id ASC);
```

可以修改索引的名字：

```sql
ALTER INDEX <索引名> RENAME TO <新索引名>;
```

删除索引：

```sql
DROP INDEX <索引名> ON <表名>;
```

### 数据查询

数据查询使用 `SELECT` 语句进行。  

```sql
SELECT [ALL|DISTINCT] <目标列表达式> [别名] [, <目标列表达式> [别名], ...]
FROM <表名或视图名> [别名] [, <表名或视图名> [别名]]
[WHERE <条件表达式>]
[GROUP BY <列名1> [HAVING <条件表达式>]]
[ORDER BY <列名2> [ASC|DESC]];
```

- `ALL`：默认值，返回查询得到的全部结果；   
- `DISTINCT`：去除结果中重复的行；  
- `<目标列表达式>`：可以是列名、函数、常量等；      
  - 假设表中有`id`，`name`，`age`，则目标列表达式可以为：  

| 目标列表达式  | 描述  |
| :---------------- | :---------------------- |
| `id StuId`        | 查询表中的 `id` 列，在结果中把列重命名为 `StuId`                     |
| `'Year of Birth'` | 查询结果中添加一列，列值为常量 `'Year of Birth'`                   |
| `2025-age BIRTHYEAR` | 计算 2025 与 `age` 列的差值，并将结果列命名为 `BIRTHYEAR`          |
| `*`               | 选择表中的所有列                                                   |
| 标准函数 | 详见下方表格 |

**SQL 标准函数**

| 函数名        | 介绍                                                     |
| :------------ | :------------------------------------------------------- |
| **字符串函数** |                                                          |
| `UPPER(str)`  | 将字符串 `str` 转换为大写。                              |
| `LOWER(str)`  | 将字符串 `str` 转换为小写。                              |
| `CONCAT(str1, str2, ...)` | 连接（拼接）两个或多个字符串。 (部分方言使用 `||` 操作符) |
| `LENGTH(str)` | 返回字符串 `str` 的长度（字符数）。 (部分方言为 `LEN`)    |
| `SUBSTRING(str FROM start [FOR length])` | 从字符串 `str` 中提取子字符串，从 `start` 位置开始，可选长度 `length`。 (语法可能因方言略有不同，如 `SUBSTR(str, start, length)`) |
| `TRIM([LEADING \| TRAILING \| BOTH] [chars FROM] str)` | 从字符串 `str` 的开头、结尾或两端移除指定的字符 `chars`（默认为空格）。 |
| `REPLACE(str, from_str, to_str)` | 在字符串 `str` 中，将所有出现的 `from_str` 替换为 `to_str`。 |
| `POSITION(substring IN str)` | 返回子字符串 `substring` 在字符串 `str` 中首次出现的位置（索引通常从 1 开始）。 |
| **数值函数**   |                                                          |
| `ABS(num)`    | 返回数值 `num` 的绝对值（非负值）。                      |
| `ROUND(num [, decimals])` | 将数值 `num` 四舍五入到指定的小数位数 `decimals`（默认为 0）。 |
| `CEILING(num)` | 返回大于或等于数值 `num` 的最小整数值（向上取整）。 (部分方言为 `CEIL`) |
| `FLOOR(num)`  | 返回小于或等于数值 `num` 的最大整数值（向下取整）。      |
| `MOD(num1, num2)` | 返回 `num1` 除以 `num2` 的余数。 (部分方言使用 `%` 操作符) |
| `POWER(base, exponent)` | 返回 `base` 的 `exponent` 次幂。 (部分方言为 `POW`)    |
| `SQRT(num)`   | 返回非负数值 `num` 的平方根。                            |

- `<条件表达式>`：where子句的常用查询条件：  

| 查询条件 | 谓词 |
| :---: | :---: |
| 比较 | =，>，<，>=，<=，!=，<>（这两个都是不等于），!>，!<，NOT加前面的运算符|
| 确定范围 | [NOT] BETWEEN AND（闭区间） |
| 确定集合 | [NOT] IN，示例：`where Sdept in ('CS', 'MA', 'IS')` |
| 字符匹配 | [NOT] LIKE |
| 空值 | IS [NOT] NULL，**此处`IS`不可以用`=`代替** |
| 多重条件 | AND，OR，NOT |

- 对于字符串匹配，有格式：  
  - `[NOT] LIKE '<匹配串> [ESCAPE '<转义字符>']`  
- 其中匹配串可以使用通配符：  
  - `%`：匹配任意长度的字符串，可以为空；  
  - `_`：匹配单个字符；   
  - `ESCAPE`：转义通配符；    
  - 如，`a_b`为a开头b结尾，中间一个字符；`a%b`为a开头b结尾，中间任意字符；`%a%`为包含a。  
  - 转义字符可以任意定义，如`LIKE 'a\%b' ESCAPE '\'`。

- `ORDER BY`：对查询结果按照指定列名的值进行升序/降序排序。 
  - 空值被视为无穷大。   
- `GROUP BY HAVING`：对查询结果按照指定列名的值进行分组，`HAVING`用于对分组后的结果进行筛选；   
  - `HAVING`中的条件表达式可以使用 **聚集函数**： （**where中不可以用聚集函数！！！**） 

| 函数名    | 介绍  |
| :---------------------: | :-------------------------: |
| `COUNT(*)`              | 计算总行数|
| `COUNT([DISTINCT\|ALL] <列名>)` | 统计某列中**非空行**的行数  |
| `SUM([DISTINCT\|ALL] <列名>)`   | 计算一列**数值型**值的总和  |
| `AVG([DISTINCT\|ALL] <列名>)`   | 计算一列**数值型**值的平均值 |
| `MAX([DISTINCT\|ALL] <列名>)`   | 求一列值中的最大值   |
| `MIN([DISTINCT\|ALL] <列名>)`   | 求一列值中的最小值  | 

> 其中 [DISTINCT\|ALL] 默认为 `ALL`。  

eg.

```sql
SELECT COUNT(DISTINCT No) FROM SC;
SELECT SUM(score) FROM Stu WHERE no='201215121';
SELECT Cno, COUNT(Sno) FROM SC GROUP BY Cno; // 按课程分组，统计每门课程选课人数
SELECT Sno FROM SC GROUP BY Sno HAVING COUNT(*) > 3; // 统计选课超过3门的学生
```

注意：在 `GROUP BY` 之后，聚合函数的操作都将是针对**每个分组**内部进行的，而不是针对整个表。  

### 连接查询（多表查询）

对涉及多个表的拆线呢操作称为 “连接查询”。  

#### （非）等值连接  

连接查询的`where`子句中用于连接两个表的条件称为 **连接条件** 或 **连接谓词** ，有格式：  

`[<表名1>.]<列名1> <比较运算符> [<表名2>.]<列名2>`
`[<表名1>.]<列名1> BETWEEN [<表名2>.]<列名2> AND [<表名2>.]<列名3>  `

其中比较运算符可以为：  

- 等值连接：`=`   
- 非等值连接：`>`，`<`，`>=`，`<=`，`!=`，`<>`  

eg.   

```sql
SELECT Stu.*, SC.* FROM Stu, SC WHERE Stu.Sno = SC.Sno;
```

获得的结果为：

| Stu.Sno | Sname | Sdept | SC.Sno | Cno | Score |
| :---: | :---: | :---: | :---: | :---: | :---: |
| 201215121 | 张三 | CS | 201215121 | 1 | 92 |
|...|...|...|...|...|...|

进行该连接时的过程称为 **嵌套循环连接**，即从 `Stu.Sno` 的第一行开始，从头遍历 `SC.Sno` 的每一行，找到相同的 `Sno` 值，然后将两行合并为结果表中的一行。若在 `SC.Sno` 上建立了索引，则不必遍历整个表，可以根据索引直接找到对应的行。  

#### 自然连接

即在等值连接的基础上，去掉重复的列。

eg.

```sql
SELECT Stu.Sno, Sname, Sdept, Cno, Score
FROM Stu, SC
WHERE Stu.Sno = SC.Sno;
```

注意，由于 `Sno` 在 `Stu` 和 `SC` 中都存在，因此引用时需要加上表名前缀，而其他列在两个表中是唯一的，因此不需要加表名前缀。      

在一条where中可以同时完成连接和选择，如：  

```sql
SELECT Stu.Sno, Sname
FROM Stu, SC
WHERE Stu.Sno = SC.Sno AND Score > 90;
```

#### 自身连接

自身连接是指一个表与自身进行连接。  

假设有Course表，其中Cpno为这门课的先修课： 

| Cno | Cname | Cpno |
| :---: | :---: | :---: |
| 1 | 数据库 | 5 |
| 2 | 数学 |  |
| 3 | 信息系统 | 1 |
| 4 | 操作系统 | 6 |
| 5 | 数据结构 | 7 |
| 6 | 数据处理 |  |
| 7 | C语言 | 6 |

现在要查询每一门课的先修课的先修课的课程号：

```sql
SELECT FIRST.Cno, SECOND.Cpno
FROM Course FIRST, Course SECOND
WHERE FIRST.Cno = SECOND.Cpno;
```

结果为：

| Cno | Cpno |
| :---: | :---: |
| 1 | 7 |
| 3 | 5 |
| 5 | 6 |

#### 外连接

外连接分为 **左外连接** 和 **右外连接**：  
- 左外连接会保留左表中的所有记录，右表中没有匹配的记录会以NULL填充。   
- 右外连接同理。  

语法为：  

```sql
FROM <表名> <LEFT|RIGHT> OUTER JOIN <表名> ON (<连接条件>)
```

eg.

```sql
SELECT Stu.Sno, Sname, Sdept, Cno, Score
FROM Stu LEFT OUTER JOIN SC ON (Stu.Sno = SC.Sno)
```

获得的结果为：

| Stu.Sno | Sname | Sdept | Cno | Score |
| :---: | :---: | :---: | :---: | :---: |
| 201215121 | 张三 | CS | 1 | 92 |
| 201215122 | 李四 | IS | NULL | NULL |
|...|...|...|...|...|...|

#### 多表连接

即进行多次两个表的连接

eg.

```sql
SELECT Stu.Sno, Sname, Cname, Score
FROM Stu, SC, Course
WHERE Stu.Sno = SC.Sno AND SC.Cno = Course.Cno;
```

### 嵌套查询

一个 `SELECT-FROM-WHERE` 为一个 **查询块**，在每个查询块的 `WHERE` 或 `HAVING` 子句的条件中可以嵌套查询块（允许多层嵌套），如：  

```sql
SELECT Sname
FROM Stu
WHERE Sno IN(
    SELECT Sno
    FROM SC
    WHERE Cno = '1'
);
// 查询选了id为1的课的同学的姓名
```

其中，下层查询块是嵌套在上层查询块中的，称上层查询块为 **外层查询** 或 **父查询**，下层查询块为 **内层查询** 或 **子查询**。  

注意：  
- 子查询中SELECT的列必须与父查询中WHERE的列相同。  
- 子查询不允许使用 `ORDER BY`，只能对最外层的查询排列。  

#### 带有 IN 谓词的子查询

- **不相关子查询**  
  - 子查询的条件不依赖于父查询。  
  - 先执行子查询，将子查询的结果作为父查询的条件。      

eg.
对于：

```sql
SELECT Sno, Sname, Sdept
FROM Stu
WHERE Sdept IN(
    SELECT Sdept
    FROM Stu
    WHERE Sname = '张三'
); // 查询与张三同系的学生的学号、姓名和所在系
```

相当于先执行：  

```sql
SELECT Sdept
FROM Stu
WHERE Sname = '张三';
```

结果为 `('CS')`

然后执行：  

```sql
SELECT Sno, Sname, Sdept
FROM Stu
WHERE Sdept IN ('CS')
```

**部分** 嵌套查询可以转换为连接查询，如上方的例子可以转为：  

```sql
SELECT s1.Sno, s1.Sname, s1.Sdept
FROM Stu s1, Stu s2
WHERE s1.Sdept = s2.Sdept AND s2.Sname = '张三';
```

#### 带有比较运算符的子查询

若可以确定子查询的结果只有一行，则可以使用比较运算符进行连接。 

如：  

```sql
SELECT Sname, Sdept
FROM Stu
WHERE Sdept = (
    SELECT Sdept
    FROM Stu
    WHERE Sname = '张三'
); // 查询张三所在系的所有学生的姓名和所在系
```

```sql
SELECT Sno, Cno
FROM SC x
WHERE Score > (
    SELECT AVG(Score)
    FROM SC y
    WHERE x.Cno = y.Cno
); // 查询每个学生选修课程超过平均分的课程号
```

在上方这个例子中，子查询的 WHERE 子句 `x.Cno = y.Cno` 引用了父查询的列 `x.Cno`，这意味着子查询的执行结果**不是固定的**，而是**依赖于外部查询当前正在处理的行**，这样与查询相关的子查询称为 **相关子查询**，整个查询称为 **相关嵌套查询**。  

处理过程：   

- 遍历父查询表的行，假设遍历到某一行的Cno=1；
- 判断当前行是否满足父查询 `where score > (子查询)` 的条件  
  - 进入子查询，使用当前父查询行的值进行子查询中的where条件判断  
  - 即 `where y.Cno = 1`，查询出所有Cno=1的成绩  
  - 使用聚集函数 `AVG()` 计算出平均值，返回给父查询  
  - 判断父查询的条件是否成立
- 如果成立，则将该行加入结果表中；否则继续父表下一行的比较  

#### 带有 ANY/SOME ALL 谓词的子查询

若子查询返回单个值可以用比较运算符，若返回多个值则需要使用 `ANY`（有些系统用`SOME`）或 `ALL`：  

| 谓词 | 含义 |
| :---: | :---: |
| ANY | |
| `>ANY` | 大于子查询结果中的某个值 |
| `<ANY` | 小于子查询结果中的某个值 |
| `>=ANY` | 大于等于子查询结果中的某个值 |
| `<=ANY` | 小于等于子查询结果中的某个值 |
| `=ANY` | 等于子查询结果中的某个值 |
| `!=ANY` | 不等于子查询结果中的某个值 |
| ALL | |
| `>ALL` | 大于子查询结果中的所有值 |
| `<ALL` | 小于子查询结果中的所有值 |
| `>=ALL` | 大于等于子查询结果中的所有值 |
| `<=ALL` | 小于等于子查询结果中的所有值 |
| `=ALL` | 等于子查询结果中的所有值（无意义） |
| `!=ALL` | 不等于子查询结果中的所有值 |

eg.

```sql
SELECT Sname, Sage
FROM Stu
WHERE Sage < ANY (
  SELECT Sage
  FROM Stu
  WHERE Sdept='CS')
AND Sdept!='CS';
// 查询非计科系中比计科系任意一个学生年龄小的学生的姓名和年龄
// 也可以等价于小于最小值
```

#### 带有 EXISTS 谓词的子查询

`EXISTS`，即存在量词 $\exist$，用于判断子查询的结果集中是否存在满足属于、子集、非空等条件，最终返回逻辑值 `true` 或 `false`。  

由 EXISTS 引出的子查询的目标列表达式无实际意义，因此常用 `*`表示。  

`NOT EXISTS` 同理，若结果为空集则返回 `true`，否则返回 `false`。

eg.

```sql
SELECT Sname
FROM Stu
WHERE EXISTS (
  SELECT *
  FROM SC
  WHERE Sno = Stu.Sno AND Cno = '1'
); // 查询选修了1号课程的学生姓名
```

处理过程：  

- 遍历父查询表的行，假设遍历到某一行的Sno=114514；
- 判断使用当前行进行子查询的结果是否为空    
  - 进入子查询，使用当前父查询行的值进行子查询中的where条件判断  
  - 即 `where Sno=114514`，查询出所有学生id为114514的成绩  
  - 还有AND条件：且选修了1号课程
- 如果子查询结果非空，则返回true，把当前行的Sname加入结果表，否则返回false，跳过当前Sname  

这个查询也可以等价为不相关IN查询：  

```sql
SELECT Sname
FROM Stu
WHERE Sno IN (
  SELECT Sno 
  FROM SC 
  WHERE Cno = '1');
```

注意：  
- 部分(NOT)EXISTS查询无法用其他形式的子查询等价替换  
- 所有其他形式的子查询都可以用(NOT)EXISTS替换  
- EXISTS子查询只关心内层查询是否有返回值，而不关心返回值的内容  

SQL语言中没有全称量词 $\forall$，但是可以转换为：   
$$\forall xP(x) \equiv \neg \exist x(\neg P(x))$$

即涉及到全称量词的查询可以转换为两层NOT EXISTS的子查询，如：  

```sql
SELECT Sname
FROM Stu
WHERE NOT EXISTS (
  SELECT *
  FROM Course
  WHERE NOT EXISTS (
    SELECT *
    FROM SC
    WHERE Sno = Stu.Sno 
      AND Cno = Course.Cno
  )
);
// 查询选了所有课的学生
```

查询过程：  

1.  **外层查询 (针对每个 `Stu`)**:
    *   从 `Stu` 表中选出一个学生，比如学号为 `S1`。

2.  **外层 `NOT EXISTS` (检查“是否存在未选的课”)**:
    *   开始执行其内部的子查询（中间层查询），目标是看这个子查询会不会返回 *任何* 结果。
    *   如果中间层子查询 *没有返回任何行*，则外层的 `NOT EXISTS` 条件为 `TRUE`，学生 `S1` 被选中。
    *   如果中间层子查询 *返回了至少一行*，则外层的 `NOT EXISTS` 条件为 `FALSE`，学生 `S1` 不被选中。

3.  **中间层查询 (针对学生 `S1` 和所有 `Course`)**:
    *   从 `Course` 表中选出一门课程，比如课程号为 `C1`。
    *   **内层 `NOT EXISTS` (检查“是否 S1 *没有* 选 C1”)**:
        *   开始执行其内部的子查询（最内层查询）。
        *   **最内层查询 (检查 `SC` 表)**: 在 `SC` 表中查找是否存在 `Sno = S1` 且 `Cno = C1` 的记录。
            *   **如果找到记录**: 说明 `S1` 选了 `C1`。最内层查询返回行，内层 `NOT EXISTS` 为 `FALSE`。
            *   **如果没找到记录**: 说明 `S1` *没* 选 `C1`。最内层查询不返回行，内层 `NOT EXISTS` 为 `TRUE`。
    *   **中间层 `WHERE` 条件**: 如果内层 `NOT EXISTS` 为 `TRUE`（即 `S1` 没选 `C1`），那么课程 `C1` 满足中间层查询的 `WHERE` 条件。
    *   **中间层结果**: 这个查询会收集所有 `S1` *没有* 选修的课程。如果 `S1` 选了所有课，这个查询返回空集（零行）；如果 `S1` 缺了课，这个查询会返回那些缺了的课程。

4.  **回到外层 `NOT EXISTS`**:
    *   现在知道了中间层查询的结果（对于学生 `S1`，他没选的课程列表）。
    *   如果这个列表是空的（中间层返回零行），说明 `S1` 没有“没选的课”，即选了所有课。外层 `NOT EXISTS` 为 `TRUE`，选中 `S1`。
    *   如果这个列表非空（中间层返回至少一行），说明 `S1` 至少缺了一门课。外层 `NOT EXISTS` 为 `FALSE`，不选 `S1`。

5.  **循环**: 重复步骤 1-4，对 `Stu` 表中的下一个学生进行判断，直到所有学生都被检查完毕。


```sql
SELECT Cname
FROM Course
WHERE NOT EXISTS (
  SELECT *
  FROM Stu
  WHERE NOT EXISTS (
    SELECT *
    FROM SC
    WHERE Sno=Stu.Sno
      AND Cno=Course.Cno
  )
); // 查询所有学生都选修的课程
```

**问题的逻辑转换**

*   **原始目标 (使用全称量词):** 找出所有课程 `c`，对于 *所有* 学生 `s`，`s` 都选修了 `c`。
    *   $\{ c \in Course \mid \forall s \in Stu, \text{ s 选修了 c} \}$
*   **第一次转换 (利用否定):** 找出所有课程 `c`，*不存在* 任何一个学生 `s`，使得 `s` *没有* 选修 `c`。
    *   $\{ c \in Course \mid \neg \exists s \in Stu, \neg (\text{s 选修了 c}) \}$
*   **`s 选修了 c` 的含义:** 在 `SC` 表中存在记录 `(s.Sno, c.Cno)`。
*   **`s 没有选修 c` 的含义:** 在 `SC` 表中不存在记录 `(s.Sno, c.Cno)`。
    *   $\neg (\text{s 选修了 c}) \equiv \neg \exists sc \in SC (sc.Sno = s.Sno \land sc.Cno = c.Cno)$

#### 使用 EXISTS 实现逻辑蕴涵

eg. 查询至少选修了学生114514选修的全部课程的学生号码

转为逻辑蕴涵：查询学号为x的学生，对所有课程y，只要114514选修了y，则x也选修了y，即：  

$$(\forall y) p \rightarrow q$$

等价为不存在课程y，满足学生114514选修了y，但是x没有选，即：  

$$\neg \exist y (p \land \neg q) $$

```sql
SELECT DISTINCT Sno
FROM SC SCX
WHERE NOT EXISTS (
  SELECT *
  FROM SC SCY
  WHERE SCY.Sno = '114514'
    AND NOT EXISTS (
      SELECT *
      FROM SC SCZ
      WHERE SCZ.Sno = SCX.Sno
        AND SCZ.Cno = SCY.Cno
    )
);
```

### 集合查询

参加集合查询的各查询结果的**列数和数据类型**必须相同。  

#### 并 UNION

选择计科系和年龄不大于19岁的学生  

```sql
SELECT *
FROM Stu
WHERE Sdept='CS'
UNION
SELECT *
FROM Stu
WHERE Sage<=19;
```

#### 交 INTERSECT

查询选修了1和2号课程的学生学号

```sql
SELECT Sno
FROM SC
WHERE Cno='1'
INTERSECT
SELECT Sno
FROM SC
WHERE Cno='2';
```

#### 差 EXCEPT

查询计科系年龄大于19岁的学生

```sql
SELECT *
FROM Stu
WHERE Sdept='CS'
EXCEPT
SELECT *
FROM Stu
WHERE Sage<=19;
```

### 数据更新

#### 插入

语法：`INSERT INTO 表名 [(列名1, 列名2, ...)] VALUES (值1, 值2, ...);`

```sql
INSERT INTO Stu (Sno, Sname, Ssex, Sage, Sdept)
VALUES ('20230001', '张三', '男', 20, 'IS');
```

```sql
INSERT INTO Dept_age(Sdept, Savg_Age)
SELECT Sdept, AVG(Sage)
FROM Stu
GROUP BY Sdept;
```

#### 修改

语法：`UPDATE 表名 SET 列名1=值1, 列名2=值2, ... [WHERE 条件];`

```sql
UPDATE Stu
SET Sage = 21
WHERE Sno = '20230001';
```

```sql
UPDATE SC
SET Grade=0
WHERE Sno IN (
  SELECT Sno
  FROM Stu
  WHERE Sdept='CS'
);
```

#### 删除

语法： `DELETE FROM 表名 [WHERE 条件];`  

```sql
DELETE FROM Stu
WHERE Sno = '20230001';
```

```sql
DELETE FROM SC
WHERE Sno IN (
  SELECT Sno
  FROM Stu
  WHERE Sdept='CS'
);
```

## 数据库安全性

省略

## 数据库完整性

省略

## 关系数据理论

### 问题的提出

针对一个具体的问题，如何设计一个合理的数据模式

任一关系模式由五部分组成，即一个五元组：$R(U, D, DOM, F)$  

- $R$：关系名  
- $U$：组成该关系的属性名集合  
- $D$：属性组$U$中属性所来自的域  
- $DOM$：属性向域的映象集合  
- $F$：属性间数据的依赖关系集合   

一个好的模式：不会发生插入、删除、更新异常，数据冗余小

### 规范化

规范化的目标主要是消除数据冗余、避免插入异常、删除异常和更新异常。

#### 复习：码、候选码、主码

假设有关系 `学生（身份证号，学号，年龄，性别）`

则码为：  
- 身份证号、学号、（身份证号、学号）、（身份证号、年龄）、（身份证号、性别）、（学号、年龄）、（学号、性别）、（身份证号、学号、年龄）、（身份证号、学号、性别）、（身份证号、学号、年龄、性别）

候选码为：  
- 身份证号、学号

主码为：  
- 身份证号，或学号  

#### 函数依赖

- 函数依赖  
  - 在一个关系模式 $R(U)$ 中，设 $X$ 和 $Y$ 是属性集 $U$ 的子集 ($X, Y \subseteq U$)，如果属性集 $X$ 的值可以**唯一地**确定属性集 $Y$ 的值，即知道了 $X$ 的值，就**能且只能知道一个** $Y$ 的值，则称 $Y$ 函数依赖于 $X$，或 $X$ 函数确定 $Y$，记为 $X \rightarrow Y$。  
  - 如，学号可以唯一确定学生的姓名，即 $Sno \rightarrow Sname$。  
- 平凡的函数依赖  
  - 对于函数依赖 $X \rightarrow Y$，如果 $Y \subseteq X$（即 $Y$ 是 $X$ 的子集或等于 $X$），即依赖的右侧属性（$Y$）本来就包含在左侧属性（$X$）中，那么这个函数依赖称为平凡的函数依赖。  
  - 平凡函数依赖永远成立，一般**不考虑**。  
- 非平凡的函数依赖  
  - 对于函数依赖 $X \rightarrow Y$，如果 $Y \not\subseteq X$（即 $Y$ 不是 $X$ 的子集，或者说 $Y$ 中**至少有一个不在** $X$ 中的属性），那么这个函数依赖称为非平凡的函数依赖。  
  - 如，$Sno \rightarrow Sname$ ， $\{Sno, Sname\} \rightarrow \{Sname, Sage\}$。  
- 完全函数依赖  
  - 对于函数依赖 $X \rightarrow Y$，如果对于 $X$ 的任意一个真子集 $X'$，都有 $X' \not\rightarrow Y$，即要确定 $Y$ 的值，必须知道 $X$ 中所有属性的值，缺少 $X$ 中的任何一个属性都无法唯一确定 $Y$，则称 $Y$ 完全函数依赖于 $X$，记作 $X \xrightarrow{F} Y$。  
  - 如，$\{Sno, Cno\} \xrightarrow{F} Grade$
- 部分函数依赖  
  - 对于函数依赖 $X \rightarrow Y$，如果**存在** $X$ 的真子集 $X'$，使得 $X' \rightarrow Y$，即确定 $Y$ 的值，并不需要知道 $X$ 中所有的属性值，只需要知道 $X$ 的一部分（即真子集）就足够了（ $X$ 中有些属性对于确定 $Y$ 是“冗余”的），则称 $Y$ 部分函数依赖于 $X$，记作 $X \xrightarrow{P} Y$。 
  - 如，$\{订单号, 产品号\} \xrightarrow{P} 客户名称 $，只需要知道订单号或产品号就可以确定客户名称，不需要知道所有属性。
- 传递函数依赖  
  - 在 $R(U)$ 中，若 $X \rightarrow Y, Y \not\rightarrow X, Y \rightarrow Z, Z \not\subseteq Y$，则称 $Z$ 对 $X$ 传递函数依赖，记为 $X \xrightarrow{传递} Z$。  
  - 如，$Sno \rightarrow Sdept, Sdept \rightarrow Sloc, 则 Sno \xrightarrow{传递} Sloc$

#### 范式

关系数据库中满足不同程度要求的关系模式称为不同的范式。  

各个范式之间的关系为：  

$5NF \subset 4NF \subset BCNF \subset 3NF \subset 2NF \subset 1NF$

规范化：低一级的范式的关系模式通过模式分解转换为若干个高一级范式的关系模式的集合。  

- **1NF 第一范式** 
  - 关系模式 $R$ 中的所有属性域都是不可再分的，即每个单元格只能包含一个单一的值  
- **2NF 第二范式**   
  - $R \in 1NF$，且所有非主属性都完全函数依赖于候选码  
  - 主属性：候选码中的属性；非主属性：候选码之外的属性  
  - 比如，$R(Sno, Cno, Grade)$，$Sno$ 和 $Cno$ 是候选码，$Grade$ 完全函数依赖于 $Sno$ 和 $Cno$，所以 $R$ 是 $2NF$。  
  - 违反 2NF 的例子：关系 `订单详情(订单号, 产品号, 产品名称, 数量)`，候选键是 `{订单号, 产品号}`。`产品名称` 是非主属性。
    - 因为 `产品名称` 依赖于候选键 `{订单号, 产品号}` 的真子集 `{产品号}`，所以存在部分依赖。该关系不满足 2NF。
  - 如何达到 2NF：进行**分解**，将导致部分依赖的属性分离出去。
    - `订单项(订单号, 产品号, 数量)` (候选键: `{订单号, 产品号}`)
    - `产品(产品号, 产品名称)` (候选键: `{产品号}`)
- **3NF 第三范式**
  - 关系模式 $R \in 2NF$，并且 $R$ 中没有非主属性对候选码存在 **传递函数依赖**。
  - 例子（满足 3NF）：
    -   `R(Sno, Cno, Grade)` (来自 2NF 例子) 是 3NF，因为没有非主属性 (`Grade`) 依赖于其他非主属性（这里也没有其他非主属性）。
    - 分解后的 `订单项(订单号, 产品号, 数量)` 和 `产品(产品号, 产品名称)` 通常也是 3NF。
  - 违反 3NF 的例子： 关系 `SL(Sno, Sdept, Sloc)`，候选键是 `{Sno}`。`Sdept` 和 `Sloc` 是非主属性。
    - 存在 `Sno` $\rightarrow$ `Sdept` 和 `Sdept` $\rightarrow$ `Sloc` 的传递依赖，因此，`Sdept` 和 `Sloc` 对 `Sno` 存在传递依赖。该关系不满足 3NF。
  - 如何达到 3NF：进行**分解**，将导致传递依赖的属性分离出去。
    - `SD(Sno, Sdept)` (候选键: `{Sno}`)
    - `DL(Sdept, Sloc)` (候选键: `{Sdept}`)

- **BCNF (BC范式)**，第三范式的特殊情况
  - 关系模式 $R \in 1NF$，且对于关系模式 $R$ 中的每一个非平凡的函数依赖 $X \rightarrow Y$，$X$ 都必须是 $R$ 的一个超键（包含候选键的属性集）。
  - 假设有关系 `R(仓库号，存储物品号，管理员号，数量)`，其有以下关系：
    - `(仓库号，存储物品号)——>(管理员号，数量)`
    - `(管理员号，存储物品号)——>(仓库号，数量)`
  - 它满足3NF，但是有以下关系存在：  
    - `(仓库号)——>(管理员号)`
    - `(管理员号)——>(仓库号)`
  - 即存在关键字段决定关键字段的情况，导致不满足BCNF。
  - 处理方案：分解为  
    - `R1(仓库号, 管理员号)`  
    - `R2(仓库号, 存储物品号, 数量)`

#### 多值依赖

