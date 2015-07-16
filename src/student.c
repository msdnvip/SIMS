/*
 * student.c
 *
 *  Created on: 2015年7月15日
 *      Author: golooloo
 */

#include"student.h"

int init_student_info_list() {
	student_list = (student_info*) malloc(sizeof(student_info));
	if (!student_list) {
		return FALSE;
	}
	student_list->next = NULL;
	return TRUE;
}

int student_list_empty() {
	return student_list->next == NULL;
}

void display_student_info() {
	student_info *pstu;
	pstu = student_list->next;
	printf("所有学生信息如下所示:\n");
	while (pstu) {
		printf("学号:%d\t姓名:%s\t年龄:%d\t性别:%s\t地址:%s\t电话:%s\t\n", pstu->num,
				pstu->name, pstu->age, pstu->sex, pstu->address,
				pstu->telephone);
		pstu = pstu->next;
	}
	if (!pstu) { //释放内存
		free(pstu);
	}
}

int add_student_info() {
	student_info *pstu = (student_info*) malloc(sizeof(student_info));
	if (pstu == NULL) {
		printf("初始化失败!\n");
		return FALSE;
	}
	printf("请按要求输入学生的信息.\n");
	printf("请输入学号:");
	scanf("%d", &pstu->num);
	if (search_student_info(pstu->num)) { //判断该记录是否存在
		printf("学号为%d的记录已存在!\n", pstu->num);
		return FALSE;
	}
	printf("请输入姓名:");
	scanf("%s", pstu->name);
	printf("请输入年龄:");
	scanf("%d", &pstu->age);
	printf("请输入性别:");
	scanf("%s", pstu->sex);
	printf("请输入出生年月:");
	scanf("%s", pstu->birthday);
	printf("请输入地址:");
	scanf("%s", pstu->address);
	printf("请输入电话:");
	scanf("%s", pstu->telephone);
	//插入数据
	pstu->next = student_list->next;
	student_list->next = pstu;
	return TRUE;
}

int delete_student_info(int num) {
	student_info *pstu;
	student_info *qstu;
	if (!search_student_info(num)) {
		printf("不存在学号为%d的记录!\n", num);
		return FALSE;
	}
	pstu = student_list->next;
	qstu = student_list;
	while (pstu->num != num) {
		qstu = pstu;
		pstu = pstu->next;
	}
	qstu->next = pstu->next;
	free(pstu);
	return TRUE;
}

student_info* search_student_info(int num) {
	student_info *pstu;
	pstu = student_list->next;
	while (pstu && (pstu->num != num)) {
		pstu = pstu->next;
	}
	return pstu;
}

int modify_student_info(int num) {
	int choice; //用户选择
	student_info *pstu = search_student_info(num);
	if (pstu == NULL) {
		printf("不存在学号为%d的记录!\n", num);
		return FALSE;
	}
	printf("1.修改姓名.\n");
	printf("2.修改年龄.\n");
	printf("3.修改性别.\n");
	printf("4.修改出生年月.\n");
	printf("5.修改地址.\n");
	printf("6.修改电话.\n");
	printf("请选择要修改的信息:");
	scanf("%d", &choice);
	switch (choice) {
	case 1:
		printf("请输入新的姓名:");
		scanf("%s", pstu->name);
		break;
	case 2:
		printf("请输入新的年龄:");
		scanf("%d", &pstu->age);
		break;
	case 3:
		printf("请输入新的性别:");
		scanf("%s", pstu->sex);
		break;
	case 4:
		printf("请输入新的出生年月:");
		scanf("%s", pstu->birthday);
		break;
	case 5:
		printf("请输入新的地址:");
		scanf("%s", pstu->address);
		break;
	case 6:
		printf("请输入新的地址:");
		scanf("%s", pstu->telephone);
		break;
	default:
		printf("输入错误，请重新选择操作!\n");
	}
	return TRUE;
}

int read_file() {
	FILE *pfile; //文件指针
	student_info *pstu; //链表指针
	pfile = fopen("student.txt", "r");
	if (!pfile) {
		printf("打开文件失败!\n");
		return FALSE;
	}
	fgetc(pfile);
	while (!feof(pfile)) {
		pstu = (student_info*) malloc(sizeof(student_info));
		fscanf(pfile, "%d%s%d%s%s%s", &pstu->num, pstu->name, &pstu->age,
				pstu->sex, pstu->address, pstu->telephone);
		//插入记录
		pstu->next = student_list->next;
		student_list->next = pstu;
		fgetc(pfile);
		fgetc(pfile);
	}
	if (!pfile) { //关闭文件
		fclose(pfile);
	}
	return TRUE;
}

//将学生信息保存到文件
int save_file() {
	FILE *pfile;
	student_info *pstu;
	pfile = fopen("student.txt", "w");
	if (!pfile) {
		printf("打开文件失败.\n");
		return FALSE;
	}
	pstu = student_list->next;
	while (pstu) {
		fprintf(pfile, " %d\t%s\t%d\t%s\t%s\t%s\t", pstu->num, pstu->name,
				pstu->age, pstu->sex, pstu->address, pstu->telephone);
		pstu = pstu->next;
	}
	if (!pstu) { //释放内存
		free(pstu);
	}
	if (!pfile) { //关闭文件
		fclose(pfile);
	}
	return TRUE;
}
