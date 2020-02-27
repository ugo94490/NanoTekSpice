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
        virtual bool checkLinkable(std::size_t pin) = 0;
        virtual void dump() const = 0;
        virtual void setValue(Tristate const &val, size_t pin = 1) = 0;
    };

    class Input : public IComponent
    {
    public:
        Input() {
            entry.insert({1, "input"});
            value.insert({1, UNDEFINED});
        }
        ~Input() = default;
        nts::Tristate compute(std::size_t pin = 1) { return (UNDEFINED);}
        void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) {}
        bool checkLinkable(std::size_t pin) {
            if (pin == 1)
                return true;
            return false;
        }
        void dump() const {}
        void setValue(Tristate const &val, size_t pin = 1) {
            value.at(pin) = val;
        }

    private:
        std::map<size_t, std::string> entry;
        std::map<size_t, Tristate> value;
    };

    class Output : public IComponent
    {
    public:
        Output() {
            entry.insert({1, "input"});
            value.insert({1, UNDEFINED});
        }
        ~Output() = default;
        nts::Tristate compute(std::size_t pin = 1) {return (UNDEFINED);}
        void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) {}
        bool checkLinkable(std::size_t pin) {
            if (pin == 1)
                return true;
            return false;
        }
        void dump() const {}
        void setValue(Tristate const &val, size_t pin = 1) {}

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
        std::map<std::string, IComponent *> inputs;
        std::map<std::string, IComponent *> outputs;
        std::map<std::string, IComponent *> components;
    private:
    };
};