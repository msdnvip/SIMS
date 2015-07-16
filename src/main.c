/*
 * main.c
 *
 *  Created on: 2015年7月15日
 *      Author: golooloo
 */

#include"main.h"
#include"student.h"

//全局的学生信息结构体变量
student_info* student_list;

int main() {
	int choice; //用户选择
	int num; //学号
	//初始化学生信息结构体变量
	if (!init_student_info_list()) {
		if (!student_list) {	//释放内存
			free(student_list);
		}
		return 0;
	}
	printf("***************************\n");
	printf("*     学生信息管理系统     *\n");
	printf("***************************\n");
	printf("---------------------------\n");
	if (read_file()) {
		printf("初始化成功,欢迎使用!\n");
	} else {
		printf("初始化失败,请检查后重启程序!\n");
		getchar();
		return 0;
	}
	printf("---------------------------\n");
	printf("-----------菜单------------\n");
	printf("---------------------------\n");
	menu();	//打印菜单
	while (TRUE) {
		printf("请选择操作:");
		scanf("%d", &choice);
		switch (choice) {
		case 1:
			if (student_list_empty()) {
				printf("学生信息表为空,请先添加学生信息!\n");
			} else {
				display_student_info();
			}
			break;
		case 2:
			if (add_student_info()) {
				printf("添加学生信息成功!\n");
			} else {
				printf("添加学生信息失败!\n");
				getchar();
				return 0;
			}
			break;
		case 3:
			if (student_list_empty()) {
				printf("学生信息表为空,请先添加学生信息!\n");
			} else {
				printf("请输入要删除学生信息记录的学号:");
				scanf("%d", &num);
				if (delete_student_info(num)) {
					printf("学号为%d的学生记录删除成功!\n", num);
				} else {
					printf("删除失败!\n");
				}
			}
			break;
		case 4:
			if (student_list_empty()) {
				printf("学生信息表为空,请先添加学生信息!\n");
			} else {
				printf("请输入要修改学生信息记录的学号:");
				scanf("%d", &num);
				if (modify_student_info(num))
					printf("学号为%d的学生记录修改成功!\n", num);
				else
					printf("修改失败!\n");
			}
			break;
		case 5:
			if (student_list_empty()) {
				printf("学生信息表为空,请先添加学生信息!\n");
			} else {
				if (save_file()) {
					printf("保存学生信息成功!\n");
				} else {
					printf("保存学生信息失败!\n");
				}
			}
			break;
		case 0:
			printf("欢迎下次使用,再见!\n");
			system("pause");
			exit(0);
			break;
		default:
			printf("输入错误，请重新选择操作!\n");
		}
	}
	if (!student_list) {	//释放内存
		free(student_list);
	}
	return 0;
}

void menu() {
	printf("1.查看学生信息.\n");
	printf("2.添加学生信息.\n");
	printf("3.删除学生信息.\n");
	printf("4.修改学生信息.\n");
	printf("5.保存学生信息.\n");
	printf("0.退出系统操作.\n");
}
