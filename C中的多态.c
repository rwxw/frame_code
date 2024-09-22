#include <stdio.h>
#include <stdlib.h>

typedef int (*ptrFunc)(int, int);

typedef struct data {
    int a;
    int b;
    ptrFunc callback;
}data_t;

int Add(int a, int b)
{
    return (a + b);
}

int Mul(int a, int b)
{
    return (a * b);
}

void Register(data_t *data)
{
    printf("result is :%d", data->callback(data->a, data->b));
}

int main()
{
    data_t *mydata = (data_t *)malloc(sizeof(data_t));

    mydata->a = 5;
    mydata->b = 2; 
    mydata->callback = Add;
    Register(mydata);

    printf("\n");

    mydata->a = 5;
    mydata->b = 6;
    mydata->callback = Mul; 
    Register(mydata);
}