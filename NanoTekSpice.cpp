/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** NanoTekSpice
*/

#include <vector>
#include <iostream>
#include <fstream>
#include "Parse.hpp"
#include "NanoTekSpice.hpp"

using namespace nts;

NanoTekSpice::NanoTekSpice(std::string const &file)
{
    std::vector<std::string> tab;

    tab = Parse::open_read(file);
    if (tab.size() == 0) {
        std::cerr << "BAD FILE" << std::endl;
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
    for (auto it = outputs.begin(); it != outputs.end(); ++it) {
        it->second->compute();
    }
}

void NanoTekSpice::display() const
{
    for (auto it = outputs.begin(); it != outputs.end(); ++it) {
        std::cout << it->first << "=";
        it->second->dump();
    }
}

void NanoTekSpice::setValues(std::string str)
{
    std::string delimiter = " ";
    size_t pos = 0;
    std::string token;

    while ((pos = str.find(delimiter)) != std::string::npos) {
        token = str.substr(0, pos);
        setValue(token);
        str.erase(0, pos + delimiter.length());
    }
    setValue(str);
}

void NanoTekSpice::setValue(std::string str)
{
    std::string delimiter = "=";
    size_t pos = 0;
    std::string token;
    Tristate state = UNDEFINED;

    while ((pos = str.find(delimiter)) != std::string::npos) {
        token = str.substr(0, pos);
        str.erase(0, pos + delimiter.length());
    }
    if ((str == "1" || str == "0" || str == "-1") && inputs.find(token) != inputs.end()) {
        if (str == "1")
            state = TRUE;
        if (str == "0")
            state = FALSE;
        inputs.at(token)->setValue(state);
    }
    else
        exit(84);
}

void NanoTekSpice::mainloop()
{
    std::string usrinput = "d";

    simulate();
    display();
    while (usrinput != "exit") {
        std::cout << "> ";
        std::getline(std::cin, usrinput);
        if (std::cin.eof() == 1)
            exit(0);
        if (usrinput == "simulate")
            simulate();
        else if (usrinput == "display")
            display();
        else if (usrinput == "dump")
            dump();
        else if (usrinput == "loop")
            loop();
        else if (usrinput != "exit")
            setValues(usrinput);
    }
}

void NanoTekSpice::loop()
{
    while (true) {
        simulate();
    }
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
    for (int i = 2; i < ac; i++)
        nano.setValue(av[i]);
    nano.mainloop();
    return (0);
}