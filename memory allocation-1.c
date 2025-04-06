#include <stdio.h>
struct process
{
   int pid;
   int blocksize;
   int size;
} p[10];

struct block
{
   int size;
   int allocated;
} b[10];

int bn, pn;
void display()
{
   printf(" \n id processize block\n");
   for (int i = 0; i < pn; i++)
   {
      if (p[i].blocksize == -1)
      {
         printf("%d %d not allocate\n", p[i].pid, p[i].size);
      }
      else
      {
         printf("%d %d %d \n", p[i].pid, p[i].size, p[i].blocksize);
      }
   }
}
void best()
{
   printf("\nbest fit\n");
   struct block temp;
   for (int i = 0; i < bn - 1; i++)
   {
      for (int j = 0; j < bn - i - 1; j++)
      {
         if (b[j].size > b[j + 1].size)
         {
            temp = b[j];
            b[j] = b[j + 1];
            b[j + 1] = temp;
         }
      }
   }
   for (int i = 0; i < pn; i++)
   {
      p[i].blocksize = -1;
   }
   for (int i = 0; i < bn; i++)
   {
      b[i].allocated = -1;
   }

   for (int i = 0; i < pn; i++)
   {
      for (int j = 0; j < bn; j++)
      {
         if (b[j].allocated == -1 && b[j].size >= p[i].size)
         {
            b[j].allocated = 1;
            p[i].blocksize = b[j].size;
            break;
         }
      }
   }

   display();
}
void first()
{
   printf("\nfirst fit\n");
   for (int i = 0; i < pn; i++)
   {
      p[i].blocksize = -1;
   }
   for (int i = 0; i < bn; i++)
   {
      b[i].allocated = -1;
   }
   for (int i = 0; i < pn; i++)
   {
      for (int j = 0; j < bn; j++)
      {
         if (b[j].allocated == -1 && b[j].size >= p[i].size)
         {
            b[j].allocated = 1;
            p[i].blocksize = b[j].size;
            break;
         }
      }
   }

   display();
}
void worst()
{
   printf("\nworst fit\n");
   struct block temp;
   for (int i = 0; i < bn - 1; i++)
   {
      for (int j = 0; j < bn - i - 1; j++)
      {
         if (b[j].size < b[j + 1].size)
         {
            temp = b[j];
            b[j] = b[j + 1];
            b[j + 1] = temp;
         }
      }
   }
   for (int i = 0; i < pn; i++)
   {
      p[i].blocksize = -1;
   }
   for (int i = 0; i < bn; i++)
   {
      b[i].allocated = -1;
   }

   for (int i = 0; i < pn; i++)
   {
      for (int j = 0; j < bn; j++)
      {
         if (b[j].allocated == -1 && b[j].size >= p[i].size)
         {
            b[j].allocated = 1;
            p[i].blocksize = b[j].size;
            break;
         }
      }
   }

   display();
}
int main()
{

   printf("enter the no of block");
   scanf("%d", &bn);
   for (int i = 0; i < bn; i++)
   {
      printf("enter the size of the block %d", i + 1);
      scanf("%d", &b[i].size);
   }
   printf("enter the no of process");
   scanf("%d", &pn);
   for (int i = 0; i < pn; i++)
   {
      printf("enter the process %d", i + 1);
      scanf("%d", &p[i].size);
      p[i].pid = i + 1;
   }

   first();
   best();
   worst();
}