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
        nts::Tristate compute(std::size_t pin = 1) {
            if (value.find(pin) != value.end())
                return value.at(pin);
            return (UNDEFINED);
        }
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

    class True_c : public IComponent
    {
    public:
        True_c() {
            entry.insert({1, "output"});
            value.insert({1, TRUE});
        }
        ~True_c() = default;
        nts::Tristate compute(std::size_t pin = 1) {
            if (value.find(pin) != value.end())
                return value.at(pin);
            return (UNDEFINED);
        }
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
            std::cerr << "Try to set value of true component" << std::endl;
            exit(84);
        }

    private:
        std::map<size_t, std::string> entry;
        std::map<size_t, Tristate> value;
    };

    class False_c : public IComponent
    {
    public:
        False_c() {
            entry.insert({1, "output"});
            value.insert({1, FALSE});
        }
        ~False_c() = default;
        nts::Tristate compute(std::size_t pin = 1) {
            if (value.find(pin) != value.end())
                return value.at(pin);
            return (UNDEFINED);
        }
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
            std::cerr << "Try to set value of false component" << std::endl;
            exit(84);
        }

    private:
        std::map<size_t, std::string> entry;
        std::map<size_t, Tristate> value;
    };

    class Clock : public IComponent
    {
    public:
        Clock() {
            entry.insert({1, "output"});
            value.insert({1, UNDEFINED});
        }
        ~Clock() = default;
        nts::Tristate compute(std::size_t pin = 1) {
            if (value.find(pin) != value.end())
                return value.at(pin);
            return (UNDEFINED);
        }
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
            if (adress.find(1) == adress.end()) {
                std::cerr << "output not linked to anything" << std::endl;
                exit(84);
            }
            Tristate val = adress.at(pin).first.compute(adress.at(pin).second);
            setValue(val, pin);
            return (val);
        }
        void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) {
            if (!other.checkLinkable(otherPin)) {
                std::cerr << "Tried to link pure output to input !" << std::endl;
                exit(84);
            }
            adress.insert({pin, {other, otherPin}});
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
