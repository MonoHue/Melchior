/*
    *   Eratosthenes Sieve with O(n) Complexity
    *
    *   An improved Eratosthenes Sieve to find all prime numbers in [2, range).
    *
    *   Required Header File:
    *       <cstring> - memset().
    *   Input:
    *       None.
    *   Output:
    *       int prime[RANGE]
    *           An 0-index array with primes, like {2, 3, 5, ...}.
    *           Mention that RANGE indicates the range of the WORST case.
    *   Return:
    *       The quantity of prime numbers in [2, range).
    *   Parameter:
    *       int range
    *           Indicate the end of the range.
    *
*/

//Parameter
const int RANGE = 100000;   //  [2, RANGE)
//Output
int prime[RANGE];

//Return the quantity of prime numbers in [2, range).
int linearsieve(int range)   {  //  [2, range)
    //Intermediate Variables
    int cnt = 0;    //The index of prime[] & counter of prime numbers.
    bool isprime[RANGE];    //Indicate whether the number is prime.

    //Initialization
    memset(prime, 0, sizeof(prime));
    memset(isprime, 0, sizeof(isprime));

    for (int i = 2;i <= range;i++) {
        if (arr[i] == true)    prime[cnt++] = i;
        for (int j = 0;j < cnt && (long long) i * prime[j] <= range;j ++) {
            isprime[i * prime[j]] = false;
            if (i % prime[j] == 0) break;
        }
    }

    return cnt; //Return the quantity of prime numbers in [2, range).
}
