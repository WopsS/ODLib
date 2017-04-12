#pragma once

/// <summary>
/// Implement a singleton  class without inheritance. Should be used in header file.
/// </summary>
#define ODLIB_IMPLEMENT_SINGLETON_HEADER(Class) \
public: \
    template<typename... Args> \
    static Class* Construct(Args&& ...args) \
    { \
        std::call_once(m_constructFlag, [&]() \
        { \
            m_instance.reset(new Class(std::forward<Args>(args)...)); \
        }); \
        return m_instance.get(); \
    } \
    static Class* GetInstance(); \
    static const bool IsReleased(); \
    static void Release(); \
private: \
    friend std::unique_ptr<Class>::deleter_type; \
    Class(const Class&) = delete; \
    Class(Class&&) = delete; \
    Class& operator=(const Class&) = delete; \
    Class& operator=(Class&&) = delete; \
    static std::unique_ptr<Class> m_instance; \
    static std::once_flag m_constructFlag; \
    static std::once_flag m_releaseFlag;

/// <summary>
/// Implement a singleton  class without inheritance. Should be used in source file.
/// </summary>
#define ODLIB_IMPLEMENT_SINGLETON_SOURCE(Class) \
std::unique_ptr<Class> Class::m_instance; \
std::once_flag Class::m_constructFlag; \
std::once_flag Class::m_releaseFlag; \
Class* Class::GetInstance() \
{ \
    if (IsReleased() == true) \
    { \
        return Construct(); \
    } \
    return m_instance.get(); \
} \
const bool Class::IsReleased() \
{ \
    return m_instance == nullptr; \
} \
void Class::Release() \
{ \
    if (IsReleased() == false) \
    { \
        std::call_once(m_releaseFlag, [&]() \
        { \
            m_instance.reset(nullptr); \
        }); \
    } \
}
