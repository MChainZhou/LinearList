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
/** 清空线性表*/
void listClear(LinearList *list);
/** 获取线性表的长度*/
int listLenght(LinearList *list);
/** 线性表新增数据*/
void listAddValue(LinearList *list,LinearListNodeValue value);
/** 线性表插入数据*/
void listInsterValue(LinearList *list,LinearListNodeValue value, int index);
#endif /* LinearList_h */
