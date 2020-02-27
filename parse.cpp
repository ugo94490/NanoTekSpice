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

const std::map<size_t, std::string> puce {
    {15, "2716"},
    {16, "4008"},
    {2, "4011"},
    {3, "4013"},
    {4, "4017"},
    {5, "4030"},
    {6, "4040"},
    {7, "4069"},
    {8, "4081"},
    {9, "4094"},
    {10, "4503"},
    {11, "4512"},
    {12, "4514"},
    {13, "i4004"},
    {14, "mk4801"},
    {1, "4071"},
    {0, "4001"}
};

nts::IComponent *create4001(void)
{
    nts::IComponent *compo = new Chip4001();

    return (compo);
}

IComponent *create4071(void)
{
    nts::IComponent *compo = new Chip4071();

    return (compo);
}

nts::IComponent *(*tab_fct[2])(void) = {
    create4001,
    create4071
};

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
    for (std::vector<std::string>::size_type i = 0; i < tab.size(); i++)
        for (int j = 0; tab[i][j]; j++) {
            while (tab[i][j] == ' ' && ((j < tab[i].size() && tab[i][j + 1] == ' ') || (j < tab[i].size() && tab[i][j + 1] == '\n')))
                tab[i].erase(j + 1, 1);
            if (tab[i][0] == ' ')
                tab[i].erase(0, 1);
        }
    return (tab);
}

std::map<std::string, IComponent *> Parse::get_input(std::vector<std::string> tab)
{
    std::map<std::string, IComponent *> input;
    bool start = false;
    Input inpu;

    for (std::vector<std::string>::size_type i = 0; i < tab.size(); i++) {
        if (tab[i].compare(0, 10, ".chipsets:") == 0)
            start = true;
        if (tab[i].compare(0, 6, "input ") == 0 && start == true)
            input.insert({tab[i].substr(6, tab[i].size() - 7), new Input});
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

IComponent *create_component(size_t j)
{
    IComponent *new_compo = tab_fct[j]();

    return (new_compo);
}

std::map<std::string, IComponent *> Parse::get_compo(std::vector<std::string> tab)
{
    std::map<std::string, IComponent *> compo;
    bool start = false;

    for (std::vector<std::string>::size_type i = 0; i < tab.size(); i++) {
        if (tab[i].compare(0, 10, ".chipsets:") == 0)
            start = true;
        if (tab[i].compare(0, 7, ".links:") == 0)
            start = false;
        for (std::map<std::string, int>::size_type j = 0; j < puce.size(); j++)
            if (tab[i].compare(0, puce.at(j).size(),puce.at(j)) == 0 && start == true)
                compo.insert({tab[i].substr(puce.at(j).size() + 1, tab[i].size() - puce.at(j).size() - 2), create_component(j)});
    }
    return (compo);
}

int check_in_compo(std::string line, std::map<std::string, IComponent *> component)
{
    int index = line.find(':', 0);

    if (index == (line.size() - 1))
        return (-1);
    if (component.count(line.substr(0, index)) == 0)
        return (-1);
    return (0);
}

int check_in_output(std::string line, std::map<std::string, IComponent *> output)
{
    int index = line.find(':', 0);

    if (index == (line.size() - 1))
        return (-1);
    if (output.count(line.substr(0, index)) == 0)
        return (-1);
    return (0);
}

int check_in_input(std::string line, std::map<std::string, IComponent *> input)
{
    int index = line.find(':', 0);
    std::string save;

    if (index == (line.size() - 1))
        return (-1);
    save = line.substr(0, index);
    if (input.count(save) == 0)
        return (-1);
    return (0);
}

int check_digit(std::string str)
{
    for (int i = 0; i < str.size(); i++) {
        if (std::isdigit(str[i]) == 0)
            return (84);
    }
    return (0);
}

void make_link_compo(std::map<std::string, IComponent *> *component, std::map<std::string, IComponent *> *output, std::map<std::string, IComponent *> *input, std::string line)
{
    int index = line.find(':', 0);
    std::string save = line.substr(0, index);
    size_t start = index + 1;
    size_t end = line.find(' ', 0);
    std::string pin = line.substr(start, end - start);
    std::string full_compo = line.substr(end + 1, line.size() - end);
    size_t index_scd = line.find(':', end);
    std::string new_compo = line.substr(end + 1, index_scd - end - 1);
    size_t start_pin = index_scd + 1;
    size_t end_pin = line.size();
    std::string nb_pin;
    IComponent *found_compo;

    if (line[line.size() - 1] == '\n') {
        std::cout << end_pin - start_pin << std::endl;
        nb_pin = line.substr(start_pin, end_pin - start_pin - 1);
    } else {
        nb_pin = line.substr(start_pin, end_pin - start_pin);
    }
    if (check_digit(pin) == 84) {
        std::cerr << "Non Numerical-Number for first Pin" << std::endl;
        return;
    }
    std::cout << nb_pin << std::endl;
    if (check_digit(nb_pin) == 84) {
        std::cerr << "Non Numerical-Number for second Pin" << std::endl;
        return;
    }
    if (output->count(new_compo) != 0) {
        found_compo = output->find(new_compo)->second;
        IComponent &ref_to_comp = *found_compo;
        component->at(save)->setLink(std::stoi(pin), ref_to_comp, std::stoi(nb_pin));
        return;
    }
    if (component->count(new_compo) != 0) {
        found_compo = component->find(new_compo)->second;
        IComponent &ref_to_comp = *found_compo;
        component->at(save)->setLink(std::stoi(pin), ref_to_comp, std::stoi(nb_pin));
        return;
    }
    if (input->count(new_compo) != 0) {
        found_compo = input->find(new_compo)->second;
        IComponent &ref_to_comp = *found_compo;
        component->at(save)->setLink(std::stoi(pin), ref_to_comp, std::stoi(nb_pin));
        return;
    }
}

void make_link_input(std::map<std::string, IComponent *> *component, std::map<std::string, IComponent *> *output, std::map<std::string, IComponent *> *input, std::string line)
{
    int index = line.find(':', 0);
    std::string save = line.substr(0, index);
    size_t start = index + 1;
    size_t end = line.find(' ', 0);
    std::string pin = line.substr(start, end - start);
    std::string full_compo = line.substr(end + 1, line.size() - end);
    size_t index_scd = line.find(':', end);
    std::string new_compo = line.substr(end + 1, index_scd - end - 1);
    size_t start_pin = index_scd + 1;
    size_t end_pin = line.size();
    std::string nb_pin;
    IComponent *found_compo;

    if (line[line.size() - 1] == '\n') {
        std::cout << end_pin - start_pin << std::endl;
        nb_pin = line.substr(start_pin, end_pin - start_pin - 1);
    } else {
        nb_pin = line.substr(start_pin, end_pin - start_pin);
    }
    if (check_digit(pin) == 84) {
        std::cerr << "Non Numerical-Number for first Pin" << std::endl;
        return;
    }
    std::cout << nb_pin << std::endl;
    if (check_digit(nb_pin) == 84) {
        std::cerr << "Non Numerical-Number for second Pin" << std::endl;
        return;
    }
    if (output->count(new_compo) != 0) {
        found_compo = output->find(new_compo)->second;
        IComponent &ref_to_comp =  *found_compo;
        input->at(save)->setLink(std::stoi(pin), ref_to_comp, std::stoi(nb_pin));
        return;
    }
    if (component->count(new_compo) != 0) {
        found_compo = component->find(new_compo)->second;
        IComponent &ref_to_comp = *found_compo;
        input->at(save)->setLink(std::stoi(pin), ref_to_comp, std::stoi(nb_pin));
        return;
    }
    if (input->count(new_compo) != 0) {
        found_compo = input->find(new_compo)->second;
        IComponent &ref_to_comp = *found_compo;
        input->at(save)->setLink(std::stoi(pin), ref_to_comp, std::stoi(nb_pin));
        return;
    }
}

void make_link_output(std::map<std::string, IComponent *> *component, std::map<std::string, IComponent *> *output, std::map<std::string, IComponent *> *input, std::string line)
{
    int index = line.find(':', 0);
    std::string save = line.substr(0, index);
    size_t start = index + 1;
    size_t end = line.find(' ', 0);
    std::string pin = line.substr(start, end - start);
    std::string full_compo = line.substr(end + 1, line.size() - end);
    size_t index_scd = line.find(':', end);
    std::string new_compo = line.substr(end + 1, index_scd - end - 1);
    size_t start_pin = index_scd + 1;
    size_t end_pin = line.size();
    std::string nb_pin;
    IComponent *found_compo;

    if (line[line.size() - 1] == '\n') {
        std::cout << end_pin - start_pin << std::endl;
        nb_pin = line.substr(start_pin, end_pin - start_pin - 1);
    } else {
        nb_pin = line.substr(start_pin, end_pin - start_pin);
    }
    if (check_digit(pin) == 84) {
        std::cerr << "Non Numerical-Number for first Pin" << std::endl;
        return;
    }
    std::cout << nb_pin << std::endl;
    if (check_digit(nb_pin) == 84) {
        std::cerr << "Non Numerical-Number for second Pin" << std::endl;
        return;
    }
    if (output->count(new_compo) != 0) {
        found_compo = output->find(new_compo)->second;
        IComponent &ref_to_comp = *found_compo;
        output->at(save)->setLink(std::stoi(pin), ref_to_comp, std::stoi(nb_pin));
        return;
    }
    if (component->count(new_compo) != 0) {
        found_compo = component->find(new_compo)->second;
        IComponent &ref_to_comp = *found_compo;
        output->at(save)->setLink(std::stoi(pin), ref_to_comp, std::stoi(nb_pin));
        return;
    }
    if (input->count(new_compo) != 0) {
        found_compo = input->find(new_compo)->second;
        IComponent &ref_to_comp = *found_compo;
        output->at(save)->setLink(std::stoi(pin), ref_to_comp, std::stoi(nb_pin));
        return;
    }
}


void parse_link(std::vector<std::string> tab, std::map<std::string, IComponent *> component, std::map<std::string, IComponent *> output, std::map<std::string, IComponent *> input)
{
    bool start = false;

    for (std::vector<std::string>::size_type i = 0; i < tab.size(); i++) {
        if (start == true && check_in_compo(tab[i], component) != -1) {
            std::cout << "DETECT COMPO : " << tab[i] << std::endl;
            make_link_compo(&component, &output, &input, tab[i]);
        }
        if (start == true && check_in_input(tab[i], input) != -1) {
            std::cout << "DETECT INPUT : " << tab[i] << std::endl;
            make_link_input(&component, &output, &input, tab[i]);
        }
        if (start == true && check_in_output(tab[i], output) != -1) {
            std::cout << "DETECT OUTPUT : " << tab[i] << std::endl;
            make_link_output(&component, &output, &input, tab[i]);
        }
        if (tab[i].compare(0, 7, ".links:") == 0)
            start = true;
    }
    return;
}

void fill_nano(std::map<std::string, IComponent *> *component, std::map<std::string, IComponent *> *output, std::map<std::string, IComponent *> *input, NanoTekSpice &obj)
{

}

int Parse::check_error(std::vector<std::string> tab, NanoTekSpice &obj)
{
    std::map<std::string, IComponent *> input;
    std::map<std::string, IComponent *> component;
    std::map<std::string, IComponent *> output;
    std::vector<std::string> clean = Parse::clean_comment(tab);

    clean = clean_str(clean);
    input = get_input(clean);
    output = get_output(clean);
    component = get_compo(clean);
    parse_link(clean, component, output, input);
    obj.setInput(input);
    obj.setComponent(component);
    obj.setOutput(output);

    return (0);
}

/*int main(int ac, char **av)
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
*/