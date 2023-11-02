#include <chrono>
#include <iostream>
#include <latch>
#include <stop_token>
#include <thread>

using namespace std::literals::chrono_literals;

// jthread will automatically join when destructed.

void doParallelWork(std::stop_token token) {
  std::cout << "starting parallel work" << std::endl;
  while (!token.stop_requested()) {
    // spin
  }
  std::cout << "finished parallel work" << std::endl;
}

int main() {
  std::jthread jt{&doParallelWork};
  std::stop_source stopSource = jt.get_stop_source();
  std::this_thread::sleep_for(10ms);
  std::cout << stopSource.stop_possible() << " " << stopSource.stop_requested()
            << std::endl;
  // the destructor of jthread will call stop_token and join

  std::atomic<float> f{9.0};

  // std::atomic wait

  std::atomic<int> value{0};
  std::jthread job{[&value]() {
    std::cout << "thread starts waiting." << std::endl;
    value.wait(0);
    std::cout << "done waiting: " << std::endl;
  }};

  value = 1;
  value.notify_all();

  // A latch will block execution until its countdown reaches zero.
  std::latch startLatch{1};  // wait for a single countdown

  std::jthread jt2{[&startLatch] {
    std::cout << "starting latch thread:" << std::endl;
    startLatch.count_down();
  }};

  // make this thread wait until it knows that the other thread has started
  startLatch.arrive_and_wait();

  // semaphore limits the number of times it can be aquired before being
  // released
  std::counting_semaphore semaphore{4};  // allow 4 threads
  std::vector<std::jthread> threads;
  for (int i{0}; i < 10; ++i) {
    threads.emplace_back([&semaphore] {
      semaphore.acquire();
      std::cout << "lock aquired: " << std::endl;
      std::this_thread::sleep_for(100ms);
      semaphore.release();
      std::cout << "lock released" << std::endl;
    });
  }

  return 0;
}
