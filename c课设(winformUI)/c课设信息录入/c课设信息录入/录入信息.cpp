#include"info.h"
//调用c保存客房类别信息
EX_API void Rtype_add(char rt, int suite_no,int rfree)
{
	if ((fp = fopen("客房类别信息.txt", "a+")) == NULL)
	{
		printf("客房类别信息打开失败\n");
		_getch();
		exit(0);
	}
	int max;
	fprintf(fp, "%c", rt);
	//根据客房类别自动计算最多入住人数
	if (rt == 'D')
	{
		max = 2;
	}
	else if (rt == 'S')
	{
		max = 1;
	}
	else if (rt == 'T')
	{
		max = 3;
	}
	else if (rt == 'F')
	{
		max = 4;
	}
	fprintf(fp, "%d %d %d", max, suite_no, rfree);
	fclose(fp);
}

//调用c保存客房基本信息
EX_API void Basic_add(char*room_no,char rt, float s, float rent, char balcony, char occupied)
{
	if ((fp = fopen("客房基本信息.txt", "a+")) == NULL)
	{
		printf("客房基本信息打开失败\n");
		_getch();
		exit(0);
	}
	fprintf(fp, "%s\n", room_no);
	fprintf(fp, "%c", '8');
	fprintf(fp, "%s\n", room_no);
	fprintf(fp, "%c%f %f %c%c", rt, s, rent, balcony, occupied);
	fclose(fp);
}

//调用c保存客人租房信息
EX_API void Guest_add(char*id, char*name, char*room_no, char*tin, char*tout, float deposit, float tpay, float rpay)
{
	if ((fp = fopen("客人租房信息.txt", "a+")) == NULL)
	{
		printf("客人租房信息打开失败\n");
		_getch();
		exit(0);
	}
	fprintf(fp,"%s\n", id);
	fprintf(fp, "%s\n", name);
	fprintf(fp, "%s\n", room_no);
	fprintf(fp, "%s\n", tin);
	fprintf(fp, "%s\n", tout);
	if (strcmp(tout,"0")==0)//如果在住
	{
		fprintf(fp, "%f ", 0);//入住月数为填写0
		fprintf(fp, "%f %f %f ", deposit, tpay, rpay);//在住的无法自动计算，手动输入
	}
	else//如果不在住 
	{
		float staymonth0,rent;
		staymonth0 = c_month(tin, tout);
		fprintf(fp, "%f ", staymonth0);//自动计算入住月数
		fprintf(fp, "%f ", deposit);
		//自动计算应缴费用:取出房间号对应的月租，应缴费用=月租*入住月数
		create_list(&head);
		rent=seek_rent(head,room_no);
		tpay = rent*staymonth0;
		fprintf(fp, "%f ", tpay);
		fprintf(fp, "%f ", rpay);
	}
	fclose(fp);
}

//计算两个日期间相差月数，并作为返回值返回
EX_API float c_month(char*tstart, char*tend)
{
	float result;
	char year1[5] = { 0 }, year2[5] = { 0 }, month1[3] = { 0 }, month2[3] = { 0 }, day1[3] = { 0 }, day2[3] = { 0 };
	int y1, y2, m1, m2, d1, d2;
	//分别取出字符串形式中的年月日
	strncpy(year1, tstart, 4);
	strncpy(year2, tend, 4);
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
	//粗略计算相差月数 
	result = (y2 - y1) * 12 + m2 - m1 + (d2 - d1) / 30.5;
	return result;
}

void create_list(BI_NODE**phead)//创建链表
{
	//打开文件 
	if ((fp1 = fopen("客房基本信息.txt", "r+")) == NULL)
	{
		printf("客房基本信息打开失败\n");
		_getch();
		exit(0);
	}
	BI_NODE *hd = NULL, *p;
	char room_no[4];
	int ret;
	//读取并创建客房类别信息链表（后进先出） 
	while (!feof(fp1))
	{
		//读取文件数据 
		//以下操作是为了避免feof到文件尾多读一次的问题 
		ret = fscanf(fp1, "%s", room_no);
		if (ret == -1)
		{
			break;
		}
		else
		{
			//读取数据非空，创建结点，存储数据 
			p = (BI_NODE*)malloc(sizeof(BI_NODE));
			strcpy(p->room_no, room_no);
		}
		//读取文件数据 
		fscanf(fp1, "%s", p->tel);
		fscanf(fp1, "%c", &p->rtype);
		fscanf(fp1, "%c", &p->rtype);
		fscanf(fp1, "%f", &p->S);
		fscanf(fp1, "%f", &p->rent);
		fscanf(fp1, "%c", &p->balcony);
		fscanf(fp1, "%c", &p->balcony);
		fscanf(fp1, "%c", &p->occupied);
		p->next = hd;
		hd = p;
	}
	fclose(fp1);
	*phead = hd;
}

float seek_rent(BI_NODE *head,char*room_no)//查找所租房间的租金
{
	int rent=0;
	while (head != NULL)
	{
		if (strcmp(room_no, head->room_no) == 0)
		{
			rent = head->rent;
			break;
		}
		head = head->next;
	}
	return rent;
}

