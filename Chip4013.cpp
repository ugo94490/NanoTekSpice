/*
** EPITECH PROJECT, 2020
** Chip4013
** File description:
** Chip4013
*/

#include "Chip.hpp"

using namespace nts;
static const std::map<size_t, std::string> entrytypes =
{
    {1, "output"},
    {2, "output"},
    {3, "input"},
    {4, "input"},
    {5, "input"},
    {6, "input"},
    {8, "input"},
    {9, "input"},
    {10, "input"},
    {11, "input"},
    {12, "output"},
    {13, "output"}
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

Chip4013::Chip4013()
{
    entry = entrytypes;
    value = values;
}

Chip4013::~Chip4013()
{
}

Tristate Chip4013::compute(std::size_t pin)
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
        case 1:
            value.at(1) = Compute::computeNand(Compute::computeNot(value.at(6)), Compute::computeNand(value.at(5), value.at(3)));
            return (value.at(1));
        case 2:
            value.at(2) = Compute::computeNand(Compute::computeNand(Compute::computeNand(value.at(5), value.at(5)), value.at(3)), value.at(4));
            return (value.at(2));
        case 12:
            value.at(12) = Compute::computeNand(Compute::computeNand(Compute::computeNand(value.at(9), value.at(9)), value.at(11)), value.at(10));
            return (value.at(12));
        case 13:
            value.at(13) = Compute::computeNand(Compute::computeNot(value.at(8)), Compute::computeNand(value.at(9), value.at(11)));
            return (value.at(13));
        default:
            std::cerr << "invalid pin for compute" << std::endl;
            return UNDEFINED;
    }
}

bool Chip4013::checkLinkable(std::size_t pin)
{
    if (entry.find(pin) == entry.end() || entry.at(pin) != "output")
        return false;
    return true;
}

void Chip4013::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
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

void Chip4013::dump() const
{
}

void Chip4013::setValue(Tristate const &val, size_t pin) {
    value.at(pin) = val;
}
