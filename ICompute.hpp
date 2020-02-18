/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** ICompute
*/

#pragma once

#include "NanoTekSpice.hpp"

namespace nts
{
    class ICompute
    {
    public:
        virtual ~ICompute() = default;
        virtual Tristate compute(Tristate const &val1, Tristate const &val2);
    };

    class ComputeAnd
    {
    public:
        ComputeAnd() = default;
        ~ComputeAnd() = default;
        Tristate compute(Tristate const &val1, Tristate const &val2) {
            if (val1 == UNDEFINED && val2 == UNDEFINED)
                return UNDEFINED;
            if (val1 && val2)
                return TRUE;
            return FALSE;
        }
    };

    class ComputeAnd
    {
    public:
        ComputeAnd() = default;
        ~ComputeAnd() = default;
        Tristate compute(Tristate const &val1, Tristate const &val2) {
            if (val1 == UNDEFINED && val2 == UNDEFINED)
                return UNDEFINED;
            if (val1 && val2)
                return TRUE;
            return FALSE;
        }
    };

    class ComputeOr
    {
    public:
        ComputeOr() = default;
        ~ComputeOr() = default;
        Tristate compute(Tristate const &val1, Tristate const &val2) {
            if (val1 == UNDEFINED && val2 == UNDEFINED)
                return UNDEFINED;
            if (val1 || val2)
                return TRUE;
            return FALSE;
        }
    };

    class ComputeXor
    {
    public:
        ComputeXor() = default;
        ~ComputeXor() = default;
        Tristate compute(Tristate const &val1, Tristate const &val2) {
            if (val1 == UNDEFINED && val2 == UNDEFINED)
                return UNDEFINED;
            if (val1 || val2 && val1 != val2)
                return TRUE;
            return FALSE;
        }
    };
};