#ifndef CHAOS_BLOCKING_QUEUE_H
#define CHAOS_BLOCKING_QUEUE_H

#include <assert.h>

#include "nocopyable.h"

/**
 * 阻塞队列：在队列的基础上增加如下要求
 * 1. 队列满时，队列会阻塞插入元素的线程，直到队列不满。
 * 2. 队列空时，获取元素的线程会等待队列变为非空。
 */
namespace chaos
{
    
} // namespace chaos


#endif