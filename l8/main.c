#include<stdio.h>
#include<string.h>


#define MAXLEN 100
typedef struct DATA
{
    char key[10];
    char name[20];
    int age;
}DATA;

typedef struct SLType
{
    DATA ListData[MAXLEN+1];
    int ListLen;
}SLType;

void SLInit (SLType *SL)
{
    SL->ListLen=0;
}

int SLLength(SLType *SL)
{
    return (SL->ListLen);
}

int Insert(SLType *SL,int n,DATA data)
{
    int i;
    if(SL->ListLen>=MAXLEN)
    {
        printf("顺序表已满，不能插入元素!\n");
        return 0;
    }
    
    if(n<1||n>SL->ListLen-1)
    {
        printf("插入的元素序号错误，不能插入元素!\n");
        return 0;
    }
    
    for (i=SL->ListLen;i>=n;i--)
    {
        SL->ListData[i+1]=SL->ListData[i];
    }
    SL->ListData[n]=data;
    SL->ListLen++;
    return 1;
}

int SLAdd(SLType *SL,DATA data)
{
  if(SL->ListLen>=MAXLEN)
  {
      printf("顺序表已满，不能添加节点了!\n");
      return 0;
  }
    SL->ListData[++SL->ListLen]=data;
    return 1;
}


int SLDelete(SLType *SL,int n)
{
    int i;
    if(n<1||n>SL->ListLen+1)
    {
        printf("删除节点序号错误，不能删除节点\n");
        return 0;
    }
    
    for(i=n;i<SL->ListLen;i++)
    {
        SL->ListData[i]=SL->ListData[i+1];
    }
    SL->ListLen--;
    return 1;
}

DATA *SLFindByNum(SLType *SL,int n)
{
    if(n<1||n>SL->ListLen+1)
    {
        printf("节点序号错误，不能返回节点!\n");
        return NULL;
    }
    return   &(SL->ListData[n]);
}

int SLFindByCont(SLType *SL,char *key)
{
    int i;
    for(i=1;i<=SL->ListLen;i++)
    {
        if(strcmp(SL->ListData[i].key,key)==0)
        {
            return i;
        }
    }
    return 0;
}

int SLALL(SLType *SL)
{
    int i;
    for(i=1;i<=SL->ListLen;i++)
    {
        printf("(%s,%s,%d)\n",SL->ListData[i].key,SL->ListData[i].name,SL->ListData[i].age);
    }
    return 0;
}

int main ()
{
    int i;
    SLType SL;
    DATA data;
    DATA *pdata;
    char key[10];
    
    printf("顺序表操作演示！\n");
    SLInit(&SL);
    printf("初始化顺序表完成！\n");
    
    do
    {
        printf("输入添加的节点(学号 姓名 年龄):");
        scanf("%s%s%d",&data.key,&data.name,&data.age);
        if(data.age)
        {
            if(!SLAdd(&SL, data))
            {                         
                break;
            }
        }
        else
        {
            break;
        }
    }while(1);
    printf("\n顺序表中的节点顺序为:\n");
    SLALL(&SL);
    
    printf("\n要取出节点序号:");
    scanf("%d",&i);
    pdata=SLFindByNum(&SL, i);
    if(pdata)
    {
        printf("第%d个节点为：(%s,%s,%d)\n",i,pdata->key,pdata->name,pdata->age);
    }

    printf("\n要查找节点的关键字：");
    scanf("%s",key);
    i=SLFindByCont(&SL,key);
    pdata=SLFindByNum(&SL,i);
    if(pdata)
    {
        printf("第%d个的节点为：(%s,%s,%d)\n",i,pdata->key,pdata->name,pdata->age);
    }
    
    return 0;
}

