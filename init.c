/* 文件加载模块 ------------------------------------------------------------------------*/
/**
 * 加载课程信息
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
void readfile_course()
{
    FILE * fp = fopen("info-course.txt","r");;
    char filepath[20];
    struct couse *p1,*p2;
    N1=0;
    if(fp==NULL)
    {
        printf("+---------------------------------------------------------+\n");
        printf("| 找不到info-course.txt文件!                               |\n");
        printf("+---------------------------------------------------------+\n");
        exit(0);
    }
    p1=p2=(struct couse*)malloc(sizeof(struct couse));
    fscanf(fp,"%d%s%d%d%d",&p1->num1,p1->name1,&p1->score,&p1->nelepeo,&p1->Melepeo);
    head1=NULL;
    while(!feof(fp))
    {
        N1=N1+1;
        if(N1==1)head1=p1;
        else p2->next=p1;
        p2=p1;
        p1=(struct couse * )malloc(sizeof(struct couse));
        fscanf(fp,"%d%s%d%d%d",&p1->num1,p1->name1,&p1->score,&p1->nelepeo,&p1->Melepeo);
    }
    p2->next=NULL;
}
/**
 * 加载学生信息
 */
void readfile_student()
{
    int i=0;
    FILE * fp;
    char filepath[20];
    struct student *p1,*p2;
    N2=0;
    fp=fopen("info-student.txt","r");
    if(fp==NULL)
    {
        printf("+---------------------------------------------------------+\n");
        printf("|找不到info-student.txt文件!                               |\n");
        exit(0);
    }
    p1=p2=(struct student*)malloc(sizeof(struct student));
    fread(p1,sizeof(struct student),1,fp);
    head2=NULL;
    while(!feof(fp))
    {
        i=0;
        N2=N2+1;
        if(N2==1)head2=p1;
        else p2->next=p1;
        p2=p1;
        p1=(struct student * )malloc(sizeof(struct student));
        fread(p1,sizeof(struct student),1,fp);
    }
    p2->next=NULL;
}