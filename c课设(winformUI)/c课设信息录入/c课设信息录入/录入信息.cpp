#include"info.h"
//����c����ͷ������Ϣ
EX_API void Rtype_add(char rt, int suite_no,int rfree)
{
	if ((fp = fopen("�ͷ������Ϣ.txt", "a+")) == NULL)
	{
		printf("�ͷ������Ϣ��ʧ��\n");
		_getch();
		exit(0);
	}
	int max;
	fprintf(fp, "%c", rt);
	//���ݿͷ�����Զ����������ס����
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

//����c����ͷ�������Ϣ
EX_API void Basic_add(char*room_no,char rt, float s, float rent, char balcony, char occupied)
{
	if ((fp = fopen("�ͷ�������Ϣ.txt", "a+")) == NULL)
	{
		printf("�ͷ�������Ϣ��ʧ��\n");
		_getch();
		exit(0);
	}
	fprintf(fp, "%s\n", room_no);
	fprintf(fp, "%c", '8');
	fprintf(fp, "%s\n", room_no);
	fprintf(fp, "%c%f %f %c%c", rt, s, rent, balcony, occupied);
	fclose(fp);
}

//����c��������ⷿ��Ϣ
EX_API void Guest_add(char*id, char*name, char*room_no, char*tin, char*tout, float deposit, float tpay, float rpay)
{
	if ((fp = fopen("�����ⷿ��Ϣ.txt", "a+")) == NULL)
	{
		printf("�����ⷿ��Ϣ��ʧ��\n");
		_getch();
		exit(0);
	}
	fprintf(fp,"%s\n", id);
	fprintf(fp, "%s\n", name);
	fprintf(fp, "%s\n", room_no);
	fprintf(fp, "%s\n", tin);
	fprintf(fp, "%s\n", tout);
	if (strcmp(tout,"0")==0)//�����ס
	{
		fprintf(fp, "%f ", 0);//��ס����Ϊ��д0
		fprintf(fp, "%f %f %f ", deposit, tpay, rpay);//��ס���޷��Զ����㣬�ֶ�����
	}
	else//�������ס 
	{
		float staymonth0,rent;
		staymonth0 = c_month(tin, tout);
		fprintf(fp, "%f ", staymonth0);//�Զ�������ס����
		fprintf(fp, "%f ", deposit);
		//�Զ�����Ӧ�ɷ���:ȡ������Ŷ�Ӧ�����⣬Ӧ�ɷ���=����*��ס����
		create_list(&head);
		rent=seek_rent(head,room_no);
		tpay = rent*staymonth0;
		fprintf(fp, "%f ", tpay);
		fprintf(fp, "%f ", rpay);
	}
	fclose(fp);
}

//�����������ڼ��������������Ϊ����ֵ����
EX_API float c_month(char*tstart, char*tend)
{
	float result;
	char year1[5] = { 0 }, year2[5] = { 0 }, month1[3] = { 0 }, month2[3] = { 0 }, day1[3] = { 0 }, day2[3] = { 0 };
	int y1, y2, m1, m2, d1, d2;
	//�ֱ�ȡ���ַ�����ʽ�е�������
	strncpy(year1, tstart, 4);
	strncpy(year2, tend, 4);
	strncpy(month1, tstart + 5, 2);
	strncpy(month2, tend + 5, 2);
	strncpy(day1, tstart + 8, 2);
	strncpy(day2, tend + 8, 2);
	//�ַ�����ʽ������ת��Ϊint��ʽ
	y1 = atoi(year1);
	y2 = atoi(year2);
	m1 = atoi(month1);
	m2 = atoi(month2);
	d1 = atoi(day1);
	d2 = atoi(day2);
	//���Լ���������� 
	result = (y2 - y1) * 12 + m2 - m1 + (d2 - d1) / 30.5;
	return result;
}

void create_list(BI_NODE**phead)//��������
{
	//���ļ� 
	if ((fp1 = fopen("�ͷ�������Ϣ.txt", "r+")) == NULL)
	{
		printf("�ͷ�������Ϣ��ʧ��\n");
		_getch();
		exit(0);
	}
	BI_NODE *hd = NULL, *p;
	char room_no[4];
	int ret;
	//��ȡ�������ͷ������Ϣ��������ȳ��� 
	while (!feof(fp1))
	{
		//��ȡ�ļ����� 
		//���²�����Ϊ�˱���feof���ļ�β���һ�ε����� 
		ret = fscanf(fp1, "%s", room_no);
		if (ret == -1)
		{
			break;
		}
		else
		{
			//��ȡ���ݷǿգ�������㣬�洢���� 
			p = (BI_NODE*)malloc(sizeof(BI_NODE));
			strcpy(p->room_no, room_no);
		}
		//��ȡ�ļ����� 
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

float seek_rent(BI_NODE *head,char*room_no)//�������ⷿ������
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

