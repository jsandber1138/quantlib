
/*
 * Copyright (C) 2000-2001 QuantLib Group
 *
 * This file is part of QuantLib.
 * QuantLib is a C++ open source library for financial quantitative
 * analysts and developers --- http://quantlib.org/
 *
 * QuantLib is free software and you are allowed to use, copy, modify, merge,
 * publish, distribute, and/or sell copies of it under the conditions stated
 * in the QuantLib License.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 * or FITNESS FOR A PARTICULAR PURPOSE. See the license for more details.
 *
 * You should have received a copy of the license along with this file;
 * if not, please email quantlib-users@lists.sourceforge.net
 * The license is also available at http://quantlib.org/LICENSE.TXT
 *
 * The members of the QuantLib Group are listed in the Authors.txt file, also
 * available at http://quantlib.org/group.html
*/

/*! \file americancondition.hpp
    \fullpath Include/ql/Pricers/%americancondition.hpp
    \brief american option exercise condition

*/

// $Id$
// $Log$
// Revision 1.10  2001/08/28 13:37:35  nando
// unsigned int instead of int
//
// Revision 1.9  2001/08/09 14:59:47  sigmud
// header modification
//
// Revision 1.8  2001/08/08 11:07:49  sigmud
// inserting \fullpath for doxygen
//
// Revision 1.7  2001/08/07 11:25:54  sigmud
// copyright header maintenance
//
// Revision 1.6  2001/07/25 15:47:28  sigmud
// Change from quantlib.sourceforge.net to quantlib.org
//
// Revision 1.5  2001/06/22 16:38:15  lballabio
// Improved documentation
//
// Revision 1.4  2001/05/24 15:38:08  nando
// smoothing #include xx.hpp and cutting old Log messages
//

#ifndef BSM_american_condition_h
#define BSM_american_condition_h

#include "ql/FiniteDifferences/standardstepcondition.hpp"

namespace QuantLib {

    namespace Pricers {

        class AmericanCondition 
        : public FiniteDifferences::StandardStepCondition {
          public:
            AmericanCondition(const Array& initialPrices);
            void applyTo(Array& a, Time t) const;
          private:
            Array initialPrices_;
        };


        // inline definitions
        
        inline AmericanCondition::AmericanCondition(
            const Array& initialPrices)
            : initialPrices_(initialPrices) {}

        inline void AmericanCondition::applyTo(Array& a, Time t) const {
            for (unsigned int i = 0; i < a.size(); i++)
                a[i] = QL_MAX(a[i], initialPrices_[i]);
        }

    }

}


#endif
