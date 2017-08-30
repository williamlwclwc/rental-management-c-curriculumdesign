#include"info.h"
//调用c保存客房类别信息
EX_API void Rtype_add(char rt, int max, int suite_no,int rfree)
{
	if ((fp = fopen("客房类别信息.txt", "a+")) == NULL)
	{
		printf("客房类别信息打开失败\n");
		_getch();
		exit(0);
	}
	fprintf(fp, "%c%d %d %d", rt, max, suite_no, rfree);
	fclose(fp);
}
//调用c保存客房基本信息
EX_API void Basic_add(char*room_no, char*tel, char rt, float s, float rent, char balcony, char occupied)
{
	if ((fp = fopen("客房基本信息.txt", "a+")) == NULL)
	{
		printf("客房基本信息打开失败\n");
		_getch();
		exit(0);
	}
	fprintf(fp, "%s\n", room_no);
	fprintf(fp, "%s\n", tel);
	fprintf(fp, "%c%f %f %c%c", rt, s, rent, balcony, occupied);
	fclose(fp);
}
//调用c保存客人租房信息
EX_API void Guest_add(char*id, char*name, char*room_no, char*tin, char*tout, float staymonth, float deposit, float tpay, float rpay)
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
	fprintf(fp, "%f %f %f %f ", staymonth, deposit, tpay, rpay);
	fclose(fp);
}
