#ifndef __FUNCION_H__
#define __FUNCION_H__

#include "struct.h"

Information rezero(Information* infor); 

int function(int i); 

void regis(Information* infor); 

void list(Information* infor); 

void BDAY(Information* infor); 

void MemberINfor(Information* infor); 

void MemberCancell(Information* infor);  

void Customer_list(Information* infor); 
void (*pfunc)(Information*);
#endif