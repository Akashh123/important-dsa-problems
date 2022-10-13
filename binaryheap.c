#include <stdio.h> 
#include<conio.h> 
#define HEAP_FULL 100  
int insert(int *p,int value,int n)
{
    if (HEAP_FULL == (n - 1))
    {
        printf("Heap is FULL");
        return n;
    }
    else
    {
        int i;
        int temp;
        n = n + 1;
        p[n] = value;
        i = n + 1;
        while (i > 1)
        {
            if (p[i - 1] > p[(i / 2) - 1])
            {
                temp = p[(i / 2) - 1];
                p[(i / 2) - 1] = p[i - 1];
                p[i - 1] = temp;
                i = (i / 2);
            }
            else
            {
                break;
            }
        }
        return n;
    }
}
void print(int *p, int n)
{
    if (n == -1)
    {
        printf("Heap is empty");
    }

    else
    {
        int i = 0;
        for (i = 0; i <= n; i++)
        {
            printf("\n-------\n| %d |\n-------\n", p[i]);
        }
    }
}
int deleteheap(int *p, int n)
{
    if (n == -1)
    {
        printf("Can't Delete Item as Heap is Empty.");
        return n;
    }
    else
    {
        int temp, i = 0, tree = 0, s = 0, k;
        p[0] = p[n];
        k = n;
        while ((k / 2) >= 1)
        {
            tree = tree + 1;
            k = k / 2;
        }
        n = n - 1;
        while (s < tree)
        {
            if (p[(2 * i) + 1] < p[(2 * i) + 2])
            {
                if (p[(2 * i) + 2] > p[i])
                {
                    temp = p[i];
                    p[i] = p[(2 * i) + 2];
                    p[(2 * i) + 2] = temp;
                    i = 2 * i + 2;
                    s = s + 1;
                }
                else
                {
                    break;
                }
            }
            else if (p[(2 * i) + 1] > p[(2 * i) + 2])
            {
                if (p[(2 * i) + 1] > p[i])
                {
                    temp = p[i];
                    p[i] = p[(2 * i) + 1];
                    p[(2 * i) + 1] = temp;
                    i = 2 * i + 1;
                }
                else
                {
                    break;
                }
            }
            else
            {
                break;
            }
        }
        return n;
    }
}
int main()
{
    int arr[HEAP_FULL];
    int t = 1, n = -1;
    s = s + 1;
    while (t == 1)
    {
        int x; printf("\n---------------------------------------------------------------  
\n---------------------------------------------------------------"); printf("\n| Enter your's  choice |\n-------------------------\n1. Enter a  
value in Max Heap\n2. Print data \n3. Delete a value from Max Heap\n4.  EXIT\n");  
scanf("%d",&x); switch(x) 
{
        case 1:
        {
            int value;
            printf("Enter the value to be inserted\n");
            scanf("%d", &value);
            n = insert(arr, value, n);
            break;
        }
        case 2:
        {
            print(arr, n);
            break;
        }
        case 3:
        {
            n = deleteheap(arr, n);

            break;
        }
        case 4:
        {
            t = 0;
            break;
        }  
}
    }
    return 0;
}