#ifndef CHAOS_CONDITION_H
#define CHAOS_CONDITION_H

#include <pthread.h>

namespace chaos
{
    class Condition
    {
    private:
        pthread_cond_t pcond_;
        
    public:
        Condition(/* args */);
        
        ~Condition();

        bool wait();

        bool timewait(double seconds);

        // signal
        void notify();

        // broadcast
        void notifyAll();

    };
    
    Condition::Condition(/* args */)
    {
    }
    
    Condition::~Condition()
    {
    }

} // namespace chaos


#endif