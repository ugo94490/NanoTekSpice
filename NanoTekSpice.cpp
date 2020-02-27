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
    if (tab.size() == 0) {
        std::cout << "BAD FILE" << std::endl;
        exit (84);
    }
    std::vector<std::string> clean = Parse::clean_comment(tab);
    clean = Parse::clean_str(clean);
    inputs = Parse::get_input(clean);
    outputs = Parse::get_output(clean);
    components = Parse::get_compo(clean);
    Parse::parse_link(clean, components, outputs, inputs);
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
    for (auto it = components.begin(); it != components.end(); ++it)
        it->second->dump();
}

void NanoTekSpice::setValue(const std::string &input, const Tristate &value)
{
    inputs.find(input)->second->setValue(value);
}

int main(int ac, char **av)
{
    if (ac < 2)
        return (84);

    NanoTekSpice nano(av[1]);
    nano.loop();
    return (0);
}