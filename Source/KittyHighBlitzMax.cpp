// Lic:
// Kitty/Source/KittyHighBlitzMax.cpp
// Kitty High BlitzMax
// version: 24.10.05
// Copyright (C) 2019, 2020, 2023, 2024 Jeroen P. Broks
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
		void KittyBlitzMax() {
			static _KittyPL Me{};
            Me.caseinsensitive = true;
            Me.singcomment = "'";
            Me.escape = '~';
            auto KeyWords{ Me.KeyWords }, BaseTypes{ Me.BaseTypes };
            KeyWords->push_back("import");
            KeyWords->push_back("module");
            KeyWords->push_back("type");
            KeyWords->push_back("moduleinfo");
            KeyWords->push_back("public");
            KeyWords->push_back("private");
            KeyWords->push_back("extends");
            KeyWords->push_back("method");
            KeyWords->push_back("function");
            BaseTypes->push_back("string");
            BaseTypes->push_back("int");
            BaseTypes->push_back("byte");
            BaseTypes->push_back("long");
            KeyWords->push_back("select");
            KeyWords->push_back("case");
            KeyWords->push_back("default");
            KeyWords->push_back("goto"); // EEEEW!
            KeyWords->push_back("if");
            KeyWords->push_back("else");
            KeyWords->push_back("elseif");
            KeyWords->push_back("then");
            KeyWords->push_back("while");
            KeyWords->push_back("true");
            KeyWords->push_back("false");
            KeyWords->push_back("abstract");
            KeyWords->push_back("self");
            KeyWords->push_back("try");
            KeyWords->push_back("catch");
            KeyWords->push_back("finally");
            KeyWords->push_back("local");
            KeyWords->push_back("global");
            KeyWords->push_back("return");
            KeyWords->push_back("for");
            KeyWords->push_back("eachin");
            KeyWords->push_back("new");
            KeyWords->push_back("delete");
            KeyWords->push_back("break");
            KeyWords->push_back("null");
            KeyWords->push_back("field");
            KeyWords->push_back("include");
            KeyWords->push_back("incbin");
            KeyWords->push_back("framework");
            KeyWords->push_back("strict");
            KeyWords->push_back("superstrict");
            KeyWords->push_back("const");
            KeyWords->push_back("not");
            KeyWords->push_back("repeat");

            KeyWords->push_back("rem"); // Although I must set some things right here...

            // Endings
            KeyWords->push_back("end");
            KeyWords->push_back("endif");
            KeyWords->push_back("endfunction");
            KeyWords->push_back("endmethod");
            KeyWords->push_back("endtype");
            KeyWords->push_back("endrem");
            KeyWords->push_back("wend");
            KeyWords->push_back("next");
            KeyWords->push_back("until");
            KeyWords->push_back("forever");


            _KittyHigh::Langs["bmx"] = Me.Base;
            Me.Base->Language = "BlitzMax";
		}
	}
}