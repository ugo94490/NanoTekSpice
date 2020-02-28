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
            entry.insert({1, "output"});
            value.insert({1, UNDEFINED});
        }
        ~Input() = default;
        nts::Tristate compute(std::size_t pin = 1) { return (UNDEFINED);}
        void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) {
            std::cerr << "Tried to link pure input with an output !" << std::endl;
            exit(84);
        }
        bool checkLinkable(std::size_t pin) {
            if (pin == 1)
                return true;
            return false;
        }
        void dump() const {
            if (value.at(1) == UNDEFINED)
                std::cout << "U" << std::endl;
            else
                std::cout << value.at(1) << std::endl;
        }
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
        nts::Tristate compute(std::size_t pin = 1) {
            std::cout << pin << std::endl;
            if (adress.find(pin) == adress.end())
                return (adress.at(pin).first.compute(adress.at(pin).second));
            std::cout << "output could not be calculated" << std::endl;
            return (UNDEFINED);
        }
        void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) {
            if (!other.checkLinkable(otherPin)) {
                std::cerr << "Tried to link pure output to input !" << std::endl;
                exit(84);
            }
            adress.insert({pin, {other, otherPin}});
            std::cout << "output linked!" << std::endl;
        }
        bool checkLinkable(std::size_t pin) {
            if (pin == 1)
                return true;
            return false;
        }
        void dump() const {
            if (value.at(1) == UNDEFINED)
                std::cout << "U" << std::endl;
            else
                std::cout << value.at(1) << std::endl;
        }
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
        void mainloop();
        void setValues(std::string str);
        void setValue(std::string str);
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