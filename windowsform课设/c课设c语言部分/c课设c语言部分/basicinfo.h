#pragma once

//includeͷ�ļ�
#include<stdlib.h>
#include<string.h>

//����ṹ����
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
	struct guest_node *cnext;  /**< ָ������ⷿ��Ϣ֧����ָ��*/
	struct basicinfo_node *next;  /**< ָ����һ���ָ��*/
} BI_NODE;

/**
*�����ⷿ��Ϣ�����ṹ
*/
typedef struct guest_node {
	char id[20];            /**< ���֤��*/
	char name[20];              /**< ��������*/
	char room_no[4];                   /**< ��ס�ͷ����*/
	char tin[18];          /**< ��סʱ��*/
	char tout[18];               /**< �˷�ʱ��*/
	float staymonth;                  /**< ��ס����*/
	float deposit;        /**< Ѻ��*/
	float tpay;          /**< Ӧ�ɷ���*/
	float rpay;            /**< ʵ�ɷ���*/
	struct guest_node *next;      /**< ָ����һ����ָ��*/
} G_NODE;

/**
*�ͷ�������Ϣ�����ṹ
*/
typedef struct roomtype_node {
	char rtype;         /**< �ͷ����*/
	int max;           /**< �����ס����*/
	int suite_no;            /**< �ͷ�����*/
	int rfree;       /**< �ͷ�δס����*/
	struct basicinfo_node *snext;  /**< ָ��ͷ�������Ϣ֧����ָ��*/
	struct roomtype_node *next;  /**< ָ����һ����ָ��*/
} ROOM_NODE;

/**
*�����ⷿͳ�������ṹ
*/
typedef struct count_node {
	char id[20];            /**< ���֤��*/
	char name[20];              /**< ��������*/
	float staymonth;                  /**< ��ס����*/
	float tpay;          /**< Ӧ�ɷ���*/
	float rpay;            /**< ʵ�ɷ���*/
	struct count_node *next;      /**< ָ����һ����ָ��*/
} C_NODE;

//�������������庯��ע����cpp�ļ��У� 
void Creatlist(ROOM_NODE **phead);
void Printlist(ROOM_NODE *phead);
void type_printtodoc(ROOM_NODE *phead);
void type_del_list(ROOM_NODE **headp);
void type_change(ROOM_NODE *head);
void basic_printtodoc(ROOM_NODE *phead);
void basic_del_list(ROOM_NODE **headp);
void basic_change(ROOM_NODE *head);
void guest_printtodoc(ROOM_NODE *phead);
void guest_del_list(ROOM_NODE **headp);
void guest_change(ROOM_NODE *head);
void type_search(ROOM_NODE *head);
void basic_search_rn(ROOM_NODE *head);
void basic_search_tr(ROOM_NODE *head);
void g_search_id(ROOM_NODE *head);
void g_search_nt(ROOM_NODE *head);
void count1(ROOM_NODE*head);
void count2(ROOM_NODE*head);
void count3(ROOM_NODE*head);
void count4(ROOM_NODE*head);
void count5(ROOM_NODE*head);
C_NODE *count_list(ROOM_NODE *hd);
void sort_list(C_NODE *hd);
float c_month(char*tstart, char*tend);
 
