/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** Chip
*/

#pragma once

#include <iostream>
#include "ICompute.hpp"

namespace nts {
    class Chip4001 : public IComponent
    {
    public:
        Chip4001();
        ~Chip4001();
        nts::Tristate compute(std::size_t pin = 1);
        void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin);
        bool checkLinkable(std::size_t pin);
        void dump() const;
        void setValue(Tristate const &val, size_t pin = 1);
    
    private:
        std::map<size_t, std::string> entry;
        std::map<size_t, std::pair<IComponent&, size_t>> address;
        std::map<size_t, Tristate> value;
    };

    class Chip4008 : public IComponent
    {
    public:
        Chip4008();
        ~Chip4008();
        nts::Tristate compute(std::size_t pin = 1);
        void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin);
        bool checkLinkable(std::size_t pin);
        void dump() const;
        void setValue(Tristate const &val, size_t pin = 1);
    
    private:
        std::map<size_t, std::string> entry;
        std::map<size_t, std::pair<IComponent&, size_t>> address;
        std::map<size_t, Tristate> value;
    };

    class Chip4011 : public IComponent
    {
    public:
        Chip4011();
        ~Chip4011();
        nts::Tristate compute(std::size_t pin = 1);
        void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin);
        bool checkLinkable(std::size_t pin);
        void dump() const;
        void setValue(Tristate const &val, size_t pin = 1);
    
    private:
        std::map<size_t, std::string> entry;
        std::map<size_t, std::pair<IComponent&, size_t>> address;
        std::map<size_t, Tristate> value;
    };

    class Chip4030 : public IComponent
    {
    public:
        Chip4030();
        ~Chip4030();
        nts::Tristate compute(std::size_t pin = 1);
        void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin);
        bool checkLinkable(std::size_t pin);
        void dump() const;
        void setValue(Tristate const &val, size_t pin = 1);
    
    private:
        std::map<size_t, std::string> entry;
        std::map<size_t, std::pair<IComponent&, size_t>> address;
        std::map<size_t, Tristate> value;
    };

    class Chip4071 : public IComponent
    {
    public:
        Chip4071();
        ~Chip4071();
        nts::Tristate compute(std::size_t pin = 1);
        void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin);
        bool checkLinkable(std::size_t pin);
        void dump() const;
        void setValue(Tristate const &val, size_t pin = 1);
    
    private:
        std::map<size_t, std::string> entry;
        std::map<size_t, std::pair<IComponent&, size_t>> address;
        std::map<size_t, Tristate> value;
    };

    class Chip4081 : public IComponent
    {
    public:
        Chip4081();
        ~Chip4081();
        nts::Tristate compute(std::size_t pin = 1);
        void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin);
        bool checkLinkable(std::size_t pin);
        void dump() const;
        void setValue(Tristate const &val, size_t pin = 1);
    
    private:
        std::map<size_t, std::string> entry;
        std::map<size_t, std::pair<IComponent&, size_t>> address;
        std::map<size_t, Tristate> value;
    };

    class Chip4069 : public IComponent
    {
    public:
        Chip4069();
        ~Chip4069();
        nts::Tristate compute(std::size_t pin = 1);
        void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin);
        bool checkLinkable(std::size_t pin);
        void dump() const;
        void setValue(Tristate const &val, size_t pin = 1);
    
    private:
        std::map<size_t, std::string> entry;
        std::map<size_t, std::pair<IComponent&, size_t>> address;
        std::map<size_t, Tristate> value;
    };

    class Chip4013 : public IComponent
    {
    public:
        Chip4013();
        ~Chip4013();
        nts::Tristate compute(std::size_t pin = 1);
        void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin);
        bool checkLinkable(std::size_t pin);
        void dump() const;
        void setValue(Tristate const &val, size_t pin = 1);
    
    private:
        std::map<size_t, std::string> entry;
        std::map<size_t, std::pair<IComponent&, size_t>> address;
        std::map<size_t, Tristate> value;
    };

    class Chip4514 : public IComponent
    {
    public:
        Chip4514();
        ~Chip4514();
        nts::Tristate compute(std::size_t pin = 1);
        void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin);
        bool checkLinkable(std::size_t pin);
        void dump() const;
        void setValue(Tristate const &val, size_t pin = 1);
    
    private:
        std::map<size_t, std::string> entry;
        std::map<size_t, std::pair<IComponent&, size_t>> address;
        std::map<size_t, Tristate> value;
    };
};
