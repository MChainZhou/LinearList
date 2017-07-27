//
//  main.m
//  LinearList
//
//  Created by apple on 2017/7/27.
//  Copyright © 2017年 apple. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "LinearList.h"

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        LinearList *list = listCreat(5);
        listAddValue(list, 1);
        listAddValue(list, 2);
        listAddValue(list, 3);
        listAddValue(list, 4);
        listAddValue(list, 5);
        
        
        listDele(list, 2);
        
    }
    return 0;
}
