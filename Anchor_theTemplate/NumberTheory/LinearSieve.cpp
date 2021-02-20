/*
 *  Eratosthenes Sieve with O(n) Complexity
 *
 *  The improved Eratosthenes Sieve to find all prime numbers in [2, range).
 *
 *  Required Header File:
 *      <cstring> - memset().
 *
 *  Prerequisite:
 *      const int RANGE
 *          Declare the MAX RANGE.
 *      int cnt = 0
 *          The index of prime[] & count of prime numbers.
 *
 *  Product:
 *      int prime[]
 *          A 0-index array consists of primes, like {2, 3, 5, ...}.
 *          Numbers inside are in [2, range).
 *          The valid interval is [0, cnt).
 *      bool isprime[]
 *          A array indicates whether a number is prime.
 *          e.g.    isprime[2] checks whether 2 is a prime number.
 *
 *  Functions:
 *  int linearsieve(int range)
 *      Make prime[] and isprime[].
 *      Parameter:
 *          range - Declare the end of the function.
 *      Return:
 *          The quantity of prime numbers in [2, range).
 *
 */

//Prerequisite
const int RANGE = 1e9;   //  [2, RANGE) - The upperbound of the problem.
int cnt = 0;    //The index of prime[] & count of prime numbers.
//Product
int prime[RANGE];
bool isprime[RANGE];    //Indicate whether the number is prime.

//Return the quantity of prime numbers in [2, range).
int linearsieve(int range)   {  //  [2, range)
    //Initialization
    memset(prime, 0, sizeof(prime));
    memset(isprime, true, sizeof(isprime));

    for (int i = 2;i <= range;i++) {
        if (arr[i] == true)    prime[cnt++] = i;
        for (int j = 0;j < cnt && (long long) i * prime[j] <= range;j ++) {
            isprime[i * prime[j]] = false;
            if (i % prime[j] == 0) break;
        }
    }

    return cnt; //Return the quantity of prime numbers in [2, range).
}
