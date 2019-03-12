#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define MAX_TRACE_POINTS 25
int TraceNum[MAX_TRACE_POINTS];
typedef struct
{
    int iNumberOfPoints;
    float fTracePointX[MAX_TRACE_POINTS];
    float fTracePointY[MAX_TRACE_POINTS];
} ObjectTrace_t;

void simplify(ObjectTrace_t *ObjectTrace, int start, int end, int nums, double epsilon)
{

    if (ObjectTrace==NULL || (end-start)==1) {
        /* code */
        return;
    }
    float dx = ObjectTrace->fTracePointX[end] - ObjectTrace->fTracePointX[start];
    float dy = ObjectTrace->fTracePointY[end] - ObjectTrace->fTracePointY[start];

    double d;
    double dmax = 0.0;

    double norm = sqrt(dx*dx+dy*dy);
    int current;
    current = start+1;
    int furthest=start;
        
    while(current !=end){
        /* code */
        d = abs(dx*(ObjectTrace->fTracePointY[start]-ObjectTrace->fTracePointY[current])-dy*(ObjectTrace->fTracePointX[start]-ObjectTrace->fTracePointX[current]))/norm;
        if (d>dmax) {
            /* code */
            furthest = current;
            dmax = d;
        }
        current = current+1;
    }
    if (dmax>epsilon) {
        /* code */
        simplify(ObjectTrace,start,furthest,nums,epsilon);
        simplify(ObjectTrace,furthest,end,nums,epsilon);
    }
    else
    {
        /* code */
        current = start+1;
        int previous;
        while(current !=end){
            /* code */
            previous = current;
            current = current+1;
            TraceNum[previous] = 1;
        }
    }    
}

void initTraceArray(){
    for(int i = 0; i < MAX_TRACE_POINTS; i++)
    {
        /* code */
        TraceNum[i] = 0;
    }
    
}

int main(){
    ObjectTrace_t ObjectTrace;
    ObjectTrace.iNumberOfPoints = 15;
    memset(ObjectTrace.fTracePointX, 0, 25);
	memset(ObjectTrace.fTracePointY, 0, 25);
    int i;
    for(i=0;i<ObjectTrace.iNumberOfPoints;i++){
        ObjectTrace.fTracePointX[i] = i+(float)rand()/RAND_MAX;
        ObjectTrace.fTracePointY[i] = i*2;
    }

    /*display*/
    for(i=0;i<ObjectTrace.iNumberOfPoints;i++){
        printf("%f %f\n",ObjectTrace.fTracePointX[i],ObjectTrace.fTracePointY[i]);
    }
    initTraceArray();
    for(int i = 0; i < MAX_TRACE_POINTS; i++)
    {
        /* code */
        printf("%d ",TraceNum[i]);
    }
    printf("\n");
    simplify(&ObjectTrace,0,14,15,0.01);
    int deleteNum=0;
    for(int i = 0; i < MAX_TRACE_POINTS; i++)
    {
        /* code */
        if (TraceNum[i]==1) {
            printf("%d\n",i);
            deleteNum = deleteNum+1;
        }       
    }
    // new ObjectTrace
    // for(int i = 0; i < MAX_TRACE_POINTS; i++)
    // {
    //     /* code */
    //     printf("%d ",TraceNum[i]);
    // }
    // printf("\n");
    // printf("%d\n",deleteNum);
    // delete the points 

    for(i=0;i<ObjectTrace.iNumberOfPoints;i++){
        printf("%f %f\n",ObjectTrace.fTracePointX[i],ObjectTrace.fTracePointY[i]);
    }

    ObjectTrace.iNumberOfPoints = ObjectTrace.iNumberOfPoints-deleteNum;
    int index=0;
    for(int i = 0; i < MAX_TRACE_POINTS; i++)
    {
        /* code */
        if (TraceNum[i]==0) {
            /* code */
            ObjectTrace.fTracePointX[index]=ObjectTrace.fTracePointX[i];
            ObjectTrace.fTracePointY[index]=ObjectTrace.fTracePointY[i];
            index = index+1;
        }
    }
    for(int i = index; i < MAX_TRACE_POINTS; i++)
    {
        /* code */
        ObjectTrace.fTracePointX[i]=0;
        ObjectTrace.fTracePointY[i]=0;
    }
    
     /*display*/
    for(i=0;i<ObjectTrace.iNumberOfPoints;i++){
        printf("%f %f\n",ObjectTrace.fTracePointX[i],ObjectTrace.fTracePointY[i]);
    }
    
    
    
}
