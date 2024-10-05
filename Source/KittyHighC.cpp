// Lic:
// Kitty/Source/KittyHighC.cpp
// Kitty High C and C++
// version: 24.10.05
// Copyright (C) 2019, 2020, 2023 Jeroen P. Broks
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
		void KittyHighC() {
			static _KittyPL Me{};

		



			_KittyHigh::Langs["c"] = Me.Base;
						_KittyHigh::Langs["h"] = Me.Base;
									_KittyHigh::Langs["cpp"] = Me.Base;
												_KittyHigh::Langs["hpp"] = Me.Base;
															Me.Base->Language = "C/C++";

			auto
				BaseTypes{ Me.BaseTypes },
				KeyWords{ Me.KeyWords };
			KeyWords->push_back("void");
			BaseTypes->push_back("bool");
			BaseTypes->push_back("auto");
			BaseTypes->push_back("char");
			BaseTypes->push_back("int");
			KeyWords->push_back("asm");
			KeyWords->push_back("else");
			KeyWords->push_back("new");
			KeyWords->push_back("this");
			KeyWords->push_back("enum");
			KeyWords->push_back("operator");
			KeyWords->push_back("throw");
			KeyWords->push_back("explicit");
			KeyWords->push_back("private");
			KeyWords->push_back("true");
			KeyWords->push_back("break");
			KeyWords->push_back("export");
			KeyWords->push_back("protected");
			KeyWords->push_back("try");
			KeyWords->push_back("case");
			KeyWords->push_back("extern");
			KeyWords->push_back("public");
			KeyWords->push_back("typedef");
			KeyWords->push_back("catch");
			KeyWords->push_back("false");
			KeyWords->push_back("register");
			KeyWords->push_back("typeid");
			KeyWords->push_back("float");
			KeyWords->push_back("reinterpret_cast");
			KeyWords->push_back("typename");
			KeyWords->push_back("class");
			KeyWords->push_back("for");
			KeyWords->push_back("return");
			KeyWords->push_back("union");
			KeyWords->push_back("const");
			KeyWords->push_back("friend");
			KeyWords->push_back("short");
			KeyWords->push_back("unsigned");
			KeyWords->push_back("const_cast");
			KeyWords->push_back("goto");
			KeyWords->push_back("signed");
			KeyWords->push_back("using");
			KeyWords->push_back("continue");
			KeyWords->push_back("if");
			KeyWords->push_back("sizeof");
			KeyWords->push_back("virtual");
			KeyWords->push_back("default");
			KeyWords->push_back("inline");
			KeyWords->push_back("static");
			KeyWords->push_back("delete");
			KeyWords->push_back("static_cast");
			KeyWords->push_back("volatile");
			KeyWords->push_back("do");
			KeyWords->push_back("long");
			KeyWords->push_back("struct");
			KeyWords->push_back("wchar_t");
			KeyWords->push_back("double");
			KeyWords->push_back("mutable");
			KeyWords->push_back("switch");
			KeyWords->push_back("while");
			KeyWords->push_back("dynamic_cast");
			KeyWords->push_back("namespace");
			KeyWords->push_back("template");
		}

	}