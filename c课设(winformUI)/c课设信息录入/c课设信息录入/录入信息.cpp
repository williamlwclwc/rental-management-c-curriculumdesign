#include"info.h"
//����c����ͷ������Ϣ
EX_API void Rtype_add(char rt, int max, int suite_no,int rfree)
{
	if ((fp = fopen("�ͷ������Ϣ.txt", "a+")) == NULL)
	{
		printf("�ͷ������Ϣ��ʧ��\n");
		_getch();
		exit(0);
	}
	fprintf(fp, "%c%d %d %d", rt, max, suite_no, rfree);
	fclose(fp);
}
//����c����ͷ�������Ϣ
EX_API void Basic_add(char*room_no, char*tel, char rt, float s, float rent, char balcony, char occupied)
{
	if ((fp = fopen("�ͷ�������Ϣ.txt", "a+")) == NULL)
	{
		printf("�ͷ�������Ϣ��ʧ��\n");
		_getch();
		exit(0);
	}
	fprintf(fp, "%s\n", room_no);
	fprintf(fp, "%s\n", tel);
	fprintf(fp, "%c%f %f %c%c", rt, s, rent, balcony, occupied);
	fclose(fp);
}
//����c��������ⷿ��Ϣ
EX_API void Guest_add(char*id, char*name, char*room_no, char*tin, char*tout, float staymonth, float deposit, float tpay, float rpay)
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
	fprintf(fp, "%f %f %f %f ", staymonth, deposit, tpay, rpay);
	fclose(fp);
}
