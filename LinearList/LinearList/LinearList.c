//
//  LinearList.c
//  LinearList
//
//  Created by apple on 2017/7/27.
//  Copyright © 2017年 apple. All rights reserved.
//

#include "LinearList.h"
#include <stdlib.h>


//定义一个函数创建线性表
LinearList *listCreat(int capacity){
    if (capacity < 0) {
        return NULL;
    }
    LinearList *list = malloc(sizeof(LinearList));
    //当内存不够的时候有可能创建失败
    if (list) {
        list->capacity = capacity;
        list->length = 0;
        list->value = malloc(capacity * sizeof(LinearListNodeValue));
    }
    
    return list;
}


/** 释放线性表*/
void listReleas(LinearList *list){
    if (list == NULL) {
        return;
    }
    
    free(list->value);
    free(list);
}
