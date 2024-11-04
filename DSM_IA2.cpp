#include <bits/stdc++.h>
using namespace std;

bool pair_is_in_relation(int e1, int e2, int b[], int sizeOfB) 
{
    for (int i = 0; i < sizeOfB; i += 2) 
    {
        if (b[i] == e1 && b[i+1] == e2) 
            return true;
    }
    return false;
}

bool reflexive(int a[], int sizeOfA, int b[], int sizeOfB) 
{
    for (int i = 0; i < sizeOfA; i++) 
    {
        if (!pair_is_in_relation(a[i], a[i], b, sizeOfB)) 
            return false;
    }
    cout << "Reflexive - Yes" << endl;
    return true;
}

bool symmetric(int a[], int sizeOfA, int b[], int sizeOfB) 
{
    for (int i = 0; i < sizeOfB; i += 2) 
    {
        int e = b[i];
        int f = b[i+1];
        if (!pair_is_in_relation(f, e, b, sizeOfB)) 
            return false;
    }
    cout << "Symmetric - Yes" << endl;
    return true;
}

bool antiSymmetric(int a[], int sizeOfA, int b[], int sizeOfB) 
{
    for (int i = 0; i < sizeOfB; i += 2) 
    {
        int e = b[i];
        int f = b[i+1];
        if (e != f && pair_is_in_relation(f, e, b, sizeOfB)) 
            return false;
    }
    cout << "AntiSymmetric - Yes" << endl;
    return true;
}

bool transitive(int a[], int sizeOfA, int b[], int sizeOfB) 
{
    for (int i = 0; i < sizeOfB; i += 2) 
    {
        int e = b[i];
        int f = b[i+1];
        for (int j = 0; j < sizeOfB; j += 2) 
        {
            if (f == b[j]) 
            {
                int g = b[j+1];
                if (!pair_is_in_relation(e, g, b, sizeOfB)) 
                    return false;
            }
        }
    }
    cout << "Transitive - Yes" << endl;
    return true;
}

int main() 
{
    char keepGoing = 'y';
    while (keepGoing == 'y') 
    {
        int sizeOfA;
        cout << "Enter the size of the set: ";
        cin >> sizeOfA;

        int setA[sizeOfA];
        cout << "Enter the elements of the set: ";
        for (int i = 0; i < sizeOfA; i++) 
        {
            cin >> setA[i];
        }

        int sizeOfB;
        cout << "Enter the number of pairs in the relation: ";
        cin >> sizeOfB;
        sizeOfB *= 2;

        int relB[sizeOfB];
        cout << "Enter the relation pairs (as pairs of integers):" << endl;
        for (int i = 0; i < sizeOfB; i += 2) 
        {
            cout << "Pair " << (i / 2) + 1 << ": ";
            cin >> relB[i] >> relB[i + 1];
        }

        cout << "Results for the entered set and relation:" << endl;
        reflexive(setA, sizeOfA, relB, sizeOfB);
        symmetric(setA, sizeOfA, relB, sizeOfB);
        antiSymmetric(setA, sizeOfA, relB, sizeOfB);
        transitive(setA, sizeOfA, relB, sizeOfB);

        cout << endl << "Would you like to test it again? (y/n): ";
        cin >> keepGoing;
    }

    return 0;
}