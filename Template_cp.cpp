#include <bits/stdc++.h>
using namespace std;
#define ll long long
int GCD(int a,int b);
//Function to check whether a number is prime or not in O(sqrt(n))
bool isprime(int n)
{
    int cnt = 0;
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            cnt++;
            if ((n / i) != i)
            {
                cnt++;
            }
        }
    }
    if (cnt == 2)
        return true;
    return false;
}

//Euler Totient Function phi(N) = count of total co-prime pairs,TC-O(sqrt(N))
int phi(int n)
{
    int res=n;
    for(int i=2;i*i<=n;i++)
    {
        if(n%i==0)
        {
            res*=(i-1);
            res/=i;
        }
        while(n%i==0)
        {
            n/=i;
        }
    }
    if(n>1)
    {
        res*=(n-1);
        res/=n;
    }
    return res;
}

//Euler Totient Function phi(N) = count of total co-prime pairs,TC-O(Nlog(N))
int Phi(int n)
{
    int cnt=0;
    for(int i=1;i<n;i++)
    {
        if(GCD(i,n) == 1)
        {
            cnt++;
        }
    }
    return cnt;
}

// Function for sieve of eratosthenes to check for primes
int N = 10000000;
bool sieve[100000001];
void create_sieve()
{
    for (int i = 2; i <= N; i++)
    {
        sieve[i] = true;
    }

    for (int i = 2; i * i <= N; i++)
    {
        if (sieve[i] == true)
        {
            for (int j = i * i; j <= N; j += i)
            {
                sieve[j] = false;
            }
        }
    }
}

//function to compute primes within sqrt(upper limit)
vector<int> findPrimes(int n)
{
    vector<int> ds;
    for (int i = 2; i <= n; i++)
    {
        if (sieve[i] == true)
        {
            ds.push_back(i);
        }
    }
    return ds;
}

// segmented sieve function
void Segmented_Sieve(int l, int r)
{
    //suppose we are given a lower and upper limit (l&r) and we are asked to find the primes between them
    //step 1: find the primes in the range(0,sqrt(r))
    //step 2: create a dummy array of size r-l+1 and mark all of them as 1
    //step 3: iterate through the array and mark all the factors of primes as 0
    // final step : re-iterate through the array and print all the elements which has value as 1 which is
    // the ultimate prime betwen the array
    vector<int> primes = findPrimes(sqrt(r));
    int dummy[r - l + 1];
    for (int i = 0; i < r - l + 1; i++)
    {
        dummy[i] = 1;
    }
    for (auto it : primes)
    {
        int firstMultiple = (l / it) * it;
        if (firstMultiple < l)
            firstMultiple += it;
        for (int j = max(firstMultiple, it * it); j <= r; j += it)
        {
            dummy[j - l] = 0;
        }
    }
    for (int i = l; i <= r; i++)
    {
        if (dummy[i - l] == 1)
        {
            cout << i << " ";
        }
    }
    cout << endl;
}

// GCD in logN time
int GCD(int a, int b)
{
    if (b == 0)
        return a;

    return GCD(b, a % b);
}

// Extended Euclid GCD
// You are given a equation ax+by=gcd(a,b) and you are asked to calculate the value of x and y satisfying the
// given equation.
int EGCD(int a, int b, int &x, int &y)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int d = EGCD(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

//function to find the value of x and y of Linear Diophantine Equation (ax+by=c)(if it exits)
bool is_solution(int a, int b, int c, int &x, int &y)
{
    int x0, y0;
    int g = EGCD(abs(a), abs(b), x0, y0);
    if (c % g != 0)
    {
        return false;
    }
    x = x0 * (c / g);
    y = y0 * (c / g);
    if (a < 0)
        x = -x;
    if (b < 0)
        y = -y;
    return true;
    //Code for main function--->
    // int a,b,c,x,y;
    // cin>>a>>b>>c;
    // if(is_solution(a,b,c,x,y) == false)
    // {
    //     cout<<"No solution exists";
    // }
    // else
    // {
    //     is_solution(a,b,c,x,y);
    //     cout<<x<<" "<<y<<endl;
    // }
}

//Function to find the prime factors of a number in O(sqrt(n))
vector<int> prime_factors(int n)
{
    vector<int> prime;
    for (int i = 2; i * i <= n; i++)
    {
        while (n % i == 0)
        {
            prime.push_back(i);
            n /= i;
        }
    }
    if (n > 2)
        prime.push_back(n);
    return prime;
}

// Function to input a vector array
vector<int> array_input(int n)
{
    vector<int> arr;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        arr.push_back(x);
    }
    return arr;
}

//Function to print array
void print_array(vector<int> arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Function to calculate the factorial of a number
int factorial(int n)
{
    int j = 1;
    for (int i = 1; i <= n; i++)
    {
        j *= i;
    }
    return j;
}

void solve()
{
    //write your code here
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}