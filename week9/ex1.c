#include <stdio.h>
#include <stdlib.h>

struct Page
{
    int frameNumber;
    int counter;
};

int isInList(struct Page *pageTable, int pageNumber, int size);

int getOldestPage(struct Page *pageTable, int size);

int main(int argc, char const *argv[])
{
    int pageFramesNumber = atoi(argv[1]);
    int counter = 0;
    int miss, hit = 0;

    FILE *fp;

    char buffer[10];

    fp = fopen("Lab 09 input.txt", "r");

    struct Page *pageTable = malloc(sizeof(struct Page) * pageFramesNumber);

    while (fscanf(fp, "%s", buffer) == 1)
    {
        int readPageFrameNumber = atoi(buffer);

        int listNumber = isInList(pageTable, readPageFrameNumber, counter);

        if (listNumber != -1)
        {
            hit++;

            for (int i = 0; i < counter; i++)
            {
                pageTable[i].counter >>= 1;
            }

            pageTable[listNumber].counter = pageTable[listNumber].counter | 1 << (sizeof(int) - 1);
        }
        else
        {
            miss++;

            struct Page newPage;

            newPage.counter = 0;
            newPage.frameNumber = readPageFrameNumber;

            if (counter < pageFramesNumber)
            {
                pageTable[counter] = newPage;
                counter++;
            }
            else
            {
                pageTable[getOldestPage(pageTable, counter)] = newPage;
            }
        }
    }
    printf("hits: %d\nmisses: %d\nhit/miss ratio: %f\n", hit, miss, (double)hit / miss);

    return 0;
}

int isInList(struct Page *pageTable, int pageNumber, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (pageTable[i].frameNumber == pageNumber)
        {
            return i;
        }
    }
    return -1;
}

int getOldestPage(struct Page *pageTable, int size)
{
    int minCounter = -1;
    int page = -1;
    for (int i = 0; i < size; i++)
    {
        if (pageTable[i].counter < minCounter)
        {
            minCounter = pageTable[i].counter;
            page = i;
        }
    }
    return page;
}