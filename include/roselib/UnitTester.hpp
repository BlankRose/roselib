/* ************************************************************************** */
/*         .-.                                                                */
/*   __   /   \   __                                                          */
/*  (  `'.\   /.'`  )  UnitTester.hpp                                         */
/*   '-._.(;;;)._.-'                                                          */
/*   .-'  ,`"`,  '-.                                                          */
/*  (__.-'/   \'-.__)  By: Rosie (https://github.com/BlankRose)               */
/*      //\   /        Last Updated: March 20, 2024 [06:21 pm]                */
/*     ||  '-'                                                                */
/* ************************************************************************** */

#pragma once

/// Includes all very basic definitions used throughout every
/// single unit testers (such as enumerations, structures and typedefs)
#include "UnitTester/utils.hpp"

/// Defines base class used by every specialized unit testers
#include "UnitTester/UnitTesterBase.hpp"

/// Defines the callable specialized unit tester
#include "UnitTester/UnitTesterFunction.hpp"

/// Defines the conditional specialized unit tester
/// ( Is the simpliest to use )
#include "UnitTester/UnitTesterConditional.hpp"