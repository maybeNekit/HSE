#include <iostream>
#include <vector>
#include <string>
enum class Permission{
    READ = 1 << 0,
    WRITE = 1 << 1,
    EXECUTE = 1 << 2,
    DELETE = 1 << 3
};

Permission operator|(Permission a, Permission b) {
    return static_cast<Permission>(static_cast<int>(a) | static_cast<int>(b));
}

Permission operator&(Permission a, Permission b) {
    return static_cast<Permission>(static_cast<int>(a) & static_cast<int>(b));
}

Permission operator~(Permission a) {
    return static_cast<Permission>(~static_cast<int>(a));
}

struct User {
    std::string name;
    Permission permission;
};

bool check(Permission userPerm, Permission checkPerm) {
    return (userPerm & checkPerm) == checkPerm;
}

int main() {
    std::vector<User> users = {
        {"Nikita", Permission::READ | Permission::WRITE | Permission::EXECUTE | Permission::DELETE},
        {"Misha", Permission::READ|Permission::WRITE },
        {"Ronaldo", Permission::READ },
        {"CR7", Permission::READ | Permission::WRITE | Permission::EXECUTE}
    };
    for (const auto& user : users) {
        
    }
    return 0;
}