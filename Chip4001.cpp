/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** Chip4001
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

Chip4001::Chip4001()
{
    entry = entrytypes;
    value = values;
}

Chip4001::~Chip4001()
{
}

Tristate Chip4001::compute(std::size_t pin)
{
    if (pin < 1 || pin == 7 || pin > 13)
        return UNDEFINED;
    switch (pin) {
        case 3:
            value[3] = Compute::computeNor(address.find(1) != address.end() ? address.at(1).first.compute(address.at(1).second) : value[1],
            address.find(2) != address.end() ? address.at(2).first.compute(address.at(2).second) : value[2]);
            return (value[3]);
        case 4:
            value[4] = Compute::computeNor(address.find(5) != address.end() ? address.at(5).first.compute(address.at(5).second) : value[5],
            address.find(6) != address.end() ? address.at(6).first.compute(address.at(6).second) : value[6]);
            return value[4];
        case 10:
            value[10] = Compute::computeNor(address.find(8) != address.end() ? address.at(8).first.compute(address.at(8).second) : value[8],
            address.find(9) != address.end() ? address.at(9).first.compute(address.at(9).second) : value[9]);
            return value[10];
        case 11:
            value[11] = Compute::computeNor(address.find(12) != address.end() ? address.at(12).first.compute(address.at(12).second) : value[13],
            address.find(13) != address.end() ? address.at(13).first.compute(address.at(13).second) : value[13]);
            return value[11];
        default:
            return UNDEFINED;
    }
}

bool Chip4001::checkLinkable(std::size_t pin)
{
    if (entry.find(pin) == entry.end() || entry[pin] != "output")
        return false;
    return true;
}

void Chip4001::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    if (entry.find(pin) == entry.end() || entry[pin] != "input" || !other.checkLinkable(otherPin))
        exit(84);
    address.at(pin).first = other;
    address.at(pin).second = otherPin;
}

void Chip4001::dump() const
{
}