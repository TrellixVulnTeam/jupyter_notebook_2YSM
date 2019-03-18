/*
给定两个二进制字符串，返回他们的和（用二进制表示）。

输入为非空字符串且只包含数字 1 和 0。

示例 1:

输入: a = "11", b = "1"
输出: "100"
示例 2:

输入: a = "1010", b = "1011"
输出: "10101"
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char* addBinary(char* a, char* b) {
    int lenA = strlen(a);
    int lenB = strlen(b);
    int max = lenA>lenB?lenA:lenB;
    int i = lenA-1;
    int j = lenB-1;
    int ret = 0;
    char *res = (char*)malloc(sizeof(char)*(max+2));
    res[max+1] = '\0';
    for(int k=max;k>=0;k--,i--,j--){
        if (i>=0&&j>=0) {
            if ((a[i]-'0'+b[j]-'0'+ret)<=1) {
                res[k]=a[i]-'0'+b[j]-'0'+ret+'0';
                ret = 0;
            }else
            {
                res[k] = a[i] - '0' + b[j] - '0'  + ret - 2 + '0';
                ret = 1;
            }        
        }else if (i>=0)
        {
            if ((a[i]-'0'+ret)>1) {
                res[k]=a[i]-'0'+ret-2+'0';
                ret = 1;
            }else
            {
                res[k]=a[i]-'0'+ret+'0';
                ret = 0;
            }
        }else if (j>=0)
        {
            if ((b[j]-'0'+ret)>1) {
                res[k]=b[j]-'0'+ret-2+'0';
                ret = 1;
            }else
            {
                res[k] = b[j]-'0'+ret+'0';
                ret=0;
            }            
        }    
    }
    if (ret>0) {
        res[0]='1';
    }else
    {
        *res++;
    }
    return res;
}
int main(){
    char *a = "1010";
    char *b = "1011";

    char *c = addBinary(a,b);
    printf("%s",c);
    return 0;
}
