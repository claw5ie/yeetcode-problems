bool
isPalindrome (struct ListNode *head)
{
  size_t count = 0, capacity = 16;
  int *buffer = (int *)malloc (capacity * sizeof (int));

  while (head != NULL)
    {
      if (count >= capacity)
        {
          capacity = capacity * 2 + 1;
          buffer = (int *)realloc (buffer, capacity * sizeof (int));
        }

      buffer[count++] = head->val;
      head = head->next;
    }

  bool is_palindrome = true;

  for (size_t i = 0; i < count; i++)
    {
      if (buffer[i] != buffer[--count])
        {
          is_palindrome = false;
          break;
        }
    }

  free (buffer);

  return is_palindrome;
}
