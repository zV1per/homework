#include "LinkStack.h" 
#include <iostream>


static bool inited = 0;
//Á´Õ»

//³õÊ¼»¯Õ»
Status initLStack(LinkStack *s){
	
	if (!inited)
	{
		s->top = nullptr;
		s->count = 0;
		inited = 1;
		return SUCCESS;
	}
	return ERROR;
}

//ÅÐ¶ÏÕ»ÊÇ·ñÎª¿Õ
Status isEmptyLStack(LinkStack *s){
	if (!inited||s->count==0) return ERROR;
	return SUCCESS;
}

//µÃµ½Õ»¶¥ÔªËØ
Status getTopLStack(LinkStack *s,ElemType *e){
	if (!inited || s->count == 0) return ERROR;
	*e = s->top->data;
	return SUCCESS;
}

//Çå¿ÕÕ»
Status clearLStack(LinkStack *s){
	if (!inited || s->count == 0) return ERROR;
	for (int i = 0; i < s->count; i++)
	{
		popLStack(s,nullptr);
	}
	s->count = 0;
	return SUCCESS;
}

//Ïú»ÙÕ»
Status destroyLStack(LinkStack *s){
	exit(0);
}

//¼ì²âÕ»³¤¶È
Status LStackLength(LinkStack *s,int *length){
	if (!inited) return ERROR;
	*length = s->count;
	return SUCCESS;
}

//ÈëÕ»
Status pushLStack(LinkStack *s,ElemType data){
	if (!inited) return ERROR;
	StackNode* toadd = (StackNode*)malloc(sizeof(StackNode));
	if (toadd==nullptr)
	{
		return ERROR;
	}
	toadd->data = data;
	toadd->next = nullptr;
	if (!s->count)
	{
		s->top = toadd;
		s->count++;
		return SUCCESS;
	}
	StackNode* current = s->top;
	for (int i = 0; i < s->count - 1; i++)
	{
		current = current->next;
	}
	current->next = toadd;
	s->count++;
	return SUCCESS;
}

//³öÕ»
Status popLStack(LinkStack *s,ElemType *data){
	if (!s->count || !inited) return ERROR;
	StackNode* current = s->top;
	if (s->count==1)
	{
		*data = current->data;
		s->count--;
		return SUCCESS;
	}
	for (int i = 0; i < s->count - 2; i++)
	{
		current = current->next;
	}
	*data = current->next->data;
	free(current->next);
	current->next = nullptr;
	s->count--;
	return SUCCESS;
}
