#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#define  EX_API __declspec(dllexport)   //解决在不同语言调用下的名字匹配问题
FILE *fp;
EX_API void Rtype_add(char rt,int max, int suite_no,int rfree);            //调用c保存客房类别信息
EX_API void Guest_add(char*id,char*name,char*room_no,char*tin,char*tout,float staymonth,float deposit,float tpay,float rpay);            //调用c保存客人租房信息
EX_API void Basic_add(char*room_no,char*tel,char rt,float s,float rent,char balcony,char occupied);            //调用c保存客房基本信息
