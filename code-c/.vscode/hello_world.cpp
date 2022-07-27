#include "studentmangersystem.h" 
#include <stdlib.h>
#include <unistd.h>
#include<string.h>
//欢迎
void welcome()
{
    printf("*****************************************\n");
    printf("*\t欢迎使用学生成绩管理系统\t*\n");
    printf("*****************************************\n");
    printf("*\t     请选择功能列表\t\t*\n");
    printf("*****************************************\n");
    printf("1.学生数据录入\n");
    printf("2.学生成绩显示\n");
    printf("3.学生成绩存储\n");
    printf("4.学生成绩读取\n");
    printf("5.学生数据查找\n");
    printf("6.退出系统\n");
    printf("*****************************************\n");
}

//学生数据录入
void inputname()
{
    //创建一个新节点
    node* newnode=(node*)malloc(sizeof(node));//分配一个node类型大小的内存空间, 并把它赋给node* 型的变量newnode

    newnode->next=NULL;//此时后方没有节点 创建的节点既是头节点又是尾节点 将指针域设为空

    //头插法
    if(head==NULL)
    {
        head=newnode;
        //如果头没有(一个学生都没有），新生成的就是头
    }
    else
    {
        newnode->next=head;//已有学生，新节点插在头部
        head=newnode;//现在的
    }
    //分配好空间
    printf("请输入学生名字:\n");
    scanf("%s",newnode->stu.name);//name是数组名 数组名就是地址
    printf("请输入学生的年龄：\n");
    scanf("%d",&newnode->stu.age);//age是整数要取地址
    printf("请输入学生的学号：\n");
    scanf("%d",&newnode->stu.stunum);//scanf在遇到回车时会停止输入 遇到tab和空格时会停止读取
    printf("请输入学生的成绩：\n");
    scanf("%d",&newnode->stu.grade);
    printf("学生信息录入成功！\n");
    getchar();//scanf和getchar混用时 getchar会读取到前面输入数据后残留的那个回车换行符
    getchar();
    system("clear");
    
}
//学生数据显示
void printstudent()
{

    printf("*\t学号\t*\t姓名\t*\t年龄\t*\t成绩\t*\n");
    
    //遍历链表 把节点一个个打印
    node* p=head;
    while(p!=NULL)
    {
        printf("*\t%d\t*\t%s\t*\t%d\t*\t%d\t*\n",
        p->stu.stunum,
        p->stu.name,
        p->stu.age,
        p->stu.grade);

        p=p->next;
    }
   getchar();//按任意键继续

}
//学生成绩存储
void savestudent()
{
    //打开文件
    FILE* fp=fopen("/Users/garaiya/Desktop/stuifo.txt","w");//创建一个文件指针 FILE为系统定义的结构体类型
    if(fp==NULL)
    {
        printf("打开文件失败。\n");
    }
    node* p=head;
    while(p!=NULL)
    {
        fprintf(fp,
        "*\t%d\t*\t%s\t*\t%d\t*\t%d\t*\n",
        p->stu.stunum,
        p->stu.name,
        p->stu.age,
        p->stu.grade);

        p=p->next;
    }
    //关闭文件
    fclose(fp);
    printf("\n数据保存成功!\n");
    getchar();
    system("clear");
}

//读取学生信息
void readstudent()
{
    
    //打开文件
    FILE* fp=fopen("/Users/garaiya/Desktop/stuifo.txt","r");

    if(fp == NULL)
    {
        printf("数据录入失败！\n");
        return;
    }
    student stu;
    
        while(fread(&stu,1,sizeof(student),fp))
        {
            node *newnode=(node*)malloc(sizeof(node));
            newnode->next=NULL;

            memcpy(newnode,&stu,sizeof(student));

            //头插法
        if(head==NULL)
        {
        head=newnode;
        //如果头没有(一个学生都没有），新生成的就是头
        }
        else
        {
        newnode->next=head;//已有学生，新节点插在头部
        head=newnode;//现在的
        }
        }
            
    fclose(fp);
    printf("数据载入成功！\n");
    getchar();

}

//查找学生信息
node *findstudent()
{
    int nstunum;
    char szname[20]={0};
    printf("请输入要查找学生的学号:\n ");
    scanf("%d",&nstunum);
    printf("请输入要查找学生的姓名:\n");
    scanf("%s",szname);
    
    node *p=head;
    while(p!=NULL)
    {
        if(p->stu.stunum==nstunum||0==strcmp(p->stu.name,szname))
        {
            return p;
        }
        p=p->next;
    }
    //没有找到
    return NULL;
}


int main()
{
    
    while (1)
    {
        //欢迎
       welcome();

        //按数字键加回车进入下一进程
        char ch=getchar();
        switch(ch)
        {
            case'1':
            inputname();
            break;
            case'2':
            printstudent();
            break;
            case'3':
            savestudent();
            break;
            case'4':
            readstudent();
            break;
            case'5':
            {
            node *p=findstudent();
            if(p!=NULL)
            {
                printf("*\t%d\t*\t%s\t*\t%d\t*\t%d\t*\n",
            p->stu.stunum,
            p->stu.name,
            p->stu.age,
            p->stu.grade);
            }
            else
            printf("没有找到\n");
            }
            break;
            case'6':
            printf("bye bye!\n");
            return 0;
            default:
            printf("你的输入有误\n");
            break;
        }

    }

}


