#pragma once

template<typename T>
class Vector{
public:
    Vector(){
        re_alloc(2);
    }

    void PushBack(const T& value){
        if(m_Size >= m_Capacity)
            re_alloc(m_Capacity + m_Capacity / 2);

        m_Data[m_Size] = value;
        m_Size++;
    }

    const T& operator[](size_t index) const{
        return m_Data[index];
    }

    T& operator[](size_t index){
        return m_Data[index];
    }

private:
    void re_alloc(size_t new_capacity){
        /*
        *   allocates a bigger block of memory for a full vector
        *   moves over old elements and deletes old vector
        */
        T* new_block = new T[new_capacity];

        if(new_capacity < m_Size)
            m_Size = new_capacity;

        for(size_t i=0; i < m_Size; i++)
            new_block[i] = m_Data[i];

        delete[] m_Data;
        m_Data = new_block;
        m_Capacity = new_capacity;
    }

private:
    T* m_Data = nullptr;
    size_t m_Size = 0;
    size_t m_Capacity = 0;
}
