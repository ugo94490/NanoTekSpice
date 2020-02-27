/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** NanoTekSpice
*/

#include <vector>
#include <iostream>
#include "Parse.hpp"
#include "NanoTekSpice.hpp"

using namespace nts;

NanoTekSpice::NanoTekSpice(std::string const &file)
{
    std::vector<std::string> tab;

    tab = Parse::open_read(file);
    if (tab.size() == 0 || Parse::check_error(tab) == 84) {
        std::cout << "BAD FILE" << std::endl;
        return;
    }
}

NanoTekSpice::~NanoTekSpice()
{
}

void NanoTekSpice::simulate()
{
    /*for (auto it = outputs.begin(); it != outputs.end(); ++it) {
        it->second.compute();
    }*/
}

void NanoTekSpice::display() const
{
    for (auto it = outputs.begin(); it != outputs.end(); ++it) {
    }
}

void NanoTekSpice::loop()
{

}

void NanoTekSpice::dump() const
{
    /*for (auto it = components.begin(); it != components.end(); ++it)
        it->second.dump();*/
}

void NanoTekSpice::setValue(const std::string &input, const Tristate &value)
{
    inputs[input].setValue(value);
}
