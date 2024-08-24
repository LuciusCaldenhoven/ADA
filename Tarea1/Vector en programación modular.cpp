#include <iostream>
#include <cstdlib> 

struct Vector
{
    int* m_pVect; 
    int m_nCount;  
    int m_nMax;    
    int m_nDelta;  
};


void InitVector(Vector *pThis, int delta)
{
    pThis->m_pVect = nullptr;
    pThis->m_nCount = 0;
    pThis->m_nMax = 0;
    pThis->m_nDelta = delta;
}

void Resize(Vector *pThis)
{
 
    int* temp = (int*)realloc(pThis->m_pVect, sizeof(int) * (pThis->m_nDelta + pThis->m_nMax));
    
    pThis->m_pVect = temp;
    pThis->m_nMax += pThis->m_nDelta;
}


void Insert(Vector *pThis, int elem)
{
    if (pThis->m_nCount == pThis->m_nMax) 
        Resize(pThis); 
    pThis->m_pVect[pThis->m_nCount++] = elem;
}





int main()
{
    Vector myVector;
    InitVector(&myVector, 5); 


    for (int i = 0; i < 12; ++i) {
        Insert(&myVector, i * 10); 
    }


    std::cout << "elementos en vector: ";
    for (int i = 0; i < myVector.m_nCount; ++i) {
        std::cout << myVector.m_pVect[i] << " ";
    }
    std::cout << std::endl;


    return 0;
}
