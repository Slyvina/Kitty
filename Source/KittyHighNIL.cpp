// Lic:
// Kitty/Source/KittyHighNIL.cpp
// Kitty High NIL Isn't Lua
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
		void KittyHighNIL() {
            static _KittyPL Me{};
            // Not complete yet, but for now this will do!
            Me.BaseTypes->push_back("table");
            Me.BaseTypes->push_back("void");
            Me.BaseTypes->push_back("string");
            Me.BaseTypes->push_back("int");
            Me.BaseTypes->push_back("bool");
            Me.BaseTypes->push_back("var");
            Me.KeyWords->push_back("not");
            Me.KeyWords->push_back("class");
            Me.KeyWords->push_back("group");
            Me.KeyWords->push_back("module");
            Me.KeyWords->push_back("global");
            Me.KeyWords->push_back("private");
            Me.KeyWords->push_back("end");
            Me.KeyWords->push_back("and");
            Me.KeyWords->push_back("or");
            Me.KeyWords->push_back("quickmeta");
            Me.KeyWords->push_back("switch");
            Me.KeyWords->push_back("case");
            Me.KeyWords->push_back("default");
            // Me.KeyWords->push_back("goto"); // EEEEW!
            Me.KeyWords->push_back("if");
            Me.KeyWords->push_back("else");
            Me.KeyWords->push_back("elseif");
            Me.KeyWords->push_back("do");
            Me.KeyWords->push_back("while");
            Me.KeyWords->push_back("true");
            Me.KeyWords->push_back("false");
            Me.KeyWords->push_back("abstract");
            Me.KeyWords->push_back("override");
            Me.KeyWords->push_back("self");
            Me.KeyWords->push_back("get");
            Me.KeyWords->push_back("set");
            Me.KeyWords->push_back("try");
            Me.KeyWords->push_back("catch");
            Me.KeyWords->push_back("finally");
            Me.KeyWords->push_back("static");
            Me.KeyWords->push_back("return");
            Me.KeyWords->push_back("for");
            Me.KeyWords->push_back("in");
            Me.KeyWords->push_back("delegate");
            Me.KeyWords->push_back("readonly");
            Me.KeyWords->push_back("new");
            Me.KeyWords->push_back("break");
            Me.KeyWords->push_back("nil");
            Me.KeyWords->push_back("extends");

            Me.KeyWords->push_back("CONSTRUCTOR");
            Me.KeyWords->push_back("DESTRUCTOR");

            //Me.KeyWords->push_back("foreach");
            _KittyHigh::Langs["nil"] = Me.Base;
            Me.Base->Language = "NIL isn't Lua";
        }


    

    void KittyHighLua() {
        static _KittyPL Me{};
            // Not complete yet, but for now this will do!
            Me.KeyWords->push_back("local");
            Me.KeyWords->push_back("end");
            Me.KeyWords->push_back("function");
            Me.KeyWords->push_back("goto"); // EEEEW!
            Me.KeyWords->push_back("if");
            Me.KeyWords->push_back("else");
            Me.KeyWords->push_back("elseif");
            Me.KeyWords->push_back("do");
            Me.KeyWords->push_back("while");
            Me.KeyWords->push_back("true");
            Me.KeyWords->push_back("false");
            Me.KeyWords->push_back("return");
            Me.KeyWords->push_back("for");
            Me.KeyWords->push_back("in");
            Me.KeyWords->push_back("break");
            Me.KeyWords->push_back("nil");
            Me.KeyWords->push_back("or");
            Me.KeyWords->push_back("and");
            Me.KeyWords->push_back("not");
            _KittyHigh::Langs["lua"] = Me.Base;
            Me.Base->Language = "Lua";
            Me.singcomment = "--";
            Me.mulcomment = true;
            Me.mulcommentstart = "--[[";
            Me.mulcommentend = "]]";
            Me.KeyWords->push_back("not");

		}
	}
}