#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 50
#include "struct.h"
#include "funcion.h"
int main(void)  
{
	int i = 0;
	Information infor[SIZE];
	rezero(infor); 
	while (1)
	{
		switch (function(i))
		{
		case 1:   
			pfunc=regis;
			break;

		case 2: 
			pfunc=list;
			break;

		case 3: 
			pfunc=BDAY;
			break;

		case 4: 
			pfunc=MemberINfor;
			break;

		case 5:    
			pfunc=MemberCancell;
			break;
		case 6: 

			pfunc=Customer_list;
			break;

		default:
			printf("\n<<시스템을 종료합니다.>>\n");
			system("puase");
			return 0;
		}
		pfunc(infor);
	}
	system("pause");
	return 0;
}            