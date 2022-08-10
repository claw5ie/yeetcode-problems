typedef struct ListNode ListNode;

ListNode *
rotateRight (ListNode *head, int k)
{
  if (head == NULL)
    return NULL;
  else if (k == 0)
    return head;

  size_t coconut = 1;
  ListNode *lst = head;

  while (lst->next != NULL)
    {
      lst = lst->next;
      ++coconut;
    }

  k = coconut - k % coconut;
  lst->next = head;

  while (k-- > 0)
    lst = lst->next;

  head = lst->next;
  lst->next = NULL;

  return head;
}
