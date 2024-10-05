// Lic:
// Kitty/Source/KittyHighNeil.cpp
// Kitty High Neil
// version: 24.10.05
// Copyright (C) 2020, 2023, 2024 Jeroen P. Broks
// This software is provided 'as-is', without any express or implied
// warranty.  In no event will the authors be held liable for any damages
// arising from the use of this software.
// Permission is granted to anyone to use this software for any purpose,
// including commercial applications, and to alter it and redistribute it
// freely, subject to the following restrictions:
// 1. The origin of this software must not be misrepresented; you must not
// claim that you wrote the original software. If you use this software
// in a product, an acknowledgment in the product documentation would be
// appreciated but is not required.
// 2. Altered source versions must be plainly marked as such, and must not be
// misrepresented as being the original software.
// 3. This notice may not be removed or altered from any source distribution.
// EndLic
#include <Kitty_High.hpp>
namespace Slyvina {
	namespace Kitty {
		void KittyHighNeil() {
			static _KittyPL Me{};
			auto BaseTypes{ Me.BaseTypes }, KeyWords{ Me.KeyWords };
			auto B{ Me.Base };
			Me.caseinsensitive = true;
			// Base Types
			KeyWords->push_back("void");
			BaseTypes->push_back("string");
			BaseTypes->push_back("int");
			BaseTypes->push_back("bool");
			BaseTypes->push_back("var");
			BaseTypes->push_back("plua");
			// Not complete yet, but for now this will do!
			KeyWords->push_back("not");
			KeyWords->push_back("class");
			KeyWords->push_back("group");
			KeyWords->push_back("module");
			KeyWords->push_back("global");
			KeyWords->push_back("private");
			KeyWords->push_back("end");
			KeyWords->push_back("and");
			KeyWords->push_back("or");
			KeyWords->push_back("table");
			KeyWords->push_back("quickmeta");
			KeyWords->push_back("switch");
			KeyWords->push_back("case");
			KeyWords->push_back("default");
			// KeyWords->push_back("goto"); // EEEEW!
			KeyWords->push_back("if");
			KeyWords->push_back("else");
			KeyWords->push_back("elseif");
			KeyWords->push_back("do");
			KeyWords->push_back("while");
			KeyWords->push_back("true");
			KeyWords->push_back("false");
			KeyWords->push_back("abstract");
			KeyWords->push_back("override");
			KeyWords->push_back("self");
			KeyWords->push_back("get");
			KeyWords->push_back("set");
			KeyWords->push_back("try");
			KeyWords->push_back("catch");
			KeyWords->push_back("finally");
			KeyWords->push_back("static");
			KeyWords->push_back("return");
			KeyWords->push_back("for");
			KeyWords->push_back("in");
			KeyWords->push_back("delegate");
			KeyWords->push_back("readonly");
			KeyWords->push_back("new");
			KeyWords->push_back("break");
			KeyWords->push_back("nil");
			KeyWords->push_back("extends");

			KeyWords->push_back("repeat");
			KeyWords->push_back("until");
			KeyWords->push_back("loopwhile");
			KeyWords->push_back("init");
			KeyWords->push_back("cfor");
			KeyWords->push_back("pairs");
			KeyWords->push_back("ipairs");
			KeyWords->push_back("with");
			KeyWords->push_back("const");

			KeyWords->push_back("constructor");
			KeyWords->push_back("destructor");
			KeyWords->push_back("infinity");
			KeyWords->push_back("defer");

			KeyWords->push_back("import");
			KeyWords->push_back("export");

			KeyWords->push_back("module");

			//KeyWords->push_back("foreach");
			B->Langs["neil"] = B;
			B->Language = "Neil";
		}
	}
}