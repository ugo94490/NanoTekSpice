/*
** EPITECH PROJECT, 2020
** NanoTekSpice
** File description:
** Factory.hpp
*/

#pragma once

#include <vector>
#include <string>
#include <map>
#include "NanoTekSpice.hpp"

class Parse 
{
public:
    static std::map<std::string, nts::IComponent *> get_input(std::vector<std::string> tab);
    static std::map<std::string, nts::IComponent *> get_output(std::vector<std::string> tab);
    static std::map<std::string, nts::IComponent *> get_compo(std::vector<std::string> tab);
    static std::vector<std::string> open_read(std::string stream);
    static std::vector<std::string> clean_comment(std::vector<std::string> tab);
    static std::vector<std::string> clean_str(std::vector<std::string> tab);
    static int check_error(std::vector<std::string> tab, NanoTekSpice &obj);
    std::unique_ptr<nts::IComponent> create4001(const std::string &value) const noexcept;
    std::unique_ptr<nts::IComponent> create4071(void) const noexcept;
};