#include <iostream>
#include <cassert>
#include <algorithm>

class DynamicIntArray
{
public:
    DynamicIntArray() = default;
    // RAII
    // Resource Acquisition Is Initialization
    // Acquire resources in ctor
    // Release them in the dtor
    explicit DynamicIntArray(size_t size):
        m_arr{new int[size]{}},
        m_size{size},
        m_capacity{size}
    {}

    // Rule of 3
    // If you define / delete one of destructor, copy constructor and assignment operator
    // you must define / delete them all if you want your program to run correctly
    ~DynamicIntArray()
    {
        delete [] m_arr;
    }

    DynamicIntArray(const DynamicIntArray& other):
        m_arr{new int[other.m_capacity]},
        m_size{other.m_size},
        m_capacity{other.m_capacity}
    {
        std::copy(other.begin(), other.end(), begin());
    }

    // Copy and Swap Idiom
    DynamicIntArray& operator=(const DynamicIntArray& other)
    {
        DynamicIntArray temp{other};
        swap(temp);
        return *this;
    }

    void push_back(int element)
    {
        if (m_size >= m_capacity)
        {
            extend();
        }
        m_arr[m_size++] = element;
    }

    size_t size() const
    {
        return m_size;
    }

    size_t capacity() const
    {
        return m_capacity;
    }

    int* begin()
    {
        return m_arr;
    }

    int* end()
    {
        return m_arr + m_size;
    }

    const int* begin() const
    {
        return m_arr;
    }

    const int* end() const
    {
        return m_arr + m_size;
    }

    void reserve(size_t capacity)
    {
        if (capacity > m_capacity)
        {
            resize(capacity);
        }
    }

    void swap(DynamicIntArray& other)
    {
        using std::swap;
        swap(m_arr, other.m_arr);
        swap(m_size, other.m_size);
        swap(m_capacity, other.m_capacity);
    }
private:
    int* m_arr{nullptr};
    size_t m_size{0};
    size_t m_capacity{0};

    void extend()
    {
        resize(m_capacity * 3 / 2 + 1);
    }

    void resize(size_t capacity)
    {
        m_capacity = capacity;

        int* new_m_arr{new int[m_capacity]};
        std::copy(begin(), end(), new_m_arr);
        delete [] m_arr;
        m_arr = new_m_arr;
    }
};

// ADL
void swap(DynamicIntArray& lhs, DynamicIntArray& rhs)
{
    lhs.swap(rhs);
}

int main()
{
    DynamicIntArray da;
    da.reserve(20);
    for (int i = 0; i < 20; i++)
    {
        da.push_back(i);
    }

    DynamicIntArray db;

    // Correct way to swap user defined types
    using std::swap;
    swap(da, db); // Uses our swap if their is one define or std::swap otherwise

    // Uses std::cbegin and std::cend which in turn use .begin and .end
    for (int num : db)
    {
        std::cout << num << ' ';
    }

    return 0;
}
