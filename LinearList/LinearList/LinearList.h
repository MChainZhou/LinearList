//
//  LinearList.h
//  LinearList
//
//  Created by apple on 2017/7/27.
//  Copyright © 2017年 apple. All rights reserved.
//

#ifndef LinearList_h
#define LinearList_h

#include <stdio.h>

typedef int LinearListNodeValue;

//数组结构体->线性表
typedef struct {
    int capacity;
    int length;
    LinearListNodeValue * value;
}LinearList;

/** 定义一个线性表*/
LinearList *listCreat(int capacity);
/** 释放线性表*/
void listReleas(LinearList *list);
#endif /* LinearList_h */
