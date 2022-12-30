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
	printf("\n<<피트니스 센터 회원관리 프로그램>>\n");
	printf("<<<원하시는 기능을 선택해주세요.>>>\n");
	do
	{
		printf("<<1. 회원등록>>\n<<2. 등록된 회원조회>>\n<<3. 생일 회원조회>>\n<<4. 회원정보 출력>>\n<<5. 회원 탈퇴>>\n<<6. 파일에 저장>>\n<<7. 종료>>\n");
		printf("<<원하는 기능선택>>: ");
		scanf_s("%d", &i);

		if (i < 1 || i>7)
			printf("<<잘못된 선택입니다. 다시 시도해주시길 바랍니다.>> \n");

		if (i == 7)
		{
			printf("<<종료를 선택하셨습니다.>>\n");
			system("pause");
			return 0;
		}
	} while (i < 1 || i>7);
	return i;
}
void regis(Information* infor)
{
	int num1;

	printf("\n<<회원등록을 선택하셨습니다.>> \n");
	printf("[락커룸 번호]  및 [회원코드]등록\n");
	do {

		do
		{
			printf("몇번째 락커룸:"); scanf_s("%d", &num1);
			if (num1 < 0 || num1>50)
			{
				printf("다시입력해주세요. \n");
			}
		} while (num1 < 0 || num1>50);
		if (infor[num1 - 1].name != NULL)
		{
			puts("락커룸에 회원이 존재합니다. ");
			puts("다른락커룸을 선택해주세요. ");

		}
	} while (infor[num1 - 1].name != NULL);



	printf("<<%d번째 락커룸 회원성명>>: ", num1);
	num1 -= 1;
	getchar();

	infor[num1].name = (char*)malloc(sizeof(char) * 20);
	gets_s(infor[num1].name, sizeof(char) * 20);

	printf("<회원전화번호입력>: ");
	infor[num1].num = (char*)malloc(sizeof(char) * 25);
	gets_s(infor[num1].num, sizeof(char) * 25);


	printf("<회원주소입력>: ");
	infor[num1].adr = (char*)malloc(sizeof(char) * 30);
	gets_s(infor[num1].adr, sizeof(char) * 30);


	do {
		printf("<회원생년입력(1900~2022)>: "); scanf_s("%d", &infor[num1].year);
	} while (infor[num1].year < 1900 || infor[num1].year > 2022);
	do {
		printf("<회원생월입력(1월~12월)>: "); scanf_s("%d", &infor[num1].month);
	} while (infor[num1].month < 1 || infor[num1].month > 12);
	do {
		printf("<회원생일입력(1일~31일)>: "); scanf_s("%d", &infor[num1].day);
	} while (infor[num1].day < 1 || infor[num1].day > 31);
}
void list(Information* infor)
{
	int i, j, k, num3;

	printf("\n회원조회를 선택하셨습니다.\n");
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
	printf("등록된 회원의 수는 %d명입니다. \n그리고 등록할 수 있는 회원의 수는 %d입니다. \n", SIZE - num3, num3);

}
void BDAY(Information* infor)
{
	int num3, i;
	int check = 0;
	printf("\n<<생일 회원조회를 선택하셨습니다.>> \n");
	printf("몇월생인지 입력해주세요.: ");
	scanf_s("%d", &num3);
	printf("%d월생은", num3);

	for (i = 0; i <= SIZE; i++)
	{
		if (num3 == infor[i].month)
		{
			printf(" %s입니다. \n", infor[i].name);
			printf("나이는 %d입니다. \n", (2022 - infor[i].year) + 1);
			check++;

		}
	}
	if (check == 0)
	{
		printf("없습니다.\n");
	}
}

void MemberINfor(Information* infor)
{
	int num3, i, num1 = 0;
	char ch1[10];
	printf("\n<<회원정보 출력을 선택하셨습니다.>> \n");
	do
	{
		printf("<1. 성함으로 검색> 또는 <2. 회원코드로 검색>"); scanf_s("%d", &num3);
		if (num3 > 2 || num3 < 1)
		{
			printf("다시 입력해주세요. \n");
		}
	} while (num3 > 2 || num3 < 1);
	if (num3 == 1)
	{
		getchar();
		printf("성함을 입력하세요: ");
		gets_s(ch1, sizeof(ch1));
		for (i = 0; i < SIZE; i++)
		{
			if (infor[i].name != NULL && !strcmp(ch1, infor[i].name))
			{
				printf("\n락커룸넘버: [%d]\n", i + 1);
				printf("성함: %s\n", infor[i].name);
				printf("전화번호: %s\n", infor[i].num);
				printf("주소: %s\n", infor[i].adr);
				printf("생년월일: %d년 %d월 %d일\n", infor[i].year, infor[i].month, infor[i].day);
				num1++;
				break;
			}
		}
		if (num1 == 0)
		{
			printf("%s회원이 존재하지 않습니다. \n", ch1);
		}
	}
	else if (num3 == 2)
	{
		printf("회원코드를 입력하세요.[락커룸 넘버]\n");
		do
		{
			printf("몇번째 락커룸:"); scanf_s("%d", &num1);
			if (num1 < 0 || num1>50)
			{
				printf("다시입력해주세요. \n");
			}
		} while (num1 < 0 || num1>50);
		printf("\n락커룸넘버: [%d]\n", num1);
		num1 -= 1;
		if (infor[num1].name == NULL)
		{
			printf("%d번라커룸은 빈 락커룸입니다. \n", num1 + 1);

		}
		else if (infor[num1].name != NULL)
		{
			printf("성함: %s\n", infor[num1].name);
			printf("전화번호: %s\n", infor[num1].num);
			printf("주소: %s\n", infor[num1].adr);
			printf("생년월일: %d년 %d월 %d일\n", infor[num1].year, infor[num1].month, infor[num1].day);
		}

	}
	else
	{
		printf("잘못입력하셨습니다. \n");
	}
}
void MemberCancell(Information* infor)
{
	int num3, num1, i;
	int num = 0;
	char ch1[10];

	printf("회원 탈퇴를 선택하셨습니다.\n");

	do
	{
		printf("<1. 성함으로 탈퇴> 또는 <2. 회원코드로 탈퇴>"); scanf_s("%d", &num3);
		if (num3 > 2 || num3 < 1)
		{
			printf("다시입력해주세요. \n");
		}
	} while (num3 > 2 || num3 < 1);
	if (num3 == 1)
	{
		getchar();
		printf("성함을 입력하세요: ");
		gets_s(ch1, sizeof(ch1));

		for (i = 0; i < SIZE; i++)
		{
			if (infor[i].name != NULL && !strcmp(ch1, infor[i].name))
			{
				printf("%s회원 탈퇴완료!\n", infor[i].name);
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
			printf("%s회원이 존재하지 않습니다. \n", ch1);
		}
	}
	else if (num3 == 2)
	{
		printf("회원코드로 탈퇴를 선택하셨습니다. \n");
		do
		{
			printf("몇번째 락커룸:"); scanf_s("%d", &num1);
			if (num1 < 0 || num1>50)
			{
				printf("다시 입력해주세요. \n");
			}
		} while (num1 < 0 || num1>50);
		num1 -= 1;
		if ((infor[num1].name == NULL))
		{
			printf("%d번라커룸은 빈 라커룸입니다. \n", num1 + 1);

		}

		else if (infor[num1].name != NULL)
		{

			printf("\n락커룸넘버: [%d]\n%s님의 회원탈퇴 완료!\n", num1 + 1, infor[num1].name);
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
	printf("파일 입출력 선택!!\n");
	fp = fopen("data.txt", "wt");
	if (fp == NULL)
	{
		puts("파일 오픈 실패!");
		system("pause");
		return;
	}
	else
	{
		puts("파일 출력성공!");
	}
	for (i = 0; i < SIZE; i++)
	{
		if (infor[i].name != NULL)
		{
			fprintf(fp, "<<<<<<<<등록된 %d번째 회원>>>>>>>>>\n", i + 1);
			fprintf(fp, "성함:%s\n", infor[i].name);
			fprintf(fp, "주소:%s\n", infor[i].adr);
			fprintf(fp, "전화번호:%s\n", infor[i].num);
			fprintf(fp, "생년월일: %d년%d월%d일생\n", infor[i].year, infor[i].month, infor[i].day);
		}
	}
	fclose(fp);
}
