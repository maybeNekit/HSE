#include <iostream>
#include <vector>
#include <string>

enum class StatusEffect {
    POISONED = 1 << 0,
    STUNNED = 1 << 1,
    INVISIBLE = 1 << 2,
    INVINCIBLE = 1 << 3,
    BURNING = 1 << 4,
    FROZEN = 1 << 5,
    BLESSED = 1 << 6,
    CURSED = 1 << 7
};

StatusEffect operator|(StatusEffect a, StatusEffect b) {
    return (static_cast<StatusEffect> (static_cast<int>(a) | static_cast<int>(b)));
}

StatusEffect operator&(StatusEffect a, StatusEffect b) {
    return (static_cast<StatusEffect> (static_cast<int>(a) & static_cast<int>(b)));
}

StatusEffect operator^(StatusEffect a, StatusEffect b) {
    return (static_cast<StatusEffect> (static_cast<int>(a) ^ static_cast<int>(b)));
}

StatusEffect operator~(StatusEffect a) {
    return static_cast<StatusEffect>(~static_cast<int>(a));
}

bool checkStatus (StatusEffect a, StatusEffect b) {
    return (a & b) == b;
}

bool compStatus(StatusEffect charStatus1, StatusEffect charStatus2) {
    if ((charStatus1 == StatusEffect::BURNING && charStatus2 == StatusEffect::FROZEN) ||
        (charStatus2 == StatusEffect::BURNING && charStatus1 == StatusEffect::FROZEN) ) {
           return 0;
    }
    if ((charStatus1 == StatusEffect::BLESSED && charStatus2 == StatusEffect::CURSED) ||
        (charStatus2 == StatusEffect::BLESSED && charStatus1 == StatusEffect::CURSED) ) {
        return 0;
        }
    return 1;
}



struct Charecter {
    std::string name;
    StatusEffect status;
};

void addStatus(Charecter &name, StatusEffect newStat) {
    if (compStatus(newStat, name.status)) {
        return ;
    }
    if (checkStatus(name.status, newStat)) {
        return ;
    }
    name.status = name.status|newStat;

}

void delStatus(Charecter &name, StatusEffect delStat) {
    name.status = name.status& ~delStat;
}

void printStatus(Charecter name) {
    std::string result = "";
    if (checkStatus(name.status, StatusEffect::POISONED)){ result+= "POISONED "; }
    if (checkStatus(name.status, StatusEffect::STUNNED)){ result+= "STUNNED "; }
    if (checkStatus(name.status, StatusEffect::INVISIBLE)){ result+= "INVISIBLE "; }
    if (checkStatus(name.status, StatusEffect::INVINCIBLE)){ result+= "INVINCIBLE "; }
    if (checkStatus(name.status, StatusEffect::BURNING)){ result+= "BURNING "; }
    if (checkStatus(name.status, StatusEffect::FROZEN)){ result+= "FROZEN "; }
    if (checkStatus(name.status, StatusEffect::BLESSED)){ result+= "BLESSED "; }
    if (checkStatus(name.status, StatusEffect::CURSED)){ result+= "CURSED \n"; }
    std::cout << result;
}

int main() {
    std::vector<Charecter> charecters = {
        {"Kostian", StatusEffect::POISONED | StatusEffect::STUNNED | StatusEffect::INVISIBLE |
             StatusEffect::BURNING  | StatusEffect::BLESSED | StatusEffect::CURSED}
    };
    delStatus(charecters[0], StatusEffect::BLESSED);
    for (const auto& charecter : charecters ) {
        std::cout << charecter.name << ": ";

        printStatus(charecter);

    }
}
