typedef struct ListNode Node;

Node *
removeNthFromEnd (Node *head, int n)
{
  Node *ahead = head;

  while (n > 0 && ahead != NULL)
    {
      ahead = ahead->next;
      --n;
    }

  if (n > 0)
    return NULL;

  Node *curr = head, *prev = NULL;

  while (ahead != NULL)
    {
      prev = curr;
      curr = curr->next;
      ahead = ahead->next;
    }

  if (prev != NULL)
    prev->next = curr->next;
  else
    head = head->next;

  return head;
}
