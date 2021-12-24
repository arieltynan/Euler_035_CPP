// Euler_035_CPP.cpp : This file contains the 'main' function. Program execution begins and ends there.
// How many circular primes are there below one million?
// Current runtime: <1 second!

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

int main()
{
    vector<int> primes;
    int total = 0; //total num of circular primes
    int n = 1000000; //primes less than n (1000000)
    primes.push_back(2);
    for (int i = 3; i < n; i++)
    {
        bool prime = true;
        for (int j = 0; j < primes.size() && primes[j] * primes[j] <= i; j++)
        {
            if (i % primes[j] == 0)
            {
                prime = false;
                break;
            }
        }
        if (prime)
        {
            primes.push_back(i);
            //cout << i << " ";
        }
    } // end for loop, prime search

    //Primes without even numbers
    vector<int> pVect; //final vector of primes without even numbers
    for (int i = 0; i < primes.size(); i++)
    {
        bool evens = false;
        int pTemp = primes[i];
        while (pTemp != 0) //separates ints into digits
        {
            //cout << pTemp << " ";
            pTemp /= 10; 
            
            
            if ((pTemp % 2 == 0 || pTemp % 5 == 0) && pTemp != 0)
            {
                evens = true;
                break;
            }
        }
        //cout << endl;
        if (evens == false)
        {
            pVect.push_back(primes[i]);
            //cout << primes[i] << endl;
        }
    }
    
    for(int i = 0; i < pVect.size(); i++)
    {
        bool circ = true; //if false, number if not circular
        // Check if prime is circular
        int temp = pVect[i];
        //cout << primes[i] << endl;
        vector<int> vect;
        while (temp != 0) //separates ints into digits
        {
            vect.push_back(temp % 10);
            temp /= 10;
        }
        for (int i = 0; i < vect.size(); i++) //iterate through all circs (equal to # of digits in num)
        {
            int temp = vect[0]; //vect.back(); // temp value equal to last value in vector
            for (int j = 0; j < vect.size() - 1; j++) //circle around number
            {
                vect[j] = vect[j + 1]; //each digit sent one pos back
            }
            vect[vect.size() - 1] = temp; //last digit brought around to first digit

            int newval = 0;
            vector<int> tempVect = vect; //allows for original vect to be reused in for loop
            while (tempVect.empty() == false) //this outputs new number to be tested
            {
                newval = 10 * newval + tempVect.back();
                tempVect.pop_back();
            }
            //cout << newval << endl;
            if (bool exists = find(begin(pVect), end(pVect), newval) != end(pVect) == false)
                circ = false;

        } // end for loop
        if (circ == true)
        {
            total++;
            cout << pVect[i] << endl;
        }
    } // end for statement (cycle through primes)
    
    cout << "Number of primes: " << primes.size() << endl;
    cout << "Number of primes with 1, 3, 7, 9: " << pVect.size() << endl;
    cout << "Total circular primes: " << total << endl;
    return 0;
}

