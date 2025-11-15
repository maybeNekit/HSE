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
    return static_cast<StatusEffect>(static_cast<int>(a) | static_cast<int>(b));
}

StatusEffect operator&(StatusEffect a, StatusEffect b) {
    return static_cast<StatusEffect>(static_cast<int>(a) & static_cast<int>(b));
}

StatusEffect operator^(StatusEffect a, StatusEffect b) {
    return static_cast<StatusEffect>(static_cast<int>(a) ^ static_cast<int>(b));
}

StatusEffect operator~(StatusEffect a) {
    return static_cast<StatusEffect>(~static_cast<int>(a));
}

struct Character {
    std::string name;
    StatusEffect effect;
};

bool check(StatusEffect a, StatusEffect b) {
    return (a & b) == b;
}

bool Compstatus(StatusEffect currentEffects, StatusEffect newEffect) {
    if ((check(currentEffects, StatusEffect::BURNING) && newEffect == StatusEffect::FROZEN) ||
        (check(currentEffects, StatusEffect::FROZEN) && newEffect == StatusEffect::BURNING) ||
        (check(currentEffects, StatusEffect::BLESSED) && newEffect == StatusEffect::CURSED) ||
        (check(currentEffects, StatusEffect::CURSED) && newEffect == StatusEffect::BLESSED)) {
        return false;
        }
    return true;
}


void addEffect(Character& character, StatusEffect newEffect) {
    if (!Compstatus(character.effect, newEffect)) {
        std::cout << character.name << "error"
                  << static_cast<int>(newEffect) << std::endl;
        return;
    }
    character.effect = character.effect | newEffect;
}

void removeEffect(Character& character, StatusEffect effectToRemove) {
    if (check(character.effect, effectToRemove)) {
        character.effect = character.effect & ~effectToRemove;
        std::cout << effectToRemove << " эффект у " << character.name << " удалён.\n";
    } else {
        std::cout << character.name << " не имеет эффекта " << static_cast<int>(effectToRemove) << " для удаления.\n";
    }
}

void print(const Character& character) {
    std::string result = " ";
    if (check(character.effect, StatusEffect::POISONED)) { result += "POISONED "; }
    if (check(character.effect, StatusEffect::STUNNED)) { result += "STUNNED "; }
    if (check(character.effect, StatusEffect::INVISIBLE)) { result += "INVISIBLE "; }
    if (check(character.effect, StatusEffect::INVINCIBLE)) { result += "INVINCIBLE "; }
    if (check(character.effect, StatusEffect::FROZEN)) { result += "FROZEN "; }
    if (check(character.effect, StatusEffect::BLESSED)) { result += "BLESSED "; }
    if (check(character.effect, StatusEffect::CURSED)) { result += "CURSED "; }
    if (check(character.effect, StatusEffect::BURNING)) { result += "BURNING "; }
    std::cout << result << '\n';
}

int main() {
    std::vector<Character> users = {
        {"Nikita", StatusEffect::FROZEN | StatusEffect::BLESSED | StatusEffect::CURSED | StatusEffect::INVINCIBLE | StatusEffect::INVISIBLE | StatusEffect::POISONED | StatusEffect::STUNNED},
        {"Misha", StatusEffect::FROZEN | StatusEffect::BLESSED | StatusEffect::BURNING},
    };

    addEffect(users[0], StatusEffect::BURNING);
    addEffect(users[1], StatusEffect::STUNNED);

    for (const auto& user : users) {
        std::cout << user.name << '\n';
        print(user);
    }

    return 0;
}