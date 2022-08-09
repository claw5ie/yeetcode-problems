typedef struct ListNode ListNode;

ListNode *
addTwoNumbers (ListNode *l1, ListNode *l2)
{
  ListNode dummy, *prev = &dummy;
  int rest = 0;

  while (l1 != NULL && l2 != NULL)
    {
      rest += l1->val + l2->val;

      ListNode *node = malloc (sizeof (ListNode));

      node->val = rest % 10;
      rest /= 10;
      prev->next = node;
      prev = node;

      l1 = l1->next;
      l2 = l2->next;
    }

  if (l1 == NULL)
    l1 = l2;

  while (l1 != NULL)
    {
      ListNode *node = malloc (sizeof (ListNode));

      rest += l1->val;

      node->val = rest % 10;
      rest /= 10;
      prev->next = node;
      prev = node;

      l1 = l1->next;
    }

  if (rest != 0)
    {
      ListNode *node = malloc (sizeof (ListNode));

      node->val = rest;
      prev->next = node;
      prev = node;
    }

  prev->next = NULL;

  return dummy.next;
}
