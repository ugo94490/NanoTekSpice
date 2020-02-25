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
    class Compute
    {
    public:
        static Tristate computeAnd(Tristate const &val1, Tristate const &val2) {
            if (val1 == UNDEFINED || val2 == UNDEFINED)
                return UNDEFINED;
            if (val1 && val2)
                return TRUE;
            return FALSE;
        }
        static Tristate computeOr(Tristate const &val1, Tristate const &val2) {
            if (val1 == UNDEFINED && val2 == UNDEFINED)
                return UNDEFINED;
            if (val1 || val2)
                return TRUE;
            return FALSE;
        }
        static Tristate computeNor(Tristate const &val1, Tristate const &val2) {
            if (val1 == UNDEFINED || val2 == UNDEFINED)
                return UNDEFINED;
            if (!val1 && !val2)
                return TRUE;
            return FALSE;
        }
        static Tristate computeXor(Tristate const &val1, Tristate const &val2) {
            if (val1 == UNDEFINED || val2 == UNDEFINED)
                return UNDEFINED;
            if (val1 || val2 && val1 != val2)
                return TRUE;
            return FALSE;
        }
    };
};