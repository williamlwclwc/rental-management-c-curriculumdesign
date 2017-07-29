// c课设c语言部分.cpp : 定义控制台应用程序的入口点。

//引入包含基本信息的头文件
#include "stdafx.h"
#include"basicinfo.h"
//定义全局变量
FILE *fp;
ROOM_NODE *head = NULL;
//主函数（main）
int main(int argc,char *argv[])
{
	int i=atoi(argv[1]);
//读取文件信息，创建三大类信息的十字交叉链表
	Creatlist(&head);
//根据调用界面的信息，执行相应子函数
	switch(i)
	{
		case 0:
			type_del_list(&head);//删除客房分类信息
			break;
		case 1:
			type_change(head);//修改客房分类信息
			break;
		case 2:
			basic_del_list(&head);//删除客房基本信息
			break;
		case 3:
			basic_change(head);//修改客房基本信息
			break;
		case 4:
			guest_del_list(&head);//删除客人租房信息
			break;
		case 5:
			guest_change(head);//修改客人租房信息
			break;
		case 6:
			type_search(head);//客房类别查询 
			break;
		case 7:
			basic_search_rn(head);//客房基本信息查询：按客房编号 
			break;
		case 8:
			basic_search_tr(head);//客房基本信息查询：按类别、租金 
			break;
		case 9:
			g_search_id(head);//客人租房信息查询：按身份证号 
			break;
		case 10:
			g_search_nt(head);//客人租房信息查询：按姓名、时间 
			break;
	    case 11:
			count1(head);//统计每种类别的客房总数，入住数，未住数
	    	break;
	    case 12:
	    	count2(head);//按月统计本年度各类客房的营业额
	    	break;
	    case 13:
	    	count3(head);//输入年份，统计该年所有客房的营业额，入住月数，入住率
	    	break;
	    case 14:
	    	count4(head);//列出历年来累计出租月数最多的10个客人租房信息，按月数降序排序后输出
	    	break;
	    case 15:
	    	count5(head);//其他统计 
	    	break;
	}
	//测试链表信息
	//Printlist(head);
    return 0;
}

//自定义子函数

//创建信息链表
void Creatlist(ROOM_NODE **phead)
{
	int find=0,ret;
	char rt;
	ROOM_NODE *hd = NULL, *prtype;
	BI_NODE *pbi;
	G_NODE *pg;
	if ((fp = fopen("客房类别信息.txt", "r+")) == NULL)
	{
		printf("客房类别信息打开失败\n");
	}
	while (!feof(fp))
	{
		ret=fscanf(fp, "%c", &rt);
		if (ret == -1)
		{
			break;
		}
		else
		{
			prtype = (ROOM_NODE*)malloc(sizeof(ROOM_NODE));
			prtype->rtype = rt;
		}
		fscanf(fp, "%d", &prtype->max);
		fscanf(fp, "%d", &prtype->suite_no);
		fscanf(fp, "%d", &prtype->rfree);
		prtype->snext = NULL;
		prtype->next = hd;
		hd = prtype;
	}
	fclose(fp);
	*phead = hd;
	if ((fp = fopen("客房基本信息.txt", "r+")) == NULL)
	{
		printf("客房基本信息打开失败\n");
	}
	char room_no[20];
	while (!feof(fp))
	{
		ret=fscanf(fp, "%s", room_no);
		if (ret == -1)
		{
			break;
		}
		else
		{
			pbi = (BI_NODE*)malloc(sizeof(BI_NODE));
			strcpy(pbi->room_no,room_no);
		}
		fscanf(fp, "%s", pbi->tel);
		fscanf(fp, "%c", &pbi->rtype);
		fscanf(fp, "%c", &pbi->rtype);
		fscanf(fp, "%f", &pbi->S);
		fscanf(fp, "%f", &pbi->rent);
		fscanf(fp, "%c", &pbi->balcony);
		fscanf(fp, "%c", &pbi->balcony);
		fscanf(fp, "%c", &pbi->occupied);
		pbi->cnext = NULL;
		prtype = hd;
		while (prtype != NULL&&(prtype->rtype!=pbi->rtype))
		{
			prtype = prtype->next;
		}
		if (prtype != NULL)
		{
			pbi->next = prtype->snext;
			prtype->snext = pbi;
		}
		else
		{
			free(pbi);
		}
	}
	fclose(fp);
	if ((fp = fopen("客人租房信息.txt", "r+")) == NULL)
	{
		printf("客人租房信息打开失败\n");
	}
	while (!feof(fp))
	{
		find = 0;
		ret=fscanf(fp, "%s", room_no);
		if (ret == -1)
		{
			break;
		}
		else
		{
			pg = (G_NODE*)malloc(sizeof(G_NODE));
			strcpy(pg->id, room_no);
		}
		fscanf(fp, "%s", pg->name);
		fscanf(fp, "%s", pg->room_no);
		fscanf(fp, "%s", pg->tin);
		fscanf(fp, "%s", pg->tout);
		fscanf(fp, "%f %f %f %f ", &pg->staymonth,&pg->deposit,&pg->tpay,&pg->rpay);
		prtype = hd;
		while (prtype != NULL&&find == 0)
		{
			pbi = prtype->snext;
			while (pbi != NULL&&find == 0)
			{
				if (strcmp(pbi->room_no, pg->room_no) == 0)
				{
					find = 1;
					break;
				}
				pbi = pbi->next;
			}
			prtype = prtype->next;
		}
		if (find)
		{
			pg->next = pbi->cnext;
			pbi->cnext = pg;
		}
		else
		{
			free(pg);
		}
	}
	fclose(fp);
}
//遍历链表，检查链表数据(测试用)
void Printlist(ROOM_NODE *phead)
{
	ROOM_NODE *prt = phead;
	BI_NODE *pbi;
	G_NODE *pg;
	while (prt != NULL)
	{
		printf("%c\n",prt->rtype);
		printf("%d\n", prt->max);
		printf("%d\n", prt->suite_no);
		printf("%d\n", prt->rfree);
		pbi = prt->snext;
		while (pbi != NULL)
		{
			printf("%s\n",pbi->room_no);
			printf("%s\n", pbi->tel);
			printf("%c\n", pbi->rtype);
			printf("%f\n", pbi->S);
			printf("%f\n", pbi->rent);
			printf("%c\n", pbi->balcony);
			printf("%c\n", pbi->occupied);
			pg = pbi->cnext;
			while (pg != NULL)
			{
				printf("%s\n",pg->id);
				printf("%s\n", pg->name);
				printf("%s\n", pg->room_no);
				printf("%s\n", pg->tin);
				printf("%s\n", pg->tout);
				printf("%f\n", pg->staymonth);
				printf("%f\n", pg->deposit);
				printf("%f\n", pg->tpay);
				printf("%f\n", pg->rpay);
				pg = pg->next;
			}
			pbi = pbi->next;
		}
		prt = prt->next;
	}
}

//第一部分：数据维护
 //将改动信息输出至文件
void type_printtodoc(ROOM_NODE *phead)
{
	fp = fopen("客房类别信息.txt", "w+");
	do
	{
		fprintf(fp, "%c", phead->rtype);
		fprintf(fp, "%d ", phead->max);
		fprintf(fp, "%d ", phead->suite_no);
		fprintf(fp, "%d", phead->rfree);
		phead = phead->next;
	} while (phead != NULL);
	fclose(fp);
}
//删除客房分类信息链表
void type_del_list(ROOM_NODE **headp)
{
	ROOM_NODE *current = *headp, *prior = *headp;
	char rt;
	if ((fp = fopen("函数参数.txt", "r+")) == NULL)
	{
		fclose(fp);
		return;
	}
	fscanf(fp, "%c", &rt);
	fclose(fp);
	while (current->rtype != rt)
	{
		if (current->next == NULL)
		{
			return;
		}
		else
		{
			prior = current;
			current = current->next;
		}
	}
	if (current == *headp)
	{
		*headp = current->next;
	}
	else
	{
		prior->next = current->next;
	}
	free(current);
	type_printtodoc(head);
}
//修改客房分类信息链表
void type_change(ROOM_NODE *head)
{
	ROOM_NODE*current = head;
	char rt;
	char editobj[50];
	if ((fp = fopen("函数参数.txt", "r+")) == NULL)
	{
		printf("没有输入参数\n");
		fclose(fp);
		return;
	}
	//读取文件中参数
	fscanf(fp, "%c", &rt);
	fscanf(fp, "%s", editobj);
	fclose(fp);
	while (current->rtype != rt)
	{
		if (current->next == NULL)
		{
			return;
		}
		else
		{
			current = current->next;
		}
	}
	if (!strcmp(editobj, "客房类别"))
	{
		fscanf(fp, "%c", &current->rtype);
	}
	if (!strcmp(editobj, "最多入住人数"))
	{
		fscanf(fp, "%d", &current->max);
	}
	if (!strcmp(editobj, "客房套数"))
	{
		fscanf(fp, "%d", &current->suite_no);
	}
	if (!strcmp(editobj, "客房未入住套数"))
	{
		fscanf(fp, "%d", &current->rfree);
	}
	type_printtodoc(head);
}
//以上为：客房分类信息维护
//将改动信息输出至文件
void basic_printtodoc(ROOM_NODE *phead)
{
	fp = fopen("客房基本信息.txt", "w+");
	ROOM_NODE *prt = phead;
	BI_NODE *pbi;
	while (prt != NULL)
	{
		pbi = prt->snext;
		while (pbi != NULL)
		{
			fprintf(fp,"%s\n", pbi->room_no);
			fprintf(fp,"%s\n", pbi->tel);
			fprintf(fp,"%c", pbi->rtype);
			fprintf(fp,"%f ", pbi->S);
			fprintf(fp,"%f ", pbi->rent);
			fprintf(fp,"%c", pbi->balcony);
			fprintf(fp,"%c", pbi->occupied);
			pbi = pbi->next;
		}
		prt = prt->next;
	}
	fclose(fp);
}
//删除客房基本信息链表
void basic_del_list(ROOM_NODE **headp)
{
	if ((fp = fopen("函数参数.txt", "r+")) == NULL)
	{
		fclose(fp);
		return;
	}
	char room_no[20];
	fscanf(fp, "%s", room_no);
	fclose(fp);
	ROOM_NODE *crt = *headp;
	BI_NODE *cbi, *pbi;
	while (crt != NULL)
	{
		cbi = crt->snext;
		pbi = crt->snext;
		while (cbi != NULL)
		{
			if (strcmp(room_no, cbi->room_no) == 0)
			{
				if (cbi == crt->snext)
				{
					crt->snext = cbi->next;
				}
				else
				{
					pbi->next = cbi->next;
				}
				free(cbi);
				break;
			}
			else
			{
				cbi = cbi->next;
			}
		}
		crt = crt->next;
	}
	basic_printtodoc(head);
}
//修改客房基本信息链表
void basic_change(ROOM_NODE *head)
{
	if ((fp = fopen("函数参数.txt", "r+")) == NULL)
	{
		fclose(fp);
		return;
	}
	char room_no[20];
	char editobj[20];
	char ch;
	//读取文件中参数
	fscanf(fp, "%s", room_no);
	fscanf(fp, "%s", editobj);
	fscanf(fp, "%c", &ch);
	ROOM_NODE *crt = head;
	BI_NODE *cbi;
	while (crt != NULL)
	{
		cbi = crt->snext;
		while (cbi != NULL)
		{
			if (strcmp(room_no, cbi->room_no) == 0)
			{
				if (!strcmp(editobj, "客房编号"))
				{
					fscanf(fp, "%s", cbi->room_no);
					goto inx;
				}
				if (!strcmp(editobj, "电话号码"))
				{
					fscanf(fp, "%s", cbi->tel);
					goto inx;
				}
				if (!strcmp(editobj, "客房类别"))
				{
					fscanf(fp, "%c", &cbi->rtype);
					goto inx;
				}
				if (!strcmp(editobj, "客房面积"))
				{
					fscanf(fp, "%f", &cbi->S);
					goto inx;
				}
				if (!strcmp(editobj, "每月租金"))
				{
					fscanf(fp, "%f", &cbi->rent);
					goto inx;
				}
				if (!strcmp(editobj, "是否有阳台"))
				{
					fscanf(fp, "%c", &cbi->balcony);
					goto inx;
				}
				if (!strcmp(editobj, "是否有客人入住"))
				{
					fscanf(fp, "%c", &cbi->occupied);
					goto inx;
				}
			}
			else
			{
				cbi = cbi->next;
			}
		}
		crt = crt->next;
	}
inx:
	basic_printtodoc(head);
	fclose(fp);
}
//以上为：客房基本信息维护
//将改动信息输出至文件
void guest_printtodoc(ROOM_NODE *phead)
{
	fp = fopen("客人租房信息.txt", "w+");
	ROOM_NODE *prt = phead;
	BI_NODE *pbi;
	G_NODE *pg;
	while (prt != NULL)
	{
		pbi = prt->snext;
		while (pbi != NULL)
		{
			pg = pbi->cnext;
			while (pg != NULL)
			{
				fprintf(fp,"%s\n", pg->id);
				fprintf(fp,"%s\n", pg->name);
				fprintf(fp,"%s\n", pg->room_no);
				fprintf(fp,"%s\n", pg->tin);
				fprintf(fp,"%s\n", pg->tout);
				fprintf(fp,"%f ", pg->staymonth);
				fprintf(fp,"%f ", pg->deposit);
				fprintf(fp,"%f ", pg->tpay);
				fprintf(fp,"%f ", pg->rpay);
				pg = pg->next;
			}
			pbi = pbi->next;
		}
		prt = prt->next;
	}
}
//删除客人租房信息链表
void guest_del_list(ROOM_NODE **phead)
{
	if ((fp = fopen("函数参数.txt", "r+")) == NULL)
	{
		fclose(fp);
		return;
	}
	char id[20];
	fscanf(fp, "%s",id);
	fclose(fp);
	ROOM_NODE *crt = *phead;
	BI_NODE *cbi;
	G_NODE *cg, *pg;
	while (crt != NULL)
	{
		cbi = crt->snext;
		while (cbi != NULL)
		{
			cg = cbi->cnext;
			pg = cbi->cnext;
			while (cg != NULL)
			{
				if(strcmp(id, cg->id) == 0)
				{
					if (cg == cbi->cnext)
					{
						cbi->cnext = cg->next;
					}
					else
					{
						pg->next = cg->next;
					}
					free(cg);
					break;
				}
				else
				{
					cg = cg->next;
				}
			}
			cbi = cbi->next;
		}
		crt = crt->next;
	}
	guest_printtodoc(head);
}
//修改客人租房信息链表
void guest_change(ROOM_NODE *head)
{
	if ((fp = fopen("函数参数.txt", "r+")) == NULL)
	{
		fclose(fp);
		return;
	}
	char id[20];
	char editobj[20];
	char ch;
	//读取文件中参数
	fscanf(fp, "%s", id);
	fscanf(fp, "%s", editobj);
	fscanf(fp, "%c", &ch);
	ROOM_NODE *crt = head;
	BI_NODE *cbi;
	G_NODE *cg;
	while (crt != NULL)
	{
		cbi = crt->snext;
		while (cbi != NULL)
		{
			cg = cbi->cnext;
			while (cg != NULL)
			{
				if (strcmp(id, cg->id) == 0)
				{
					if (!strcmp(editobj, "身份证号"))
					{
						fscanf(fp, "%s", cg->id);
						goto inx;
					}
					if (!strcmp(editobj, "客人姓名"))
					{
						fscanf(fp, "%s", cg->name);
						goto inx;
					}
					if (!strcmp(editobj, "入住客房编号"))
					{
						fscanf(fp, "%s", cg->room_no);
						goto inx;
					}
					if (!strcmp(editobj, "入住时间"))
					{
						fscanf(fp, "%s", cg->tin);
						goto inx;
					}
					if (!strcmp(editobj, "退房时间"))
					{
						fscanf(fp, "%s", cg->tout);
						goto inx;
					}
					if (!strcmp(editobj, "入住月数"))
					{
						fscanf(fp, "%f", &cg->staymonth);
						goto inx;
					}
					if (!strcmp(editobj, "押金"))
					{
						fscanf(fp, "%f", &cg->deposit);
						goto inx;
					}
					if (!strcmp(editobj, "应缴费用"))
					{
						fscanf(fp, "%f", &cg->tpay);
						goto inx;
					}
					if (!strcmp(editobj, "实缴费用"))
					{
						fscanf(fp, "%f", &cg->rpay);
						goto inx;
					}
				}
				else
				{
					cg = cg->next;
				}
			}
		cbi = cbi->next;
		}
		crt = crt->next;
	}
inx:
	guest_printtodoc(head);
	fclose(fp);
}
//以上为：客人租房信息维护

// 第二部分：数据查询
//客房类别查询 
void type_search(ROOM_NODE *head) 
{
	ROOM_NODE*current = head;
	char rt;
	if ((fp = fopen("函数参数.txt", "r+")) == NULL)
	{
		printf("没有输入参数\n");
		fclose(fp);
		return;
	}
	//读取文件中参数
	fscanf(fp, "%c", &rt);
	fclose(fp);
	while (current->rtype != rt)
	{
		if (current->next == NULL)
		{
			return;
		}
		else
		{
			current = current->next;
		}
	}
	if ((fp = fopen("结果.txt", "w+")) == NULL)
	{
		printf("没有找到文件\n");
		fclose(fp);
		return;
	}
	fprintf(fp, "客房类别：%c\n", current->rtype);
	fprintf(fp, "最多入住人数：%d\n", current->max);
	fprintf(fp, "客房套数：%d\n", current->suite_no);
	fprintf(fp, "客房未入住人数%d\n", current->rfree);
	fclose(fp);
}
//以上为：客房类别查询 
//客房基本信息查询：按客房编号 
void basic_search_rn(ROOM_NODE *head)
{
	if ((fp = fopen("函数参数.txt", "r+")) == NULL)
	{
		fclose(fp);
		return;
	}
	char room_no[20];
	char balcony[10];
	char occupied[20];
	//读取文件中参数
	fscanf(fp, "%s", room_no);
	fclose(fp);
	ROOM_NODE *crt = head;
	BI_NODE *cbi;
	while (crt != NULL)
	{
		cbi = crt->snext;
		while (cbi != NULL)
		{
			if (strcmp(room_no, cbi->room_no) == 0)
			{
				if ((fp = fopen("结果.txt", "w+")) == NULL)
				{
					fclose(fp);
					return;
				}
				fprintf(fp, "客房编号：%s\n", cbi->room_no);
				fprintf(fp, "电话号码：%s\n", cbi->tel);
				fprintf(fp, "客房类别：%c\n", cbi->rtype);
				fprintf(fp, "客房面积：%f\n", cbi->S);
				fprintf(fp, "每月租金：%f\n", cbi->rent);
				if (cbi->balcony == '1')
				{
					strcpy(balcony,"有阳台");
				}
				else
				{
					 strcpy(balcony,"无阳台");
				}
				fprintf(fp, "是否有阳台：%s\n", balcony);
				if (cbi->occupied == 'y')
				{
					strcpy(occupied, "有客人入住");
				}
				else
				{
					strcpy(occupied, "无客人在住");
				}
				fprintf(fp, "是否已入住：%s\n", occupied);
				fclose(fp);
				return;
			}
			cbi = cbi->next;
		}
		crt = crt->next;
	}
}
//客房基本信息查询：按类别、租金 
void basic_search_tr(ROOM_NODE *head)
{
	if ((fp = fopen("函数参数.txt", "r+")) == NULL)
	{
		fclose(fp);
		return;
	}
	float rent;
	char rt,ch;
	char balcony[10], occupied[20];
	//读取文件中参数
	fscanf(fp, "%c", &rt);
	fscanf(fp, "%c", &ch);
	fscanf(fp, "%f",&rent);
	fclose(fp);
	ROOM_NODE *crt = head;
	BI_NODE *cbi;
	if ((fp = fopen("结果.txt", "w+")) == NULL)
	{
		fclose(fp);
		return;
	}
	while (crt != NULL)
	{
		if (crt->rtype == rt)
		{
			cbi = crt->snext;
		}
		else
		{
			crt = crt->next;
			continue;
		}
		while (cbi != NULL)
		{
			if (rent==cbi->rent)
			{
				fprintf(fp, "客房编号：%s\n", cbi->room_no);
				fprintf(fp, "电话号码：%s\n", cbi->tel);
				fprintf(fp, "客房类别：%c\n", cbi->rtype);
				fprintf(fp, "客房面积：%f\n", cbi->S);
				fprintf(fp, "每月租金：%f\n", cbi->rent);
				if (cbi->balcony == '1')
				{
					strcpy(balcony, "有阳台");
				}
				else
				{
					strcpy(balcony, "无阳台");
				}
				fprintf(fp, "是否有阳台：%s\n", balcony);
				if (cbi->occupied == 'y')
				{
					strcpy(occupied, "有客人入住");
				}
				else
				{
					strcpy(occupied, "无客人在住");
				}
				fprintf(fp, "是否已入住：%s\n\n", occupied);
			}
			cbi = cbi->next;
		}
		crt = crt->next;
	}
	fclose(fp);
}
//以上为：客房基本信息查询 
//客人租房信息查询：按身份证号 
void g_search_id(ROOM_NODE *head)
{
	if ((fp = fopen("函数参数.txt", "r+")) == NULL)
	{
		fclose(fp);
		return;
	}
	char id[20];
	//读取文件中参数
	fscanf(fp, "%s", id);
	fclose(fp);
	ROOM_NODE *crt = head;
	BI_NODE *cbi;
	G_NODE *cg;
	while (crt != NULL)
	{
		cbi = crt->snext;
		while (cbi != NULL)
		{
			cg = cbi->cnext;
			while (cg != NULL)
			{
				if (strcmp(id, cg->id) == 0)
				{
					if ((fp = fopen("结果.txt", "w+")) == NULL)
					{
						fclose(fp);
						return;
					}
					fprintf(fp, "身份证号：%s\n", cg->id);
					fprintf(fp, "姓名：%s\n", cg->name);
					fprintf(fp, "所租房房间号：%s\n", cg->room_no);
					fprintf(fp, "入住时间：%s\n", cg->tin);
					if (cg->tout == "0")
					{
						fprintf(fp, "退房时间：%s\n", "在住");
					}
					else
					{
						fprintf(fp, "退房时间：%s\n", cg->tout);
					}
					fprintf(fp, "入住月数：%f\n", cg->staymonth);
					fprintf(fp, "押金：%f\n", cg->deposit);
					fprintf(fp, "应缴费用：%f\n", cg->tpay);
					fprintf(fp, "实缴费用：%f\n", cg->rpay);
					fclose(fp);
					return;
				}
				else
				{
					cg = cg->next;
				}
			}
			cbi = cbi->next;
		}
		crt = crt->next;
	}
}
//客人租房信息查询：按姓名、时间范围 
void g_search_nt(ROOM_NODE *head)
{
	if ((fp = fopen("函数参数.txt", "r+")) == NULL)
	{
		fclose(fp);
		return;
	}
	char name[20];
	char start[20];
	char end[20];
	//读取文件中参数
	fscanf(fp, "%s", name);
	fscanf(fp, "%s", start);
	fscanf(fp, "%s", end);
	fclose(fp);
	ROOM_NODE *crt = head;
	BI_NODE *cbi;
	G_NODE *cg;
	if ((fp = fopen("结果.txt", "w+")) == NULL)
	{
		fclose(fp);
		return;
	}
	while (crt != NULL)
	{
		cbi = crt->snext;
		while (cbi != NULL)
		{
			cg = cbi->cnext;
			while (cg != NULL)
			{
				if ((strstr(cg->name, name) != NULL)&&(strcmp(cg->tin,start)>=0)&&(strcmp(cg->tin,end)<=0))
				{
					fprintf(fp, "身份证号：%s\n", cg->id);
					fprintf(fp, "姓名：%s\n", cg->name);
					fprintf(fp, "所租房房间号：%s\n", cg->room_no);
					fprintf(fp, "入住时间：%s\n", cg->tin);
					if (cg->tout == "0")
					{
						fprintf(fp, "退房时间：%s\n", "在住");
					}
					else
					{
						fprintf(fp, "退房时间：%s\n", cg->tout);
					}
					fprintf(fp, "入住月数：%f\n", cg->staymonth);
					fprintf(fp, "押金：%f\n", cg->deposit);
					fprintf(fp, "应缴费用：%f\n", cg->tpay);
					fprintf(fp, "实缴费用：%f\n", cg->rpay);
				}
				cg = cg->next;
			}
			cbi = cbi->next;
		}
		crt = crt->next;
	}
	fclose(fp);
}
//以上为：客人租房信息查询
 
//第三部分：数据统计 
//统计每种类别的客房总数，入住数，未住数
void count1(ROOM_NODE*head)
{
	ROOM_NODE *prt = head;
	int sum_no=0, occupied=0, rfree=0;
	if ((fp = fopen("结果.txt", "w+")) == NULL)
	{
		fclose(fp);
		return;
	}
	while (prt != NULL)
	{
		if (prt->rtype == 'D')
		{
			fprintf(fp,"%s\t", "双人间");
			fprintf(fp,"%d\t", prt->suite_no);
			sum_no += prt->suite_no;
			fprintf(fp,"%d\t", prt->suite_no-prt->rfree);
			occupied += prt->suite_no - prt->rfree;
			fprintf(fp,"%d\n", prt->rfree);
			rfree += prt->rfree;
			prt = prt->next;
		}
		else if (prt->rtype == 'S')
		{
			fprintf(fp, "%s\t", "单人间");
			fprintf(fp, "%d\t", prt->suite_no);
			sum_no += prt->suite_no;
			fprintf(fp, "%d\t", prt->suite_no - prt->rfree);
			occupied += prt->suite_no - prt->rfree;
			fprintf(fp, "%d\n", prt->rfree);
			rfree += prt->rfree;
			prt = prt->next;
		}
		else if (prt->rtype == 'T')
		{
			fprintf(fp, "%s\t", "三人间");
			fprintf(fp, "%d\t", prt->suite_no);
			sum_no += prt->suite_no;
			fprintf(fp, "%d\t", prt->suite_no - prt->rfree);
			occupied += prt->suite_no - prt->rfree;
			fprintf(fp, "%d\n", prt->rfree);
			rfree += prt->rfree;
			prt = prt->next;
		}
		else if (prt->rtype == 'F')
		{
			fprintf(fp, "%s\t", "四人间");
			fprintf(fp, "%d\t", prt->suite_no);
			sum_no += prt->suite_no;
			fprintf(fp, "%d\t", prt->suite_no - prt->rfree);
			occupied += prt->suite_no - prt->rfree;
			fprintf(fp, "%d\n", prt->rfree);
			rfree += prt->rfree;
			prt = prt->next;
		}
	}
	fprintf(fp, "%s\t", "合计");
	fprintf(fp, "%d\t", sum_no);
	fprintf(fp, "%d\t", occupied);
	fprintf(fp, "%d\n", rfree);
	fclose(fp);
} 
//按月统计本年度各类客房的营业额
void count2(ROOM_NODE*head)
{
	if ((fp = fopen("函数参数.txt", "r+")) == NULL)
	{
		fclose(fp);
		return;
	}
	char time[20];
	fscanf(fp, "%s", time);//读入UI输入的年份信息
	char time0[20],time1[20],time2[20], time3[20], time4[20], time5[20], time6[20], time7[20], time8[20], time9[20], time10[20], time11[20], time12[20];
	strcpy(time1, time);
	strcpy(time2, time);
	strcpy(time3, time);
	strcpy(time4, time);
	strcpy(time5, time);
	strcpy(time6, time);
	strcpy(time7, time);
	strcpy(time8, time);
	strcpy(time9, time);
	strcpy(time10, time);
	strcpy(time11, time);
	strcpy(time12, time);
	strcpy(time0, time);
	strcat(time1, "/01/00-00:00");
	strcat(time2, "/02/00-00:00");
	strcat(time3, "/03/00-00:00");
	strcat(time4, "/04/00-00:00");
	strcat(time5, "/05/00-00:00");
	strcat(time6, "/06/00-00:00");
	strcat(time7, "/07/00-00:00");
	strcat(time8, "/08/00-00:00");
	strcat(time9, "/09/00-00:00");
	strcat(time10, "/10/00-00:00");
	strcat(time11, "/11/00-00:00");
	strcat(time12, "/12/00-00:00");
	strcat(time0, "/12/31-23:59");
	fclose(fp);
	ROOM_NODE *prt = head;
	BI_NODE *pbi;
	G_NODE *pg;
	//创建营业额数组，下标表示月份，下表为0用来表示合计
	float Sp[13] = { 0 }, Dp[13] = { 0 }, Tp[13] = { 0 }, Fp[13] = {0};
	if ((fp = fopen("结果.txt", "w+")) == NULL)
	{
		fclose(fp);
		return;
	}
	fprintf(fp, "年度：%s年\t\t", time);//输出统计时间条件
	//遍历链表
	while (prt != NULL)
	{
		pbi = prt->snext;
		while (pbi != NULL)
		{
			pg = pbi->cnext;
			while (pg != NULL)
			{
				if (prt->rtype == 'S')//判断客房种类
				{
					if (strcmp(pg->tout,time1)>=0&&strcmp(pg->tout,time2)<0)//退房时间为该年1月
					{
						Sp[1] += pg->rpay;//通过客人实缴费用计算营业额（下同）
					}
					else if (strcmp(pg->tout, time2) >= 0 && strcmp(pg->tout, time3)<0)//退房时间为2月
					{
						Sp[2] += pg->rpay;
					}
					else if (strcmp(pg->tout, time3) >= 0 && strcmp(pg->tout, time4)<0)//退房时间为3月
					{
						Sp[3] += pg->rpay;
					}
					else if (strcmp(pg->tout, time4) >= 0 && strcmp(pg->tout, time5)<0)//退房时间为4月
					{
						Sp[4] += pg->rpay;
					}
					else if (strcmp(pg->tout, time5) >= 0 && strcmp(pg->tout, time6)<0)//退房时间为5月
					{
						Sp[5] += pg->rpay;
					}
					else if (strcmp(pg->tout, time6) >= 0 && strcmp(pg->tout, time7)<0)//退房时间为6月
					{
						Sp[6] += pg->rpay;
					}
					else if (strcmp(pg->tout, time7) >= 0 && strcmp(pg->tout, time8)<0)//退房时间为7月
					{
						Sp[7] += pg->rpay;
					}
					else if (strcmp(pg->tout, time8) >= 0 && strcmp(pg->tout, time9)<0)//退房时间为8月
					{
						Sp[8] += pg->rpay;
					}
					else if (strcmp(pg->tout, time9) >= 0 && strcmp(pg->tout, time10)<0)//退房时间为9月
					{
						Sp[9] += pg->rpay;
					}
					else if (strcmp(pg->tout, time10) >= 0 && strcmp(pg->tout, time11)<0)//退房时间为10月
					{
						Sp[10] += pg->rpay;
					}
					else if (strcmp(pg->tout, time11) >= 0 && strcmp(pg->tout, time12)<0)//退房时间为11月
					{
						Sp[11] += pg->rpay;
					}
					else if (strcmp(pg->tout, time12) >= 0 && strcmp(pg->tout, time0)<=0)//退房时间为12月
					{
						Sp[12] += pg->rpay;
					}
				}
				if (prt->rtype == 'D')//判断客房种类
				{
					if (strcmp(pg->tout, time1) >= 0 && strcmp(pg->tout, time2)<0)//退房时间为该年1月
					{
						Dp[1] += pg->rpay;//通过客人实缴费用计算营业额（下同）
					}
					else if (strcmp(pg->tout, time2) >= 0 && strcmp(pg->tout, time3)<0)//退房时间为2月
					{
						Dp[2] += pg->rpay;
					}
					else if (strcmp(pg->tout, time3) >= 0 && strcmp(pg->tout, time4)<0)//退房时间为3月
					{
						Dp[3] += pg->rpay;
					}
					else if (strcmp(pg->tout, time4) >= 0 && strcmp(pg->tout, time5)<0)//退房时间为4月
					{
						Dp[4] += pg->rpay;
					}
					else if (strcmp(pg->tout, time5) >= 0 && strcmp(pg->tout, time6)<0)//退房时间为5月
					{
						Dp[5] += pg->rpay;
					}
					else if (strcmp(pg->tout, time6) >= 0 && strcmp(pg->tout, time7)<0)//退房时间为6月
					{
						Dp[6] += pg->rpay;
					}
					else if (strcmp(pg->tout, time7) >= 0 && strcmp(pg->tout, time8)<0)//退房时间为7月
					{
						Dp[7] += pg->rpay;
					}
					else if (strcmp(pg->tout, time8) >= 0 && strcmp(pg->tout, time9)<0)//退房时间为8月
					{
						Dp[8] += pg->rpay;
					}
					else if (strcmp(pg->tout, time9) >= 0 && strcmp(pg->tout, time10)<0)//退房时间为9月
					{
						Dp[9] += pg->rpay;
					}
					else if (strcmp(pg->tout, time10) >= 0 && strcmp(pg->tout, time11)<0)//退房时间为10月
					{
						Dp[10] += pg->rpay;
					}
					else if (strcmp(pg->tout, time11) >= 0 && strcmp(pg->tout, time12)<0)//退房时间为11月
					{
						Dp[11] += pg->rpay;
					}
					else if (strcmp(pg->tout, time12) >= 0 && strcmp(pg->tout, time0) <= 0)//退房时间为12月
					{
						Dp[12] += pg->rpay;
					}
				}
				if (prt->rtype == 'T')//判断客房种类
				{
					if (strcmp(pg->tout, time1) >= 0 && strcmp(pg->tout, time2)<0)//退房时间为该年1月
					{
						Tp[1] += pg->rpay;//通过客人实缴费用计算营业额（下同）
					}
					else if (strcmp(pg->tout, time2) >= 0 && strcmp(pg->tout, time3)<0)//退房时间为2月
					{
						Tp[2] += pg->rpay;
					}
					else if (strcmp(pg->tout, time3) >= 0 && strcmp(pg->tout, time4)<0)//退房时间为3月
					{
						Tp[3] += pg->rpay;
					}
					else if (strcmp(pg->tout, time4) >= 0 && strcmp(pg->tout, time5)<0)//退房时间为4月
					{
						Tp[4] += pg->rpay;
					}
					else if (strcmp(pg->tout, time5) >= 0 && strcmp(pg->tout, time6)<0)//退房时间为5月
					{
						Tp[5] += pg->rpay;
					}
					else if (strcmp(pg->tout, time6) >= 0 && strcmp(pg->tout, time7)<0)//退房时间为6月
					{
						Tp[6] += pg->rpay;
					}
					else if (strcmp(pg->tout, time7) >= 0 && strcmp(pg->tout, time8)<0)//退房时间为7月
					{
						Tp[7] += pg->rpay;
					}
					else if (strcmp(pg->tout, time8) >= 0 && strcmp(pg->tout, time9)<0)//退房时间为8月
					{
						Tp[8] += pg->rpay;
					}
					else if (strcmp(pg->tout, time9) >= 0 && strcmp(pg->tout, time10)<0)//退房时间为9月
					{
						Tp[9] += pg->rpay;
					}
					else if (strcmp(pg->tout, time10) >= 0 && strcmp(pg->tout, time11)<0)//退房时间为10月
					{
						Tp[10] += pg->rpay;
					}
					else if (strcmp(pg->tout, time11) >= 0 && strcmp(pg->tout, time12)<0)//退房时间为11月
					{
						Tp[11] += pg->rpay;
					}
					else if (strcmp(pg->tout, time12) >= 0 && strcmp(pg->tout, time0) <= 0)//退房时间为12月
					{
						Tp[12] += pg->rpay;
					}
				}
				if (prt->rtype == 'F')//判断客房种类
				{
					if (strcmp(pg->tout, time1) >= 0 && strcmp(pg->tout, time2)<0)//退房时间为该年1月
					{
						Fp[1] += pg->rpay;//通过客人实缴费用计算营业额（下同）
					}
					else if (strcmp(pg->tout, time2) >= 0 && strcmp(pg->tout, time3)<0)//退房时间为2月
					{
						Fp[2] += pg->rpay;
					}
					else if (strcmp(pg->tout, time3) >= 0 && strcmp(pg->tout, time4)<0)//退房时间为3月
					{
						Fp[3] += pg->rpay;
					}
					else if (strcmp(pg->tout, time4) >= 0 && strcmp(pg->tout, time5)<0)//退房时间为4月
					{
						Fp[4] += pg->rpay;
					}
					else if (strcmp(pg->tout, time5) >= 0 && strcmp(pg->tout, time6)<0)//退房时间为5月
					{
						Fp[5] += pg->rpay;
					}
					else if (strcmp(pg->tout, time6) >= 0 && strcmp(pg->tout, time7)<0)//退房时间为6月
					{
						Fp[6] += pg->rpay;
					}
					else if (strcmp(pg->tout, time7) >= 0 && strcmp(pg->tout, time8)<0)//退房时间为7月
					{
						Fp[7] += pg->rpay;
					}
					else if (strcmp(pg->tout, time8) >= 0 && strcmp(pg->tout, time9)<0)//退房时间为8月
					{
						Fp[8] += pg->rpay;
					}
					else if (strcmp(pg->tout, time9) >= 0 && strcmp(pg->tout, time10)<0)//退房时间为9月
					{
						Fp[9] += pg->rpay;
					}
					else if (strcmp(pg->tout, time10) >= 0 && strcmp(pg->tout, time11)<0)//退房时间为10月
					{
						Fp[10] += pg->rpay;
					}
					else if (strcmp(pg->tout, time11) >= 0 && strcmp(pg->tout, time12)<0)//退房时间为11月
					{
						Fp[11] += pg->rpay;
					}
					else if (strcmp(pg->tout, time12) >= 0 && strcmp(pg->tout, time0) <= 0)//退房时间为12月
					{
						Fp[12] += pg->rpay;
					}
				}
				pg = pg->next;
			}
			pbi = pbi->next;
		}
		prt = prt->next;
	}
	//计算合计营业额
	for (int i = 1; i <= 12; i++)
	{
		Sp[0] += Sp[i];
		Dp[0] += Dp[i];
		Tp[0] += Tp[i];
		Fp[0] += Fp[i];
	}
	//向文件中输出结果
	fprintf(fp, "计量单位：元人民币\n");
	fprintf(fp, "月份\t单人间\t双人间\t三人间\t四人间\n");
	for (int i = 1; i <= 12; i++)
	{
		fprintf(fp, "%2d\t%-8.1f%-8.1f%-8.1f%-8.1f\n", i,Sp[i],Dp[i],Tp[i],Fp[i]);
	}
	fprintf(fp, "合计\t%-8.1f%-8.1f%-8.1f%-8.1f\n", Sp[0], Dp[0], Tp[0], Fp[0]);
	fclose(fp);
}
//输入年份，统计该年所有客房的营业额，入住月数，入住率
void count3(ROOM_NODE*head)
{
	if ((fp = fopen("函数参数.txt", "r+")) == NULL)
	{
		fclose(fp);
		return;
	}
	char time[20];
	fscanf(fp, "%s", time);//读入UI输入的年份信息
	char time1[20];
	strcpy(time1, time);//将年份信息录入time1中
    strcat(time,"/00/00-00:00");//将读入的年份重组成结构变量中一样格式的字符串方便比较
	fclose(fp);
	ROOM_NODE *prt = head;
	BI_NODE *pbi;
	G_NODE *pg;
	float profit, month, rate;//分别为当前房间营业额，入住总月数，入住率
	float sum_profit=0, sum_month=0,sum_rate=0,sum_room=0;//合计营业额，合计入住约束，总入住率，总房间数（用于计算总入住率）
	if ((fp = fopen("结果.txt", "w+")) == NULL)
	{
		fclose(fp);
		return;
	}
	fprintf(fp, "统计年份：%s年\n", time1);//输出统计时间条件
	fprintf(fp, "%-10s%-10s%-10s%-10s%-10s\n","客房编号","客房类别","营业额","入住月数","入住率");//输出表头
	//遍历链表
	while (prt != NULL)
	{
		pbi = prt->snext;
		while (pbi != NULL)
		{
			profit = 0;
			month = 0;
			rate = 0;
			fprintf(fp, "%-10s", pbi->room_no);
			fprintf(fp, "%-10c", pbi->rtype);
			sum_room++;//统计房间总数
			pg = pbi->cnext;
			while (pg != NULL)
			{
				if (strcmp(time, pg->tin) >= 0 && strcmp(time, pg->tout) <= 0)//判断客人是否在给定年份内租房
				{
					//符合时间范围，记录相应信息
					profit += pg->rpay;
					month += pg->staymonth;
					rate += pg->staymonth / 12.0;
				}
				pg = pg->next;
			}
			fprintf(fp, "%-10.1f", profit);
			fprintf(fp, "%-10.1f", month);
			fprintf(fp, "%-10.1f\n", rate);
			sum_profit += profit;
			sum_month += month;
			pbi = pbi->next;
		}
		prt = prt->next;
	}
	sum_rate = sum_month / (sum_room*12.0);//总入住率=出租总月数/(总房间数*12)
	fprintf(fp, "%-10s", "合计");
	fprintf(fp, "%-10s", "N/A");//房间类别合计没有意义
	fprintf(fp, "%-10.1f", sum_profit);
	fprintf(fp, "%-10.1f", sum_month);
	fprintf(fp, "%-10.1f\n", sum_rate);
	fclose(fp);
}
//列出历年来累计出租月数最多的10个客人租房信息，按月数降序排序后输出
void count4(ROOM_NODE*head)
{
	if ((fp = fopen("函数参数.txt", "r+")) == NULL)
	{
		fclose(fp);
		return;
	}
	char time[20];
	fscanf(fp, "%s", time);//读入UI输入的年份信息
	fclose(fp);
	C_NODE *c_list = NULL;
	//创建统计信息新链表,并完成排序
	c_list=count_list(head);
	//输出新链表中的内容
	if ((fp = fopen("结果.txt", "w+")) == NULL)
	{
		fclose(fp);
		return;
	}
	fprintf(fp, "统计时间：%s\n", time);
	fprintf(fp, "%-20s%-15s%-15s%-15s%-15s\n","身份证号","姓名","累计住宿月数","应缴费用总额","实缴费用总额");
	int count = 1;
	while (c_list != NULL&&count<=10)
	{
		fprintf(fp, "%-20s", c_list->id);
		fprintf(fp, "%-15s", c_list->name);
		fprintf(fp, "%-15.1f", c_list->staymonth);
		fprintf(fp, "%-15.1f", c_list->tpay);
		fprintf(fp, "%-15.1f\n", c_list->rpay);
		c_list = c_list->next;
		count++;
	}
	fclose(fp);
}
//创建统计链表
C_NODE *count_list(ROOM_NODE *hd)
{
	if ((fp = fopen("函数参数.txt", "r+")) == NULL)
	{
		fclose(fp);
	}
	char time[20];
	fscanf(fp, "%s", time);//读入UI输入的年份信息
	ROOM_NODE *prt = hd;
	BI_NODE *pbi;
	G_NODE *pg;
	C_NODE *pcr = NULL,*pct;
	float staymonth=0;
	//遍历链表
	while (prt != NULL)
	{
		pbi = prt->snext;
		while (pbi != NULL)
		{
			pg = pbi->cnext;
			while (pg != NULL)
			{
				if (strcmp(pg->tin,time)<=0)//截止至time时间，客人出租过房或在住
				{
					if (strcmp(pg->tout,time)<=0)//退房时间在time之前，直接使用staymonth
					{
						staymonth = pg->staymonth;
					}
					else if (strcmp(pg->tout,time)>0||strcmp(pg->tout,"0")==0)//退房时间在time之后或在住，计算入住月数staymonth
					{
						staymonth = c_month(time, pg->tin);
					}
					//将信息导入新建统计用链表
					pct = (C_NODE*)malloc(sizeof(C_NODE));
					strcpy(pct->id, pg->id);
					strcpy(pct->name, pg->name);
					pct->staymonth = staymonth;
					pct->tpay = pg->tpay;
					pct->rpay = pg->rpay;
					pct->next = pcr;
					pcr = pct;
				}
				pg = pg->next;
			}
			pbi = pbi->next;
		}
		prt = prt->next;
	}
	//对新链表按入住月数排序
	sort_list(pcr);
	return pcr;
}
//对链表排序
void sort_list(C_NODE *hd)
{
	C_NODE *p_prior, *p_after, *p_cur, *p_temp;
	p_prior = hd;
	if (p_prior == NULL)
	{
		return;
	}
	p_temp = (C_NODE*)malloc(sizeof(C_NODE));
	while (p_prior->next != NULL)
	{
		p_cur = p_prior;
		p_after = p_prior->next;
		while (p_after != NULL)
		{
			if (p_cur->staymonth < p_after->staymonth)
			{
				p_cur = p_after;
			}
			p_after = p_after->next;
		}
		if (p_cur != p_prior)
		{
			*p_temp = *p_prior;
			*p_prior = *p_cur;
			p_prior->next = p_temp->next;
			p_temp->next = p_cur->next;
			*p_cur = *p_temp;
		}
		p_prior = p_prior->next;
	}
	free(p_temp);
}
//计算两个日期间相差月数，并作为返回值返回
float c_month(char*tstart, char*tend)
{
	float result;
    char year1[5], year2[5], month1[5], month2[5], day1[5], day2[5];
	int y1, y2, m1, m2, d1, d2;
	//分别取出字符串形式中的年月日
	strncpy(year1, tstart, 4);
	strncpy(year2,tend, 4);
	strncpy(month1, tstart + 5, 2);
	strncpy(month2, tend + 5, 2);
	strncpy(day1, tstart + 8, 2);
	strncpy(day2, tend + 8, 2);
	//字符串形式的数字转化为int形式
	y1 = atoi(year1);
	y2 = atoi(year2);
	m1 = atoi(month1);
	m2 = atoi(month2);
	d1 = atoi(day1);
	d2 = atoi(day2);
	result = ((y2 - y1) * 365 + (m2 - m1)*30.5 + d2 - d1) / 12.0;//粗略计算相差月数
	return result;
}
//自设统计：统计目前钱还没有交齐的客人信息 
void count5(ROOM_NODE*head)
{
	ROOM_NODE *prt = head;
	BI_NODE *pbi;
	G_NODE *pg;
	if ((fp = fopen("结果.txt", "w+")) == NULL)
	{
		fclose(fp);
		return;
	}
	fprintf(fp, "%-25s%-15s%-15s%-15s\n", "身份证号", "姓名", "房间号", "未缴纳金额");
	float sum = 0;
	while (prt != NULL)
	{
		pbi = prt->snext;
		while (pbi != NULL)
		{
			pg = pbi->cnext;
			while (pg != NULL)
			{
				if (pg->rpay < pg->tpay)
				{
					fprintf(fp, "%-25s", pg->id);
					fprintf(fp, "%-15s", pg->name);
					fprintf(fp, "%-15s", pg->room_no);
					fprintf(fp, "%-15.1f\n", pg->tpay - pg->rpay);
					sum += pg->tpay - pg->rpay;
				}
				pg = pg->next;
			}
			pbi = pbi->next;
		}
		prt = prt->next;
	}
	fprintf(fp, "\n总未缴纳金额：%f元\n", sum);
	fclose(fp);
}

