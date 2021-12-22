#include <iostream>

using namespace std;

int **CreateMatr(int sizei, int sizej);
int *CreateMatrOne(int sizeOn);
void Deletematr(int **ptr, int size);
void DeletematrOn(int *ptr, int size);
void InitMatr(int **ptr, int sizeI, int sizeJ, int *ptrS, int sizeOn);
void InitMatrOn(int *ptr, int sizeOn);
void PrintMatr(int **ptr, int sizeI, int sizeJ);
void PrintMatrOn(int *ptr, int sizeOn);

int main()
{
    int **ptrD = nullptr;
    int *ptrS = nullptr;
    int sizeI = 3, sizeJ = 5, sizeOn = 10;

    cout << "Enter size On " << endl;
    cin >> sizeOn;
    cout << "Enter size I " << endl;
    cin >> sizeI;
    cout << "Enter size J " << endl;
    cin >> sizeJ;
    cout << endl;

    ptrD = CreateMatr(sizeI, sizeJ);
    ptrS = CreateMatrOne(sizeOn);
    InitMatrOn(ptrS, sizeOn);
    InitMatr(ptrD, sizeI, sizeJ, ptrS, sizeOn);
    PrintMatrOn(ptrS, sizeOn);
    cout << endl;
    PrintMatr(ptrD, sizeI, sizeJ);
    Deletematr(ptrD, sizeI);
    DeletematrOn(ptrS, sizeOn);

    system("pause");
    return 0;
}

int *CreateMatrOne(int sizeOn) 
{
    int *ptr = nullptr;
    ptr = new int[sizeOn];
    return ptr;
}

int **CreateMatr(int sizei, int sizej)
{
    int **ptr = nullptr;
    ptr = new int *[sizei];
    for (int i = 0; i < sizei; i++)
    {
        ptr[i] = new int[sizej];
    }
    return ptr;
}

void Deletematr(int **ptr, int size)
{
    for (int i = 0; i < size; i++)
    delete[] ptr[i];
    delete[] ptr;
    return;
}

void DeletematrOn(int *ptr, int size)
{
    delete[] ptr;
    return;
}

void InitMatr(int **ptr, int sizeI, int sizeJ, int *ptrS, int sizeOn) 
{
    int temp = sizeOn, k = 0;

    for (int i = 0; i < sizeI; i++)
    {
        for (int j = 0; j < sizeJ; j++) 
        {
            if (k != temp)
            {
                ptr[i][j] = ptrS[k];
                k++;
            }
            else
            {
                ptr[i][j] = 0;
            }
        }
    }
    return;
}

void InitMatrOn(int *ptr, int sizeOn) 
{
    for (int i = 0; i < sizeOn; i++)
    ptr[i] = (rand() % 10);
    return;
}

void PrintMatr(int **ptr, int sizeI, int sizeJ)
{
    for (int i = 0; i < sizeI; i++)
    {
        for (int j = 0; j < sizeJ; j++)
        {
            cout << ptr[i][j] << "  ";
        }
        cout << endl;
    }
    return;
}

void PrintMatrOn(int *ptr, int sizeI) {
    for (int i = 0; i < sizeI; i++)
    {
        std::cout << ptr[i] << " ";
    }
    cout << endl;
    return;
}
