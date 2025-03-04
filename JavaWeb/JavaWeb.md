# Java Web

# Web标准  

组成部分：  

- HTML：结构  
  - 页面元素和内容  
- CSS：表现  
  - 元素的外观、位置等  
- JavaScript：行为      
  - 交互效果    

## HTML

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


### 标题

```HTML
<h1>一级标题</h1>
<h2>二级标题</h2>
<h3>三级标题</h3>
<h4>四级标题</h4>
<h5>五级标题</h5>
<h6>六级标题</h6>
```

### 超链接

```HTML
<a href="https://www.baidu.com">百度</a>
```

- `herf`：指向的地址  
- `target` 为打开方式   
  - `_blank`：新窗口打开    
  - `_self`：本窗口打开（默认值）  

### 图片 视频 音频

```HTML
<img src="http://i.fxgpt.site/i/2025/02/18/ndxh0g.jpg" alt="测试图片">
```

- `src`：图片地址   
- `alt`：图片描述  
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

### 列表

```HTML
<ul>
    <li>列表项1</li>
    <li>列表项2</li>
    <li>列表项3</li>
</ul>
```

- `ul`：无序列表，`ol`：有序列表   
- `li`：列表项  

对于有序列表：  

- `type`：设置列表项的序号类型，如 `1`、`A`、`a`、`I`、`i` 等  
- `start`：设置列表项的起始序号  


### 换行 段落

```HTML
第一行
<hr>
第二行

<p>这是一个段落</p>
```

### 注释

```HTML
<!-- 这是一个注释 -->
```

### 文本格式化

```HTML
<font face="Arial" size="4" color="red">这是一段文本</font>
<b>加粗</b>
<i>斜体</i>
<u>下划线</u>
<s>删除线</s>
<sup>上标</sup>
<sub>下标</sub>
<hr> // 水平线
```

### 特殊符号

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

### CSS引入方式

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

### 颜色的表示形式

- 关键字  
  - red, green, blue, etc.  
- rgb 
  - `rgb(r, g, b)`，红绿蓝三色的强度，取值范围0-255   
- rgba  
  - `rgba(r, g, b, a)`，红绿蓝三色的强度和**不透明度**，取值范围0-1（1表示完全不透明）  
- 十六进制  
  - `#rrggbb`，红绿蓝三色的强度，取值范围00-FF    

## CSS
