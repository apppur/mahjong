#include <iostream>
#include <ctime>
#include <ratio>
#include <chrono>

class TimeUtil
{
    public:
        TimeUtil()
        {
            start = std::chrono::steady_clock::now();
        }
        ~TimeUtil() {}

        double Span()
        {
            std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
            std::chrono::duration<double> time_span = std::chrono::duration_cast<std::chrono::duration<double>>(end-start);
            std::cout << "Calc win cost :" << time_span.count() << " seconds" << std::endl;
            return time_span.count();
        }

        void Reset()
        {
            start = std::chrono::steady_clock::now();
        }

    private:
        std::chrono::steady_clock::time_point start;
};
