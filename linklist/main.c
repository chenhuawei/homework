//
// Created by chenhuawei on 2019-04-17.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

typedef int ElemType;

struct Node {
    ElemType data;
    struct Node *next;
};

typedef struct {
    struct Node * head;
    struct Node * tail;

} LinkList;

struct LinkList * createLinkList() {
    LinkList * linkList = malloc(sizeof(LinkList));
    linkList->head = NULL;
    linkList->tail = NULL;
    return linkList;
}

void destroyLinkList(LinkList * linkList) {

    struct Node *node = linkList->head;
    struct Node *next = NULL;
    while (node) {
        next = node->next;
        free(node);
        node = next;
    }

    free(linkList);
}

void appendItem(LinkList * linkList, ElemType data) {
    struct Node *node = malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;

    if (!linkList->head) {
        linkList->head = node;
    }

    struct Node * tail = linkList->tail;
    if (tail) {
        tail->next = node;
    }
    linkList->tail = node;
}

void removeFirstItem(LinkList * linkList) {
    struct Node *head = linkList->head;
    struct Node *next = head->next;
    free(head);
    linkList->head = next;
}

void removeLastItem(LinkList * linkList) {
    struct Node *tail = NULL;
    struct Node *node = linkList->head;
    while (node) {
        if (node == linkList->tail) {
            free(node);
            break;
        }
        tail = node;
        node = node->next;
    }
    tail->next = NULL;
    linkList->tail = tail;
}

ElemType getItemAt(LinkList * linkList, int index) {
    struct Node *node = linkList->head;
    int i = 0;
    while (node) {
        if (i++ == index)
            return (node->data);
        node = node->next;
    }
    return NULL;
}

void printAllItems(LinkList * linkList) {
    struct Node *node = linkList->head;
    int seq = 0;
    while (node) {
        printf("\t%2d. %2d\n", ++seq, node->data);
        node = node->next;
    }
}

int main() {
    LinkList * linkList = createLinkList();
    ElemType data;

    printf("append 10 items:\n");
    for (int i = 1; i <= 10; i ++) {
        appendItem(linkList, i);
    }
    printAllItems(linkList);

    data = getItemAt(linkList, 4);
    assert(data == 5);

    printf("remove first item:\n");
    removeFirstItem(linkList);
    data = getItemAt(linkList, 0);
    assert(data == 2);
    printAllItems(linkList);

    printf("remove last item:\n");
    removeLastItem(linkList);
    data = getItemAt(linkList, 7);
    assert(data == 9);
    printAllItems(linkList);

    destroyLinkList(linkList);

    return 0;
}