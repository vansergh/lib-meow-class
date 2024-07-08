#define TEST_DEBUG

#pragma once
#include <iostream>


class MeowClass {
public:
    MeowClass() :
        name_{"default"}
    {
        #ifdef TEST_DEBUG
        std::cout << "Default Constructor. Address: " << (void*)this << ", Name: \"" << name_ << "\"\n";
        #endif
    }
    MeowClass(std::string name) :
        name_{name}
    {
        #ifdef TEST_DEBUG
        std::cout << "Parametrized Constructor. Address: " << (void*)this << ", Name: \"" << name_ << "\"\n";
        #endif
    }
    ~MeowClass() {
        #ifdef TEST_DEBUG
        std::cout << "Destructor. Address: " << (void*)this << ", Name: \"" << name_ << "\"\n";
        #endif
    }
    MeowClass(const MeowClass& other) :
        name_{other.name_}
    {
        #ifdef TEST_DEBUG
        std::cout << "Copy Constructor. Address: " << (void*)this << ", Other Address: " << (void*)&other << ", Name: \"" << name_ << "\"\n";
        #endif
    }
    MeowClass(MeowClass&& other) :
        name_{other.name_}
    {
        #ifdef TEST_DEBUG
        std::cout << "Move Constructor. Address: " << (void*)this << ", Other Address: " << (void*)&other << ", Name: \"" << name_ << "\"\n";
        #endif
    }
    MeowClass& operator=(const MeowClass& other) {
        #ifdef TEST_DEBUG
        std::cout << "Copy Assignment. Address: " << (void*)this << ", Name: \"" << name_ << "\", Other Address: " << (void*)&other << ", Other Name: \"" << other.name_ << "\"\n";
        #endif
        name_ = other.name_;
        return *this;
    }
    MeowClass& operator=(MeowClass&& other) {
        #ifdef TEST_DEBUG
        std::cout << "Move Assignment. Address: " << (void*)this << ", Name: \"" << name_ << "\", Other Address: " << (void*)&other << ", Other Name: \"" << other.name_ << "\"\n";
        #endif
        name_ = other.name_;
        return *this;
    }
    void Rename(const std::string& new_name) {
        #ifdef TEST_DEBUG
        std::cout << "Renaming. Address: " << (void*)this << ", Name: \"" << name_ << "\", New Name: \"" << new_name << "\"\n";
        #endif
        name_ = new_name;
    }
    const std::string& GetName() const {
        const std::string& result = name_;
        return result;
    }
private:
    std::string name_;
};
std::ostream& operator<<(std::ostream& os, const MeowClass& right) {
    os << right.GetName();
    return os;
}