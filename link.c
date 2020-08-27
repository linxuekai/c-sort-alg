#include <stdlib.h>
#include <stdio.h>
#include "link.h"

LinkNode *createLink()
{
    LinkNode *head = malloc(sizeof(int) + sizeof(void *));
    head->next = NULL;
}

LinkNode *createLinkNode(int value)
{
    LinkNode *node = malloc(sizeof(int) + sizeof(void *));
    node->value = value;
    node->next = NULL;
}

void linkAdd(LinkNode *linkHead, LinkNode *newNode)
{
    LinkNode *target = linkHead;
    while (target->next)
        target = target->next;
    target->next = newNode;
}

void linkRemove(LinkNode *linkHead, LinkNode *targetNode)
{
    LinkNode *prevNode = linkHead;
    while (prevNode->next != targetNode)
    {
        if (prevNode->next == NULL)
            return;
        prevNode = prevNode->next;
    }
    prevNode->next = prevNode->next->next;
    free(targetNode);
}

void linkInsert(LinkNode *appendTo, LinkNode *targetNode)
{
    targetNode->next = appendTo->next;
    appendTo->next = targetNode;
}

void freeLink(LinkNode *linkHead)
{
    LinkNode *pNode = NULL;
    while (linkHead->next)
    {
        pNode = linkHead;
        while (pNode->next)
            pNode = pNode->next;
        linkRemove(linkHead, pNode);
    }
    free(linkHead);
}

void linkClear(LinkNode *linkHead)
{
    LinkNode *pNode = NULL;
    while (linkHead->next)
    {
        pNode = linkHead;
        while (pNode->next)
            pNode = pNode->next;
        linkRemove(linkHead, pNode);
    }
}

void printLink(LinkNode *linkHead)
{
    LinkNode *pNode = linkHead;
    while (pNode->next)
    {
        pNode = pNode->next;
        printf("%d, ", pNode->value);
    }
    printf("\b\b;\n");
}