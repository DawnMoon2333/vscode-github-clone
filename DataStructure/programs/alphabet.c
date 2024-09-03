#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 50  // 顺序表的最大容量

typedef char DataType;  // 定义顺序表中元素的数据类型

typedef struct SeqList {
    DataType data[MAX_SIZE];  // 存储顺序表元素的数组
    int length;               // 顺序表的当前长度
} SeqList;

// 初始化顺序表
void initSeqList(SeqList *list) {
    list->length = 0;
}

SeqList createSeqList(){
    SeqList list;
    initSeqList(&list);
    return list;
}

// 向顺序表中插入元素
int insertSeqList(SeqList *list, int pos, DataType value) {
    if (pos < 0 || pos > list->length || list->length == MAX_SIZE) {
        return 0;  // 插入位置非法或顺序表已满
    }
    for (int i = list->length; i > pos; i--) {
        list->data[i] = list->data[i - 1];
    }
    list->data[pos] = value;
    list->length++;
    return 1;  // 插入成功
}

// 从顺序表中删除元素
int deleteSeqList(SeqList *list, int pos) {
    if (pos < 0 || pos >= list->length) {
        return 0;  // 删除位置非法
    }
    for (int i = pos; i < list->length - 1; i++) {
        list->data[i] = list->data[i + 1];
    }
    list->length--;
    return 1;  // 删除成功
}

// 打印顺序表
void printSeqList(SeqList *list) {
    for (int i = 0; i < list->length; i++) {
        printf("%c ", list->data[i]);
    }
    printf("\n");
}

int main() {
    // 创建并初始化线性表
    SeqList list = createSeqList();

    // 插入字母表元素
    for (int i = 0; i <= 25; i++){
        insertSeqList(&list, i, i + 97);
    }

    printf("顺序表元素: ");
    printSeqList(&list);

    deleteSeqList(&list, 3);
    printf("删除元素后顺序表: ");
    printSeqList(&list);

    return 0;
}
