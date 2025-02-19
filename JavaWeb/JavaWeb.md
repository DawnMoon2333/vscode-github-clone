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

### 图片

```HTML
<img src="http://i.fxgpt.site/i/2025/02/18/ndxh0g.jpg" alt="测试图片">
```

其中 `src` 为图片地址，`alt` 为图片加载失败时的替代文本  

### 换行

```HTML
第一行
<hr>
第二行
```

### 注释

```HTML
<!-- 这是一个注释 -->
```

### 文本格式化

```HTML
<b>加粗</b>
<i>斜体</i>
<u>下划线</u>
<s>删除线</s>
<sup>上标</sup>
<sub>下标</sub>
```

### CSS引入方式

- 行内  
  - 写在标签的 `style` 属性中  
  - <h4 style="color: red;">Hello World</h1>  
  - <span style="color: gray;">2024年5月15日</span>
- 内部  
  - 写在 `<head>` 标签中的 `<style>` 标签中  

```html
<head>
  <title>
    标题
  </title>
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

`<span>` 可以用于给元素添加样式，但是 `<span>` 本身没有特殊含义  



## CSS
