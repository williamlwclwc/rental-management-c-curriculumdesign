#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#define  EX_API __declspec(dllexport)   //解决在不同语言调用下的名字匹配问题

/**
*客房基本信息链结点结构
*/
typedef struct basicinfo_node {
	char room_no[4];           /**< 客房编号*/
	char tel[5];             /**< 电话号码*/
	char rtype;             /**< 客房类别*/
	float S;                 /**< 客房面积*/
	float rent;            /**< 每月租金*/
	char balcony;             /**< 是否有阳台*/
	char occupied;            /**< 是否有人入住*/
	struct basicinfo_node *next;  /**< 指向下一结点指针*/
} BI_NODE;

FILE *fp,*fp1;
BI_NODE *head = NULL;

EX_API void Rtype_add(char rt,int suite_no,int rfree);            //调用c保存客房类别信息
EX_API void Guest_add(char*id,char*name,char*room_no,char*tin,char*tout,float deposit,float tpay,float rpay);            //调用c保存客人租房信息
EX_API void Basic_add(char*room_no,char rt,float s,float rent,char balcony,char occupied);            //调用c保存客房基本信息
EX_API float c_month(char*tstart, char*tend);
void create_list(BI_NODE**phead);
float seek_rent(BI_NODE *head, char*room_no);