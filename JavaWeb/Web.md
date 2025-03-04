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
- `title`：鼠标悬停时显示的文本   
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
- `title`：鼠标悬停时显示的文本  
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

## 颜色的表示形式

- 关键字  
  - red, green, blue, etc.  
- rgb 
  - `rgb(r, g, b)`，红绿蓝三色的强度，取值范围0-255   
- rgba  
  - `rgba(r, g, b, a)`，红绿蓝三色的强度和**不透明度**，取值范围0-1（1表示完全不透明）  
- 十六进制  
  - `#rrggbb`，红绿蓝三色的强度，取值范围00-FF    

# CSS

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