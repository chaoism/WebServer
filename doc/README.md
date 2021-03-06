# 同步/异步日志系统

- 同步日志，当输出日志时，必须等待日志输出语句执行完毕后，才能执行后面的业务逻辑语句。

- 异步日志，日志输出语句与业务逻辑语句并不是在同一个线程中运行，而是有专门的线程用于进行日志输出操作，处理业务逻辑的主线程不用等待即可执行后续业务逻辑。

## 日志级别

- `TRACE`
- `DEBUG`
- `INFO`
- `WARN`
- `ERROR`
- `FATAL`

## `BlockingQueue` / `BoundedBlockingQueue`

- `BlockingQueue` 阻塞队列

- `BoundedBlockingQueue` 有界阻塞队列

## `Producer` `Consumer`

基于阻塞队列的生产者消费者模式的同步日志系统。

多线程开发中，如果生产者生产数据的速度很快，而消费者消费数据的速度很慢，那么生产者就必须等待消费者消费完了数据才能够继续生产数据，因为生产那么多也没有地方放啊；同理如果消费者的速度大于生产者那么消费者就会经常处理等待状态，所以为了达到生产者和消费者生产数据和消费数据之间的平衡，那么就需要一个缓冲区用来存储生产者生产的数据

- 保证生产者不会在缓冲区满的时候继续向缓冲区放入数据，而消费者也不会在缓冲区空的时候，消耗数据
- 缓冲区满的时候，生产者会进入休眠状态，当下次消费者开始消耗缓冲区的数据时，生产者才会被唤醒，开始往缓冲区中添加数据；当缓冲区空的时候，消费者也会进入休眠状态，直到生产者往缓冲区中添加数据时才会被唤醒

- `Object` 的 `wait()` / `notify()`方法
- `Semaphore` 的 `acquire()` / `release()`方法
- `BlockingQueue` 阻塞队列方法
- `Lock` 和 `Condition` 的 `await()` / `signal()`方法
- `PipedInputStream` / `PipedOutputStream`
