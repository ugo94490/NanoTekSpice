/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** Chip4514
*/

#include <vector>
#include "Chip.hpp"

using namespace nts;
static const std::map<size_t, std::string> entrytypes =
{
    {1, "input"},
    {2, "input"},
    {3, "input"},
    {4, "output"},
    {5, "output"},
    {6, "output"},
    {7, "output"},
    {8, "output"},
    {9, "output"},
    {10, "output"},
    {11, "output"},
    {13, "output"},
    {14, "output"},
    {15, "output"},
    {16, "output"},
    {17, "output"},
    {18, "output"},
    {19, "output"},
    {20, "output"},
    {21, "input"},
    {22, "input"},
    {23, "input"}
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
    {8, UNDEFINED},
    {9, UNDEFINED},
    {10, UNDEFINED},
    {11, UNDEFINED},
    {13, UNDEFINED},
    {14, UNDEFINED},
    {15, UNDEFINED},
    {16, UNDEFINED},
    {17, UNDEFINED},
    {18, UNDEFINED},
    {19, UNDEFINED},
    {20, UNDEFINED},
    {21, UNDEFINED},
    {22, UNDEFINED},
    {23, UNDEFINED}
};

Chip4514::Chip4514()
{
    entry = entrytypes;
    value = values;
}

Chip4514::~Chip4514()
{
}

Tristate Chip4514::compute(std::size_t pin)
{
    std::vector<size_t> vectvals = {{11, 9, 10, 8, 7, 6, 5, 4, 18, 17, 20, 19, 14, 13, 16, 15}};
    size_t val = 0;
    for (auto it = value.begin(); it != value.end(); ++it) {
        if (address.find(it->first) != address.end())
            value.at(it->first) = address.at(it->first).first.compute(address.at(it->first).second);
    }
    if (entry.find(pin) == entry.end() || entry.at(pin) != "output") {
        std::cerr << "invalid pin for compute" << std::endl;
        exit(84);
    }
    if (value.at(1) == UNDEFINED || value.at(2) == UNDEFINED || value.at(3) == UNDEFINED ||
    value.at(21) == UNDEFINED || value.at(22) == UNDEFINED || value.at(23) == UNDEFINED)
        return UNDEFINED;
        value.at(pin) = FALSE;
    if (value.at(23) == TRUE || value.at(1) == FALSE)
        return (value.at(pin));
    if (value.at(2) == TRUE)
        val += 1;
    if (value.at(3) == TRUE)
        val += 2;
    if (value.at(21) == TRUE)
        val += 4;
    if (value.at(22) == TRUE)
        val += 8;
    value.at(vectvals[val]) = TRUE;
    return value.at(pin);
}

bool Chip4514::checkLinkable(std::size_t pin)
{
    if (entry.find(pin) == entry.end() || entry.at(pin) != "output")
        return false;
    return true;
}

void Chip4514::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
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

void Chip4514::dump() const
{
}

void Chip4514::setValue(Tristate const &val, size_t pin) {
    value.at(pin) = val;
}