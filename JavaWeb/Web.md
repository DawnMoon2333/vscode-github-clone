# Web标准  

组成部分：  

- HTML：结构  
  - 页面元素和内容  
- CSS：表现  
  - 元素的外观、位置等  
- JavaScript：行为      
  - 交互效果    

# HTML

文件格式：  

```HTML
<!DOCTYPE html>  // 声明文档类型为html
<html lang="zh-CN">  // 声明文档语言为简体中文
<head>  // 头部
    <meta charset="UTF-8">  // 指定字符集
    <title>这是一个测试文件</title>
</head>
<body>  // 主体
    <h1>  // 一级标题
        Hello World
    </h1>
</body>
</html>
```

浏览器对html文件 **从上到下逐行解析**  

每个html元素都有四个属性：  

- id：唯一标识符  
- class：类名  
- title：鼠标悬停时显示的文本  
- style：行内样式  



# Head

## title

## meta

## base

## link

## style

## script

# Body

## 全局属性

适用于所有html元素的属性

| 属性名   | 作用 |
|---------|------|
| `id` | 元素的唯一标识符 |
| `class` | 为元素指定一个或多个 CSS 类名 |
| `style` | 行内样式定义 |
| `title` | 鼠标悬停时显示的提示文本 |
| `hidden` | 隐藏元素 |

## 标题

```HTML
<h1>一级标题</h1>
<h2>二级标题</h2>
<h3>三级标题</h3>
<h4>四级标题</h4>
<h5>五级标题</h5>
<h6>六级标题</h6>
```

## 超链接

<a href="https://www.baidu.com">百度</a>

```HTML
<a href="https://www.baidu.com">百度</a>
```

- `herf`：指向的地址    
- `target` 为打开方式   
  - `_blank`：新窗口打开    
  - `_self`：本窗口打开（默认值）  

与 `锚点` 结合，可以实现页面内跳转    

```html
<h2 id="test">这是一个标题</h2>
<a href="#test">跳转到 test</a>
<a href="/path/to/htmlfile/index.html#test">跳转到 test</a>
```

在html中 `href` 的值可以为绝对路径或相对路径：  

| **路径类型** | **示例** | **解释** |
|:-----------:|:--------:|:--------:|
| **绝对路径** | `https://example.com/page.html` | 指向外部网站或完整 URL |
| **同级目录** | `index.html` | 访问当前目录下的 `index.html` |
| **子目录** | `pages/contact.html` | 访问 `pages` 目录下的 `contact.html` |
| **上级目录** | `../index.html` | 访问上一级目录中的 `index.html` |
| **根目录** | `/products/list.html` | 从网站根目录访问 `products/list.html` |

## 图片 视频 音频

<img src="http://i.fxgpt.site/i/2025/03/04/qy2z62.png" alt="测试图片" width=100px/>

```HTML
<img src="http://i.fxgpt.site/i/2025/03/04/qy2z62.png" alt="测试图片" width=100px/>
```

- `src`：图片地址   
- `alt`：对图像的文本描述     
  - 在图片加载失败时显示    
- `width`：宽度  
- `height`：高度  
  - 宽度和高度建议仅设置一个，另一个会被自动等比例缩放，若同时设置宽度和高度则会导致白边  
  - 单位：px，%（相对于父元素的百分比）

```html
<video src="http://i.fxgpt.site/i/2025/02/18/ndy2zr.mp4" controls></video>
```

- `src`：视频地址   
- `controls`：显示控制条  
- `autoplay`：自动播放  
- `width`：宽度  
- `height`：高度      

```html
<audio src="http://i.fxgpt.site/i/2025/02/18/ndy2zr.mp3" controls></audio>
```

- `src`：音频地址   
- `controls`：显示控制条  

## 列表

### 无序列表 

<ul>
    <li>列表项1</li>
    <li>列表项2</li>
    <li>列表项3</li>
</ul>

```HTML
<ul>
    <li>列表项1</li>
    <li>列表项2</li>
    <li>列表项3</li>
</ul>
```

- `ul`：无序列表，`ol`：有序列表   
- `li`：列表项  

### 有序列表

<ol>
    <li>列表项1</li>
    <li>列表项2</li>
    <li>列表项3</li>
</ol>

```HTML
<ol>
    <li>列表项1</li>
    <li>列表项2</li>
    <li>列表项3</li>
</ol>
```

- `ol`：有序列表   
- `li`：列表项  
- `type`：设置列表项的序号类型，如 `1`、`A`、`a`、`I`、`i` 等  
- `start`：设置列表项的起始序号  

### 定义列表

<dl>
    <dt>列表项1</dt>
    <dd>列表项1的描述</dd>
    <dt>列表项2</dt>
    <dd>列表项2的描述1</dd>
    <dd>列表项2的描述2</dd>
</dl>

```HTML
<dl>
    <dt>列表项1</dt>
    <dd>列表项1的描述</dd>
    <dt>列表项2</dt>
    <dd>列表项2的描述1</dd>
    <dd>列表项2的描述2</dd>
</dl>
```

- `dl`：定义列表   
- `dt`：列表项

## 段落

<p>这是一个段落</p>

```HTML
<p>这是一个段落</p>
```

## 注释

```HTML
<!-- 这是一个注释 -->
```

## 文本格式化

<font face="Arial" size="4" color="red">Red Text</font>
<b>加粗</b>
<i>斜体</i>
<u>下划线</u>
<s>删除线</s>
文字的<sup>上标</sup>
文字的<sub>下标</sub>
<hr>  <!-- 水平线 -->

```HTML
<font face="Arial" size="4" color="red">Example here</font>
<b>加粗</b>
<i>斜体</i>
<u>下划线</u>
<s>删除线</s>
<sup>上标</sup>
<sub>下标</sub>
<hr>  <!-- 水平线 -->
```

## 特殊符号

| 符号 | HTML实体   |
|------|------------|
| <    | \&lt;      |
| >    | \&gt;      |
| &    | \&amp;     |
| "    | \&quot;    |
| '    | \&apos;    |
| ©    | \&copy;    |
| ±    | \&plusmn;  |
| ×    | \&times;   |
| ÷    | \&divide;  |
| ≠    | \&ne;      |
| ≤    | \&le;      |
| ≥    | \&ge;      |
| ∞    | \&infin;   |
| π    | \&pi;      |
| ≈    | \&asymp;   |
| ≠    | \&ne;      |
| ≠    | \&ne;      |

## div 和 span

`<div>` 是一个 **块级元素**，它作为一种容器，本身不显示内容，而是用于 **组织内容**  

每个 `<div>` 会独占一行，在末尾自动换行     

<div>
    <h4>这是一个标题</h4>
    <p>这是一个段落</p>
</div>

```HTML
<div>
    <h4>这是一个标题</h4>
    <p>这是一个段落</p>
</div>
```

- `style`：用于设置元素的样式   
  - `color`：文字颜色   
  - `background-color`：背景颜色  
- `class`：用于设置元素的类名，用于在 CSS 中设置样式    
- `align`：用于设置元素的对齐方式  
  - `left`：左对齐  
  - `center`：居中对齐  
  - `right`：右对齐   

`<span>` 是一个 **行内元素**，与 `<div>` 类似，是一种容器  

<span>
    <h4>这是一个标题</h4>
    <p>这是一个段落</p>
</span>

```HTML
<span>
    <h4>这是一个标题</h4>
    <p>这是一个段落</p>
</span>
```

## 表格

<table>
  <caption>
  <!-- 标题 -->
    这里是标题
  </caption>
  <!-- tr是一行，即table row -->
  <tr>
    <!-- th是表头，即table header -->
    <th>姓名</th>
    <th>年龄</th>
    <th>城市</th>
  </tr>
  <tr>
    <!-- td是一个单元格，即table data -->
    <td>张三</td>
    <td>30</td>
    <td>北京</td>
  </tr>
  <tr>
    <td>李四</td>
    <td>25</td>
    <td>上海</td>
  </tr>
  <tr>
    <td>王五</td>
    <td>35</td>
    <td>广州</td>
  </tr>
  <tr>
      <td>赵六</td>
      <td>28</td>
      <td>深圳</td>
  </tr>
</table>

```html
<table>
  <caption>
  <!-- 标题 -->
    这里是标题
  </caption>
  <!-- tr是一行，即table row -->
  <tr>
    <!-- th是表头，即table header -->
    <th>姓名</th>
    <th>年龄</th>
    <th>城市</th>
  </tr>
  <tr>
    <!-- td是一个单元格，即table data -->
    <td>张三</td>
    <td>30</td>
    <td>北京</td>
  </tr>
  <tr>
    <td>李四</td>
    <td>25</td>
    <td>上海</td>
  </tr>
  <tr>
    <td>王五</td>
    <td>35</td>
    <td>广州</td>
  </tr>
  <tr>
      <td>赵六</td>
      <td>28</td>
      <td>深圳</td>
  </tr>
</table>
```

### 基本属性

- `align`, `valign`：表格相对周围元素的水平、垂直对齐方式  
  - left, left, right  
- `bgcolor`：背景颜色   
  - 取值参考 [颜色表示形式](#颜色的表示形式)  
- `border`：边框宽度  
- `cellpadding`：单元格内容与单元格边框之间的距离   
- `cellspacing`：单元格之间的距离   
- `height`, `width`：表格的高度和宽度   

### 单元格合并 跨行跨列

表格从上向下，从左向右解析，使用 `colspan` 和 `rowspan` 可以实现合并单元格，解析时若该单元格被其他合并的单元格占用会跳过该单元格的解析：  

<table>
  <tr>
    <td colspan ="2">单元格占两列</td>
    <td width="90">&nbsp;</td>
    <!-- 三个单元格已经被解析完了 -->
  </tr>
  <tr>
    <td width="75">&nbsp;</td>
    <td width="90">&nbsp;</td>
    <td rowspan="2"> 单元格占两行</td>
  </tr>
  <tr>
    <td>&nbsp;</td>
    <td>&nbsp;</td>
    <!-- 接下来这个单元格不解析 -->
  </tr>
</table>

```html
<table>
  <tr>
    <td colspan ="2">单元格占两列</td>
    <td width="90">&nbsp;</td>
    <!-- 使用 &nbsp; 创建一个空白实体引用，防止单元格被跳过 -->
    <!-- 三个单元格已经被解析完了 -->
  </tr>
  <tr>
    <td width="75">&nbsp;</td>
    <td width="90">&nbsp;</td>
    <td rowspan="2"> 单元格占两行</td>
  </tr>
  <tr>
    <td>&nbsp;</td>
    <td>&nbsp;</td>
    <!-- 接下来这个单元格不解析 -->
  </tr>
</table>
```

### 单元格分组

- 行分组  
  - `<caption>`：表格标题
  - `<thead>`, `<tfoot>`：表头、表尾   
    - 仅可出现一次
  - `<tbody>`：表的主体   
    - 可以出现多次，用于将表格分为多个部分    

<table>
  <caption>企业员工薪水绩效表</caption>
  <thead>
    <tr>
      <th>员工编号</th>
      <th>员工岗位</th>
      <th>基本工资</th>
      <th>本月绩效</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td>YF0016</td>
      <td>Java高级工程师</td>
      <td>6000</td>
      <td>3000</td>
    </tr>
    <tr>
      <td>YF0021</td>
      <td>Java程序员</td>
      <td>3000</td>
      <td>2500</td>
    </tr>
  </tbody>
  <tbody>
    <tr>
      <td>YF0016</td>
      <td>WEB前端工程师</td>
      <td>5000</td>
      <td>2500</td>
    </tr>
    <tr>
      <td>YF0021</td>
      <td>软件测试工程师</td>
      <td>3000</td>
      <td>2000</td>
    </tr>
  </tbody>
  <tfoot>
    <tr>
      <td colspan="3">总计</td>
      <td>10W</td>
    </tr>
  </tfoot>
</table>

```html
<table>
  <caption>企业员工薪水绩效表</caption>
  <thead>
    <tr>
      <th>员工编号</th>
      <th>员工岗位</th>
      <th>基本工资</th>
      <th>本月绩效</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td>YF0016</td>
      <td>Java高级工程师</td>
      <td>6000</td>
      <td>3000</td>
    </tr>
    <tr>
      <td>YF0021</td>
      <td>Java程序员</td>
      <td>3000</td>
      <td>2500</td>
    </tr>
  </tbody>
  <tbody>
    <tr>
      <td>YF0016</td>
      <td>WEB前端工程师</td>
      <td>5000</td>
      <td>2500</td>
    </tr>
    <tr>
      <td>YF0021</td>
      <td>软件测试工程师</td>
      <td>3000</td>
      <td>2000</td>
    </tr>
  </tbody>
  <tfoot>
    <tr>
      <td colspan="3">总计</td>
      <td>10W</td>
    </tr>
  </tfoot>
</table>
```

## 颜色的表示形式

- 关键字  
  - red, green, blue, etc.  
- rgb 
  - `rgb(r, g, b)`，红绿蓝三色的强度，取值范围0-255   
- rgba  
  - `rgba(r, g, b, a)`，红绿蓝三色的强度和**不透明度**，取值范围0-1（1表示完全不透明）  
- 十六进制  
  - `#rrggbb`，红绿蓝三色的强度，取值范围00-FF    

## 表单

用于采集和提交用户输入，包括表单域和按钮两部分  

<form action="http://www.baidu.com">
  <label for="username">用户名：</label>
  <input type="text" name="username" id="username">
  <br>
  <label for="password">密码：</label>
  <input type="password" name="password" id="password">
  <br>
  <input type="submit" value="提交">
</form>

```html
<form action="http://www.baidu.com">
  <label for="username">用户名：</label>
  <input type="text" name="username" id="username">
  <br>
  <label for="password">密码：</label>
  <input type="password" name="password" id="password">
  <br>
  <input type="submit" value="提交">
</form>
```
- `<form>` 表单
  - `action`：表单提交的地址  
  - `method`：表单提交的方式，默认为 `get`    
    - get, post, put, delete, etc.    
    - 传输的url中，域名和数据之间用`?`分隔，数据之间用`&`分隔   
  - `name`：表单域的名称，用于提交时识别，现在多用`id`替代     
  - `enctype`：表单数据的编码方式  
    - `application/x-www-form-urlencoded`：**默认方式**，将数据编码为 `key=value` 的形式，并所有字符用`unicode`编码，并对特殊字符进行处理（空格替换为`+`，其他字符替换为百分号加十六进制值）      
    - `multipart/form-data`：将数据编码为二进制格式，用于上传文件   

### 常见表单域

- `<input>` 表单域   
  - `type`：表单域的类型，默认为 `text`    
    - text, password, radio, checkbox, submit, reset, button, file, hidden, etc.    
    - 值为`password`，显示的输入值为`***`   
    - 值为`radio`，需要设置相同的`name`属性，表示一组单选按钮，提交时只提交被选中的那个按钮的值   
    - 值为`checkbox`，需要设置相同的`name`属性，表示一组复选框，提交时提交所有被选中的复选框的值   
    - 值为`hidden`，会在页面中隐藏，但还是会传递给服务器。但是可以在源码中查看，因为不可用于存储敏感数据  
    - 
  - `value`：表单域的默认值，默认为空字符串    
  - `size`：表单域显示的宽度，默认为20个字符宽度  
  - `disabled`：是否禁用，默认为不禁用  

可以使用`<fieldset>`以**边框环绕**的形式实现表单的分组：  

<form>
  <fieldset>
    <legend>用户信息</legend>
    <label for="username">用户名：</label>
    <input type="text" name="username" id="username">
  </fieldset>
  <fieldset>
    <label for="password">密码：</label>
    <input type="password" name="password" id="password">
    <input type="submit" value="提交">
  </fieldset>
</form>

```html
<form>
  <fieldset>
    <legend>用户信息</legend>
    <label for="username">用户名：</label>
    <input type="text" name="username" id="username">
  </fieldset>
  <fieldset>
    <label for="password">密码：</label>
    <input type="password" name="password" id="password">
    <input type="submit" value="提交">
  </fieldset>
</form>
```


### 多行文本框

<textarea name="content" id="content" cols="30" rows="4">
这里是
多行
文本
可以
翻动</textarea>

```html
<textarea name="content" id="content" cols="30" rows="4">
这里是
多行
文本
可以翻动</textarea>
```

- `wrap`：自动换行的效果  
  - `off`：默认值，不自动换行，超出的部分用滚动条查看  
  - `virtual`：在用户视角自动换行，但实际换行以回车为准   
  - `physical`：在用户视角和实际都自动换行  

### 列表选择框

<select name="city" id="city">
  <option value="bj">北京</option>
  <option value="sh">上海</option>
  <option value="gz">广州</option>
  <option value="sz">深圳</option>
</select>

```html
<select name="city" id="city">
  <option value="bj">北京</option>
  <option value="sh">上海</option>
  <option value="gz">广州</option>
  <option value="sz">深圳</option>
</select>
```

- `<select>` 列表选择框   
  - `size`：列表选择框显示的行数，默认为1   
  - `multiple`：是否可多选，默认为单选  
  - `disabled`：是否禁用，默认为不禁用  
    - 禁用后，无法选择，也无法提交  
- `<option>` 列表选项   
  - `selected`：默认选中的选项    
  - `value`：选项的值，默认为选项的文本内容   

可以使用`optgroup`来将选项分组：  

<select>
    <optgroup label="水果">
        <option value="apple">苹果</option>
        <option value="banana">香蕉</option>
    </optgroup>
    <optgroup label="蔬菜">
        <option value="carrot">胡萝卜</option>
        <option value="tomato">番茄</option>
    </optgroup>
</select>


```html
<select>
    <optgroup label="水果">
        <option value="apple">苹果</option>
        <option value="banana">香蕉</option>
    </optgroup>
    <optgroup label="蔬菜">
        <option value="carrot">胡萝卜</option>
        <option value="tomato">番茄</option>
    </optgroup>
</select>
```

### 按钮控件

<input type="submit" value="提交">

```html
<input type="submit | reset | button" value="提交">
```

- `type`：按钮的类型，默认为 `submit`  
  - `submit`：提交按钮，点击后会提交表单  
  - `reset`：重置按钮，点击后会重置表单  
  - `button`：普通按钮，点击后不会提交表单，需要通过JavaScript来处理   
- `value`：按钮的文本内容，默认为空字符串     
- `disabled`：是否禁用，默认（不写disabled）为不禁用    


# CSS

## 简介

CSS（Cascading Style Sheets，层叠样式表）是一种用于描述HTML文档样式的语言，可以控制HTML元素的布局、颜色、字体、背景等样式。   

**样式** 是CSS的基本单元，每个样式包含：  

- 选择器：用于选择要应用样式的HTML元素    
- 声明：包含一个或多个属性和值，用于定义样式  

## CSS引入方式

- 行内  
  - 写在标签的 `style` 属性中  
  - <h4 style="color: red;">Hello World</h1>  
  - <span style="color: gray;">2025年1月1日</span>  
  - 注意，`<span>` 可以用于给元素添加样式，但是 `<span>` 本身没有特殊含义  
- 内部  
  - 写在 `<head>` 标签中的 `<style>` 标签中  

```html
<head>
    <meta charset="UTF-8">
    <title>这是一个测试文件</title>
  <style>
    span {
      color: red;
    } 
  </style>
</head>
<body>
  <span>这个是红色的</span>
</body>
```

写在 `<head>` 中的 `<style>` 的作用范围是 `<body>` 中的所有 `<span>` 元素

- 外部  
  - 写在单独的 `.css` 文件中，通过 `<link>` 标签引入  

/css/style.css  

```css
span {
  color: red;
}
```

/index.html  

```html
<head>
    <meta charset="UTF-8">
    <title>这是一个测试文件</title>
    <!-- 在这一行中引入css文件 -->
    <link rel="stylesheet" href="css/style.css">
</head>
<body>
    <span>外部引入的css</span>
    </body>
</html>
```

使用 `css选择器` 来为特定的元素添加样式   

- 元素选择器 `h1 {...}`  
  - 选择页面中所有 `<h1>` 标签  
- 类选择器 `.cls {...}`  
  - 选择页面中所有class属性为 `cls` 的标签  
- id选择器 `#hid {...}`  
  - 选择页面中id属性为 `hid` 的标签   
- 优先级  
  - id > 类 > 元素  
  - 即根据id选择来添加的样式会覆盖其他的样式  

```html
<!DOCTYPE html>
<html lang="zh-CN">
<head>
    <meta charset="UTF-8">
    <title>这是一个测试文件</title>
    <style>
        span{
            color: red;
        }
        .cls{
            color: green;
        }
        #time{
            color: blue;
        }
    </style>
</head>
<body>
    <span>红色</span>
    <span class="cls">绿色</span>
    <span class="cls" id="time">蓝色</span>
</body>
</html>
```
