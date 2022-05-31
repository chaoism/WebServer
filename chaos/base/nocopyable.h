#ifndef CHAOS_BASE_NOCOPYABLE_H
#define CHAOS_BASE_NOCOPYABLE_H

namespace chaos
{
/**
 * 不可拷贝的类
 * 删除 拷贝构造函数 和 拷贝赋值运算符 声明为 delete
 * 默认构造和析构函数设为protected
 */
class noncopyable
{
public:
    noncopyable(const noncopyable&) = delete;
    void operator=(const noncopyable&) = delete;

protected:
    noncopyable() = default;
    ~noncopyable() = default;
};

} // namespace chaos

#endif