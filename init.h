#ifndef _INIT_H
#define _INIT_H

/**
 * 学生选课系统
基本要求：
	1）课程信息存储结构设计（课程编号、课程名字、学
           分、任课老师、班级最大学生数、目前已选人数）
	2）选课信息存储结构设计（学生学号、所选课程编号）
	3）课程管理（新增课程、删除课程）
	4）查询可选课程（显示可供选择课程，排除已选课程）
	5）查询已选课程（显示已选课程列表及总学分）
	6）选课（输入学号和课程编号）
	7）退选（输入学号和课程编号）
	8）信息存储与读取
 */
 //N1 课程数量
 //N2 学生数量
//extern int N1,N2,kk1,kk2,kk3;
//extern struct couse * head1;         //课程信息指针头
//extern struct student * head2;       //学生信息指针头


/**
 * 课程信息结构体
 */
typedef struct couse
{
    int num1;      //课程编号
    char name1[20];   //课程名称
    int score;       //学分
    int nelepeo;  //课程已选人数
    int Melepeo;  //课程人数上限
    struct couse * next;
} couse;
/**
 * 学生信息结构体
 */
struct student
{
    int num2;    //学号
    char name2[20];   //学生名字
    int nelenum[50];  //已选课程编号
    int nelen;  //已选课程数量
    struct student * next;
};

//中间填写你要定义的全局变量
int N1,N2,kk1,kk2,kk3;
struct couse * head1; 
struct student * head2;


void readfile_course();
void readfile_student();



#endif
