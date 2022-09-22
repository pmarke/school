#include <iostream>
#include <thread>
#include <vector>
#include <mutex>

// A global variable that is unique for every thread.
thread_local int num;

int globalNum{0};
std::mutex globalMutex1;
std::mutex globalMutex2;

void incrementNumNoMutex(size_t numIters) {

    for (size_t ii = 0; ii < numIters; ++ii) {
        globalNum++;
    }

}

void incrementNumWithMutex1(size_t numIters) {

    for (size_t ii = 0; ii < numIters; ++ii) {
        std::unique_lock lock(globalMutex1);
        globalNum++;
    }

}

void incrementNumWithMutex2(size_t numIters) {

    for (size_t ii = 0; ii < numIters; ++ii) {
        std::unique_lock lock(globalMutex2);
        globalNum++;
    }

}

class Counter
{
    public:
        Counter(int id, int numIterations)
            : mId(id), mNumIterations(numIterations)
        {
        }
        void operator()() const
        {
            for (int i = 0; i < mNumIterations; ++i) {
            // The mutex prevents mutliple threads from writing to the output stream buffer.
            // Uncomment this and run the code to see what happens when a mutex is not used.
            std::lock_guard lock(sMutex);
            std::cout << "Counter " << mId << " has value " << i << std::endl;
            }
        }
    private:
        int mId;
        int mNumIterations;
        static std::mutex sMutex;
};

std::mutex Counter::sMutex;

std::once_flag gOnceFlag;

void initializeSharedResources()
{
    // ... Initialize shared resources to be used by multiple threads.
    std::cout << "Shared resources initialized." << std::endl;
}
void processingFunction()
{
    // Make sure the shared resources are initialized.
    std::call_once(gOnceFlag, initializeSharedResources);

    // ... Do some work, including using the shared resources
    std::cout << "Processing" << std::endl;
}

int main(int, char**) {


     // Using uniform initialization syntax
     std::thread t1{ Counter{ 1, 20 }};

     // Using named variable
     Counter c(2, 12);
     std::thread t2(c);

     // Using temporary
     std::thread t3(Counter(3, 10));

     // Wait for threads to finish
     t1.join();
     t2.join();
     t3.join();


    ///////////////////////////////////////////
    // Using Call Once
    ///////////////////////////////////////////

    // Launch 3 threads.
    std::vector<std::thread> threads(3);
    for (auto& t : threads) {
        t = std::thread{ processingFunction };
    }
    // Join on all threads
    for (auto& t : threads) {
        t.join();
    }


    /////////////////////////////////////////////
    // Testing how mutexes work
    /////////////////////////////////////////////
    // 1) Increment using the same mutex.
    size_t numIters = 500;
    t1 = std::thread{incrementNumWithMutex1, numIters};
    t2 = std::thread{incrementNumWithMutex1, numIters};
    t1.join();
    t2.join();

    std::cout << "Value should be 1000. global number: " << globalNum <<  std::endl;

    // 2) Increment using different mutex

    t1 = std::thread{incrementNumWithMutex1, numIters};
    t2 = std::thread{incrementNumWithMutex2, numIters};
    t1.join();
    t2.join();

    std::cout << "Is value 2000? global number: " << globalNum << std::endl;

    return 0;

}
