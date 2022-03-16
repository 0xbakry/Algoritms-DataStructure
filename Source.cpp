#include<iostream>
using namespace std;


char Alph[] = { 'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z' };

struct elemnt {
    int ind = 0, r1 = 0, r2 = 0;
};

class SuffixArray {
private:
    int size = 0, max_r1 = 0;
    char *suffix;
    elemnt* arrayOfElemnts;
public :
    SuffixArray(const char suff[])
    {   
        
        while (suff[size] != '\0')
            size++;

        suffix = new char[size];
        strcpy(suffix, suff);
        
        arrayOfElemnts = new elemnt[size]();
        for (int i = 0; i < size; i++)
            arrayOfElemnts[i].ind = i;

    }

    void ConstructUsingPrefixDoubling()
    {
        initiate_r1();
        int iter = 1;
        while (max_r1 < (size-1))
        {
            int len = pow(2, iter);
            sort_using_r1_r2(arrayOfElemnts, 0, size - 1);
            update_r1();
            sort_using_ind(arrayOfElemnts, 0, size - 1);
            update_r2(len);
            iter++;
        }
        sort_using_r1(arrayOfElemnts, 0, size - 1);

    }


    void initiate_r1()
    {

        int NumOfUniqueChars = 1, count = 0;
        bool found = false;

        for (int i = 0; i < 26 ; i++)
        {
            if (count < size)
            {
                for (int j = 0; j < size; j++)
                {
                    if (suffix[j] == Alph[i])
                    {
                        found = true;
                        arrayOfElemnts[j].r1 = NumOfUniqueChars;
                        if (arrayOfElemnts[j].r1 > max_r1)
                            max_r1 = arrayOfElemnts[j].r1;
                        count++;
                    }
                }
                if (found)
                {
                    NumOfUniqueChars++;
                    found = false;
                }
            }
            else
            {
                arrayOfElemnts[size-1].r1 = 0;
                break;
            }
        }
        for (int i = 0; i < size-1; i++)
        {
            arrayOfElemnts[i].r2 = arrayOfElemnts[i + 1].r1;
        }

    }
    void swap(elemnt& a, elemnt& b)
    {
        elemnt t = a;
        a = b;
        b = t;
    }
    bool greaterthan(elemnt x, elemnt y)
    {
        if (x.r1 > y.r1)
            return true;
        else if (x.r1 == y.r1 && x.r2 > y.r2)
            return true;
        else
            return false;
    }
    int partition_1(elemnt* &arr, int start, int end)
    { 
        int p = end,  i = start-1;

        for (int j = start; j < end ; j++)
        {
            if (greaterthan(arr[p], arr[j]))
            {
                i++;
                swap(arr[i], arr[j]);

            }

        }
        swap(arr[i + 1], arr[end]);
        return (i + 1);
    }
    void sort_using_r1_r2(elemnt* &arr, int start, int end)
    {
        if (start < end)
        {
            int q = partition_1(arr, start, end);
            sort_using_r1_r2(arr, start, q - 1);
            sort_using_r1_r2(arr, q + 1, end);

        }
    }
    void update_r1()
    {
        int count = 0, NumOfUniqueChars = 1;
        for (int i = 1; i < size-1; i++)
        {

            if (arrayOfElemnts[i].r1 == arrayOfElemnts[i + 1].r1)
            {
                if (arrayOfElemnts[i].r2 == arrayOfElemnts[i + 1].r2)
                    count++;
                else
                {
                    for (int j = i - count; j <= i; j++)
                    {
                        arrayOfElemnts[j].r1 = NumOfUniqueChars;
                        if (arrayOfElemnts[j].r1 > max_r1)
                            max_r1 = arrayOfElemnts[j].r1;
                    }
                    NumOfUniqueChars++;
                    count = 0;
                }
            }
            else
            {
                for (int j = i - count; j <= i; j++)
                {
                    arrayOfElemnts[j].r1 = NumOfUniqueChars;
                    if (arrayOfElemnts[j].r1 > max_r1)
                        max_r1 = arrayOfElemnts[j].r1;
                }
                NumOfUniqueChars++;
                count = 0;
            }
        }

        if (arrayOfElemnts[size - 1].r1 == arrayOfElemnts[size - 2].r1)
        {
            if (arrayOfElemnts[size - 1].r2 == arrayOfElemnts[size - 2].r2)
            {
                count++;
                for (int j = size - count; j <= (size - 1); j++)
                {
                    arrayOfElemnts[j].r1 = NumOfUniqueChars;
                    if (arrayOfElemnts[j].r1 > max_r1)
                        max_r1 = arrayOfElemnts[j].r1;
                }
            }
            else
            {
                for (int j = (size-1) - count; j <= (size - 2); j++)
                {
                    arrayOfElemnts[j].r1 = NumOfUniqueChars;
                    if (arrayOfElemnts[j].r1 > max_r1)
                        max_r1 = arrayOfElemnts[j].r1;
                }
                arrayOfElemnts[size-1].r1 = NumOfUniqueChars;
                if (arrayOfElemnts[size-1].r1 > max_r1)
                    max_r1 = arrayOfElemnts[size-1].r1;
            }
        }
        else
        {
            for (int j = (size - 1) - count; j <= (size - 2); j++)
            {
                arrayOfElemnts[j].r1 = NumOfUniqueChars;
                if (arrayOfElemnts[j].r1 > max_r1)
                    max_r1 = arrayOfElemnts[j].r1;
                NumOfUniqueChars++;
            }
            arrayOfElemnts[size - 1].r1 = NumOfUniqueChars;
            if (arrayOfElemnts[size-1].r1 > max_r1)
                max_r1 = arrayOfElemnts[size-1].r1;
        }
 
    }
    int partition_2(elemnt*& arr, int start, int end)
    {
        int p = arr[end].ind, i = start - 1;

        for (int j = start; j < end; j++)
        {
            if (arr[j].ind <= p)
            {
                i++;
                swap(arr[i], arr[j]);

            }

        }
        swap(arr[i + 1], arr[end]);
        return (i + 1);
    }
    void sort_using_ind(elemnt*& arr, int start, int end)
    {
        if (start < end)
        {
            int q = partition_2(arr, start, end);
            sort_using_ind(arr, start, q - 1);
            sort_using_ind(arr, q + 1, end);

        }
    }
    int partition_3(elemnt*& arr, int start, int end)
    {
        int p = arr[end].r1, i = start - 1;

        for (int j = start; j < end; j++)
        {
            if (arr[j].r1 <= p)
            {
                i++;
                swap(arr[i], arr[j]);

            }

        }
        swap(arr[i + 1], arr[end]);
        return (i + 1);
    }
    void sort_using_r1(elemnt*& arr, int start, int end)
    {
        if (start < end)
        {
            int q = partition_3(arr, start, end);
            sort_using_r1(arr, start, q - 1);
            sort_using_r1(arr, q + 1, end);

        }
    }
    void update_r2(int len)
    {
        for (int i = 0; i < size; i++)
        {
            if ((i + len) > (size - 1))
            {
                for (int j = i; j < size; j++)
                    arrayOfElemnts[j].r2 = 0;
                break;
            }
            else
            {
                arrayOfElemnts[i].r2 = arrayOfElemnts[i + len].r1;
            }
        }

    }

    void Print()
    {
        for (int i = 0; i < size; i++)
        {
            cout << arrayOfElemnts[i].ind << " ";
        }
    }

    ~SuffixArray() {
       delete[] this->arrayOfElemnts;

    }

};

int main()
{
    SuffixArray t("ACGACTACGATAAC$");
    t.ConstructUsingPrefixDoubling();
    t.Print(); // Prints:  14 11 12  0  6  3  9 13  1  7  4  2  8 10  5
    return 0;
}
