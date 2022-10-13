#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
struct data
{
    int value;
    struct data *next;
    struct data *prev;
};
struct data *head = NULL;
int insertAtBeginning()
{
    int num;
    printf("\nEnter the number you want to store\n");
    scanf("%d", &num);
    if (head == NULL)
    {
        head = (struct data *)(malloc(sizeof(struct data)));
        head->value = num;
        head->next = NULL;
        head->prev = NULL;
    }
    else
    {
        struct data *temp = NULL;
        temp = head;
        head = (struct data *)(malloc(sizeof(struct data)));
        head->value = num;
        head->next = temp;
        head->prev = NULL;
    }
    return 1;
}
int insertAtEnd()
{
    if (head == NULL)
    {
        printf("\nLinklist is Empty,so cant insert at the end\n");
    }
    else
    {
        int num;
        printf("\nEnter the number you want to store\n");
        scanf("%d", &num);
        struct data *temp, *check;
        temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        check = (struct data *)(malloc(sizeof(struct data)));
        check->next = NULL;
        check->prev = temp;
        check->value = num;
        temp->next = check;
        return 1;
    }
}
int afterData(int num)
{
    if (head == NULL)
    {
        printf("Linklist is empty, can't enter after particular data");
    }
    else
    {
        struct data *temp = NULL;
        temp = head;
        while (temp->next != NULL && temp->value != num)
        {
            temp = temp->next;
        }
        if (temp->next == NULL && temp->value != num)
        {
            printf("Data you entered was not found\n");
        }
        else
        {
            int data;
            printf("Enter the data you want to Insert :");
            scanf("%d", &data);
            if (temp->next == NULL && temp->value == num)
            {
                temp->next = (struct data *)(malloc(sizeof(struct data)));
                temp->next->next = NULL;
                temp->next->prev = temp;
                temp->next->value = data;
            }
            else
            {
                struct data *check;
                check = (struct data *)(malloc(sizeof(struct data)));
                check->value = data;
                temp->next->prev = check;
                check->next = temp->next;
                temp->next = check;
            }
            return 1;
        }
    }
}
int beforeData(int num)
{
    if (head == NULL)
    {
        printf("Linklist is empty, can't enter after particular data");
    }
    else if (head->value == num)
    {
        insertAtBeginning(num);
    }
    else
    {
        struct data *temp;
        temp = head;
        while (temp->next != NULL && temp->value != num)
        {
            temp = temp->next;
        }
        if (temp->next == NULL && temp->value != num)
        {
            printf("Data you entered was not found");
        }
        else
        {
            int data;
            printf("Enter the data you want to Insert:");
            scanf("%d", &data);
            struct data *check;
            check = (struct data *)(malloc(sizeof(struct data)));
            temp->prev->next = check;
            check->prev = temp->prev;
            check->next = temp;
            temp->prev = check;
            check->value = data;
            return 1;
        }
    }
}
int afterNode(int _num)
{
    if (head == NULL)
    {
        printf("Linklist is empty. Can't enter after a particular node");
    }
    else
    {
        int check = 1;
        struct data *temp;
        temp = head;
        while (temp->next != NULL && check != _num)
        {
            temp = temp->next;
            check = check + 1;
        }
        if (_num < 1)
        {
            printf("Enter atleast 1 otherwise insert at beginning\n");
        }
        else if (temp->next == NULL && check != _num)
        {
            printf("Can't enter after this particular node as the no. of nodes are less.(Print data to check the no. of nodes)\n");
        }
        else
        {
            struct data *try;
            int data;
            printf("Enter the data you want to Insert:");
            scanf("%d", &data);
            if (temp->next == NULL && check == _num)
            {
                try = (struct data *)malloc(sizeof(struct data));
                temp->next = try;
                try->prev = temp;
                try->next = NULL;
                try->value = data;
            }
            else
            {
                try = (struct data *)malloc(sizeof(struct data));
                try->next = temp->next;
                try->prev = temp;
                try->value = data;
                temp->next->prev = try;
                temp->next = try;
            }
            return 1;
        }
    }
}
int beforeNode(int _num)
{
    if (head == NULL)
    {
        printf("Linklist is empty. Can't enter before a particular node");
    }
    else
    {
        int check = 1;
        struct data *temp;
        temp = head;
        while (temp->next != NULL && check != _num)
        {
            temp = temp->next;
            check = check + 1;
        }
        if (_num == 1)
        {
            insertAtBeginning();
            return 1;
        }
        else if (temp->next == NULL && check != _num)
        {
            printf("Can't enter after this particular node as the no. of nodes are less.(Print data to check the no. of nodes)\n");
        }
        else
        {
            struct data *try;
            int data;
            printf("Enter the data you want to Insert:");
            scanf("%d", &data);
            try = (struct data *)malloc(sizeof(struct data));
            try->next = temp;
            try->prev = temp->prev;
            try->value = data;
            temp->prev->next = try;
            temp->prev = try;
            return 1;
        }
    }
}
void deleteFromBeginning()
{
    if (head == NULL)
    {
        printf("Linklist is already empty");
    }
    else
    {
        struct data *temp;
        temp = head;
        head = temp->next;
        temp->next->prev = NULL;
        printf("Data deleted successfully");
        free(temp);
    }
}
void deleteFromEnd()
{
    if (head == NULL)
    {
        printf("Linklist is already empty");
    }
    else
    {
        struct data *temp;
        temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->prev->next = NULL;
        printf("Data deleted successfully");
        free(temp);
    }
}
int deleteData(int _num)
{
    if (head == NULL)
    {
        printf("Linklist is already empty.");
    }
    else
    {
        struct data *temp;
        temp = head;
        if (head->value == _num)
        {
            head = temp->next;
            free(temp);
            return 1;
        }
        else
        {
            while (temp->next != NULL && temp->value != _num)
            {
                temp = temp->next;
            }
            if (temp->next == NULL && temp->value != _num)
            {
                printf("Data you entered was not found. (Check the data by printing the elements)");
            }
            else
            {
                if (temp->next == NULL && temp->value == _num)
                {
                    temp->prev->next = NULL;
                    free(temp);
                }
                else
                {
                    temp->prev->next = temp->next;
                    temp->next->prev = temp->prev;
                    free(temp);
                }
                return 1;
            }
        }
    }
}
int deleteNode(int _num)
{
    if (head == NULL)
    {
        printf("Linklist is already empty.");
    }
    else
    {
        struct data *temp;
        int check = 1;
        temp = head;
        if (_num == 1)
        {
            head = temp->next;
            free(temp);
            return 1;
        }
        else
        {
            while (temp->next != NULL && check != _num)
            {
                temp = temp->next;
                check = check + 1;
            }
            if (temp->next == NULL && check != _num)
            {
                printf("Node you entered was not found. (Check the nodes by printing the elements)");
            }
            else
            {
                if (temp->next == NULL && check == _num)
                {
                    temp->prev->next = NULL;
                    free(temp);
                }
                else
                {
                    temp->prev->next = temp->next;
                    temp->next->prev = temp->prev;
                    free(temp);
                }
                return 1;
            }
        }
    }
}

void print()
{
    if (head == NULL)
    {
        printf("\n-------------------\n| Linklist is Empty |\n-------------------\n");
    }
    else
    {
        struct data *temp;
        temp = head;
        while (temp != NULL)
        {
            printf("\n----------------\n| DATA   --  %d |\n----------------\n", temp->value);
            temp = temp->next;
        }
    }
}
int main()
{
    int count;
    for (;;)
    {
        printf("\n---------------------------------------------------------------\n---------------------------------------------------------------");
        printf("\nSelect the operation from the following list:\n");
        printf("1.Insert at Beginning\n2.Insert at End\n3.Insert at Random location\n4.Delete from Beginning\n5.Delete from End\n6.Delete from Random Location\n7.Print all Data\n8.Quit\n\n");
        scanf("%d", &count);
        switch (count)
        {
        case 1:
        {
            printf("You selected to Insert at Beginnning");
            int check;
            check = insertAtBeginning();
            if (check == 1)
            {
                printf("-----------------------------------\n| Data stored without any failure |\n-----------------------------------\n");
            }
            else
            {
                printf("-------------------------\n| Failed to store data. |\n-------------------------\n");
            }
            break;
        }
        case 2:
        {
            int check;
            printf("You selected to Insert at End");
            check = insertAtEnd();
            if (check == 1)
            {
                printf("-----------------------------------\n| Data stored without any failure |\n-----------------------------------\n");
            }
            else
            {
                printf("\n-------------------------\n| Failed to store data. |\n-------------------------\n");
            }
            break;
        }
        case 3:
        {
            int data;
            printf("Select the way you would like to enter data\n1. After a particular data\n2. Before a particular data\n3. After a particular node\n4. Before a particular node\n\n");
            scanf("%d", &data);
            switch (data)
            {
            case 1:
            {
                int num, temp;
                printf("\nEnter the data after which you want to enter new node\n");
                scanf("%d", &num);
                temp = afterData(num);
                if (temp == 1)
                {
                    printf("-----------------------------------\n| Data stored without any failure |\n-----------------------------------\n");
                }
                else
                {
                    printf("-------------------------\n| Failed to store data. |\n-------------------------");
                }
                break;
            }
            case 2:
            {
                int num, temp;
                printf("\nEnter the data before which you want to enter new node\n");
                scanf("%d", &num);
                temp = beforeData(num);
                if (temp == 1)
                {
                    printf("-----------------------------------\n| Data stored without any failure |\n-----------------------------------\n");
                }
                else
                {
                    printf("-------------------------\n| Failed to store data. |\n-------------------------");
                }
                break;
            }
            case 3:
            {
                int num, temp;
                printf("\nEnter the node  after which you want to enter new node\n");
                scanf("%d", &num);
                temp = afterNode(num);
                if (temp == 1)
                {
                    printf("-----------------------------------\n| Data stored without any failure |\n-----------------------------------\n");
                }
                else
                {
                    printf("-------------------------\n| Failed to store data. |\n-------------------------");
                }
                break;
            }
            case 4:
            {
                int num, temp;
                printf("\nEnter the node  before which you want to enter new node\n");
                scanf("%d", &num);
                temp = beforeNode(num);
                if (temp == 1)
                {
                    printf("-----------------------------------\n| Data stored without any failure |\n-----------------------------------\n");
                }
                else
                {
                    printf("-------------------------\n| Failed to store data. |\n-------------------------");
                }
                break;
            }
            }
            break;
        }
        case 4:
        {
            deleteFromBeginning();
            break;
        }
        case 5:
        {
            deleteFromEnd();
            break;
        }
        case 6:
        {
            int _data;
            printf("Select the way you would like to delete data\n1. Particular data\n2. Particular node\n\n");
            scanf("%d", &_data);
            switch (_data)
            {
            case 1:
            {
                int num, temp;
                printf("Enter the data which you want to delete");
                scanf("%d", &num);
                temp = deleteData(num);
                if (temp == 1)
                {
                    printf("-----------------------------------\n| Data deleted without any failure |\n-----------------------------------\n");
                }
                else
                {
                    printf("-------------------------\n| Failed to delete data. |\n-------------------------");
                }
                break;
            }
            case 2:
            {
                int num, temp;
                printf("Enter the node which you want to delete");
                scanf("%d", &num);
                temp = deleteNode(num);
                if (temp == 1)
                {
                    printf("-----------------------------------\n| Node deleted without any failure |\n-----------------------------------\n");
                }
                else
                {
                    printf("-------------------------\n| Failed to delete Node. |\n-------------------------");
                }
                break;
            }
            }
            break;
        }

        case 7:
        {
            print();
            break;
        }

        case 8:
        {
            goto end;
            break;
        }
        }
    }
end:
    return 0;
}
