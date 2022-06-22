#ifndef CHAOS_CONDITION_H
#define CHAOS_CONDITION_H

#include <pthread.h>
#include <exception>

#include "nocopyable.h"

namespace chaos
{
    class Condition : noncopyable
    {
    private:
        pthread_cond_t pcond_;
        // pthread_mutex_t& mutex_;
        
    public:
        Condition();
        
        ~Condition();

        bool wait(pthread_mutex_t *mutex_);

        bool timewait(pthread_mutex_t *mutex_, struct timespec t);

        // signal
        bool notify();

        // broadcast
        bool notifyAll();

    };
    
    Condition::Condition()
    {
        if (pthread_cond_init(&pcond_, NULL) != 0)
        {
            throw std::exception();
        }
    }
    
    Condition::~Condition() { pthread_cond_destroy(&pcond_); }

    bool Condition::wait(pthread_mutex_t *mutex_)
    {
        int ret = 0;
        ret = pthread_cond_wait(&pcond_, mutex_);
        return ret == 0;
    }

    bool Condition::timewait(pthread_mutex_t *mutex_, struct timespec t)
    {
        int ret = 0;
        ret = pthread_cond_timedwait(&pcond_, mutex_, &t);
        return ret == 0;
    }

    bool Condition::notify() { return pthread_cond_signal(&pcond_) == 0; }

    bool Condition::notifyAll() { return pthread_cond_broadcast(&pcond_) == 0; }

} // namespace chaos


#endif