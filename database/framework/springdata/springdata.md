# springdata
## 1. 原始方式和jdbcTempate访问数据库
### 1.1 步骤
1. 创建maven项目
2. 获取jdbc,junit依赖,在https://mvnrepository.com/ 搜索mysql,找到合适jdbc依赖
3. 数据表的准备
```sql
##创建数据库
create database spring_data;
##切换到数据库
use spring_data;
##展示数据库的所有表
show tables;
##创建表
create table student(
    id Int not null auto_increment,
    name varchar(20) not null,
    age int not null,
    primary key(id)
);
##查看表结构
desc student;
##插入数据
insert into student(name,age) values("zhangsan",20);
insert into student(name,age) values("lisi",21);
insert into student(name,age) values("wangwu",22);
```
4. 开发JDBCUtil工具类
    - 获取Connection,关闭Connection,Statement,ResultSet
    - 注意事项: 配置属性放置在配置文件中

5. 建立对象模型,DAO(访问数据库相关的东西)
6. 使用spring jdbc的方式操作数据库
    - 添加依赖
    - 配置beans.xml
    - 开发query(),save()方法 
### 1.2 弊端

- 代码多,重复
- 分页的话比较麻烦
- ...

## spring_data