/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** NanoTekSpice
*/

#pragma once

#include <list>
#include <map>
#include <memory>

namespace nts {
    enum Tristate {
        UNDEFINED = (-true),
        TRUE = true,
        FALSE = false
    };

    class IComponent
    {
    public:
        virtual ~IComponent() = default;
        virtual nts::Tristate compute(std::size_t pin = 1) = 0;
        virtual void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) = 0;
        virtual void dump() const = 0;
    };

    class Input : public IComponent
    {
    public:
        Input() {}
        ~Input() {}
        nts::Tristate compute(std::size_t pin = 1) {}
        void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) {};
        void setValue(Tristate const &val, size_t pin = 1) {}
        void dump() const {}

    private:
        std::map<size_t, std::string> entry;
        std::map<size_t, std::pair<IComponent&, size_t>> adress;
        std::map<size_t, Tristate> value;
    };

    class Output : public IComponent
    {
    public:
        Output() {}
        ~Output() {}
        nts::Tristate compute(std::size_t pin = 1) {}
        void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) {}
        void dump() const {}

    private:
        std::map<size_t, std::string> entry;
        std::map<size_t, std::pair<IComponent&, size_t>> adress;
        std::map<size_t, Tristate> value;
    };

    class NanoTekSpice
    {
    public:
        NanoTekSpice(std::string const &file);
        ~NanoTekSpice();
        void simulate();
        void display() const;
        void loop();
        void dump() const;
        void setValue(const std::string &input, const Tristate &value);

    protected:
        std::map<std::string, Input&> inputs;
        std::map<std::string, IComponent&> outputs;
        std::map<std::string, IComponent&> components;
    private:
    };
};