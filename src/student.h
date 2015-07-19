/*
 * student.h
 *
 *  Created on: 2015年7月15日
 *      Author: golooloo
 */

#ifndef STUDENT_H_
#define STUDENT_H_

#define TRUE 1
#define FALSE 0

#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

/*定义学生信息结构体变量*/
typedef struct node {
	int num; //学号
	char name[16]; //姓名
	int age;  //年龄
	char sex[4]; //性别
	char birthday[20]; //出生年月
	char address[32]; //地址
	char telephone[16]; //电话
	char email[32]; //电子邮箱
	struct node *next; //链表指针域
} student_info;

/*全局变量声明*/
extern student_info* student_list;

/*初始化学生信息结构体变量*/
int init_student_info_list();

/*判断学生信息结构体变量是否为空*/
int student_list_empty();

/*向学生信息结构体变量中添加记录*/
int add_student_info();

/*从学生信息结构体变量中删除学生信息*/
int delete_student_info(int num);

/*修改记录*/
int modify_student_info(int num);

/*查找记录*/
student_info* search_student_info(int num);

//显示所有记录
void display_student_info();

//将记录保存到文件
int save_file();

//从文件中读取记录
int read_file();

#endif /* STUDENT_H_ */
