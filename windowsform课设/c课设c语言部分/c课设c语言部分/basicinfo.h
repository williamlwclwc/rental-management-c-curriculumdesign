#pragma once

//include头文件
#include<stdlib.h>
#include<string.h>

//定义结构变量
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
	struct guest_node *cnext;  /**< 指向客人租房信息支链的指针*/
	struct basicinfo_node *next;  /**< 指向下一结点指针*/
} BI_NODE;

/**
*客人租房信息链结点结构
*/
typedef struct guest_node {
	char id[20];            /**< 身份证号*/
	char name[20];              /**< 客人姓名*/
	char room_no[4];                   /**< 入住客房编号*/
	char tin[18];          /**< 入住时间*/
	char tout[18];               /**< 退房时间*/
	float staymonth;                  /**< 入住月数*/
	float deposit;        /**< 押金*/
	float tpay;          /**< 应缴费用*/
	float rpay;            /**< 实缴费用*/
	struct guest_node *next;      /**< 指向下一结点的指针*/
} G_NODE;

/**
*客房分类信息链结点结构
*/
typedef struct roomtype_node {
	char rtype;         /**< 客房类别*/
	int max;           /**< 最多入住人数*/
	int suite_no;            /**< 客房套数*/
	int rfree;       /**< 客房未住套数*/
	struct basicinfo_node *snext;  /**< 指向客房基本信息支链的指针*/
	struct roomtype_node *next;  /**< 指向下一结点的指针*/
} ROOM_NODE;

/**
*客人租房统计链结点结构
*/
typedef struct count_node {
	char id[20];            /**< 身份证号*/
	char name[20];              /**< 客人姓名*/
	float staymonth;                  /**< 入住月数*/
	float tpay;          /**< 应缴费用*/
	float rpay;            /**< 实缴费用*/
	struct count_node *next;      /**< 指向下一结点的指针*/
} C_NODE;

//函数声明（具体函数注释在cpp文件中） 
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
 
