#include "concurrent_queue.h"

template <typename Data>
void ConcurrentQueue<Data>::push(const Data& data) {
    boost::mutex::scoped_lock lock(mutex);
    q.push(data);
    lock.unlock();
    condition.notify_one();
}

template<typename Data>
bool ConcurrentQueue<Data>::empty() const {
    boost::mutex::scoped_lock lock(mutex);
    return q.empty();
}

template<typename Data>
bool ConcurrentQueue<Data>::try_pop(Data& popped_value) {
    boost::mutex::scoped_lock lock(mutex);
    if(q.empty()){
        return false;
    }

    popped_value = q.front();
    q.pop();
    return true;
}

template<typename Data>
void ConcurrentQueue<Data>::wait_and_pop(Data &popped_value) {
    boost::mutex::scoped_lock lock(mutex);
    while(q.empty()){
        condition.wait(lock);
    }

    popped_value = q.front();
    q.pop();
}
