/* 学生信息管理模块--------------------------------------------------------------------------- */
/**
 * 添加学生信息
 * @param incouse 学生信息
 */
#include<stdio.h>
#include<stdlib.h>
#include"coursemanage.h"
#include"init.h"
#include"courseselection.h"
#include"save.h"
#include"studentmanage.h"
extern int N1,N2,kk1,kk2,kk3;
extern struct couse * head1; 
extern struct student * head2;
void insert_student(struct student * incouse)
{
    struct student *p0,*p1,*p2;
    p1=head2;
    p0=incouse;
    if(head2==NULL)
    {
        head2=p0;
        p0->next=NULL;
    }
    else
    {
        while((p0->num2 > p1->num2) && (p1->next!=NULL))
        {
            p2=p1;
            p1=p1->next;
        }
        if(p0->num2 <= p1->num2)
        {
            if(head2==p1) head2=p0;
            else p2->next=p0;
            p0->next=p1;
        }
        else
        {
            p1->next=p0;
            p0->next=NULL;
        }
    }
    N2=N2+1;
}
/**
 * 删除学生信息
 * @param num2
 */
void delete_student(int num2)
{
    struct student *p1,*p2;
    if(head2==NULL)
    {
        printf("+---------------------------------------------------------+\n");
        printf("| 没有该学生信息,无法删除!                                   |\n");
        printf("+---------------------------------------------------------+\n");
        printf("\n");
        printf("\n");
        return;
    }
    p1=head2;
    while(num2!=p1->num2 && p1->next!=NULL)
    {
        p2=p1;
        p1=p1->next;
    }
    if(num2==p1->num2)
    {
        if(p1==head2) head2=p1->next;
        else p2->next=p1->next;
        printf("+---------------------------------------------------------+\n");
        printf("|已删除该学生信息!                                        |\n");
        N2=N2-1;
    }
    else
    {
        printf("+---------------------------------------------------------+\n");
        printf("|无该学号的学生!                                          |\n");
    }
}
/**
 * 学生信息管理主函数
 */
void management_student()
{
    struct student * incouse;
    int i,num2;
    printf("+---------------------------------------------------------+\n");
    printf("|                      学生信息管理                       |\n");
    printf("+--+------------------------------------------------------+\n");
    printf("|1 | 新增学生信息                                         |\n");
    printf("+--+------------------------------------------------------+\n");
    printf("|2 | 删除学生信息                                         |\n");
    printf("+--+------------------------------------------------------+\n");
    printf("|3 | 返回主菜单                                           |\n");
    printf("+--+------------------------------------------------------+\n");
    printf("|请选择(1~3):                                             |\n");
    scanf("%d",&i);
    switch(i)
    {
        case(1):
        {
            system("clear");
            incouse=(struct student *)malloc(sizeof(struct student));
            incouse->nelen=0;
            incouse->nelenum[0]=0;
            printf("+--------+--------+---------------------------------------+\n");
            printf("|学生学号|学生姓名|                                       |\n");
            printf("+--------+--------+---------------------------------------+\n");
            scanf("%d%s",&incouse->num2,incouse->name2);
            insert_student(incouse);
            //system("clear");
            printf("+---------------------------------------------------------+\n");
            printf("| 新增成功!                                               |\n" );
            break;
        }
        case(2):
        {
            system("clear");
            printf("+---------------------------------------------------------+\n");
            printf("|请输入要删除学生的学号:                                  |\n");
            scanf("%d",&num2);
            //system("clear");
            delete_student(num2);
            break;
        }
        case(3)://system("clear");
            break;
    }
}
/**
 * 选课
 * @param s  学生信息
 */
void elect(struct student * s)
{
    struct couse * p;
    int num1,i;
    //system("clear");
    printf("+---------------------------------------------------------+\n");
    printf("|请输入要选课的编号:                                       |\n");
    scanf("%d",&num1);
    for(i=0;s->nelenum[i]!=0;i++);
    s->nelenum[i]=num1;
    (s->nelen)++;
    p=head1;
    while(p->num1!=num1) p=p->next;
    (p->nelepeo)++;
    //system("clear");
    printf("+---------------------------------------------------------+\n");
    printf("| 选课成功!                                               |\n");
    printf("+---------------------------------------------------------+\n");
}