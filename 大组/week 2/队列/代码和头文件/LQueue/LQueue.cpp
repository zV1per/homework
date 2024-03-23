#include "LQueue.h" 

static bool inited = 0;

/**
 *  @name        : void InitLQueue(LQueue *Q)
 *    @description : 初始化队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void InitLQueue(LQueue *Q){
	if (!inited)
	{
		Q->front = nullptr;
		Q->rear = nullptr;
		Q->length = 0;
		inited = 1;
	}
}

/**
 *  @name        : void DestoryLQueue(LQueue *Q)
 *    @description : 销毁队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void DestoryLQueue(LQueue *Q){
	exit(0);
}

/**
 *  @name        : Status IsEmptyLQueue(const LQueue *Q)
 *    @description : 检查队列是否为空
 *    @param         Q 队列指针Q
 *    @return         : 空-TRUE; 未空-FALSE
 *  @notice      : None
 */
Status IsEmptyLQueue(const LQueue *Q){
	if (!inited || Q->length == 0) return TRUE;
	return FALSE;
}

/**
 *  @name        : Status GetHeadLQueue(LQueue *Q, void *e)
 *    @description : 查看队头元素
 *    @param         Q e 队列指针Q,返回数据指针e
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否空
 */
Status GetHeadLQueue(LQueue *Q, void *e){
	if (!inited) return FALSE;
	*((void**)e) = &(Q->front->data);
	return TRUE;
}

/**
 *  @name        : int LengthLQueue(LQueue *Q)
 *    @description : 确定队列长度
 *    @param         Q 队列指针Q
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : None
 */
int LengthLQueue(LQueue *Q){
	return (int)Q->length;
}

/**
 *  @name        : Status EnLQueue(LQueue *Q, void *data)
 *    @description : 入队操作
 *    @param         Q 队列指针Q,入队数据指针data
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否为空
 */
Status EnLQueue(LQueue *Q, void *data){
	if (!inited) return FALSE;
	Node* toadd = (Node*)malloc(sizeof(Node));
	if (toadd == nullptr)
	{
		return FALSE;
	}
	toadd->data = data;
	toadd->next = nullptr;
	if (!Q->length)
	{
		Q->front = toadd;
		Q->rear = toadd;
		Q->length++;
		return TRUE;
	}
	Node* current = Q->front;
	for (int i = 0; i < Q->length - 1; i++)
	{
		current = current->next;
	}
	current->next = toadd;
	Q->rear = toadd;
	Q->length++;
	return TRUE;
}

/**
 *  @name        : Status DeLQueue(LQueue *Q)
 *    @description : 出队操作
 *    @param         Q 队列指针Q
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : None
 */
Status DeLQueue(LQueue* Q) {
	if (!Q->length || !inited) return FALSE;
	if (Q->length==1)
	{
		free(Q->front);
		Q->front = nullptr;
		Q->rear = nullptr;
		Q->length--;
		return TRUE;
	}
	Node* s = Q->front;
	Q->front = s->next;
	free(s);
	Q->length--;
	return TRUE;
}

/**
 *  @name        : void ClearLQueue(AQueue *Q)
 *    @description : 清空队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void ClearLQueue(LQueue* Q) {
	if (!Q->length || !inited) return;
	if (Q->length==1)
	{
		free(Q->front);
		Q->front = nullptr;
		Q->rear = nullptr;
		Q->length--;
		return;
	}
	Node* s = Q->front;
	for (int i = 0; i < Q->length-1; i++)
	{
		Q->front = s->next;
		free(s);
		s = Q->front;
	}
	free(s);
	Q->front = nullptr;
	Q->rear = nullptr;
	Q->length = 0;
}

/**
 *  @name        : Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q))
 *    @description : 遍历函数操作
 *    @param         Q 队列指针Q，操作函数指针foo
 *    @return         : None
 *  @notice      : None
 */
Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q)){
	void* pp{ 0 };
	if (!Q->length || !inited) return FALSE;
	if (Q->length == 1)
	{
		pp = &Q->front->data;
		(*foo)(&pp);
		return TRUE;
	}
	Node* s = Q->front;
	for (int i = 0; i < Q->length - 1; i++)
	{
		pp = &s->data;
		(*foo)(&pp);
		s =s->next;
	}
	pp = &s->data;
	(*foo)(&pp);
	return TRUE;
}
//
///**
// *  @name        : void LPrint(void *q)
// *    @description : 操作函数
// *    @param         q 指针q
// 
// *  @notice      : None
// */
void LPrint(void *q){
	switch (type)
	{
	case'i':
		if (*(int**)q==nullptr)
		{
			printf("The queue is empty now!You should add something!\n");
			break;
		}
		printf("%d\n", ***(int***)q);
		break;
	case'f':
		if (*(float**)q == nullptr)
		{
			printf("The queue is empty now!You should add something!\n");
			break;
		}
		printf("%f\n", ***(float***)q);
		break;
	case'c':
		if (*(char**)q == nullptr)
		{
			printf("The queue is empty now!You should add something!\n");
			break;
		}
		printf("%c\n", ***(char***)q);
		break;
	default:
		printf("There is no matching type");
		break;
	}
}

/**************************************************************
 *    End-Multi-Include-Prevent Section
 **************************************************************/


