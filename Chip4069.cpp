/*
** EPITECH PROJECT, 2020
** Chip4069
** File description:
** Chip4069
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

Chip4069::Chip4069()
{
    entry = entrytypes;
    value = values;
}

Chip4069::~Chip4069()
{
}

Tristate Chip4069::compute(std::size_t pin)
{
    if (pin < 1 || pin == 7 || pin > 13) {
        std::cerr << "invalid pin for compute" << std::endl;
        return UNDEFINED;
    }
    switch (pin) {
        case 3:
            value.at(3) = Compute::computeAnd(address.find(1) != address.end() ? address.at(1).first.compute(address.at(1).second) : value.at(1),
            address.find(2) != address.end() ? address.at(2).first.compute(address.at(2).second) : value.at(2));
            return (value.at(3));
        case 4:
            value.at(4) = Compute::computeAnd(address.find(5) != address.end() ? address.at(5).first.compute(address.at(5).second) : value.at(5),
            address.find(6) != address.end() ? address.at(6).first.compute(address.at(6).second) : value.at(6));
            return value.at(4);
        case 10:
            value.at(10) = Compute::computeAnd(address.find(8) != address.end() ? address.at(8).first.compute(address.at(8).second) : value.at(8),
            address.find(9) != address.end() ? address.at(9).first.compute(address.at(9).second) : value.at(9));
            return value.at(10);
        case 11:
            value.at(11) = Compute::computeAnd(address.find(12) != address.end() ? address.at(12).first.compute(address.at(12).second) : value.at(13),
            address.find(13) != address.end() ? address.at(13).first.compute(address.at(13).second) : value.at(13));
            return value.at(11);
        default:
            std::cerr << "invalid pin for compute" << std::endl;
            return UNDEFINED;
    }
}

bool Chip4069::checkLinkable(std::size_t pin)
{
    if (entry.find(pin) == entry.end() || entry.at(pin) != "output")
        return false;
    return true;
}

void Chip4069::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
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

void Chip4069::dump() const
{
}

void Chip4069::setValue(Tristate const &val, size_t pin) {
    value.at(pin) = val;
}
