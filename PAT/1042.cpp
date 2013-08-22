#include <iostream>
#include <stdio.h>


using namespace std;


int main()
{
    int k;
    int random[54];
    int card1[54];
    int card2[54];
    scanf("%d", &k);

    for(int i = 0; i < 54; i++)
    {
        card1[i] = i;
        scanf("%d", random+i);
    }

    int *pOldCard = card1;
    int *pNewCard = card2;
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < 54; j++) {
            pNewCard[random[j]-1] = pOldCard[j];
        }
        int *temp = pNewCard;
        pNewCard = pOldCard;
        pOldCard = temp;
    }
    for (int i = 0; i < 54; i++) {
        char c;
        int sequence = pOldCard[i];
        if((sequence/13) == 0)
        {
            c = 'S';
        }
        else if ((sequence/13) == 1)
        {
            c = 'H';
        }
        else if ((sequence/13) == 2)
        {
            c = 'C';
        }
        else if ((sequence/13) == 3)
        {
            c = 'D';
        }
        else
        {
            c = 'J';
        }
        printf("%c%d", c, (sequence%13) + 1);
        if (i < 53)
        {
            printf(" ");
        }
    }
}
