<script type="text/javascript" 
  src="http://cdn.mathjax.org/mathjax/latest/MathJax.js?config=TeX-AMS-MML_HTMLorMML">
</script>
<script type="text/x-mathjax-config">
  MathJax.Hub.Config({ tex2jax: {inlineMath: [['$', '$']]}, messageStyle: "none" });
</script>


<script type="text/javascript" 
  src="http://cdn.mathjax.org/mathjax/latest/MathJax.js?config=TeX-AMS-MML_HTMLorMML">
</script>
<script type="text/x-mathjax-config">
  MathJax.Hub.Config({ tex2jax: {inlineMath: [['$', '$']]}, messageStyle: "none" });
</script>

# HDFS Zookeeper

## 文件系统

一种存储和组织计算机数据的方法，使对数据的访问和查找变得容易  

- 文件名  
  - 用于定位存储位置      
- 元数据 Metadata  
  - 保存文件属性的数据  
  - 文件名、文件长度、文件权限、etc     
- 数据块 Block  
  - 存储文件的最小单元      


## HDFS

HDFS（Hadoop Distributed File System），Hadoop分布式文件系统，在**商品硬件**（商用服务器）上运行的分布式文件系统  

### 特性        

- 高容错能力，可部署于低成本硬件上   
- 提供对数据的高吞吐访问，适用于有大数据集的应用程序        
- 通过数据块机制可以提高客户端访问吞吐量        
- 放宽对Linux Posix的要求，实现对文件系统数据的**流式访问**，提高访问效率     
- HDFS最早是Apache Nutch Web搜索引擎项目的基础结构，现在是Apache Hadoop的核心部分       

### 应用场景  

- 存储网站数据      
- 存储交通电子眼数据    
- 存储气象传感器采集的数据  
- 不适用于需要实时响应的场景    
- 不适用于存储大量小文件        
- 不适用于多用户写和随机写  

### 计算机集群结构


- 分布式文件系统把文件分布存储到多个计算机节点上，这些节点构成计算机集群      
- 目前分布式文件系统采用的计算机集群使用普通硬件，降低硬件开销        

### 基本系统架构

![alt text](image/HDFS_Architecture.png)

- Client 客户端    
  - HDFS接口，用于访问文件      
- NameNode  
  - 存储文件名和元数据，数据块与DataNode的对应关系    
  - 管理Namespace（包含FSimage和editslog）      
    - FSimage负责维护文件系统树，以及文件树中的文件和元数据 
    - editslog负责记录对文件的修改操作  
- DataNode      
  - 负责文件的存储和读取        
- 在一个HDFS中，可以有多个Client和多个DataNode，但是只能有一个NameNode      

HDFS基本存储单位：Block 块  

- 默认大小128M，远大于普通文件系统，降低寻址开销      
- 一个文件被分为多个块进行存储      
- 块存储好处        
  - 支持大规模文件存储  
  - 简化系统设计    
  - 适合数据备份    

### 体系架构

![alt text](image/HDFS_Architecture_2.png)

### 命名空间管理

HDFS的命名空间包括**目录、文件、块**  

HDFS使用传统的分级文件体系，用户可以像使用传统文件系统一样创建删除目录和文件等      

由NameNode维护文件系统命名空间，对命名空间及其属性的更改由NameNode的editslog记录    

### 通信协议

所有HDFS通信协议都是构建在**TCP/IP**协议之上  

- Client通过可配置的端口向NameNode发起TCP连接，使用客户端协议与NameNode交互   
- NameNode和DataNode之间使用数据节点协议进行交互    
- Client与DataNode之间通过RPC进行交互       

客户端：  

- Client是用户操作HDFS最常用的方式，但严格来说Client不属于HDFS的一部分      

### 单NameNode的局限性      

- NameNode保存在内存中，HDFS的容量受限于内存大小        
- 整个HDFS的吞吐量受限于单个NameNode的吞吐量    
- 集群中只有一个NameNode，一个Namespace，无法对不同应用程序进行隔离     
- 一旦唯一的NameNode发生故障将导致整个集群不可用  

### 关键特性

- HA 高可用性（Hadoop 2.0）  
  - ![alt text](image/HDFS_HA.png)  
  - 有两个NameNode：Active（主节点）和Stand By（备份节点）    
  - 正常情况下仅由主节点提供服务，备份节点用于备份元数据信息        
  - 使用Zookeeper监控NameNode状态，当主节点故障时，使用备份节点接管服务，保证服务不中断     
- 元数据持久化（Hadoop 1.0）     
  - ![alt text](image/HDFS_Secondary_NameNode.png)  
  - 通过Secondary NameNode实现   
  - 对editlog中的日志进行合并，减少editlog的大小，减少NameNode故障恢复时间      
- HDFS联邦（Hadoop 2.0）    
  - ![alt text](image/Federation.png)
  - 用多个NameNode存储元数据，各个NameNode存储的Namespace的元数据 互不相交  
- 数据副本机制（Hadoop 1.0）  
  - 将同一个数据块复制到多个DataNode上，提高数据的可靠性和读取数据的吞吐量      
- 数据完整性保障    
  - 重建失效数据盘的副本数据        
    - DataNode故障时，NameNode发起副本重建动作，恢复丢失副本  
  - 集群数据均衡        
    - 保证数据库在DataNode上的分布是均衡的  
  - 元数据可靠性保证    
    - 采用日志机制操作元数据，同时将元数据存储于主备NameNode上  
    - 快照机制在误操作时可以及时恢复    
  - 安全模式    
    - 发现数据节点或硬盘故障时，禁止客户端对数据的**写操作**，防止故障扩散  

### HDFS 3.0 新特性

- 支持纠删码Erasure Coding      
  - 检错码：仅可以检测错码        
  - 纠错码：可以检测错码并对其纠正  
  - 纠删码：具备纠错码的功能，且可以在一定范围内数据出错的情况下恢复数据        
  - 3.0使用纠删码代替副本机制，提供了相同的容错能力，但存储占用小很多   
- 支持多NameNode    
  - 运行运行多个备用NameNode    
  - 但是只有一个Active NameNode提供服务，其余的都是Stand By     
- 基于HDFS路由器的联合      
  - 添加RPC路由层       
  - 简化HDFS客户端对联合集群的访问  
- DataNode新增负载均衡Disk Balancer     
  - 可以对节点内部磁盘间的数据进行平衡      

### 常用shell命令       

- dfs  
  - `-cat`：查看文件内容    
  - `-ls`：显示目录列表     
  - `-rm`：删除文件     
  - `-put`：上传目录/文件到HDFS      
  - `-get`：从HDFS下载文件/目录      
  - `-mkdir`：创建目录  
  - `-chmod`：改变文件属性      
- dfsadmin      
  - `-safemode`：安全模式操作   
  - `-report`：报告服务状态  

### 数据读写流程        

- 写入  
  - Client通过`Distribute File System`向NameNode发起创建文件的请求    
  - NameNode接收到请求后将可写入数据块的DataNode返回给Client    
  - Client通过`FSData OutputStream`写入数据    
    - 向第一个DataNode写入第一个副本    
    - 写入40%时将写入操作传给第二个DataNode，写入第二个副本     
    - 同理写入第三个副本    
    - 写完后反馈给Client    
  - 客户端关闭写操作    
- 读取  
  - Client通过`Distribute FileSystem`向NameNode发起读取文件的请求   
  - NameNode获取目标文件的元数据信息，即需要从哪些DataNode上读取Block  
  -  Client通过`FSData InputStream`读取数据    
    -  找到对应DataNode，读取所需Block    
  - 关闭输入流  

![alt text](image/ReadWrite.png)

## Zookeeper

Zookeeper，分布式服务框架，用于解决数据一致性等分布式应用的数据管理问题，提供分布式、高可用性的协调服务能力  

![alt text](image/Zookeeper.png)

### 体系架构

Zookeeper集群由一组Server节点组成，启动时选举其中一个为Leader节点（获得半数以上投票），其余为Follower节点  

Leader节点收到数据变更请求后，先写硬盘后写内存      

### 容灾能力

对有n个服务器的集群：  

- n为奇数，$n=2x+1$         
  - leader节点需要 $x+1$ 票，容灾能力为 $x$  
- n为偶数，$n=2x+2$         
  - leader节点需要 $x+2$ 票，容灾能力为 $x$   

### 关键特性

- 最终一致性    
  - 任一server所提供的数据是一致的   
- 实时性    
  - Client可以在一定时间范围内获得服务器的更新信息或失效信息    
- 可靠性    
  - 一条消息被一个server接收等同于被所有server接收  
- 等待无关性    
  - 低速或失效的client不会干预快速的client的请求，使得每个client都可以有效地等待    
- 原子性    
  - 更新要么成功，要么失败  
- 顺序一致性    
  - 客户端所发送的更新按照被发送的顺序执行      

### 读特性 

读操作可以在任意节点完成

### 写特性

对一个节点的写请求会自动发送给其余所有节点，最后一个节点逐层返回写入成功信息给客户端        

### 常用命令

| 命令 | 功能 |
| :---: | :---: |
| `zkCli.sh -server [ip:port]` | 连接Zookeeper服务器 |
| `create /node` | 创建节点 |
| `delete /node` | 删除节点 |
| `ls /node` | 列出节点子节点 |
| `get /node` | 获取节点数据 |
| `set /node data` | 设置节点数据 |

# Hive分布式数据仓库

## 概述

Hive是Apache的一个开源大数据组件

## 功能与架构

## 基本操作
