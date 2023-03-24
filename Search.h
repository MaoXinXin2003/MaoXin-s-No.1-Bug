#include "mainwindow.h"

#define SEARCH_H
/* 线性表初始长度 */
#define INIT_SIZE 1024

/* 线性表长度增量 */
#define INCREASE_SIZE 10

/* 文件名最大长度 */
#define FILE_NAME_LEN 20

/* 字符数组最大长度 */
#define MAX_STR 255

/* 单个单词最大长度 */
#define WORD_LEN 20

#define WORD 21

/* 状态码 */
typedef int Status;
#define TRUE 1
#define FALSE 0

#define OK 2
#define ERROR -2

#ifndef _STATUS_H_			// 如果系统中已经有了下面状态码的定义，就不再重复定义了
#define OVERFLOW -4		// 堆栈上溢 超过所能表述的最大正数
#define UNDERFLOW -3	// 堆栈下溢 超过所能表述的最大负数
#endif // SEARCH_H

/************* 结构体定义 ************/

/* 定义顺序串 */
typedef struct {
    char ch[MAX_STR];
    int length;
}String;

/* 单个单词结构 */
typedef struct {
    char word[INIT_SIZE];	// 存储单词，不超过二十个字符
    int count;			// 单词出现的次数
}ElementType;

/* 单词列表 */
typedef struct {
    ElementType * et;	// 指向存储单词的头指针
    int length;
    int listSize;
}SeqList;

/************* 函数定义 ************/

/* 初始化单词列表 */
Status init_SeqList(SeqList * sq, ElementType * et);

/* 添加单词 -  */
Status add_SeqList(SeqList * sq, ElementType * et, char * word);

/* 统计单个单词个数 */
Status count_SeqList(SeqList * sq, ElementType * et);

/* 创建文本文件 */
Status create_File();

/* 单词汇总 */
Status wordCollect();

/* 串模式匹配算法 */
Status BF_Compare(String s1, String s2, int length);

/* 部分匹配函数表 */
void get_next(String s2, int * next);

/* 检索单词出现的个数 */
Status searchWordCount();

/* 检索单词在该行出现的次数、行号、相关位置 */
Status searchWordLine();

/* 单词索引菜单 */
void searchWord_Menu();

/* 主菜单 */
Status main_Menu();

/* 清屏函数 - Windows/Linux */
void clear();

/* 按任意键继续 */
void continueStart();
