#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>
#define FSize 3
typedef struct packet
{
    int SeqNum;
    char Data[FSize + 1];
} packet;
struct packet *readdata, *transdata;
int divide(char *msg)
{
    int msglen, NoOfPacket, i, j;
    msglen = strlen(msg);
    NoOfPacket = msglen / FSize;
    if ((msglen % FSize) != 0)
        NoOfPacket++;
    readdata = (struct packet *)malloc(sizeof(packet) * NoOfPacket);
    for (i = 0; i < NoOfPacket; i++)
    {
        readdata[i].SeqNum = i + 1;
        for (j = 0; (j < FSize) && (*msg != '\0'); j++, msg++)
            readdata[i].Data[j] = *msg;
        readdata[i].Data[j] = '\0';
    }
    printf("\nThe Message has been divided as follows\n");
    printf("\nPacket No. Data\n\n");
    for (i = 0; i < NoOfPacket; i++)
        printf(" %2d %s\n", readdata[i].SeqNum,
               readdata[i].Data);
    return NoOfPacket;
}
void shuffle(int NoOfPacket)
{
    int *Status;
    int i, j, trans;
    randomize();
    Status = (int *)calloc(NoOfPacket, sizeof(int));
    transdata = (struct packet *)malloc(sizeof(packet) * NoOfPacket);
    for (i = 0; i < NoOfPacket;)
    {
        trans = rand() % NoOfPacket;
        if (Status[trans] != 1)
        {
            transdata[i].SeqNum = readdata[trans].SeqNum;
            strcpy(transdata[i].Data, readdata[trans].Data);
            i++;
            Status[trans] = 1;
        }
    }
    free(Status);
}
void sortframes(int NoOfPacket)
{
    packet temp;
    int i, j;
    for (i = 0; i < NoOfPacket; i++)
        for (j = 0; j < NoOfPacket – i - 1; j++)
            if (transdata[j].SeqNum > transdata[j + 1].SeqNum)
            {
                temp.SeqNum = transdata[j].SeqNum;
                strcpy(temp.Data, transdata[j].Data);
                transdata[j].SeqNum = transdata[j + 1].SeqNum;
                strcpy(transdata[j].Data, transdata[j + 1].Data);
                transdata[j + 1].SeqNum = temp.SeqNum;
                strcpy(transdata[j + 1].Data, temp.Data);
            }
}
void receive(int NoOfPacket)
{
    int i;
    printf("\nPackets received in the following order\n");
    for (i = 0; i < NoOfPacket; i++)
        printf("%4d", transdata[i].SeqNum);
    sortframes(NoOfPacket);
    printf("\n\nPackets in order after sorting..\n");
    for (i = 0; i < NoOfPacket; i++)
        printf("%4d", transdata[i].SeqNum);
    printf("\n\nMessage received is :\n");
    for (i = 0; i < NoOfPacket; i++)
        printf("%s", transdata[i].Data);
}
void main()
{
    char *msg;
    int NoOfPacket;
    clrscr();
    printf("\nEnter The message to be Transmitted :\n");
    scanf("%[^\n]", msg);
    NoOfPacket = divide(msg);
    shuffle(NoOfPacket);
    receive(NoOfPacket);
    free(readdata);
    free(transdata);
    getch();
}