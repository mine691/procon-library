#include <iostream>
#include <chrono>
using namespace std;

struct Timer
{
    chrono::high_resolution_clock::time_point start;

    Timer() { reset(); }

    void reset()
    {
        start = chrono::high_resolution_clock::now();
    }

    chrono::milliseconds::rep elapsed_time()
    {
        auto end = chrono::high_resolution_clock::now();
        return chrono::duration_cast<chrono::milliseconds>(end - start).count();
    }
};

int main()
{
    Timer timer;
    cout << timer.elapsed_time() << "\n";
}
