/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** Chip4008
*/

#include "Chip.hpp"

using namespace nts;
static const std::map<size_t, std::string> entrytypes =
{
    {1, "input"},
    {2, "input"},
    {3, "input"},
    {4, "input"},
    {5, "input"},
    {6, "input"},
    {7, "input"},
    {9, "input"},
    {10, "output"},
    {11, "output"},
    {12, "output"},
    {13, "output"},
    {14, "output"},
    {15, "input"}
};
static const std::map<size_t, Tristate> values =
{
    {1, UNDEFINED},
    {2, UNDEFINED},
    {3, UNDEFINED},
    {4, UNDEFINED},
    {5, UNDEFINED},
    {6, UNDEFINED},
    {7, UNDEFINED},
    {9, UNDEFINED},
    {10, UNDEFINED},
    {11, UNDEFINED},
    {12, UNDEFINED},
    {13, UNDEFINED},
    {14, UNDEFINED},
    {15, UNDEFINED}
};

Chip4008::Chip4008()
{
    entry = entrytypes;
    value = values;
}

Chip4008::~Chip4008()
{
}

Tristate Chip4008::compute(std::size_t pin)
{
    for (auto it = value.begin(); it != value.end(); ++it) {
        if (it->first != 8 && address.find(it->first) != address.end())
            value.at(it->first) = address.at(it->first).first.compute(address.at(1).second);
    }
    if (pin < 1 || pin == 8 || pin > 15 || entry.at(pin) != "output") {
        std::cerr << "invalid pin for compute" << std::endl;
        return UNDEFINED;
    }
    value.at(10) = Compute::computeSum(value.at(6), value.at(7), value.at(9));
    value.at(14) = Compute::computeSumCarry(value.at(6), value.at(7), value.at(9));
    value.at(11) = Compute::computeSum(value.at(4), value.at(5), value.at(14));
    value.at(14) = Compute::computeSumCarry(value.at(4), value.at(5), value.at(14));
    value.at(12) = Compute::computeSum(value.at(2), value.at(3), value.at(14));
    value.at(14) = Compute::computeSumCarry(value.at(2), value.at(3), value.at(14));
    value.at(13) = Compute::computeSum(value.at(1), value.at(15), value.at(14));
    value.at(14) = Compute::computeSumCarry(value.at(1), value.at(15), value.at(14));
    return value.at(pin);
}

bool Chip4008::checkLinkable(std::size_t pin)
{
    if (entry.find(pin) == entry.end() || entry.at(pin) != "output")
        return false;
    return true;
}

void Chip4008::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
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

void Chip4008::dump() const
{
}

void Chip4008::setValue(Tristate const &val, size_t pin) {
    value.at(pin) = val;
}