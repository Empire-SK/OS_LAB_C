#include <stdio.h>
int main()
{
  int n, m;
  printf("Enter the no. oif processes:\n");
  scanf("%d", &n);
  printf("Enter the no. of resurces:\n");
  scanf("%d", &m);
  int allocation[n][m], max[n][m], need[n][m];
  int available[m], work[m];
  int finish[n], safesequence[n], count = 0; 
  printf("Enter allocation matrix: ");
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      printf("P%d Resource %d: ", i, j);
      scanf("%d", &allocation[i][j]);
    }
  }
  printf("Enter max matrix: ");
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {

      printf("P%d Resource %d: ", i, j);
      scanf("%d", &max[i][j]);
    }
  }
  printf("Enter available resource: ");
  for (int j = 0; j < m; j++)
  {
    printf("Resource %d: ", j);
    scanf("%d", &available[j]);
  }

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      need[i][j] = max[i][j] - allocation[i][j];
    }
  }

  for (int j = 0; j < m; j++)
  {
    work[j] = available[j];
  }

  for (int i = 0; i < n; i++)
  {
    finish[i] = 0;
  }

  while (count < n)
  {
    int found = 0;
    for (int i = 0; i < n; i++)
    {
      if (finish[i] == 0)
      {
        int flag = 1;

        for (int j = 0; j < m; j++)
        {
          if (need[i][j] > work[j])
          {
            flag = 0;
            break;
          }
        }
        if (flag == 1)
        {
          for (int k = 0; k < m; k++)
          {
            work[k] += allocation[i][k];
          }
          safesequence[count++] = i;
          finish[i] = 1;
          found = 1;
        }
      }
    }

    if (found == 0)
    {
      printf("Deadlock condition...\n");
      return 0;
    }
  }
  printf("system is in a safe state,\nsafe sequence : ");
  for (int i = 0; i < n; i++)
  {
    printf("P%d ", safesequence[i]);
  }
  printf("\n ");
  return 0;
}
