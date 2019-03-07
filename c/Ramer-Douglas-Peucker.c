#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define MAX_TRACE_POINTS 25

typedef struct node
{
    /* data */
    float x;  //数据域，用于存储数据
    float y;
    struct node * next; // 指针，可以用来访问节点数据，也可以遍历，指向下一个节点
}ObjectPoint_2d;

/*
头结点：是头结点是首节点前的那个节点
		并不存放数据的数据
		头结点的数据类型和首节点的类型一模一样
		未来方便对链表的操作
头指针：存放头结点地址的指针变量
首节点：存放第一个有效数据的节点
尾节点：存放最后一个有效数据的节点
*/
typedef struct
{
	int iNumberOfPoints;
	float fTracePointX[MAX_TRACE_POINTS];
	float fTracePointY[MAX_TRACE_POINTS];
}ObjectTrace_t;


void simplify(ObjectPoint_2d *start_point, ObjectPoint_2d *end_point, double epsilon){
    if (start_point==end_point || start_point==NULL || end_point==NULL ||start_point->next==NULL) {
        /* code */
        return;
    }
    int dx = end_point->x - start_point->x;
    int dy = end_point->y - start_point->y;

    // Furthest point (update by iteration)
    double d;
    double dmax = 0.0f;
    ObjectPoint_2d *furthest_point = start_point;

    //loop through points between endpoints
    double norm = sqrt(dx*dx+dy*dy);
    ObjectPoint_2d *current_point = start_point->next;

    while(current_point !=end_point){
        /* code */
        // calculate distance of current point to line between endpoints
        d = abs(dx*(start_point->y-current_point->y)-dy*(start_point->x-current_point->y))/norm;
        if(d>dmax){
            furthest_point = current_point;
            dmax = d;
        }
        // next iteration
        current_point = current_point->next;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                               
    } 

    // check if maximum distance deviates enough  
    if (dmax>epsilon) {  // 最大偏离大于阈值
        /* code */
        simplify(start_point, furthest_point,epsilon);
        simplify(furthest_point,end_point,epsilon);
        }
    else // 未偏离 ，则删除中间的点,释放内存
    {
        /* code */
        ObjectPoint_2d *current_point = start_point->next;
        ObjectPoint_2d *previous_point;
        while(current_point!=end_point){
            /* code */
            previous_point = current_point;
            current_point = current_point->next;  
            free(previous_point);
        }
        // chain endpoints together
        start_point->next = end_point;        
    }    
}

int main()
{
    ObjectTrace_t ObjectTrace;
    ObjectTrace.iNumberOfPoints = 15;
    int i;
    for(i=0;i<ObjectTrace.iNumberOfPoints;i++){
        ObjectTrace.fTracePointX[i] = i+(float)rand()/RAND_MAX;
        ObjectTrace.fTracePointY[i] = i*2;
    }

    /*display*/
    for(i=0;i<ObjectTrace.iNumberOfPoints;i++){
        printf("%f %f\n",ObjectTrace.fTracePointX[i],ObjectTrace.fTracePointY[i]);
    }

    /*构建、赋值给链表*/
    //头指针
    ObjectPoint_2d *node = NULL;
    node = (ObjectPoint_2d *)malloc(sizeof(ObjectPoint_2d));
    if (node == NULL) {
        /* code */
        printf("malloc fair!\n");
    }
    memset(node,0,sizeof(ObjectPoint_2d)); //3、清一下
    ObjectPoint_2d *pTail = node;
    pTail->next = NULL;
    for( i = 0; i < ObjectTrace.iNumberOfPoints; i++)
    {
        /* code */
        ObjectPoint_2d *pNew = (ObjectPoint_2d *)malloc(sizeof(ObjectPoint_2d));
        if (pNew == NULL) {
            /* code */
            printf("malloc fair");
            exit(-1);
        }
        pNew->x=ObjectTrace.fTracePointX[i];
        pNew->y=ObjectTrace.fTracePointY[i];
        pTail->next = pNew;
        pNew->next = NULL;
        pTail = pNew;
    }
    /* 遍历链表*/
    printf("%f %f\n",node->x,node->y);
    printf("%f %f\n",pTail->x,pTail->y);

    
    simplify(node,pTail,20);
    /**/
    // while(node!=NULL){
    //     /* code */
    //     printf("%f %f\n",node->x,node->y);
    //     node = node->next;
    // }
    // printf("%f %f\n",pTail->x,pTail->y);
    
    ObjectTrace_t new_ObjectTrace;
    new_ObjectTrace.iNumberOfPoints = 0;
    int index = 0;
    while(node!=NULL){
        /* code */
        new_ObjectTrace.fTracePointX[index]=node->x;
        new_ObjectTrace.fTracePointY[index]=node->y;
        new_ObjectTrace.iNumberOfPoints++;
        index++;
        node = node->next;
    }
    
    for(i=0;i<new_ObjectTrace.iNumberOfPoints;i++){
        printf("%f %f\n",new_ObjectTrace.fTracePointX[i],new_ObjectTrace.fTracePointY[i]);
    }
    return 0;
}

