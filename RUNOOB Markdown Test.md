打开vscode的markdown预览：  
ctrl+shift+p
Markdown: Open Preview to the Side  


# 一级标题
## 二级标题
### 三级标题


句末加两个空格换行  
或者
<br/>
<br/>


*斜体*  
**粗体**  
***粗斜体***  
~~删除线~~  
</u>下划线</u>


分隔线
***
---


无序列表
* 第一项
* 第二项
* 第三项

+ 第一项
+ 第二项
+ 第三项

- 第一项
- 第二项
- 第三项

有序列表
1. 第一项
2. 第二项
3. 第三项



区块
> 11111
> 22222
>> 3333
>>> 4444


行内代码`printf()`  

多行代码
```c
printf()
printf()
```

超链接 [链接名](https://www.bilibili.com)  
直接显示链接地址 <https://www.runoob.com>

![RUNOOB 图标](https://static.jyshare.com/images/runoob-logo.png)


表格  
https://www.tablesgenerator.com/markdown_tables#
|  表头   | 表头  |
|  :-:   | :-:   |
| 单元格  | 单元格 |
| 单元格  | 单元格 |


如果有latex公式，在开头加
```html
<script type="text/javascript" 
  src="http://cdn.mathjax.org/mathjax/latest/MathJax.js?config=TeX-AMS-MML_HTMLorMML">
</script>
<script type="text/x-mathjax-config">
  MathJax.Hub.Config({ tex2jax: {inlineMath: [['$', '$']]}, messageStyle: "none" });
</script>
```