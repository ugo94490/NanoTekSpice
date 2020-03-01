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
            if (val1 == TRUE && val2 == TRUE)
                return TRUE;
            return FALSE;
        }
        static Tristate computeNand(Tristate const &val1, Tristate const &val2) {
            if (val1 == UNDEFINED && val2 == UNDEFINED)
                return UNDEFINED;
            if (val1 == FALSE || val2 == FALSE)
                return TRUE;
            return FALSE;
        }
        static Tristate computeOr(Tristate const &val1, Tristate const &val2) {
            if (val1 == UNDEFINED && val2 == UNDEFINED)
                return UNDEFINED;
            if (val1 == TRUE || val2 == TRUE)
                return TRUE;
            return FALSE;
        }
        static Tristate computeNor(Tristate const &val1, Tristate const &val2) {
            if (val1 == UNDEFINED || val2 == UNDEFINED)
                return UNDEFINED;
            if (val1 == FALSE && val2 == FALSE)
                return TRUE;
            return FALSE;
        }
        static Tristate computeXor(Tristate const &val1, Tristate const &val2) {
            if (val1 == UNDEFINED || val2 == UNDEFINED)
                return UNDEFINED;
            if ((val1 == TRUE || val2 == TRUE) && val1 != val2)
                return TRUE;
            return FALSE;
        }
        static Tristate computeNot(Tristate const &val) {
            if (val == UNDEFINED)
                return (UNDEFINED);
            if (val == TRUE)
                return (FALSE);
            return (TRUE);
        }
        static Tristate computeSum(Tristate const &val1, Tristate const &val2, Tristate const &val3) {
            int nb = 0;

            if (val1 == UNDEFINED || val2 == UNDEFINED || val3 == UNDEFINED)
                return (UNDEFINED);
            nb = val1 + val2 + val3;
            if (nb%2 == 1)
                return (TRUE);
            return (FALSE);
        }
        static Tristate computeSumCarry(Tristate const &val1, Tristate const &val2, Tristate const &val3) {
            int nb = 0;

            if (val1 == UNDEFINED || val2 == UNDEFINED || val3 == UNDEFINED)
                return (UNDEFINED);
            nb = val1 + val2 + val3;
            if (nb/2 == 1)
                return (TRUE);
            return (FALSE);
        }
    };
};