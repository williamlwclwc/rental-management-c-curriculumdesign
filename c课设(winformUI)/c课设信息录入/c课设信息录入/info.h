#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#define  EX_API __declspec(dllexport)   //����ڲ�ͬ���Ե����µ�����ƥ������
FILE *fp;
EX_API void Rtype_add(char rt,int max, int suite_no,int rfree);            //����c����ͷ������Ϣ
EX_API void Guest_add(char*id,char*name,char*room_no,char*tin,char*tout,float staymonth,float deposit,float tpay,float rpay);            //����c��������ⷿ��Ϣ
EX_API void Basic_add(char*room_no,char*tel,char rt,float s,float rent,char balcony,char occupied);            //����c����ͷ�������Ϣ
