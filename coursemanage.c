/* 课程管理模块----------------------------------------------------------------------------------------*/
/**
 * 增加课程
 * @param incouse  课程信息
 */
//中间填写你要定义的全局变量
//中间填写你要定义的全局变量
/**
 * 课程信息结构体
 */
#include<stdio.h>
#include<stdlib.h>
#include"init.h"
#include"courseselection.h"
#include"save.h"
#include"studentmanage.h"
#include"coursemanage.h"
extern int N1,N2,kk1,kk2,kk3;
extern struct couse * head1; 
extern struct student * head2;
void insert_course(struct couse *incouse)
{
    struct couse *p0,*p1,*p2;
    p1=head1;
    p0=incouse;
    if(head1==NULL)
    {
        head1=p0;
        p0->next=NULL;
    }
    //按照顺序进行编号
    else
    {
        while((p0->num1 > p1->num1) && (p1->next!=NULL))
        {
            p2=p1;
            p1=p1->next;
        }
        if(p0->num1 <= p1->num1)
        {
            if(head1==p1) head1=p0;
            else p2->next=p0;
            p0->next=p1;
        }
        else
        {
            p1->next=p0;
            p0->next=NULL;
        }
    }
    N1=N1+1;
}
/**
 * 删除课程
 * @param num1  课程编号
 */
void delete_course(int num1)  //课程管理子函数(删除课程)
{
    struct couse *p1,*p2;
    if(head1==NULL)
    {
        printf("+---------------------------------------------------------+\n");
        printf("| 没有课程,无法删除!                                       |\n");
        printf("+---------------------------------------------------------+\n");
        printf("\n");
        printf("\n");
        return;
    }
    p1=head1;
    while(num1!=p1->num1 && p1->next!=NULL)
    {
        p2=p1;
        p1=p1->next;
    }
    if(num1==p1->num1)
    {
        if(p1==head1) head1=p1->next;
        else p2->next=p1->next;
        printf("+---------------------------------------------------------+\n");
        printf("|已删除该编号课程!                                        |\n");
        printf("+---------------------------------------------------------+\n");
        printf("\n");
        printf("\n");
        N1=N1-1;
    }
    else
    {
        printf("+---------------------------------------------------------+\n");
        printf("| 无该编号的课程!                                         |\n");
        printf("+---------------------------------------------------------+\n");
        printf("\n");
        printf("\n");
    }
}
/**
 * 课程管理主函数
 */
void management_course()
{
    struct couse * incouse;
    int i,num1;
    printf("+---------------------------------------------------------+\n");
    printf("|                        课程管理                         |\n");
    printf("+--+------------------------------------------------------+\n");
    printf("|1 | 新增课程                                             |\n");
    printf("+--+------------------------------------------------------+\n");
    printf("|2 | 删除课程                                             |\n");
    printf("+--+------------------------------------------------------+\n");
    printf("|3 | 返回主菜单                                           |\n");
    printf("+--+------------------------------------------------------+\n");
    printf("| 请选择(1~3):                                            |\n");
    scanf("%d",&i);
    switch(i)
    {
        case(1):
        {
            system("clear");
            incouse=(struct couse *)malloc(sizeof(struct couse));
            printf("+--------+------------------------------+----+------------+\n");
            printf("|课程编号|课程名称                      |学分|课程人数上限|\n");
            printf("+--------+------------------------------+----+------------+\n");
            scanf("%d%s%d%d",&incouse->num1,incouse->name1,&incouse->score,&incouse->Melepeo);
            incouse->nelepeo=0;
            insert_course(incouse);
            //system("clear");
            printf("+---------------------------------------------------------+\n");
            printf("| 添加成功!                                               |\n" );
            break;
        }
        case(2):
        {
            system("clear");
            printf("+---------------------------------------------------------+\n");
            printf("|请输入要删除课程的编号:                                  |\n");
            scanf("%d",&num1);
            delete_course(num1);
            //system("clear");
            printf("+---------------------------------------------------------+\n");
            printf("| 删除成功!                                               |\n");
            break;
        }
        case(3)://system("clear");
         break;
    }
}