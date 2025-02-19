# SpringBoot

## 分层交互逻辑

- Controller：控制层  
  - 接收前端请求，调用Service层方法，将Service返回的数据封装为http相应
- Service：服务层       
  - 定义业务接口  
- ServiceImpl ：服务层实现  
  - 实现具体业务逻辑，调用DAO层方法访问数据库   
- DAO(Data Access Object)：数据访问对象层   
  - 定义数据库操作接口  
- Mapper：映射器层  
  - 与DAO层相同

## application配置文件

在 `src/main/resources/application.yaml` 中进行配置文件的编写  

```yaml
server:
  port: 9090

email:
  user: testemail@mail.com
  code: test123456
  auth: true
```

yaml文件使用缩进表示层级关系，缩进不允许使用tab，只允许空格  

在具体业务类中，使用以下方法获取配置文件中的内容：  

1、每个变量分别获取  

```java
@Component
public class EmailConfig {
    @Value("${email.user}")
    private String user;

    @Value("${email.code}")
    private String code;

    @Value("${email.auth}")
    private Boolean auth;
}

```

2、使用前缀统一获取，需要保证变量名和配置文件中的键名一致  

```java
@Component
@ConfigurationProperties(prefix = "email")
public class EmailConfig {
    private String user;
    private String code;
    private Boolean auth;
}
```

## mybatis数据库


