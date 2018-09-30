typedef  int ElementType;

typedef struct ListNode {
	ElementType Element;  //data
	struct ListNode *Next;    // point to the next node
}LinkList;

LinkList *createList(int n);
void TraverseList(LinkList *list);
void InsertList(LinkList *list, int pos, int val);
void UpdateElement(LinkList *list, int pos, int value);
void DeleteList(LinkList *list, int pos);
int SearchList(LinkList *list, int value);
