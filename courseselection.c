/* 选课系统部分-------------------------------------------------------------------------- */
#include<stdio.h>
#include<stdlib.h>
#include"coursemanage.h"
#include"init.h"
#include"courseselection.h"
#include"save.h"
#include"studentmanage.h"
/**
 * 查询可选课程
 */
extern int N1,N2,kk1,kk2,kk3;
extern struct couse * head1; 
extern struct student * head2;
void cheak()
{
    char e;
    struct couse * c;
    struct student * s;
    int num2,i,j=0,t=0;
    printf("+---------------------------------------------------------+\n");
    printf("|请输入你的学号:                                          |\n");
    scanf("%d",&num2);
    s=head2;
    while(s->num2!=num2 && s->next!=NULL) s=s->next;
    if(s->num2!=num2)
    {
        printf("+---------------------------------------------------------+\n");
        printf("|不存在你的信息,请让教师录入你的信息!                     |\n");
        printf("+---------------------------------------------------------+\n");
        return;
    }
    c=head1;
    //system("clear");
    printf("+---------------------------------------------------------+\n");
    printf("|你的可选课程编号:                                        |\n");
    printf("+---------------------------------------------------------+\n");
    while(c!=NULL)
    {
        for(t=0,i=0;s->nelenum[i]!=0;i++)
        {
            if(c->num1==s->nelenum[i]) t=1;
        }
        if(t==0 && (c->nelepeo!=c->Melepeo))
        {
            printf("|%-4d|                                                    |\n",c->num1);
            printf("+---------------------------------------------------------+\n");
            j++;
        }
        c=c->next;
    }
    if(j==0)
    {
        printf("| 你已选完所有课程，无法再多选!                              |\n");
        printf("+---------------------------------------------------------+\n");
        return;
    }
    printf("|选课(y/n)?:                                              |\n");
    getchar();
    e=getchar();
    i=0;
    while(e=='y')
    {
        elect(s);
        printf("|继续选课(y/n)?:                                          |\n");
        getchar();
        e=getchar();
    }
    //system("clear");
}
/**
 * 退课
 * @param p  学生信息
 */
void back(struct student * p)
{
    struct couse * p1;
    int num1,i,j;
    //system("clear");
    printf("+---------------------------------------------------------+\n");
    printf("|请输入你要退掉的课程编号:                                |\n");
    scanf("%d",&num1);
    p1=head1;
    while(p1->num1!=num1) p1=p1->next;
    for(i=0;p->nelenum[i]!=num1;i++);
    for(j=i;p->nelenum[j]!=0;j++) p->nelenum[j]=p->nelenum[j+1];
    p->nelenum[--j]=0;
    (p1->nelepeo)--;
    printf("+---------------------------------------------------------+\n");
    printf("| 退课成功!                                               |\n");
    printf("+---------------------------------------------------------+\n");
}
/**
 * 查询已选课程
 */
void hcheak()
{
    char c;
    struct couse * p0;
    struct student * p;
    int num2,i,f=0;
    //system("clear");
    printf("+---------------------------------------------------------+\n");
    printf("| 请输入学号:                                              |\n");
    scanf("%d",&num2);
    p=head2;
    //system("clear");
    while(p->num2!=num2 && p!=NULL) p=p->next;
    if(p==NULL)
    {
        printf("+---------------------------------------------------------+\n");
        printf("|不存在你的信息,请回主菜单录入信息:                          |\n");
        printf("+---------------------------------------------------------+\n");
        printf("\n");
        return;
        //goto end;
    }
    printf("+--------------+------------------------------------------+\n");
    printf("| 已选课程编号 |                                          |\n");
    printf("+---------------------------------------------------------+\n");
    if(p->nelenum[0]==0)
    {
        printf("+---------------------------------------------------------+\n");
        printf("| 你还没选课!                                              |\n");
        printf("+---------------------------------------------------------+\n");
        printf("\n");
        printf("\n");
        return;
        //goto end;
    }
    for(i=0;p->nelenum[i]!=0;i++)
    {
        printf("|%14d|                                          |\n",p->nelenum[i]);
        p0=head1;
        while(p0->num1!=p->nelenum[i]) p0=p0->next;
        f=f+p0->score;
    }
    printf("+---------------------------------------------------------+\n");
    printf("|总学分: %d                                               |\n",f);
    printf("+---------------------------------------------------------+\n");
    printf("| 是否进行退课(y/n)?                                      |\n");
    getchar();
    c=getchar();
    while(c=='y')
    {
        system("clear");
        back(p);
        printf("| 继续退课(y/n)?                                          |\n");
        getchar();
        c=getchar();
        (p->nelen)--;
    }
    //system("clear");
    //end:;
}
/**
 * 学生选课主函数
 */
void elective()
{
    int i;
    printf("+---------------------------------------------------------+\n");
    printf("|                         学生选课                        |\n");
    printf("+--+------------------------------------------------------+\n");
    printf("|1 | 查询可选课程                                         |\n");
    printf("+--+------------------------------------------------------+\n");
    printf("|2 | 查询已选课程                                         |\n");
    printf("+--+------------------------------------------------------+\n");
    printf("|3 | 返回主菜单                                           |\n");
    printf("+--+------------------------------------------------------+\n");
    printf("请输入(1~3):                                              |\n");
    scanf("%d",&i);
    switch(i)
    {
        case(1):cheak();break;
        case(2):hcheak();break;
        case(3):;break;
    }
}
/**
 * 输出课程信息
 */
void list_course()
{
    struct couse * p;
    p=head1;
    printf("+--------+----------------+----+------------+-------------+\n");
    printf("|课程编号|        课程名称|学分|课程已选人数| 课程人数上限|\n");
    printf("+--------+----------------+----+------------+-------------+\n");
    while(p!=NULL)
    {
        printf("|%8d|%16s|%4d|%12d|%13d|\n",p->num1,p->name1,p->score,p->nelepeo,p->Melepeo);
        p=p->next;
    }
    printf("+--------+----------------+----+------------+-------------+\n");
    printf("\n");
    printf("\n");
}
/**
 * 输出学生信息
 */
void list_student()
{
    struct student * p;
    p=head2;
    printf("+--------+-----------------------------------+------------+\n");
    printf("|学生学号|                           学生姓名|已选课程数量|\n");
    printf("+--------+-----------------------------------+------------+\n");
    while(p!=NULL)
    {
        printf("|%8d|%35s|%12d|\n",p->num2,p->name2,p->nelen);
        p=p->next;
    }
    printf("+--------+-----------------------------------+------------+\n");
    printf("\n");
    printf("\n");
}