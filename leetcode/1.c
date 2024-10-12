#include<stdio.h>
#include<stdlib.h>;

typedef struct hashnode{
    int key;
    int value;
    struct hashnode* next;
} hashnode;

typedef struct hashmap{
    hashnode* node;
}hashmap;

hashmap* hashInit(){
    hashmap* map = (hashmap*)malloc(sizeof(hashmap));
    map->node = NULL;
    return map;
}

void hashPush(hashmap* map, int key, int value){
    hashnode* node = (hashnode*)malloc(sizeof(hashnode));
    node->key=key;
    node->value=value;
    node->next=NULL;
    if(map->node==NULL){
        map->node=node;
    }
    else{
        hashnode* cur = map->node;
        while(cur->next!=NULL){
            cur = cur->next;
        }
        cur->next=node;
    }
}

int hashGet(hashmap* map, int key){
    if(map->node==NULL) return -1;
    hashnode* node = map->node;
    while(node!=NULL){
        if(node->key==key) return node->value;
        node = node->next;
    }
    return -1;
}

void freenode(hashnode* node){
    if (node->next==NULL) return;
    free(node->next);
    free(node);
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    hashmap* map = hashInit();
    int key = 0, value = 0, delta=0;
    int* result = (int*)malloc(sizeof(int)*2);
    result[0] = 0;
    result[1] = 0;
    for(int i = 0; i < numsSize; i++){
        delta = target - nums[i];
        value = hashGet(map, delta);
        if (value==-1) {
            hashPush(map, nums[i], i);
            continue;
        }
        result[0] = i;
        result[1] = value;
        break;
    }
    *returnSize = 2;
    freenode(map->node);
    free(map);
    return result;
}

