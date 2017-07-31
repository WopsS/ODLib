#pragma once

#ifdef ODLIB_SINGLETON_USE_CAMELCASE
#define ODLIB_PRIVATE_SINGLETON_FUNCTIONS_HEADER(Class) \
template<typename... Args> \
static Class* Construct(Args&& ...args) \
{ \
    return construct(std::forward<Args>(args)...); \
} \
static Class* GetInstance(); \
static const bool IsReleased(); \
static void Release();

#define ODLIB_PRIVATE_SINGLETON_FUNCTIONS_SOURCE(Class) \
Class* Class::GetInstance() \
{ \
    return get_instance(); \
} \
const bool Class::IsReleased() \
{ \
    return is_released(); \
} \
void Class::Release() \
{ \
    release(); \
}
#else
#define ODLIB_PRIVATE_SINGLETON_FUNCTIONS_HEADER(Class)
#define ODLIB_PRIVATE_SINGLETON_FUNCTIONS_SOURCE(Class)
#endif

/// <summary>
/// Implement a singleton  class without inheritance. Should be used in header file.
/// </summary>
#define ODLIB_SINGLETON_IMPLEMENT_HEADER(Class) \
public: \
    template<typename... Args> \
    static Class* construct(Args&& ...args) \
    { \
        std::call_once(m_construct_flag, [&]() \
        { \
            m_instance.reset(new Class(std::forward<Args>(args)...)); \
        }); \
        return m_instance.get(); \
    } \
    static Class* get_instance(); \
    static const bool is_released(); \
    static void release(); \
    ODLIB_PRIVATE_SINGLETON_FUNCTIONS_HEADER(Class) \
private: \
    friend std::unique_ptr<Class>::deleter_type; \
    Class(const Class&) = delete; \
    Class(Class&&) = delete; \
    Class& operator=(const Class&) = delete; \
    Class& operator=(Class&&) = delete; \
    static std::unique_ptr<Class> m_instance; \
    static std::once_flag m_construct_flag; \
    static std::once_flag m_release_flag;

/// <summary>
/// Implement a singleton  class without inheritance. Should be used in source file.
/// </summary>
#define ODLIB_SINGLETON_IMPLEMENT_SOURCE(Class) \
std::unique_ptr<Class> Class::m_instance; \
std::once_flag Class::m_construct_flag; \
std::once_flag Class::m_release_flag; \
Class* Class::get_instance() \
{ \
    if (is_released() == true) \
    { \
        return construct(); \
    } \
    return m_instance.get(); \
} \
const bool Class::is_released() \
{ \
    return m_instance == nullptr; \
} \
void Class::release() \
{ \
    if (is_released() == false) \
    { \
        std::call_once(m_release_flag, [&]() \
        { \
            m_instance.reset(nullptr); \
        }); \
    } \
} \
ODLIB_PRIVATE_SINGLETON_FUNCTIONS_SOURCE(Class)