#include <string>
#include <iostream>
#include <set>
#include <vector>
#include <map>
#include <algorithm>

using Ingredients = std::map<std::string, int>;

struct Dish {
    std::string name;
    std::set<std::string> ingredients;
};

using Dishes = std::vector<Dish>;
using DishesIngredients = std::pair<Dishes&, Ingredients&>;

Ingredients readIngredients(std::istream& istr)
{
    Ingredients res;
    size_t count;
    if (istr >> count) {
        for (size_t i = 0; i < count; ++i) {
            std::string name;
            int calories;
            istr >> name >> calories;
            res[name] = calories;
        }
    }
    return res;
}

Dishes readDishes(std::istream& istr)
{
    Dishes res;
    size_t num;
    istr >> num;
    for (size_t i = 0; i < num; ++i)
    {
        Dish dish;
        istr >> dish.name;
        size_t ingNum;
        istr >> ingNum;
        for (size_t j = 0; j < ingNum; ++j)
        {
            std::string ingr;
            istr >> ingr;
            dish.ingredients.insert(ingr);
        }
        res.push_back(dish);
    }
    return res;
}

std::ostream& operator<<(std::ostream& ostr, const Dish& dish)
{
    ostr << dish.name << ":";
    bool first = true;
    for (const auto& ingr : dish.ingredients) {
        if (!first) {
            ostr << ",";
        }
        ostr << " " << ingr;
        first = false;
    }
    return ostr;
}

int calcCalories(const Dish& dish, const Ingredients& ingrs)
{
    int total = 0;
    for (const auto& ingrName : dish.ingredients) {
        auto it = ingrs.find(ingrName);
        if (it != ingrs.end()) {
            total += it->second;
        }
    }
    return total;
}

std::ostream& operator<<(std::ostream& ostr, const Dishes& dishes)
{
    for (const Dish& dish : dishes)
    {
        ostr << dish << "\n";
    }
    return ostr;
}

std::ostream& operator<<(std::ostream& ostr, const DishesIngredients& di)
{
    for (const auto& dish : di.first) {
        ostr << dish << "; " << calcCalories(dish, di.second) << "\n";
    }
    return ostr;
}

struct Comparator
{
    const Ingredients& ingrs;
    bool operator()(const Dish& lhs, const Dish& rhs) const
    {
        return calcCalories(lhs, ingrs) > calcCalories(rhs, ingrs);
    }
};

void sortDishesByCalories(DishesIngredients& di)
{
    std::sort(di.first.begin(), di.first.end(), Comparator{di.second});
}