#include <iostream>

template <typename Type>
class CVector
{
private:
    Type *m_pVect;
    int m_nCount, m_nMax, m_nDelta;

    void Resize();

public:
    CVector(int delta);
    void Init(int delta);
    void Insert(Type elem);
 
};


template <typename Type>
void CVector<Type>::Init(int delta)
{
    m_nCount = 0;
    m_nMax = delta;
    m_nDelta = delta;
    m_pVect = new Type[m_nMax];  
}

template <typename Type>
void CVector<Type>::Resize()
{
    Type *pTemp = new Type[m_nMax + m_nDelta];
    for (int i = 0; i < m_nMax; ++i)
    {
        pTemp[i] = m_pVect[i];
    }
    delete[] m_pVect;
    m_pVect = pTemp;
    m_nMax += m_nDelta;
}

template <typename Type> 
CVector<Type>::CVector(int delta)
{
    Init(delta);
}

template <typename Type>
void CVector<Type>::Insert(Type elem)
{
    if (m_nCount == m_nMax)
    {
        Resize();
    }
    m_pVect[m_nCount++] = elem;
}



int main()
{
    CVector<int> vec(5);
    

    vec.Insert(10);
    vec.Insert(20);
    vec.Insert(30);
    vec.Insert(40);
    vec.Insert(50);
    vec.Insert(60);  
    vec.Insert(70);

    return 0;
}
