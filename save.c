/* 储存模块函数----------------------------------------------------------------------- */
/**
 * 存储课程信息
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

void savefile_course()
{
    FILE * fp;
    struct couse * p;
    char filepath[30];
    fp=fopen("info-course.txt","w");
    if((fp=fopen("info-course.txt","w"))==NULL)
    {
        printf("\n+---------------------------------------------------------+\n");
        printf("| 保存失败!                                               |\n");
        exit(0);
    }
    p=head1;
    while(p!=NULL)
    {
        fprintf(fp,"%d %s %d %d %d\n",p->num1,p->name1,p->score,p->nelepeo,p->Melepeo);
        p=p->next;
    }
    fclose(fp);
    printf("\n+---------------------------------------------------------+\n");
    printf("| 课程信息已保存在info-course.txt中!                      |\n");
}
/**
 * 存储学生信息
 */
void savefile_student()
{
    FILE * fp;
    struct student * p;
    char filepath[30];
    fp=fopen("info-student.txt","w");
    if((fp=fopen("info-student.txt","w"))==NULL)
    {
        printf("+---------------------------------------------------------+\n");
        printf("| 保存失败!                                               |\n");
        exit(0);
    }
    p=head2;
    while(p!=NULL)
    {
        fwrite(p,sizeof(struct student),1,fp);
        p=p->next;
    }
    fclose(fp);
    printf("+---------------------------------------------------------+\n");
    printf("| 学生信息已保存在info-student.txt中!                     |\n");
}
/**
 * 存储信息
 */
void save_all()
{
    savefile_course();
    savefile_student();
}