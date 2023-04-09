#include <bits/stdc++.h>
using namespace std;
class Lazy
{
public:
    static Lazy *getInstance()
    {
        if (lazy == nullptr)
        {
            lazy = new Lazy;
        }
        return lazy;
    }

private:
    Lazy() {}
    static Lazy *lazy;
};
Lazy *Lazy::lazy = nullptr;
int main()
{
    Lazy *tmp = Lazy::getInstance();
    Lazy *tmp2 = Lazy::getInstance();
    if (tmp == tmp2)
    {
        cout << "fuck" << endl;
    }
    return 0;
}
