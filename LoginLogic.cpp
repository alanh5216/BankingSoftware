#include <string>
#include "LoginLogic.h"
bool Login(const std::string* Password_ptr) {
    if(*Password_ptr == "Password") return true;

    return false;
}