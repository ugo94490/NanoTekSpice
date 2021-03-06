/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** Chip4030
*/

#include "Chip.hpp"

using namespace nts;
static const std::map<size_t, std::string> entrytypes =
{
    {1, "input"},
    {2, "input"},
    {3, "output"},
    {4, "output"},
    {5, "input"},
    {6, "input"},
    {8, "input"},
    {9, "input"},
    {10, "output"},
    {11, "output"},
    {12, "input"},
    {13, "input"}
};
static const std::map<size_t, Tristate> values =
{
    {1, UNDEFINED},
    {2, UNDEFINED},
    {3, UNDEFINED},
    {4, UNDEFINED},
    {5, UNDEFINED},
    {6, UNDEFINED},
    {8, UNDEFINED},
    {9, UNDEFINED},
    {10, UNDEFINED},
    {11, UNDEFINED},
    {12, UNDEFINED},
    {13, UNDEFINED}
};

Chip4030::Chip4030()
{
    entry = entrytypes;
    value = values;
}

Chip4030::~Chip4030()
{
}

Tristate Chip4030::compute(std::size_t pin)
{
    for (auto it = value.begin(); it != value.end(); ++it) {
        if (address.find(it->first) != address.end())
            value.at(it->first) = address.at(it->first).first.compute(address.at(it->first).second);
    }
    if (entry.find(pin) == entry.end() || entry.at(pin) != "output") {
        std::cerr << "invalid pin for compute" << std::endl;
        exit(84);
    }
    switch (pin) {
        case 3:
            value.at(3) = Compute::computeXor(value.at(1), value.at(2));
            return (value.at(3));
        case 4:
            value.at(4) = Compute::computeXor(value.at(5), value.at(6));
            return value.at(4);
        case 10:
            value.at(10) = Compute::computeXor(value.at(8), value.at(9));
            return value.at(10);
        case 11:
            value.at(11) = Compute::computeXor(value.at(12), value.at(13));
            return value.at(11);
        default:
            std::cerr << "invalid pin for compute" << std::endl;
            return UNDEFINED;
    }
}

bool Chip4030::checkLinkable(std::size_t pin)
{
    if (entry.find(pin) == entry.end() || entry.at(pin) != "output")
        return false;
    return true;
}

void Chip4030::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    if (entry.find(pin) == entry.end() || entry.at(pin) != "input" || !other.checkLinkable(otherPin)) {
        std::cerr << pin << ", " << otherPin << std::endl;
        std::cerr << "Tried to link component output as input" << std::endl;
        exit(84);
    }
    if (address.find(pin) != address.end()) {
        address.at(pin).first = other;
        address.at(pin).second = otherPin;
    }
    else
        address.insert({pin, {other, otherPin}});
}

void Chip4030::dump() const
{
    std::cout << "4030" << std::endl;
}

void Chip4030::setValue(Tristate const &val, size_t pin) {
    value.at(pin) = val;
}