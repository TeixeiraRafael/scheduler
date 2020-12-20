#ifndef SCHEDULER_CONCURRENT_QUEUE_H
#define SCHEDULER_CONCURRENT_QUEUE_H
#include "definitions.h"

template <typename Data>
class ConcurrentQueue {

private:
    queue<Data> q;
    mutable boost::mutex mutex;
    boost::condition_variable condition;

public:
    void push(Data const& data);
    bool empty() const;
    bool try_pop(Data& popped_value);
    void wait_and_pop(Data& popped_value);
};


#endif //SCHEDULER_CONCURRENT_QUEUE_H
