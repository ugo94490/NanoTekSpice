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
        nts::Tristate compute(std::size_t pin = 1) {return this->pin;}
        void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) {};
        void dump() const {}

    private:
        Tristate pin;
    };

    class Output : public IComponent
    {
    public:
        Output() {}
        ~Output() {}
        nts::Tristate compute(std::size_t pin = 1) {return this->linked->compute(pinlinked);}
        void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) {}
        void dump() const {}

    private:
        size_t pinlinked;
        std::unique_ptr<IComponent> linked;
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
        std::map<const std::string, Tristate&> inputs;
        std::list<std::unique_ptr<IComponent>> components;
    private:
    };
};