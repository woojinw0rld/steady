#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <string.h>
#include "struct.h"
#define SIZE 50

Information rezero(Information* infor)  
{
	int i;
	for (i = 0; i < SIZE; i++)
	{
		infor[i].name = NULL;
		infor[i].adr = NULL;
		infor[i].num = NULL;
		infor[i].year = 0;
		infor[i].month = 0;
		infor[i].day = 0;
	}
	return *infor;
}
int function(int i)
{
	printf("\n<<��Ʈ�Ͻ� ���� ȸ������ ���α׷�>>\n");
	printf("<<<���Ͻô� ����� �������ּ���.>>>\n");
	do
	{
		printf("<<1. ȸ�����>>\n<<2. ��ϵ� ȸ����ȸ>>\n<<3. ���� ȸ����ȸ>>\n<<4. ȸ������ ���>>\n<<5. ȸ�� Ż��>>\n<<6. ���Ͽ� ����>>\n<<7. ����>>\n");
		printf("<<���ϴ� ��ɼ���>>: ");
		scanf_s("%d", &i);

		if (i < 1 || i>7)
			printf("<<�߸��� �����Դϴ�. �ٽ� �õ����ֽñ� �ٶ��ϴ�.>> \n");

		if (i == 7)
		{
			printf("<<���Ḧ �����ϼ̽��ϴ�.>>\n");
			system("pause");
			return 0;
		}
	} while (i < 1 || i>7);
	return i;
}
void regis(Information* infor)
{
	int num1;

	printf("\n<<ȸ������� �����ϼ̽��ϴ�.>> \n");
	printf("[��Ŀ�� ��ȣ]  �� [ȸ���ڵ�]���\n");
	do {

		do
		{
			printf("���° ��Ŀ��:"); scanf_s("%d", &num1);
			if (num1 < 0 || num1>50)
			{
				printf("�ٽ��Է����ּ���. \n");
			}
		} while (num1 < 0 || num1>50);
		if (infor[num1 - 1].name != NULL)
		{
			puts("��Ŀ�뿡 ȸ���� �����մϴ�. ");
			puts("�ٸ���Ŀ���� �������ּ���. ");

		}
	} while (infor[num1 - 1].name != NULL);



	printf("<<%d��° ��Ŀ�� ȸ������>>: ", num1);
	num1 -= 1;
	getchar();

	infor[num1].name = (char*)malloc(sizeof(char) * 20);
	gets_s(infor[num1].name, sizeof(char) * 20);

	printf("<ȸ����ȭ��ȣ�Է�>: ");
	infor[num1].num = (char*)malloc(sizeof(char) * 25);
	gets_s(infor[num1].num, sizeof(char) * 25);


	printf("<ȸ���ּ��Է�>: ");
	infor[num1].adr = (char*)malloc(sizeof(char) * 30);
	gets_s(infor[num1].adr, sizeof(char) * 30);


	do {
		printf("<ȸ�������Է�(1900~2022)>: "); scanf_s("%d", &infor[num1].year);
	} while (infor[num1].year < 1900 || infor[num1].year > 2022);
	do {
		printf("<ȸ�������Է�(1��~12��)>: "); scanf_s("%d", &infor[num1].month);
	} while (infor[num1].month < 1 || infor[num1].month > 12);
	do {
		printf("<ȸ�������Է�(1��~31��)>: "); scanf_s("%d", &infor[num1].day);
	} while (infor[num1].day < 1 || infor[num1].day > 31);
}
void list(Information* infor)
{
	int i, j, k, num3;

	printf("\nȸ����ȸ�� �����ϼ̽��ϴ�.\n");
	num3 = 0;
	for (i = 0; i < SIZE; i++)
	{
		if (infor[i].name == NULL)
		{
			printf("%3d.[%7c]\t", i + 1, '\0');
		}
		else
		{
			printf("%3d.[%5s]\t", i + 1, infor[i].name);
		}
		if ((i + 1) % 5 == 0)
		{
			puts(" ");
		}
		if (infor[i].name == NULL)
		{
			num3++;
		}
	}
	printf("\n");
	printf("��ϵ� ȸ���� ���� %d���Դϴ�. \n�׸��� ����� �� �ִ� ȸ���� ���� %d�Դϴ�. \n", SIZE - num3, num3);

}
void BDAY(Information* infor)
{
	int num3, i;
	int check = 0;
	printf("\n<<���� ȸ����ȸ�� �����ϼ̽��ϴ�.>> \n");
	printf("��������� �Է����ּ���.: ");
	scanf_s("%d", &num3);
	printf("%d������", num3);

	for (i = 0; i <= SIZE; i++)
	{
		if (num3 == infor[i].month)
		{
			printf(" %s�Դϴ�. \n", infor[i].name);
			printf("���̴� %d�Դϴ�. \n", (2022 - infor[i].year) + 1);
			check++;

		}
	}
	if (check == 0)
	{
		printf("�����ϴ�.\n");
	}
}

void MemberINfor(Information* infor)
{
	int num3, i, num1 = 0;
	char ch1[10];
	printf("\n<<ȸ������ ����� �����ϼ̽��ϴ�.>> \n");
	do
	{
		printf("<1. �������� �˻�> �Ǵ� <2. ȸ���ڵ�� �˻�>"); scanf_s("%d", &num3);
		if (num3 > 2 || num3 < 1)
		{
			printf("�ٽ� �Է����ּ���. \n");
		}
	} while (num3 > 2 || num3 < 1);
	if (num3 == 1)
	{
		getchar();
		printf("������ �Է��ϼ���: ");
		gets_s(ch1, sizeof(ch1));
		for (i = 0; i < SIZE; i++)
		{
			if (infor[i].name != NULL && !strcmp(ch1, infor[i].name))
			{
				printf("\n��Ŀ��ѹ�: [%d]\n", i + 1);
				printf("����: %s\n", infor[i].name);
				printf("��ȭ��ȣ: %s\n", infor[i].num);
				printf("�ּ�: %s\n", infor[i].adr);
				printf("�������: %d�� %d�� %d��\n", infor[i].year, infor[i].month, infor[i].day);
				num1++;
				break;
			}
		}
		if (num1 == 0)
		{
			printf("%sȸ���� �������� �ʽ��ϴ�. \n", ch1);
		}
	}
	else if (num3 == 2)
	{
		printf("ȸ���ڵ带 �Է��ϼ���.[��Ŀ�� �ѹ�]\n");
		do
		{
			printf("���° ��Ŀ��:"); scanf_s("%d", &num1);
			if (num1 < 0 || num1>50)
			{
				printf("�ٽ��Է����ּ���. \n");
			}
		} while (num1 < 0 || num1>50);
		printf("\n��Ŀ��ѹ�: [%d]\n", num1);
		num1 -= 1;
		if (infor[num1].name == NULL)
		{
			printf("%d����Ŀ���� �� ��Ŀ���Դϴ�. \n", num1 + 1);

		}
		else if (infor[num1].name != NULL)
		{
			printf("����: %s\n", infor[num1].name);
			printf("��ȭ��ȣ: %s\n", infor[num1].num);
			printf("�ּ�: %s\n", infor[num1].adr);
			printf("�������: %d�� %d�� %d��\n", infor[num1].year, infor[num1].month, infor[num1].day);
		}

	}
	else
	{
		printf("�߸��Է��ϼ̽��ϴ�. \n");
	}
}
void MemberCancell(Information* infor)
{
	int num3, num1, i;
	int num = 0;
	char ch1[10];

	printf("ȸ�� Ż�� �����ϼ̽��ϴ�.\n");

	do
	{
		printf("<1. �������� Ż��> �Ǵ� <2. ȸ���ڵ�� Ż��>"); scanf_s("%d", &num3);
		if (num3 > 2 || num3 < 1)
		{
			printf("�ٽ��Է����ּ���. \n");
		}
	} while (num3 > 2 || num3 < 1);
	if (num3 == 1)
	{
		getchar();
		printf("������ �Է��ϼ���: ");
		gets_s(ch1, sizeof(ch1));

		for (i = 0; i < SIZE; i++)
		{
			if (infor[i].name != NULL && !strcmp(ch1, infor[i].name))
			{
				printf("%sȸ�� Ż��Ϸ�!\n", infor[i].name);
				free(infor[i].name);
				free(infor[i].adr);
				free(infor[i].num);
				infor[i].name = NULL;
				infor[i].adr = NULL;
				infor[i].num = NULL;
				infor[i].year = 0;
				infor[i].month = 0;
				infor[i].day = 0;
				num++;
			}
		}
		if (num == 0)
		{
			printf("%sȸ���� �������� �ʽ��ϴ�. \n", ch1);
		}
	}
	else if (num3 == 2)
	{
		printf("ȸ���ڵ�� Ż�� �����ϼ̽��ϴ�. \n");
		do
		{
			printf("���° ��Ŀ��:"); scanf_s("%d", &num1);
			if (num1 < 0 || num1>50)
			{
				printf("�ٽ� �Է����ּ���. \n");
			}
		} while (num1 < 0 || num1>50);
		num1 -= 1;
		if ((infor[num1].name == NULL))
		{
			printf("%d����Ŀ���� �� ��Ŀ���Դϴ�. \n", num1 + 1);

		}

		else if (infor[num1].name != NULL)
		{

			printf("\n��Ŀ��ѹ�: [%d]\n%s���� ȸ��Ż�� �Ϸ�!\n", num1 + 1, infor[num1].name);
			free(infor[num1].name);
			free(infor[num1].adr);
			free(infor[num1].num);
			infor[num1].name = NULL;
			infor[num1].adr = NULL;
			infor[num1].num = NULL;
			infor[num1].year = 0;
			infor[num1].month = 0;
			infor[num1].day = 0;
		}
	}

}
void Customer_list(Information* infor)
{
	int i, j;
	char str[20];
	FILE* fp;
	printf("���� ����� ����!!\n");
	fp = fopen("data.txt", "wt");
	if (fp == NULL)
	{
		puts("���� ���� ����!");
		system("pause");
		return;
	}
	else
	{
		puts("���� ��¼���!");
	}
	for (i = 0; i < SIZE; i++)
	{
		if (infor[i].name != NULL)
		{
			fprintf(fp, "<<<<<<<<��ϵ� %d��° ȸ��>>>>>>>>>\n", i + 1);
			fprintf(fp, "����:%s\n", infor[i].name);
			fprintf(fp, "�ּ�:%s\n", infor[i].adr);
			fprintf(fp, "��ȭ��ȣ:%s\n", infor[i].num);
			fprintf(fp, "�������: %d��%d��%d�ϻ�\n", infor[i].year, infor[i].month, infor[i].day);
		}
	}
	fclose(fp);
}
