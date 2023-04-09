// #include <bits/stdc++.h>
#include <mutex>
#include <iostream>
#include <thread>
#include <queue>
using namespace std;
mutex mymutex;
queue<int> q;
void func(int n)
{
    if (!q.empty())
    {
        mymutex.lock();
        cout << q.front() << " " << n << endl;
        q.pop();
        mymutex.unlock();
    }
}
int main()
{
    for (int i = 0; i < 10; i++)
    {
        q.emplace(i);
    }
    for (int i = 0; i < 5; i++)
    {
        thread t(func, i);
        t.join();
    }
    return 0;
}
