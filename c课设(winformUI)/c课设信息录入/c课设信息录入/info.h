#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#define  EX_API __declspec(dllexport)   //����ڲ�ͬ���Ե����µ�����ƥ������

/**
*�ͷ�������Ϣ�����ṹ
*/
typedef struct basicinfo_node {
	char room_no[4];           /**< �ͷ����*/
	char tel[5];             /**< �绰����*/
	char rtype;             /**< �ͷ����*/
	float S;                 /**< �ͷ����*/
	float rent;            /**< ÿ�����*/
	char balcony;             /**< �Ƿ�����̨*/
	char occupied;            /**< �Ƿ�������ס*/
	struct basicinfo_node *next;  /**< ָ����һ���ָ��*/
} BI_NODE;

FILE *fp,*fp1;
BI_NODE *head = NULL;

EX_API void Rtype_add(char rt,int suite_no,int rfree);            //����c����ͷ������Ϣ
EX_API void Guest_add(char*id,char*name,char*room_no,char*tin,char*tout,float deposit,float tpay,float rpay);            //����c��������ⷿ��Ϣ
EX_API void Basic_add(char*room_no,char rt,float s,float rent,char balcony,char occupied);            //����c����ͷ�������Ϣ
EX_API float c_month(char*tstart, char*tend);
void create_list(BI_NODE**phead);
float seek_rent(BI_NODE *head, char*room_no);