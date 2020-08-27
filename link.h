typedef struct LinkNode
{
    int value;
    struct LinkNode *next;
} LinkNode;

LinkNode *createLink();

LinkNode *createLinkNode(int value);

void linkAdd(LinkNode *linkHead, LinkNode *newNode);

void linkRemove(LinkNode *linkHead, LinkNode *targetNode);

void linkInsert(LinkNode *appendTo, LinkNode *targetNode);

void freeLink(LinkNode *linkHead);

void linkClear(LinkNode *linkHead);

void printLink(LinkNode *linkHead);