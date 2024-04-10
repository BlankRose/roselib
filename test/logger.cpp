/* ************************************************************************** */
//         .-.
//   __   /   \   __
//  (  `'.\   /.'`  )  roselib - logger.cpp
//   '-._.(;;;)._.-'
//   .-'  ,`"`,  '-.
//  (__.-'/   \'-.__)  By: Rosie (https://github.com/BlankRose)
//      //\   /        Created at: April 10, 2024 [9:34 AM]
//     ||  '-'
/* ************************************************************************** */

#include "roselib/Logger.hpp"
#include <iostream>

void test_logger()
{
    std::cout << "\nLogger - Basics" << std::endl;
    rose::logs.debug("THIS SHOULD NOT BE VISIBLE!");
    rose::logs.info("Some info text here..");
    rose::logs.error("Some error text here..");
    rose::logs.warn("Warning, dangerous ahead!");
    rose::logs.fatal("FATALITY!");

    std::cout << "\nLogger - Construct" << std::endl;
    rose::logs_debug() << "This SHOULD NOT display per default.." << rose::logs_send;
    rose::logs_info() << "Some info text " << true << '|' << 12.3f << rose::logs_send;
    rose::logs_error() << "Some error text: " << 404 << rose::logs_send;
    rose::logs_warn() << "More warnings" << rose::logs_send;
    rose::logs_fatal() << "DEATH INCOMMING!" << rose::logs_send;
}