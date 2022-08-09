typedef struct ListNode Node;

Node *
mergeTwoLists (Node *l1, Node *l2)
{
  Node dummy, *prev = &dummy;

  while (l1 != NULL && l2 != NULL)
    {
      int v1 = l1->val, v2 = l2->val;

      if (v1 < v2)
        {
          prev->next = l1;
          prev = l1;
          l1 = l1->next;
        }
      else
        {
          prev->next = l2;
          prev = l2;
          l2 = l2->next;
        }
    }

  if (l1 == NULL)
    l1 = l2;

  while (l1 != NULL)
    {
      prev->next = l1;
      prev = l1;
      l1 = l1->next;
    }

  prev->next = NULL;

  return dummy.next;
}
