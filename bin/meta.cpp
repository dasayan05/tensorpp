/*
 *  Copyright (C) 2018
 *  @author Ayan Das
 *
 *  This program is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU General Public License
 *  as published by the Free Software Foundation; either version 2
 *  of the License, or (at your option) any later version.

 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.

 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */

#include <iostream>
using std::cout;
using std::endl;

// cmdline parser library
#include <cxxopts.hpp>

#include <tensorpp/tensorpp.hpp>
using namespace tensorpp;

int main(int argc, char** argv)
{
	cxxopts::Options options("tensorpp", "A Tensor manipulation library in C++");
	options.add_options()
		("c,compiler", "show compiler information")
		("s,system", "show system information")
        ("d,deps", "show dependency/backend information");
	
	auto args = options.parse(argc, argv);
	try {
		bool compiler = args["compiler"].as<bool>();
		bool system = args["system"].as<bool>();
        bool deps = args["deps"].as<bool>();
		
    	utils::print_info(system, compiler, deps);
    } catch(const cxxopts::OptionSpecException& optEx) {
    	cout << "cxxopts threw exception" << optEx.what() << endl;
    }
    return 0;
}
