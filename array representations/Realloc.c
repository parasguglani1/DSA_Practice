#include <stdio.h>
#include <stdlib.h>

void
display (int a[], int s)
{
  int i;
  for (i = 0; i < s; i++)
    printf ("%d ", a[i]);
  printf ("\n");
}

void
input (int a[], int start, int end)
{
  int i;
  for (int i = start; i < end; i++)
    scanf ("%d", (a + i));
}

int
main ()
{
  printf ("Enter the array size\n");
  int size, x;
  scanf ("%d", &size);
  x = size;
  int *a = (int *) malloc (size * sizeof (int));
  printf ("Enter %d integers\n", size);
  input (a, 0, size);
  printf ("Contents of the array:\n");
  display (a, size);

  printf ("Enter the new size\n");
  scanf ("%d", &size);

  a = (int *) realloc (a, size * sizeof (int));
  if (size > x)
    {
      printf ("Enter %d more elements\n", (size - x));
      input (a, x, size);
    }

  printf ("Contents of the array:\n");
  display (a, size);

  return 0;
}
