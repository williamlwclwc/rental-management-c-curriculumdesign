// c����c���Բ���.cpp : �������̨Ӧ�ó������ڵ㡣

//�������������Ϣ��ͷ�ļ�
#include "stdafx.h"
#include"basicinfo.h"

//����ȫ�ֱ���
FILE *fp;
ROOM_NODE *head = NULL;

//��������main��
int main(int argc,char *argv[])//���ô˳���ʱUI���ݸ�main�Ĳ��� 
{
	int i=atoi(argv[1]);//���������char�Ͳ���ת��Ϊint����
//��ȡ�ļ���Ϣ��������������Ϣ��ʮ�ֽ�������
	Creatlist(&head);
//���ݵ��ý������Ϣ��ִ����Ӧ�Ӻ���
	switch(i)
	{
		case 0:
			type_del_list(&head);//ɾ���ͷ�������Ϣ
			break;
		case 1:
			type_change(head);//�޸Ŀͷ�������Ϣ
			break;
		case 2:
			basic_del_list(&head);//ɾ���ͷ�������Ϣ
			break;
		case 3:
			basic_change(head);//�޸Ŀͷ�������Ϣ
			break;
		case 4:
			guest_del_list(&head);//ɾ�������ⷿ��Ϣ
			break;
		case 5:
			guest_change(head);//�޸Ŀ����ⷿ��Ϣ
			break;
		case 6:
			type_search(head);//�ͷ�����ѯ 
			break;
		case 7:
			basic_search_rn(head);//�ͷ�������Ϣ��ѯ�����ͷ���� 
			break;
		case 8:
			basic_search_tr(head);//�ͷ�������Ϣ��ѯ���������� 
			break;
		case 9:
			g_search_id(head);//�����ⷿ��Ϣ��ѯ�������֤�� 
			break;
		case 10:
			g_search_nt(head);//�����ⷿ��Ϣ��ѯ����������ʱ�� 
			break;
	    case 11:
			count1(head);//ͳ��ÿ�����Ŀͷ���������ס����δס��
	    	break;
	    case 12:
	    	count2(head);//����ͳ�Ʊ���ȸ���ͷ���Ӫҵ��
	    	break;
	    case 13:
	    	count3(head);//������ݣ�ͳ�Ƹ������пͷ���Ӫҵ���ס��������ס��
	    	break;
	    case 14:
	    	count4(head);//�г��������ۼƳ�����������10�������ⷿ��Ϣ��������������������
	    	break;
	    case 15:
	    	count5(head);//�⻧Ƿ��ͳ�� 
	    	break;
	}
	//����������Ϣ
	//Printlist(head);
    return 0;
}

//�Զ����Ӻ���

//������Ϣ����
void Creatlist(ROOM_NODE **phead)
{
	//��������ͽ�� 
	int find=0,ret;
	char rt;
	ROOM_NODE *hd = NULL, *prtype;
	BI_NODE *pbi;
	G_NODE *pg;
	//���ļ� 
	if ((fp = fopen("�ͷ������Ϣ.txt", "r+")) == NULL)
	{
		printf("�ͷ������Ϣ��ʧ��\n");
		_getch();
		exit(0); 
	}
	//��ȡ�������ͷ������Ϣ��������ȳ��� 
	while (!feof(fp))
	{
		//���²�����Ϊ�˱���feof���ļ�β���һ�ε����� 
		ret=fscanf(fp, "%c", &rt);
		if (ret == -1)
		{
			break;
		}
		else
		{
			//��ȡ���ݷǿգ�������㣬�洢���� 
			prtype = (ROOM_NODE*)malloc(sizeof(ROOM_NODE));
			prtype->rtype = rt;
		}
		//��ȡ�ļ����� 
		fscanf(fp, "%d", &prtype->max);
		fscanf(fp, "%d", &prtype->suite_no);
		fscanf(fp, "%d", &prtype->rfree);
		prtype->snext = NULL;
		prtype->next = hd;
		hd = prtype;
	}
	fclose(fp);
	*phead = hd;
	//���ļ� 
	if ((fp = fopen("�ͷ�������Ϣ.txt", "r+")) == NULL)
	{
		printf("�ͷ�������Ϣ��ʧ��\n");
		_getch();
		exit(0);
	}
	char room_no[20];
	//��ȡ�������ͷ�������Ϣ��������ȳ���
	while (!feof(fp))
	{
		//���²�����Ϊ�˱���feof���ļ�β���һ�ε����� 
		ret=fscanf(fp, "%s", room_no);
		if (ret == -1)
		{
			break;
		}
		else
		{
			//��ȡ���ݷǿգ�������㣬�洢���� 
			pbi = (BI_NODE*)malloc(sizeof(BI_NODE));
			strcpy(pbi->room_no,room_no);
		}
		//��ȡ�ļ����� 
		fscanf(fp, "%s", pbi->tel);
		fscanf(fp, "%c", &pbi->rtype);
		fscanf(fp, "%c", &pbi->rtype);
		fscanf(fp, "%f", &pbi->S);
		fscanf(fp, "%f", &pbi->rent);
		fscanf(fp, "%c", &pbi->balcony);
		fscanf(fp, "%c", &pbi->balcony);
		fscanf(fp, "%c", &pbi->occupied);
		pbi->cnext = NULL;
		prtype = hd;//�������ϲ��Ҷ�Ӧ�Ŀͷ����� 
		while (prtype != NULL&&(prtype->rtype!=pbi->rtype))
		{
			prtype = prtype->next;
		}
		//����ҵ����򽫽�㰴����ȳ��ķ�ʽ����ͷ�������Ϣ֧�� 
		if (prtype != NULL)
		{
			pbi->next = prtype->snext;
			prtype->snext = pbi;
		}
		//���δ�ҵ������ͷ����������ڴ�ռ� 
		else
		{
			free(pbi);
		}
	}
	fclose(fp);
	//���ļ� 
	if ((fp = fopen("�����ⷿ��Ϣ.txt", "r+")) == NULL)
	{
		printf("�����ⷿ��Ϣ��ʧ��\n");
		_getch();
		exit(0);
	}
	//��ȡ�����������ⷿ��Ϣ��������ȳ��� 
	while (!feof(fp))
	{
		find = 0;
		//���²�����Ϊ�˱���feof���ļ�β���һ�ε����� 
		ret=fscanf(fp, "%s", room_no);
		if (ret == -1)
		{
			break;
		}
		else
		{
			//��ȡ���ݷǿգ�������㣬�洢���� 
			pg = (G_NODE*)malloc(sizeof(G_NODE));
			strcpy(pg->id, room_no);
		}
		//��ȡ�ļ����� 
		fscanf(fp, "%s", pg->name);
		fscanf(fp, "%s", pg->room_no);
		fscanf(fp, "%s", pg->tin);
		fscanf(fp, "%s", pg->tout);
		fscanf(fp, "%f %f %f %f ", &pg->staymonth,&pg->deposit,&pg->tpay,&pg->rpay);
		//���һ�����Ϣ֧���ϵĿͷ�������Ϣ��� 
		prtype = hd;
		find=0;
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
		if (find)//����ҵ����򽫽���Ժ���ȳ��ķ�ʽ��������ⷿ��Ϣ֧���� 
		{
			pg->next = pbi->cnext;
			pbi->cnext = pg;
		}
		else//���δ�ҵ������ͷ����������ڴ�ռ� 
		{
			free(pg);
		}
	}
	fclose(fp);
}

//�������������������(������)
void Printlist(ROOM_NODE *phead)
{
	//������ 
	ROOM_NODE *prt = phead;
	BI_NODE *pbi;
	G_NODE *pg;
	//�������������ȫ����Ϣ 
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

//��һ���֣�����ά��
 //���Ķ���Ϣ������ļ�
void type_printtodoc(ROOM_NODE *phead)
{
	//��Ŀ���ļ� 
	fp = fopen("�ͷ������Ϣ.txt", "w+");
	//����������������Ϣ��ָ���ļ� 
	if (phead != NULL) 
	{
		do
		{
			fprintf(fp, "%c", phead->rtype);
			fprintf(fp, "%d ", phead->max);
			fprintf(fp, "%d ", phead->suite_no);
			fprintf(fp, "%d", phead->rfree);
			phead = phead->next;
		} while (phead != NULL);
	}
	fclose(fp);
}

//ɾ���ͷ�������Ϣ����
void type_del_list(ROOM_NODE **headp)
{
	//��������ͽ�� 
	ROOM_NODE *current = *headp, *prior = *headp;
	char rt;
	//�򿪴洢UI���ݹ����������ļ� 
	if ((fp = fopen("��������.txt", "r+")) == NULL)
	{
		printf("û���������\n");
		_getch();
		fclose(fp);
		return;
	}
	//��ȡ���� 
	fscanf(fp, "%c", &rt);
	fclose(fp);
	//�����������Ҳ���ָ��Ľ������ 
	while (current->rtype != rt)
	{
		if (current->next == NULL)//ȫ����������δ�ҵ����򷵻� 
		{
			return;
		}
		else//����Ա���һ������� 
		{
			prior = current;
			current = current->next;
		}
	}
	if (current == *headp)//���ɾ������ǵ�һ�� 
	{
		*headp = current->next;//����ͷ��� 
	}
	else//���ɾ���ǵ�һ����� 
	{
		prior->next = current->next;//����ǰ����ָ�� 
	}
	free(current);//�ͷ�ɾ�������ڴ� 
	type_printtodoc(head);//��ɾ������������Ϣ��д�ش洢�ļ� 
}

//�޸Ŀͷ�������Ϣ����
void type_change(ROOM_NODE *head)
{
	//��������ͽ�� 
	ROOM_NODE*current = head;
	char rt;
	char editobj[50];
	//�򿪲����ļ� 
	if ((fp = fopen("��������.txt", "r+")) == NULL)
	{
		printf("û���������\n");
		_getch(); 
		fclose(fp);
		return;
	}
	//��ȡ�ļ��в���
	fscanf(fp, "%c", &rt);
	fscanf(fp, "%s", editobj);
	//�����������Ҫ�޸ĵĽ�� 
	while (current->rtype != rt)
	{
		if (current->next == NULL)//���ȫ��������δ�ҵ����򷵻� 
		{
			return;
		}
		else//���������һ����� 
		{
			current = current->next;
		}
	}
	//����ҵ����޸���Ӧ��Ϣ 
	if (!strcmp(editobj, "�ͷ����"))
	{
		fscanf(fp, "%c", &current->rtype);
	}
	if (!strcmp(editobj, "�����ס����"))
	{
		fscanf(fp, "%d", &current->max);
	}
	if (!strcmp(editobj, "�ͷ�����"))
	{
		fscanf(fp, "%d", &current->suite_no);
	}
	if (!strcmp(editobj, "�ͷ�δ��ס����"))
	{
		fscanf(fp, "%d", &current->rfree);
	}
	fclose(fp);
	type_printtodoc(head);//���޸ĺ�������е���Ϣ��д����Ӧ�洢�ļ��� 
}
//����Ϊ���ͷ�������Ϣά��

//���Ķ���Ϣ������ļ�
void basic_printtodoc(ROOM_NODE *phead)
{
	//��Ŀ���ļ� 
	fp = fopen("�ͷ�������Ϣ.txt", "w+");
	//������ 
	ROOM_NODE *prt = phead;
	BI_NODE *pbi;
	//˫ѭ�������ڶ�����������Ϣ�����Ŀ���ļ��� 
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

//ɾ���ͷ�������Ϣ����
void basic_del_list(ROOM_NODE **headp)
{
	//�򿪽���д�õĲ����ļ� 
	if ((fp = fopen("��������.txt", "r+")) == NULL)
	{
		printf("û���������\n");
		_getch();
		fclose(fp);
		return;
	}
	//������� 
	char room_no[5];
	fscanf(fp, "%s", room_no);
	fclose(fp);
	//������ 
	ROOM_NODE *crt = *headp;
	BI_NODE *cbi, *pbi;
	//˫ѭ�������ڶ����������Ҷ�Ӧ��� 
	while (crt != NULL)
	{
		cbi = crt->snext;
		pbi = crt->snext;
		while (cbi != NULL)
		{
			if (strcmp(room_no, cbi->room_no) == 0)//�ҵ���Ӧ����� 
			{
				if (cbi == crt->snext)//ɾ���׽�� 
				{
					crt->snext = cbi->next;//�����׽�� 
				}
				else//ɾ�����׽�� 
				{
					pbi->next = cbi->next;//����ǰ����ָ�� 
				}
				free(cbi);//�ͷ�ɾ������ڴ� 
				goto inx;
			}
			else
			{
				cbi = cbi->next;//δ�ҵ���鿴��һ��������Ϣ��� 
			}
		}
		crt = crt->next; 
	}
inx: 
	basic_printtodoc(head);//���޸ĺ����������Ϣ��д����Ӧ���ļ��� 
}

//�޸Ŀͷ�������Ϣ����
void basic_change(ROOM_NODE *head)
{
	//�򿪲����ļ� 
	if ((fp = fopen("��������.txt", "r+")) == NULL)
	{
		printf("û���������\n");
		_getch(); 
		fclose(fp);
		return;
	}
	//������� 
	char room_no[20];
	char editobj[20];
	char ch;
	//��ȡ�ļ��в���
	fscanf(fp, "%s", room_no);
	fscanf(fp, "%s", editobj);
	fscanf(fp, "%c", &ch);
	ROOM_NODE *crt = head;
	BI_NODE *cbi;
	//˫ѭ�������ڶ����������Ҷ�Ӧ��� 
	while (crt != NULL)
	{
		cbi = crt->snext;
		while (cbi != NULL)
		{
			//���Ҷ�Ӧ����ţ������ͷ�������Ϣ��� 
			if (strcmp(room_no, cbi->room_no) == 0)
			{
				//�ҵ����ж�Ҫ�޸ĵ����ݣ����������޸ģ��޸ĺ��˳�ѭ�� 
				if (!strcmp(editobj, "�ͷ����"))
				{
					fscanf(fp, "%s", cbi->room_no);
					goto inx;
				}
				if (!strcmp(editobj, "�绰����"))
				{
					fscanf(fp, "%s", cbi->tel);
					goto inx;
				}
				if (!strcmp(editobj, "�ͷ����"))
				{
					fscanf(fp, "%c", &cbi->rtype);
					goto inx;
				}
				if (!strcmp(editobj, "�ͷ����"))
				{
					fscanf(fp, "%f", &cbi->S);
					goto inx;
				}
				if (!strcmp(editobj, "ÿ�����"))
				{
					fscanf(fp, "%f", &cbi->rent);
					goto inx;
				}
				if (!strcmp(editobj, "�Ƿ�����̨"))
				{
					fscanf(fp, "%c", &cbi->balcony);
					goto inx;
				}
				if (!strcmp(editobj, "�Ƿ��п�����ס"))
				{
					fscanf(fp, "%c", &cbi->occupied);
					goto inx;
				}
			}
			else
			{
				cbi = cbi->next;//δ�ҵ����Ϸ���ţ��鿴��һ��� 
			}
		}
		crt = crt->next;
	}
inx:
	fclose(fp);
	basic_printtodoc(head);//���޸ĺ������������д���洢��Ϣ���ļ��� 
}
//����Ϊ���ͷ�������Ϣά��

//���Ķ���Ϣ������ļ�
void guest_printtodoc(ROOM_NODE *phead)
{
	fp = fopen("�����ⷿ��Ϣ.txt", "w+");
	ROOM_NODE *prt = phead;
	BI_NODE *pbi;
	G_NODE *pg;
	//����ѭ�������������Ŀ���ļ� 
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
	fclose(fp);
}

//ɾ�������ⷿ��Ϣ����
void guest_del_list(ROOM_NODE **phead)
{
	if ((fp = fopen("��������.txt", "r+")) == NULL)
	{
		printf("û���������\n");
		_getch();
		fclose(fp);
		return;
	}
	char id[20];
	fscanf(fp, "%s",id);
	fclose(fp);
	ROOM_NODE *crt = *phead;
	BI_NODE *cbi;
	G_NODE *cg, *pg;
	//����ѭ�����������Ҷ�Ӧ��� 
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
					if (cg == cbi->cnext)//ɾ��ͷ��� 
					{
						cbi->cnext = cg->next;
					}
					else//ɾ����ͷ��� 
					{
						pg->next = cg->next;
					}
					free(cg);//�ͷ�ɾ�������ڴ� 
					goto inx;
				}
				cg = cg->next;
			}
			cbi = cbi->next;
		}
		crt = crt->next;
	}
inx:
	guest_printtodoc(head);
}

//�޸Ŀ����ⷿ��Ϣ����
void guest_change(ROOM_NODE *head)
{
	if ((fp = fopen("��������.txt", "r+")) == NULL)
	{
		printf("û���������\n");
		_getch();
		fclose(fp);
		return;
	}
	char id[20];
	char editobj[20];
	char ch;
	//��ȡ�ļ��в���
	fscanf(fp, "%s", id);
	fscanf(fp, "%s", editobj);
	fscanf(fp, "%c", &ch);
	ROOM_NODE *crt = head;
	BI_NODE *cbi;
	G_NODE *cg;
	//����ѭ�����������Ҷ�Ӧ��� 
	while (crt != NULL)
	{
		cbi = crt->snext;
		while (cbi != NULL)
		{
			cg = cbi->cnext;
			while (cg != NULL)
			{
				if (strcmp(id, cg->id) == 0)//�����֤�Ų��ҽ�� 
				{
					//�޸�ָ����Ϣ 
					if (!strcmp(editobj, "���֤��"))
					{
						fscanf(fp, "%s", cg->id);
					}
					if (!strcmp(editobj, "��������"))
					{
						fscanf(fp, "%s", cg->name);
					}
					if (!strcmp(editobj, "��ס�ͷ����"))
					{
						fscanf(fp, "%s", cg->room_no);
					}
					if (!strcmp(editobj, "��סʱ��"))
					{
						fscanf(fp, "%s", cg->tin);
					}
					if (!strcmp(editobj, "�˷�ʱ��"))
					{
						fscanf(fp, "%s", cg->tout);
					}
					if (!strcmp(editobj, "��ס����"))
					{
						fscanf(fp, "%f", &cg->staymonth);
					}
					if (!strcmp(editobj, "Ѻ��"))
					{
						fscanf(fp, "%f", &cg->deposit);
					}
					if (!strcmp(editobj, "Ӧ�ɷ���"))
					{
						fscanf(fp, "%f", &cg->tpay);
					}
					if (!strcmp(editobj, "ʵ�ɷ���"))
					{
						fscanf(fp, "%f", &cg->rpay);
					}
				}
				cg = cg->next;
			}
		    cbi = cbi->next;
		}
		crt = crt->next;
	}
	fclose(fp);
	guest_printtodoc(head);//���޸ĺ������������д���洢�ļ��� 
}
//����Ϊ�������ⷿ��Ϣά��

// �ڶ����֣����ݲ�ѯ
//�ͷ�����ѯ 
void type_search(ROOM_NODE *head) 
{
	ROOM_NODE*current = head;
	char rt;
	if ((fp = fopen("��������.txt", "r+")) == NULL)
	{
		printf("û���������\n");
		_getch();
		fclose(fp);
		return;
	}
	//��ȡ�ļ��в���
	fscanf(fp, "%c", &rt);
	fclose(fp);
	if ((fp = fopen("���.txt", "w+")) == NULL)
	{
		printf("û���ҵ��ļ�\n");
		_getch();
		fclose(fp);
		return;
	}
	//�ҵ���Ӧ�Ľ�� 
	while (current->rtype != rt)
	{
		if (current->next == NULL)
		{
			fprintf(fp, "δ�ܲ�ѯ�������Ϣ\n");
			return;
		}
		else
		{
			current = current->next;
		}
	}
	//�����ļ��������ѯ�����Ϣ 
	fprintf(fp, "�ͷ����%c\n", current->rtype);
	fprintf(fp, "�����ס������%d\n", current->max);
	fprintf(fp, "�ͷ�������%d\n", current->suite_no);
	fprintf(fp, "�ͷ�δס������%d\n", current->rfree);
	fclose(fp);
}
//����Ϊ���ͷ�����ѯ 

//�ͷ�������Ϣ��ѯ�����ͷ���� 
void basic_search_rn(ROOM_NODE *head)
{
	if ((fp = fopen("��������.txt", "r+")) == NULL)
	{
		printf("û���������\n");
		_getch();
		fclose(fp);
		return;
	}
	char room_no[20];
	char balcony[10];
	char occupied[20];
	int flag = 0;
	//��ȡ�ļ��в���
	fscanf(fp, "%s", room_no);
	fclose(fp);
	ROOM_NODE *crt = head;
	BI_NODE *cbi;
	//����������ѯ��Ӧ�����Ϣ 
	while (crt != NULL)
	{
		cbi = crt->snext;
		while (cbi != NULL)
		{
			if (strcmp(room_no, cbi->room_no) == 0)
			{
				flag = 1;
				//�����ļ��������ѯ��� 
				if ((fp = fopen("���.txt", "w+")) == NULL)
				{
					printf("û���������\n");
					_getch();
					fclose(fp);
					return;
				}
				fprintf(fp, "�ͷ���ţ�%s\n", cbi->room_no);
				fprintf(fp, "�绰���룺%s\n", cbi->tel);
				fprintf(fp, "�ͷ����%c\n", cbi->rtype);
				fprintf(fp, "�ͷ������%.1f\n", cbi->S);
				fprintf(fp, "ÿ�����%.1f\n", cbi->rent);
				if (cbi->balcony == '1')
				{
					strcpy(balcony,"����̨");
				}
				else
				{
					 strcpy(balcony,"����̨");
				}
				fprintf(fp, "�Ƿ�����̨��%s\n", balcony);
				if (cbi->occupied == 'y')
				{
					strcpy(occupied, "�п�����ס");
				}
				else
				{
					strcpy(occupied, "�޿�����ס");
				}
				fprintf(fp, "�Ƿ�����ס��%s\n", occupied);
				fclose(fp);
				return;
			}
			cbi = cbi->next;
		}
		crt = crt->next;
	}
	if (flag == 0)
	{
		if ((fp = fopen("���.txt", "w+")) == NULL)
		{
			printf("û���������\n");
			_getch();
			fclose(fp);
			return;
		}
		fprintf(fp, "δ��ѯ�������Ϣ\n");
		fclose(fp);
	}
}

//�ͷ�������Ϣ��ѯ���������� 
void basic_search_tr(ROOM_NODE *head)
{
	if ((fp = fopen("��������.txt", "r+")) == NULL)
	{
		printf("û���������\n");
		_getch(); 
		fclose(fp);
		return;
	}
	float rent;
	char rt,ch;
	char balcony[10], occupied[20];
	//��ȡ�ļ��в���
	fscanf(fp, "%c", &rt);
	fscanf(fp, "%c", &ch);
	fscanf(fp, "%f",&rent);
	fclose(fp);
	ROOM_NODE *crt = head;
	BI_NODE *cbi;
	int flag = 0;
	//ѭ����������������ѯ������������ļ� 
	if ((fp = fopen("���.txt", "w+")) == NULL)
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
				flag = 1;
				fprintf(fp, "�ͷ���ţ�%s\n", cbi->room_no);
				fprintf(fp, "�绰���룺%s\n", cbi->tel);
				fprintf(fp, "�ͷ����%c\n", cbi->rtype);
				fprintf(fp, "�ͷ������%.1f\n", cbi->S);
				fprintf(fp, "ÿ�����%.1f\n", cbi->rent);
				if (cbi->balcony == '1')
				{
					strcpy(balcony, "����̨");
				}
				else
				{
					strcpy(balcony, "����̨");
				}
				fprintf(fp, "�Ƿ�����̨��%s\n", balcony);
				if (cbi->occupied == 'y')
				{
					strcpy(occupied, "�п�����ס");
				}
				else
				{
					strcpy(occupied, "�޿�����ס");
				}
				fprintf(fp, "�Ƿ�����ס��%s\n\n", occupied);
			}
			cbi = cbi->next;
		}
		crt = crt->next;
	}
	if (flag == 0)
	{
		fprintf(fp, "δ�ܲ�ѯ�������Ϣ\n");
	}
	fclose(fp);
}
//����Ϊ���ͷ�������Ϣ��ѯ 

//�����ⷿ��Ϣ��ѯ�������֤�� 
void g_search_id(ROOM_NODE *head)
{
	if ((fp = fopen("��������.txt", "r+")) == NULL)
	{
		printf("û���������\n");
		_getch();
		fclose(fp);
		return;
	}
	char id[20];
	//��ȡ�ļ��в���
	fscanf(fp, "%s", id);
	fclose(fp);
	ROOM_NODE *crt = head;
	BI_NODE *cbi;
	G_NODE *cg;
	if ((fp = fopen("���.txt", "w+")) == NULL)
	{
	    fclose(fp);
		return;
	}
	int flag = 0;
	//ѭ����������������������ļ� 
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
					flag = 1;
					fprintf(fp, "���֤�ţ�%s\n", cg->id);
					fprintf(fp, "������%s\n", cg->name);
					fprintf(fp, "���ⷿ����ţ�%s\n", cg->room_no);
					fprintf(fp, "��סʱ�䣺%s\n", cg->tin);
					if (cg->tout == "0")
					{
						fprintf(fp, "�˷�ʱ�䣺%s\n", "��ס");
					}
					else
					{
						fprintf(fp, "�˷�ʱ�䣺%s\n", cg->tout);
					}
					fprintf(fp, "��ס������%.1f\n", cg->staymonth);
					fprintf(fp, "Ѻ��%.1f\n", cg->deposit);
					fprintf(fp, "Ӧ�ɷ��ã�%.1f\n", cg->tpay);
					fprintf(fp, "ʵ�ɷ��ã�%.1f\n", cg->rpay);
				}
				cg = cg->next;
			}
			cbi = cbi->next;
		}
		crt = crt->next;
	}
	if (flag == 0)
	{
		fprintf(fp, "δ�ܲ�ѯ�������Ϣ\n");
	}
	fclose(fp);
}

//�����ⷿ��Ϣ��ѯ����������ʱ�䷶Χ 
void g_search_nt(ROOM_NODE *head)
{
	if ((fp = fopen("��������.txt", "r+")) == NULL)
	{
		printf("û���������\n");
		_getch();
		fclose(fp);
		return;
	}
	char name[20];
	char start[20];
	char end[20];
	//��ȡ�ļ��в���
	fscanf(fp, "%s", name);
	fscanf(fp, "%s", start);
	fscanf(fp, "%s", end);
	fclose(fp);
	ROOM_NODE *crt = head;
	BI_NODE *cbi;
	G_NODE *cg;
	//ѭ��������������������������ļ� 
	if ((fp = fopen("���.txt", "w+")) == NULL)
	{
		fclose(fp);
		return;
	}
	int flag = 0;
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
					flag = 1;
					fprintf(fp, "���֤�ţ�%s\n", cg->id);
					fprintf(fp, "������%s\n", cg->name);
					fprintf(fp, "���ⷿ����ţ�%s\n", cg->room_no);
					fprintf(fp, "��סʱ�䣺%s\n", cg->tin);
					if (cg->tout == "0")
					{
						fprintf(fp, "�˷�ʱ�䣺%s\n", "��ס");
					}
					else
					{
						fprintf(fp, "�˷�ʱ�䣺%s\n", cg->tout);
					}
					fprintf(fp, "��ס������%.1f\n", cg->staymonth);
					fprintf(fp, "Ѻ��%.1f\n", cg->deposit);
					fprintf(fp, "Ӧ�ɷ��ã�%.1f\n", cg->tpay);
					fprintf(fp, "ʵ�ɷ��ã�%.1f\n", cg->rpay);
				}
				cg = cg->next;
			}
			cbi = cbi->next;
		}
		crt = crt->next;
	}
	if (flag == 0)
	{
		fprintf(fp, "δ�ܲ�ѯ�������Ϣ\n");
	}
	fclose(fp);
}
//����Ϊ�������ⷿ��Ϣ��ѯ
 
//�������֣�����ͳ�� 
//ͳ��ÿ�����Ŀͷ���������ס����δס��
void count1(ROOM_NODE*head)
{
	ROOM_NODE *prt = head;
	int sum_no=0, occupied=0, rfree=0;
	if ((fp = fopen("���.txt", "w+")) == NULL)
	{
		fclose(fp);
		return;
	}
	fprintf(fp, "%s\t%s\t%s\t%s\n", "�ͷ����", "�ͷ�����", "����ס��", "δ��ס��");
	//ѭ����������ͳ�Ƹ�������� 
	while (prt != NULL)
	{
		//�жϿͷ���𣬷ֱ����ͳ�ƣ�ÿ��ͳ��˼·��ͬ 
		if (prt->rtype == 'D')
		{
			fprintf(fp,"%s\t", "˫�˼�");
			fprintf(fp,"%d\t", prt->suite_no);
			sum_no += prt->suite_no;//�ۼӿͷ����� 
			fprintf(fp,"%d\t", prt->suite_no-prt->rfree);//��ס����ͨ���������߼���õ� 
			occupied += prt->suite_no - prt->rfree;//�ۼ���ס�� 
			fprintf(fp,"%d\n", prt->rfree);
			rfree += prt->rfree;//�ۼ�δ��ס�� 
			prt = prt->next;
		}
		else if (prt->rtype == 'S')
		{
			fprintf(fp, "%s\t", "���˼�");
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
			fprintf(fp, "%s\t", "���˼�");
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
			fprintf(fp, "%s\t", "���˼�");
			fprintf(fp, "%d\t", prt->suite_no);
			sum_no += prt->suite_no;
			fprintf(fp, "%d\t", prt->suite_no - prt->rfree);
			occupied += prt->suite_no - prt->rfree;
			fprintf(fp, "%d\n", prt->rfree);
			rfree += prt->rfree;
			prt = prt->next;
		}
	}
	//�����ͳ�ƺ�ͳ������ 
	fprintf(fp, "%s\t", "�ϼ�");
	fprintf(fp, "%d\t", sum_no);
	fprintf(fp, "%d\t", occupied);
	fprintf(fp, "%d\n", rfree);
	fclose(fp);
}
 
//����ͳ�Ʊ���ȸ���ͷ���Ӫҵ��
void count2(ROOM_NODE*head)
{
	if ((fp = fopen("��������.txt", "r+")) == NULL)
	{
		printf("û���������\n");
		_getch();
		fclose(fp);
		return;
	}
	char time[20];
	fscanf(fp, "%s", time);//����UI����������Ϣ
	//�õ�ÿ���µ��ж�ʱ��� 
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
	//����Ӫҵ�����飬�±��ʾ�·ݣ��±�Ϊ0������ʾ�ϼ�
	float Sp[13] = { 0 }, Dp[13] = { 0 }, Tp[13] = { 0 }, Fp[13] = {0};
	if ((fp = fopen("���.txt", "w+")) == NULL)
	{
		fclose(fp);
		return;
	}
	fprintf(fp, "��ȣ�%s��\t\t", time);//���ͳ��ʱ������
	//��������
	while (prt != NULL)
	{
		pbi = prt->snext;
		while (pbi != NULL)
		{
			pg = pbi->cnext;
			while (pg != NULL)
			{
				if (prt->rtype == 'S')//�жϿͷ�����
				{
					if (strcmp(pg->tout,time1)>=0&&strcmp(pg->tout,time2)<0)//�˷�ʱ��Ϊ����1��
					{
						Sp[1] += pg->rpay;//ͨ������ʵ�ɷ��ü���Ӫҵ���ͬ��
					}
					else if (strcmp(pg->tout, time2) >= 0 && strcmp(pg->tout, time3)<0)//�˷�ʱ��Ϊ2��
					{
						Sp[2] += pg->rpay;
					}
					else if (strcmp(pg->tout, time3) >= 0 && strcmp(pg->tout, time4)<0)//�˷�ʱ��Ϊ3��
					{
						Sp[3] += pg->rpay;
					}
					else if (strcmp(pg->tout, time4) >= 0 && strcmp(pg->tout, time5)<0)//�˷�ʱ��Ϊ4��
					{
						Sp[4] += pg->rpay;
					}
					else if (strcmp(pg->tout, time5) >= 0 && strcmp(pg->tout, time6)<0)//�˷�ʱ��Ϊ5��
					{
						Sp[5] += pg->rpay;
					}
					else if (strcmp(pg->tout, time6) >= 0 && strcmp(pg->tout, time7)<0)//�˷�ʱ��Ϊ6��
					{
						Sp[6] += pg->rpay;
					}
					else if (strcmp(pg->tout, time7) >= 0 && strcmp(pg->tout, time8)<0)//�˷�ʱ��Ϊ7��
					{
						Sp[7] += pg->rpay;
					}
					else if (strcmp(pg->tout, time8) >= 0 && strcmp(pg->tout, time9)<0)//�˷�ʱ��Ϊ8��
					{
						Sp[8] += pg->rpay;
					}
					else if (strcmp(pg->tout, time9) >= 0 && strcmp(pg->tout, time10)<0)//�˷�ʱ��Ϊ9��
					{
						Sp[9] += pg->rpay;
					}
					else if (strcmp(pg->tout, time10) >= 0 && strcmp(pg->tout, time11)<0)//�˷�ʱ��Ϊ10��
					{
						Sp[10] += pg->rpay;
					}
					else if (strcmp(pg->tout, time11) >= 0 && strcmp(pg->tout, time12)<0)//�˷�ʱ��Ϊ11��
					{
						Sp[11] += pg->rpay;
					}
					else if (strcmp(pg->tout, time12) >= 0 && strcmp(pg->tout, time0)<=0)//�˷�ʱ��Ϊ12��
					{
						Sp[12] += pg->rpay;
					}
				}
				if (prt->rtype == 'D')//�жϿͷ�����
				{
					if (strcmp(pg->tout, time1) >= 0 && strcmp(pg->tout, time2)<0)//�˷�ʱ��Ϊ����1��
					{
						Dp[1] += pg->rpay;//ͨ������ʵ�ɷ��ü���Ӫҵ���ͬ��
					}
					else if (strcmp(pg->tout, time2) >= 0 && strcmp(pg->tout, time3)<0)//�˷�ʱ��Ϊ2��
					{
						Dp[2] += pg->rpay;
					}
					else if (strcmp(pg->tout, time3) >= 0 && strcmp(pg->tout, time4)<0)//�˷�ʱ��Ϊ3��
					{
						Dp[3] += pg->rpay;
					}
					else if (strcmp(pg->tout, time4) >= 0 && strcmp(pg->tout, time5)<0)//�˷�ʱ��Ϊ4��
					{
						Dp[4] += pg->rpay;
					}
					else if (strcmp(pg->tout, time5) >= 0 && strcmp(pg->tout, time6)<0)//�˷�ʱ��Ϊ5��
					{
						Dp[5] += pg->rpay;
					}
					else if (strcmp(pg->tout, time6) >= 0 && strcmp(pg->tout, time7)<0)//�˷�ʱ��Ϊ6��
					{
						Dp[6] += pg->rpay;
					}
					else if (strcmp(pg->tout, time7) >= 0 && strcmp(pg->tout, time8)<0)//�˷�ʱ��Ϊ7��
					{
						Dp[7] += pg->rpay;
					}
					else if (strcmp(pg->tout, time8) >= 0 && strcmp(pg->tout, time9)<0)//�˷�ʱ��Ϊ8��
					{
						Dp[8] += pg->rpay;
					}
					else if (strcmp(pg->tout, time9) >= 0 && strcmp(pg->tout, time10)<0)//�˷�ʱ��Ϊ9��
					{
						Dp[9] += pg->rpay;
					}
					else if (strcmp(pg->tout, time10) >= 0 && strcmp(pg->tout, time11)<0)//�˷�ʱ��Ϊ10��
					{
						Dp[10] += pg->rpay;
					}
					else if (strcmp(pg->tout, time11) >= 0 && strcmp(pg->tout, time12)<0)//�˷�ʱ��Ϊ11��
					{
						Dp[11] += pg->rpay;
					}
					else if (strcmp(pg->tout, time12) >= 0 && strcmp(pg->tout, time0) <= 0)//�˷�ʱ��Ϊ12��
					{
						Dp[12] += pg->rpay;
					}
				}
				if (prt->rtype == 'T')//�жϿͷ�����
				{
					if (strcmp(pg->tout, time1) >= 0 && strcmp(pg->tout, time2)<0)//�˷�ʱ��Ϊ����1��
					{
						Tp[1] += pg->rpay;//ͨ������ʵ�ɷ��ü���Ӫҵ���ͬ��
					}
					else if (strcmp(pg->tout, time2) >= 0 && strcmp(pg->tout, time3)<0)//�˷�ʱ��Ϊ2��
					{
						Tp[2] += pg->rpay;
					}
					else if (strcmp(pg->tout, time3) >= 0 && strcmp(pg->tout, time4)<0)//�˷�ʱ��Ϊ3��
					{
						Tp[3] += pg->rpay;
					}
					else if (strcmp(pg->tout, time4) >= 0 && strcmp(pg->tout, time5)<0)//�˷�ʱ��Ϊ4��
					{
						Tp[4] += pg->rpay;
					}
					else if (strcmp(pg->tout, time5) >= 0 && strcmp(pg->tout, time6)<0)//�˷�ʱ��Ϊ5��
					{
						Tp[5] += pg->rpay;
					}
					else if (strcmp(pg->tout, time6) >= 0 && strcmp(pg->tout, time7)<0)//�˷�ʱ��Ϊ6��
					{
						Tp[6] += pg->rpay;
					}
					else if (strcmp(pg->tout, time7) >= 0 && strcmp(pg->tout, time8)<0)//�˷�ʱ��Ϊ7��
					{
						Tp[7] += pg->rpay;
					}
					else if (strcmp(pg->tout, time8) >= 0 && strcmp(pg->tout, time9)<0)//�˷�ʱ��Ϊ8��
					{
						Tp[8] += pg->rpay;
					}
					else if (strcmp(pg->tout, time9) >= 0 && strcmp(pg->tout, time10)<0)//�˷�ʱ��Ϊ9��
					{
						Tp[9] += pg->rpay;
					}
					else if (strcmp(pg->tout, time10) >= 0 && strcmp(pg->tout, time11)<0)//�˷�ʱ��Ϊ10��
					{
						Tp[10] += pg->rpay;
					}
					else if (strcmp(pg->tout, time11) >= 0 && strcmp(pg->tout, time12)<0)//�˷�ʱ��Ϊ11��
					{
						Tp[11] += pg->rpay;
					}
					else if (strcmp(pg->tout, time12) >= 0 && strcmp(pg->tout, time0) <= 0)//�˷�ʱ��Ϊ12��
					{
						Tp[12] += pg->rpay;
					}
				}
				if (prt->rtype == 'F')//�жϿͷ�����
				{
					if (strcmp(pg->tout, time1) >= 0 && strcmp(pg->tout, time2)<0)//�˷�ʱ��Ϊ����1��
					{
						Fp[1] += pg->rpay;//ͨ������ʵ�ɷ��ü���Ӫҵ���ͬ��
					}
					else if (strcmp(pg->tout, time2) >= 0 && strcmp(pg->tout, time3)<0)//�˷�ʱ��Ϊ2��
					{
						Fp[2] += pg->rpay;
					}
					else if (strcmp(pg->tout, time3) >= 0 && strcmp(pg->tout, time4)<0)//�˷�ʱ��Ϊ3��
					{
						Fp[3] += pg->rpay;
					}
					else if (strcmp(pg->tout, time4) >= 0 && strcmp(pg->tout, time5)<0)//�˷�ʱ��Ϊ4��
					{
						Fp[4] += pg->rpay;
					}
					else if (strcmp(pg->tout, time5) >= 0 && strcmp(pg->tout, time6)<0)//�˷�ʱ��Ϊ5��
					{
						Fp[5] += pg->rpay;
					}
					else if (strcmp(pg->tout, time6) >= 0 && strcmp(pg->tout, time7)<0)//�˷�ʱ��Ϊ6��
					{
						Fp[6] += pg->rpay;
					}
					else if (strcmp(pg->tout, time7) >= 0 && strcmp(pg->tout, time8)<0)//�˷�ʱ��Ϊ7��
					{
						Fp[7] += pg->rpay;
					}
					else if (strcmp(pg->tout, time8) >= 0 && strcmp(pg->tout, time9)<0)//�˷�ʱ��Ϊ8��
					{
						Fp[8] += pg->rpay;
					}
					else if (strcmp(pg->tout, time9) >= 0 && strcmp(pg->tout, time10)<0)//�˷�ʱ��Ϊ9��
					{
						Fp[9] += pg->rpay;
					}
					else if (strcmp(pg->tout, time10) >= 0 && strcmp(pg->tout, time11)<0)//�˷�ʱ��Ϊ10��
					{
						Fp[10] += pg->rpay;
					}
					else if (strcmp(pg->tout, time11) >= 0 && strcmp(pg->tout, time12)<0)//�˷�ʱ��Ϊ11��
					{
						Fp[11] += pg->rpay;
					}
					else if (strcmp(pg->tout, time12) >= 0 && strcmp(pg->tout, time0) <= 0)//�˷�ʱ��Ϊ12��
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
	//����ϼ�Ӫҵ��
	for (int i = 1; i <= 12; i++)
	{
		Sp[0] += Sp[i];
		Dp[0] += Dp[i];
		Tp[0] += Tp[i];
		Fp[0] += Fp[i];
	}
	//���ļ���������
	fprintf(fp, "������λ��Ԫ�����\n");
	fprintf(fp, "�·�\t���˼�\t˫�˼�\t���˼�\t���˼�\n");
	for (int i = 1; i <= 12; i++)
	{
		fprintf(fp, "%2d\t%-8.1f%-8.1f%-8.1f%-8.1f\n", i,Sp[i],Dp[i],Tp[i],Fp[i]);
	}
	fprintf(fp, "�ϼ�\t%-8.1f%-8.1f%-8.1f%-8.1f\n", Sp[0], Dp[0], Tp[0], Fp[0]);
	fclose(fp);
}

//������ݣ�ͳ�Ƹ������пͷ���Ӫҵ���ס��������ס��
void count3(ROOM_NODE*head)
{
	if ((fp = fopen("��������.txt", "r+")) == NULL)
	{
		printf("û���������\n");
		_getch();
		fclose(fp);
		return;
	}
	char month1[2],month2[2],day1[2],day2[2];//��ŵ�����ס����,���� 
	char time[5];//����������� 
	fscanf(fp, "%s", time);//����UI����������Ϣ
	char time1[4],time2[4];//�����������ס���˷�ʱ������ 
	fclose(fp);
	ROOM_NODE *prt = head;
	BI_NODE *pbi;
	G_NODE *pg;
	int d1,d2;//�˷���ס�������� 
	float profit, month, rate,m1,m2;//�ֱ�Ϊ��ǰ����Ӫҵ���ס����������ס��
	float sum_profit=0, sum_month=0,sum_rate=0,sum_room=0;//�ϼ�Ӫҵ��ϼ���סԼ��������ס�ʣ��ܷ����������ڼ�������ס�ʣ�
	if ((fp = fopen("���.txt", "w+")) == NULL)
	{
		fclose(fp);
		return;
	}
	fprintf(fp, "ͳ����ݣ�%s��\n", time);//���ͳ��ʱ������
	fprintf(fp, "%-10s%-10s%-10s%-10s%-10s\n","�ͷ����","�ͷ����","Ӫҵ��","��ס����","��ס��");//�����ͷ
	//��������
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
			sum_room++;//ͳ�Ʒ�������
			pg = pbi->cnext;
			while (pg != NULL)
			{
				strncpy(time2, pg->tin, 4);
				strncpy(time1, pg->tout, 4);
				strncpy(month1, pg->tout + 5, 2);
				strncpy(day1, pg->tout + 8, 2);
				m1 = atoi(month1);
				d1 = atoi(day1);
				strncpy(month2, pg->tin + 5, 2);
				strncpy(day2, pg->tin + 8, 2);
				m2 = atoi(month2);
				d2 = atoi(day2);
				if (strncmp(time, time1,4) <= 0&&strncmp(time,time2,4) >=0)//�жϿ����Ƿ��ڸ���������˷��ɷ� 
				{
					//����ʱ�䷶Χ����¼��Ӧ��Ϣ
					profit += pg->rpay;
					if(strncmp(time,time2,4)==0&&strncmp(time,time1,4)==0)//������ס���˷���ֱ����staymonth 
					{
					    month += pg->staymonth;
					    rate += pg->staymonth / 12.0;
				    }
					else if (strncmp(time,time2,4)>0&&strncmp(time,time1,4)<0)//�����������סʱ����ڣ�һ��ס��һ��
					{
						month += 12;
					}
					else if(strncmp(time, time1, 4) == 0)//��ס�ڸ���ʱ��ǰ�������˷���ͳ���˷���������
					{
						m1 += d1/30.5; 
				    	month += m1;
				    	rate += month/12.0;
					}
					else if (strncmp(time, time2, 4) == 0)//������ס���˷��ڸ���ʱ���ͳ��12-��ס��������
					{
						m2 += d2 / 30.5;
						month = month + 12 - m2;
						rate += month / 12.0;
					}
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
	sum_rate = sum_month / (sum_room*12.0);//����ס��=����������/(�ܷ�����*12)
	fprintf(fp, "%-10s", "�ϼ�");
	fprintf(fp, "%-10s", "N/A");//�������ϼ�û������
	fprintf(fp, "%-10.1f", sum_profit);
	fprintf(fp, "%-10.1f", sum_month);
	fprintf(fp, "%-10.1f\n", sum_rate);
	fclose(fp);
}

//�г��������ۼƳ�����������10�������ⷿ��Ϣ��������������������
void count4(ROOM_NODE*head)
{
	if ((fp = fopen("��������.txt", "r+")) == NULL)
	{
		printf("û���������\n");
		_getch(); 
		fclose(fp);
		return;
	}
	char time[20];
	fscanf(fp, "%s", time);//����UI����������Ϣ
	fclose(fp);
	C_NODE *c_list = NULL;
	//����ͳ����Ϣ������,���������
	c_list=count_list(head);
	//����������е�����
	if ((fp = fopen("���.txt", "w+")) == NULL)
	{
		fclose(fp);
		return;
	}
	fprintf(fp, "ͳ��ʱ�䣺%s\n", time);
	fprintf(fp, "%-20s%-15s%-15s%-15s%-15s\n","���֤��","����","�ۼ�ס������","Ӧ�ɷ����ܶ�","ʵ�ɷ����ܶ�");
	int count = 1;
	while (c_list != NULL&&count<=10)//����������ǰʮ 
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

//����ͳ������
C_NODE *count_list(ROOM_NODE *hd)
{
	if ((fp = fopen("��������.txt", "r+")) == NULL)
	{
		printf("û���������\n");
		_getch();
		fclose(fp);
	}
	char time[20];
	fscanf(fp, "%s", time);//����UI����������Ϣ
	ROOM_NODE *prt = hd;
	BI_NODE *pbi;
	G_NODE *pg;
	C_NODE *pcr = NULL,*pct;
	float staymonth=0;
	//��������
	while (prt != NULL)
	{
		pbi = prt->snext;
		while (pbi != NULL)
		{
			pg = pbi->cnext;
			while (pg != NULL)
			{
				if (strcmp(pg->tin,time)<=0)//��ֹ��timeʱ�䣬���˳����������ס
				{
					if (strncmp(pg->tout, "0", 1) != 0 && strcmp(pg->tout, time) <= 0)//�˷�ʱ����time֮ǰ��ֱ��ʹ��staymonth
					{
						staymonth = pg->staymonth;
					}
					else if (strcmp(pg->tout,time)>0 || strncmp(pg->tout,"0",1) == 0)//�˷�ʱ����time֮�����ס��������ס����staymonth
					{
						staymonth = c_month(pg->tin, time);
					}
					//����Ϣ�����½�ͳ��������
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
	//����������ס��������
	if (pcr != NULL)
	{
		sort_list_id(pcr);
		fusion_list(pcr);
		sort_list(pcr);
	}
		return pcr;
}

//���������򣨰���סʱ�䣩
void sort_list(C_NODE *hd)
{
	C_NODE *p_prior, *p_after, *p_cur, *p_temp;
	p_prior = hd;
	if (p_prior == NULL)//���� 
	{
		return;
	}
	p_temp = (C_NODE*)malloc(sizeof(C_NODE));//����ʱ���ڽ��������Ϣ����ʱ���
	//ѡ������ 
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
			//���������Ϣ������ָ���� 
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

//���������򣨰�id��Ϊ�ϲ�׼����
void sort_list_id(C_NODE *hd)
{
	C_NODE *p_prior, *p_after, *p_cur, *p_temp;
	p_prior = hd;
	if (p_prior == NULL)//���� 
	{
		return;
	}
	p_temp = (C_NODE*)malloc(sizeof(C_NODE));//����ʱ���ڽ��������Ϣ����ʱ���
											 //ѡ������ 
	while (p_prior->next != NULL)
	{
		p_cur = p_prior;
		p_after = p_prior->next;
		while (p_after != NULL)
		{
			if (strcmp(p_cur->id , p_after->id)<=0)
			{
				p_cur = p_after;
			}
			p_after = p_after->next;
		}
		if (p_cur != p_prior)
		{
			//���������Ϣ������ָ���� 
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

//�ϲ�����ⷿ�Ŀ��˵������Ϣ
void fusion_list(C_NODE *hd)
{	
    C_NODE *cg=hd,*pg=hd;
	while (cg->next != NULL)
	{
		while (strcmp(cg->id, cg->next->id) != 0)
		{
			if (cg->next == NULL)//ȫ����������δ�ҵ����򷵻� 
			{
				return;
			}
			else//����Ա���һ������� 
			{
				pg = cg;
				cg = cg->next;
			}
			if (cg->next == NULL)//ȫ����������δ�ҵ����򷵻� 
			{
				return;
			}
		}
		//�ҵ�����ⷿ���˺󣬺ϲ���Ϣ 
		cg->next->staymonth += cg->staymonth;
		cg->next->tpay += cg->tpay;
		cg->next->rpay += cg->rpay;
		//�ϲ���ɾ���˽�� 
		if (cg == hd)//���ɾ������ǵ�һ�� 
		{
			hd = cg->next;//����ͷ��� 
		}
		else//���ɾ���ǵ�һ����� 
		{
			pg->next = cg->next;//����ǰ����ָ�� 
		}
		//free(cg);//free���º���cg->next������freeӰ�첻��
		if (cg->next!= NULL)//ȫ�������������򷵻� 
		{
			cg = cg->next;
		}
		else
		{
			return;
		}
	}
}

//�����������ڼ��������������Ϊ����ֵ����
float c_month(char*tstart, char*tend)
{
	float result;
	char year1[5] = { 0 }, year2[5] = { 0 }, month1[3] = { 0 }, month2[3] = { 0 }, day1[3] = { 0 }, day2[3] = { 0 };
	int y1, y2, m1, m2, d1, d2;
	//�ֱ�ȡ���ַ�����ʽ�е�������
	strncpy(year1, tstart, 4);
	strncpy(year2,tend, 4);
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
	result=(y2-y1)*12+m2-m1+(d2-d1)/30.5; 
	return result;
}

//����ͳ�ƣ�ͳ��ĿǰǮ��û�н���Ŀ�����Ϣ 
void count5(ROOM_NODE*head)
{
	ROOM_NODE *prt = head;
	BI_NODE *pbi;
	G_NODE *pg;
	if ((fp = fopen("���.txt", "w+")) == NULL)
	{
		fclose(fp);
		return;
	}
	fprintf(fp, "%-25s%-15s%-15s%-15s\n", "���֤��", "����", "�����", "δ���ɽ��");
	float sum = 0;//����ͳ����δ�սɽ�� 
	//ѭ�����������ҵ�����δ���ѿ��� 
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
	fprintf(fp, "\n��δ���ɽ�%.1fԪ\n", sum);
	fclose(fp);
}

