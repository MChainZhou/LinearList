//
//  LinearList.c
//  LinearList
//
//  Created by apple on 2017/7/27.
//  Copyright © 2017年 apple. All rights reserved.
//

typedef void * LinearListNodeValue;

//数组结构体->线性表
typedef struct {
    int capacity;
    int length;
    LinearListNodeValue * value;
}LinearList;

#define LINEARKIST_STRUCT

#include "LinearList.h"
#include <stdlib.h>
#include <string.h>


//定义一个函数创建线性表
LinearList *listCreat(int capacity){
    if (capacity < 0) {
        return NULL;
    }
    LinearList * list = malloc(sizeof(LinearList));
    //当内存不够的时候有可能创建失败
    if (list) {
        list->length = 0;
        list->capacity = capacity;
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

/** 清空线性表*/
void listClear(LinearList *list){
    if (list == NULL) {
        return;
    }
    list->length = 0;
}

/** 获取线性表的长度*/
int listLenght(LinearList *list){
    if (list == NULL) {
        return 0;
    }
    
    return list->length;
}

/** 根据下标获取数据*/
LinearListNodeValue listGet(LinearList *list, int index){
    if (list == NULL || index < 0 || index >= list->length) {
        return 0;
    }
    return list->value[index];
}

/** 线性表插入数据*/
void listInsterValue(LinearList *list,LinearListNodeValue value, int index){
    if (list == NULL || index < 0 || index > list->length) {
        return;
    }
    //扩容:实现可变数组
    //1.判断内存是否够用
    if (list->length == list->capacity) {
        //2.如果不够用就扩容
        //2.1开辟一个新的空间
        int newCapacity = list->capacity + 10;
        LinearListNodeValue *newValue = malloc(sizeof(LinearListNodeValue) * newCapacity);
        if (newValue == NULL) return;
        //2.2把老的空间的里址赋值到新的空间里面去
//        for (int i = 0; i < list->capacity; i ++) {
//            newValue[i] = list->value[i];
//        }
        //1.目标  2.来源  3.字节
        memcpy(newValue, list->value,sizeof(LinearListNodeValue)*list->capacity);
        //2.3释放老的地址空间
        free(list->value);
        //2.4将新的地址址赋值给线性表
        list->value = newValue;
        list->capacity =  newCapacity;
    }
    
    
    
    //从index后所有的元素向后移动
    for (int i = list->length - 1; i >= index; i --) {
        list->value[i+1] = list->value[i];
    }
    //赋值插入的元素
    list->value[index] = value;
    
    //数量增加
    list->length ++;
    
}

/** 线性表新增数据*/
void listAddValue(LinearList *list,LinearListNodeValue value){
    listInsterValue(list, value, list->length);
}

/** 设置元素*/
void listSet(LinearList *list,int index,LinearListNodeValue value){
    if (list == NULL || index < 0 || index > list->length -1) {
        return;
    }
    list->value[index] = value;
    
}
/** 删除元素*/
void listDele(LinearList *list,int index){
    if (list == NULL || index < 0 || index > list->length -1) {
        return;
    }
   
    for (int i = index; i < list->length - 1; i ++) {
        list->value[i] = list->value[i+1];
    }
    list->length --;
}


/** 删除某个值的所有数据*/
void listDeleValue(LinearList *list,LinearListNodeValue value){
    if (list == NULL) {
        return;
    }
    
    int removeCount = 0;
    
    for (int i = 0; i < list->length - 1; i ++) {
        if (list->value[i] == value) {
            removeCount ++;
        }else{
            list->value[i - removeCount] = list->value[i];
        }
    }
    
    list->length -= removeCount;
}


