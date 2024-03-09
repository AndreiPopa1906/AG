#include <tuple>
#include <stdio.h>
#include <cstring> 
template <typename K, typename V>
class Map {
private:
    struct Pair 
    {
        K key;
        V value;
    };

    Pair* pair;
    int allocated;
    int size;

    void ExpandCapacity() 
    {
        allocated *= 2;
        Pair* temp_pair = new Pair[allocated];
        std::memcpy(temp_pair, pair, size * sizeof(Pair));
        delete[] pair;
        pair = temp_pair;
    }

public:
    Map() 
    {
        allocated = 10;
        size = 0;
        pair = new Pair[allocated];
    }

    ~Map() 
    {
        delete[] pair;
    }

    void Set(const K& key, const V& value) 
    {
        for (int i = 0; i < size; ++i) 
        {
            if (pair[i].key == key) 
            {
                pair[i].value = value;
                return;
            }
        }

        if (size == allocated) 
            ExpandCapacity();

        pair[size].key = key;
        pair[size].value = value;
        size++;
    }

    bool Get(const K& key, V& value) const 
    {
        for (int i = 0; i < size; ++i) 
        {
            if (pair[i].key == key) 
            {
                value = pair[i].value;
                return true;
            }
        }

        return false;
    }

    int Count() const 
    {
        return size;
    }

    void Clear() 
    {
        size = 0;
    }

    bool Delete(const K& key) 
    {
        for (int i = 0; i < size; i++) 
        {
            if (pair[i].key == key) 
            {
                pair[i] = pair[size - 1];
                size--;
                return true;
            }
        }

        return false;
    }

    bool Includes(const Map<K, V>& map) const 
    {
        for (int i = 0; i < map.size; i++) 
        {
            bool found = false;
            for (int j = 0; j < size; j++) 
                if (pair[j].key == map.pair[i].key) 
                {
                    found = true;
                    break;
                }
            if (!found)  return false;
        }

        return true;
    }

    V& operator[](const K& key)
    {
        for (int i = 0; i < size; i++)
            if (pair[i].key == key)
                return pair[i].value;
        if (size == allocated)
            ExpandCapacity();
        pair[size].key = key;
        size++;
        return pair[size - 1].value;
    }


    struct Iterator
    {
        Pair* ptr;
        int index;

        Iterator(Pair* Ptr, int Index) : ptr(Ptr), index(Index) {}

        Iterator& operator++() 
        {
            index++;
            return *this;
        }

        bool operator!=(const Iterator& other) const 
        {
            return index != other.index;
        }

        std::tuple<K&, V&, int> operator*() const 
        {
            return std::tuple<K&, V&, int>(ptr[index].key, ptr[index].value, index);
        }
    };

    Iterator begin() 
    {
        return Iterator(pair, 0);
    }

    Iterator end() 
    {
        return Iterator(pair, size);
    }
};
