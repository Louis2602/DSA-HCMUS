#include <iostream>
#include <list>
#include <stdlib.h>
#include <assert.h>
#include <ctime>

using namespace std;

struct HashTable
{
    // Number of buckets to store elements
    int buckets = 10;
    // Pointer to said buckets
    list<int> *table = new list<int>[buckets];
};

void insert(int d, HashTable &ht)
{
    // Simple hash function is just modulo number of buckets
    int bucket = d % ht.buckets;
    // Insert into hash table bucket
    ht.table[bucket].push_back(d);
}

void print(HashTable ht)
{
    for (int i = 0; i < ht.buckets; i++)
    {
        cout << "| Bucket " << i << " | ";
        for (auto j : ht.table[i])
        {
            cout << "-> | " << j << " | ";
        }
        cout << endl;
    }
}

int main()
{
    HashTable ht;
    srand(time(NULL));
    for (int i = 0; i < 20; i++)
        insert(rand() % 100, ht);
    print(ht);

    return 0;
}