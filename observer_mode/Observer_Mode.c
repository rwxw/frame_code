#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

#include "list.h"

typedef int(*observer_func)(char* buf);

struct observer_ops_node
{
    struct list_head list; //内核链表标准结构
    observer_func handler; //handler的回调函数 没有优先级
};

//全局变量的观察者链
struct list_head observer_global_list;
//具体的处理函数
int observer_handler1(char *buf)
{
    printf("666");
    return 0;
}

int observer_handler2(char *buf)
{
    printf("777");
    return 0;
}

struct observer_ops_node node1;
struct observer_ops_node node2;

void observer_mode_init()
{
    node1.handler = observer_handler1;
    node2.handler = observer_handler2;

    init_list_head(&observer_global_list);
}

//register and unregister function
int observer_register(struct observer_ops_node *node)
{
    list_add_tail(&node->list, &observer_global_list);
    return 0;
}

int observer_unregister(struct observer_ops_node* node)
{
    list_del(&node->list);
    return 0;
}




int main()
{
    
}