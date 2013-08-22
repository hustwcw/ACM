#include <stdio.h>


int main()
{
    int n;
    int array[10001];
    int number[100001];
    scanf("%d", &n);
    for(int i = 1; i < 10001; ++i)
    {
        array[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        int temp;
        scanf("%d", &temp);
        number[i] = temp;
        array[temp] = array[temp]+1;
    }
    bool flag = false;
    for (int i = 0; i < n ; i++) {
        if (array[number[i]] == 1) {
            printf("%d\n", number[i]);
            flag = true;
            break;
        }
    }

    if (flag == false)
    {
        printf("None\n");
    }
    return 0;
}
