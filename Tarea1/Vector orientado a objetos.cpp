

#include <iostream>

class CVector
{
    private:
    int *m_pVect, m_nCount, m_nMax, m_nDelta;
    
    void Init(int delta);
    void Resize();

    public:
        CVector(int delta = 10);
        ~CVector();
        void Insert(int elem);
};

CVector::CVector(int delta) : m_nCount(0), m_nMax(delta), m_nDelta(delta) {
    m_pVect = new int[m_nMax];
}

CVector::~CVector() {
    delete[] m_pVect;
}

void CVector::Insert(int elem) {
    if(m_nCount == m_nMax)
        Resize();
    m_pVect[m_nCount++] = elem;
}

void CVector::Resize() {
    int *pTemp = new int[m_nMax + m_nDelta];
    for(int i = 0; i < m_nMax; i++) 
        pTemp[i] = m_pVect[i];
    delete[] m_pVect;
    m_pVect = pTemp;
    m_nMax += m_nDelta;
}


int main() {
    
    CVector vec(5);

    vec.Insert(10);
    vec.Insert(20);
    vec.Insert(30);
    vec.Insert(40);
    vec.Insert(50);
    vec.Insert(60);
    vec.Insert(70);

 



    return 0;
}
