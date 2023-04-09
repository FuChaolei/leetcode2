#include <bits/stdc++.h>
#include <mutex>
#include <iostream>
#include <pthread.h>
#include <thread>
#include <queue>
using namespace std;
pthread_mutex_t mymutex;
pthread_cond_t mywait = PTHREAD_COND_INITIALIZER;
queue<int> q;
void *func(void *arg)
{
    // int n = *((int *)arg);
    int n = *((int *)arg);
    printf("Sleeping in thread %d ,...exiting \n", n);
    if (!q.empty())
    {
        pthread_mutex_lock(&mymutex);
        // pthread_cond_wait(&mywait, &mymutex);
        printf("我抢到了 %d ,... \n", n);
        //  cout << q.front() << " " << n << endl;
        q.pop();
        pthread_mutex_unlock(&mymutex);
    }
    return 0;
}
int main()
{
    for (int i = 0; i < 5; i++)
    {
        q.emplace(i);
    }
    pthread_mutex_init(&mymutex, 0);
    pthread_t pids[5];
    int indexes[5];
    for (int i = 0; i < 5; i++)
    {
        // pthread_mutex_lock(&mymutex);
        indexes[i] = i;
        // pthread_mutex_unlock(&mymutex);
        //  int tmp = i;
        //  printf("main() : 创建线程 %d \n", i);
        pthread_create(&pids[i], 0, func, (void *)&(indexes[i]));
        // pthread_create(&pids[i], 0, func, (void *)&i);
        //  printf("main() : 线程 %d \n", i);
    }
    // for (int i = 0; i < 5; i++)
    // {
    //     cout << "唤醒" << i << endl;
    //     pthread_cond_signal(&mywait);
    // }
    int res = 0;
    void *func_res;
    for (int i = 0; i < 5; i++)
    {
        res = pthread_join(pids[i], &func_res);
        if (res != 0)
        {
            cout << i << " 失败" << endl;
        }
    }
    pthread_mutex_destroy(&mymutex);
    while (!q.empty())
    {
        cout << q.front() << endl;
        q.pop();
    }
    return 0;
}
