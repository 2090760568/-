#include<stdio.h>
//将链表和链表节点定义在头文件中
//将函数实现写在对应的.cpp文件中

//定义一个学生
typedef struct _Student
{
    char name[20];
    int age;
    int stunum;
    int grade;
}student;
//定义student为结构变量

//节点
//系统变量加一般加_跟用户的标识符区分
typedef struct _Node
//用typedef给结构体起别名
{
    student stu;//声明了一个student类型的对象变量stu
    struct _Node *next;//指向struct_Node下一个节点的指针
}node;

node *head=NULL;//指向头 但头节点是空的
node *findstudent();


