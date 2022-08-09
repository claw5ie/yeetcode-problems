struct ListNode*
middleNode (struct ListNode* head)
{
  size_t count = 0;

  for (struct ListNode *node = head; node != NULL; ++count)
    node = node->next;

  count /= 2;

  while (head != NULL)
    {
      if (count == 0)
        return head;

      head = head->next;
      --count;
    }

  return head;
}
