#include <iostream>
#include <cstdio>


using namespace std;

enum TreeType {kNormalBST, kMirrorBST, kNotSure};


bool IsBST(int *array, int len, TreeType *type)
{
    if (len < 2) {
        return true;
    }
    int root = array[0];
    int leftEnd;
    int i = 1;
    if (*type == kNotSure) {
        int state = 0;
        while(i < len)
        {
            if (state == 0) {
                if (array[i] < root) {
                    state = 1;
                }
                else
                {
                    state = 2;
                }
            }
            else if (state == 1)
            {
                if (array[i] >= root) {
                    leftEnd = i-1;
                    state = 3;// Normal
                }
            }
            else if (state == 2)
            {
                if (array[i] < root) {
                    leftEnd = i-1;
                    state = 4;
                }
            }
            else if (state == 3) {
                if (array[i] < root) {
                    return false;
                }
            }
            else if (state == 4)
            {
                if (array[i] >= root) {
                    return false;
                }
            }

            ++i;
        }        
        if (state == 1 || state == 2) {
            return IsBST(array+1, len-1, type);
        }
        else if (state == 3)
        {
            *type = kNormalBST;
            return (IsBST(array+1, leftEnd, type) && IsBST(array+leftEnd+1, len-leftEnd-1, type));
        }
        else if (state == 4)
        {
            *type = kMirrorBST;
            return (IsBST(array+1, leftEnd, type) && IsBST(array+leftEnd+1, len-leftEnd-1, type));
        }
    }
    else if (*type == kNormalBST)
    {
        while( i < len && array[i] < root )
        {
            ++i;
        }
        leftEnd = i-1;
        for (int k = leftEnd+1; k < len; ++k) {
            if (array[k] < root) {
                return false;
            }
        }
        return (IsBST(array+1, leftEnd, type) && IsBST(array+leftEnd+1, len-leftEnd-1, type));
    }
    else if (*type == kMirrorBST)
    {
        while(i < len && array[i] >= root)
        {
            ++i;
        }
        leftEnd = i-1;
        for(int k = leftEnd+1; k < len; ++k)
        {
            if (array[k] >= root) {
                return false;
            }
        }
        return (IsBST(array+1, leftEnd, type) && IsBST(array+leftEnd+1, len-leftEnd-1, type));
    }
}

void printBST(int *array, int len, TreeType type)
{
    if (len == 0) {
        return;
    }
    else if (len == 1)
    {
        printf("%d ", array[0]);
        return;
    }

    int root = array[0];
    int i = 1;
    int leftEnd;
    if (type == kNormalBST) {
        while(i < len && array[i] < root)
        {
            ++i;
        }
    }
    else
    {
        while(i < len && array[i] >= root)
        {
            ++i;
        }
    }

        leftEnd = i-1;

        printBST(array+1, leftEnd, type);
        printBST(array+leftEnd+1, len-leftEnd-1, type);
        printf("%d ", root);
}


int main()
{
    int n;
    int *array;
    while(scanf("%d", &n) != EOF)
    {
        array = new int[n];
        for(int i = 0; i < n; ++i)
        {
            scanf("%d", array + i);
        }
        TreeType type = kNotSure;
        if(IsBST(array, n, &type))
        {
            printf("YES\n");
            int root = array[0];
            int i = 1;
            int leftEnd;
            int len = n;
            
    if (type == kNormalBST) {
        while(i < len && array[i] < root)
        {
            ++i;
        }
    }
    else
    {
        while(i < len && array[i] >= root)
        {
            ++i;
        }
    }

        leftEnd = i-1;

        printBST(array+1, leftEnd, type);
        printBST(array+leftEnd+1, len-leftEnd-1, type);
            printf("%d\n", array[0]);
        }
        else
        {
            printf("NO\n");
        }
        delete[] array;
    }

    return 0;
}
