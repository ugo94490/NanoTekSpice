/*
** EPITECH PROJECT, 2020
** NanoTekSpice
** File description:
** parse.cpp
*/

#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include "Parse.hpp"
#include "Chip.hpp"
#include "NanoTekSpice.hpp"

using namespace nts;

std::map<std::string, IComponent *> puce {
    //{"2716", Chip2716()},
    //{"4008", Chip4008()},
    //{"4011", Chip2716()},
    //{"4013", Chip4008()},
    //{"4017", Chip2716()},
    //{"4030", Chip4008()},
    //{"4040", Chip2716()},
    //{"4069", Chip4008()},
    //{"4081", Chip4008()},
    //{"4094", Chip2716()},
    //{"4503", Chip4008()},
    //{"4512", Chip2716()},
    //{"4514", Chip4008()},
    //{"i4004", Chip2716()},
    //{"mk4801", Chip4008()},
    {"4001", new Chip4001()},
    {"4071", new Chip4071()}
};

std::unique_ptr<IComponent> create4001(void)
{
    IComponent *compo = new Chip4001();
    return (compo);
}

std::vector<std::string> Parse::open_read(std::string stream)
{
    std::ifstream myfile (stream);
    std::vector<std::string> tab;
    std::string str;

    if (myfile.is_open()) {
        while (std::getline(myfile, str)) {
            str += "\n";
            tab.push_back(str);
        }
        myfile.close();
    }
    return (tab);
}

std::vector<std::string> Parse::clean_comment(std::vector<std::string> tab)
{
    int index = -1;

    for (std::vector<std::string>::size_type i = 0 ; i != tab.size(); i++) {
        index = tab[i].find('#', 0);
        if (index != -1)
            tab[i].erase(index, tab[i].size() - index - 1);
        index = -1;
    }
    return (tab);
}

std::vector<std::string> Parse::clean_str(std::vector<std::string> tab)
{
    for (std::vector<std::string>::size_type i = 0; i < tab.size(); i++) {
        for (int j = 0; tab[i][j]; j++) {
            while (tab[i][j] == ' ' && j < tab[i].size() && tab[i][j + 1] == ' ')
                tab[i].erase(j + 1, 1);
            if (tab[i][0] == ' ')
                tab[i].erase(0, 1);
        }
    }
    return (tab);
}

std::map<std::string, Input> Parse::get_input(std::vector<std::string> tab)
{
    std::map<std::string, Input> input;
    bool start = false;
    Input inpu;

    for (std::vector<std::string>::size_type i = 0; i < tab.size(); i++) {
        if (tab[i].compare(0, 10, ".chipsets:") == 0)
            start = true;
        if (tab[i].compare(0, 6, "input ") == 0 && start == true) {
            input.insert({tab[i].substr(6, tab[i].size() - 7), inpu});
        }
        if (tab[i].compare(0, 7, ".links:") == 0)
            start = false;
    }
    return (input);
}

std::map<std::string, IComponent *> Parse::get_output(std::vector<std::string> tab)
{
    std::map<std::string, IComponent *> output;
    bool start = false;

    for (std::vector<std::string>::size_type i = 0; i < tab.size(); i++) {
        if (tab[i].compare(0, 10,".chipsets:") == 0)
            start = true;
        if (tab[i].compare(0, 7,"output ") == 0 && start == true) {
            output.insert({tab[i].substr(7, tab[i].size() - 8), new Output});
        }
        if (tab[i].compare(0, 7,".links:") == 0)
            start = false;
    }
    return (output);
}

std::map<std::string, IComponent> Parse::get_compo(std::vector<std::string> tab)
{
    std::map<std::string, std::string> compo;
    bool start = false;

    for (std::vector<std::string>::size_type i = 0; i < tab.size(); i++) {
        if (tab[i].compare(0, 10, ".chipsets:") == 0)
            start = true;
        if (tab[i].compare(0, 7, ".links:") == 0)
            start = false;
        for (int j = 0; j < puce.size(); j++)
            if (tab[i].compare(0, puce[j].size() ,puce[j]) == 0 && start == true)
                compo.insert({tab[i].substr(0, puce[j].size()), tab[i].substr(puce[j].size() + 1, tab[i].size() - 1)});
    }
    return (compo);
}

int Parse::check_error(std::vector<std::string> tab)
{
    std::map<std::string, Input> input;
    std::map<std::string, IComponent> component;
    std::map<std::string, IComponent *> output;
    std::vector<std::string> clean = Parse::clean_comment(tab);

    clean = Parse::clean_str(clean);
    input = Parse::get_input(clean);
    output = Parse::get_output(clean);
    component = Parse::get_compo(clean);
    return (0);
}

int main(int ac, char **av)
{

    std::vector<std::string> tab;
    std::string str;


    if (ac == 2)
        tab = Parse::open_read(av[1]);
    else {
        std::cout << "NO FILE IN PARAMETERS" << std::endl;
        return (84);
    }
    if (tab.size() == 0 || Parse::check_error(tab) == 84) {
        std::cout << "BAD FILE" << std::endl;
        return (84);
    }
    return (0);
}
