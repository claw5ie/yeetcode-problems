struct ListNode *
reverseList (struct ListNode *head)
{
  if (head == NULL || head->next == NULL)
    return head;

  struct ListNode *prev = head->next;
  head->next = NULL;

  while (prev->next != NULL)
    {
      struct ListNode *next = prev->next;
      prev->next = head;
      head = prev;
      prev = next;
    }

  prev->next = head;

  return prev;
}
