// Lic:
// Kitty/Source/KittyHighPython.cpp
// Kitty High Python
// version: 24.10.05
// Copyright (C) 2019 Jeroen P. Broks
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
#include <High_Headers.hpp>
#include <Kitty_High.hpp>

void Slyvina::Kitty::KittyHighPython() {
	static _KittyPL Me{};
	auto BaseTypes{ Me.BaseTypes }, KeyWords{ Me.KeyWords };
	auto B{ Me.Base };
	KeyWords->push_back("False");
	KeyWords->push_back("class");
	KeyWords->push_back("finally");
	KeyWords->push_back("is");
	KeyWords->push_back("return");
	KeyWords->push_back("None");
	KeyWords->push_back("continue");
	KeyWords->push_back("for");
	KeyWords->push_back("lambda");
	KeyWords->push_back("try");
	KeyWords->push_back("True");
	KeyWords->push_back("def");
	KeyWords->push_back("from");
	KeyWords->push_back("nonlocal");
	KeyWords->push_back("while");
	KeyWords->push_back("and");
	KeyWords->push_back("del");
	KeyWords->push_back("global");
	KeyWords->push_back("not");
	KeyWords->push_back("with");
	KeyWords->push_back("as");
	KeyWords->push_back("elif");
	KeyWords->push_back("if");
	KeyWords->push_back("or");
	KeyWords->push_back("yield");
	KeyWords->push_back("assert");
	KeyWords->push_back("else");
	KeyWords->push_back("import");
	KeyWords->push_back("pass");
	KeyWords->push_back("break");
	KeyWords->push_back("except");
	KeyWords->push_back("in");
	KeyWords->push_back("raise");
	Me.mulcomment = false;
	Me.singcomment = "#";
	B->Language = "Python";
	B->Langs["py"] = B;
}