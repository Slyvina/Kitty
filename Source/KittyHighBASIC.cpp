// Lic:
// Kitty/Source/KittyHighBASIC.cpp
// Kitty High BASIC
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


#include <Kitty_High.hpp>


namespace Slyvina {
    namespace Kitty {
        void KittyHighBASIC() {
            static _KittyPL Me{};
            auto B{ Me.Base };
            auto KeyWords{ Me.KeyWords };
            B->Language = "Beginners Allpurpose Symbolic Instruction Code (BASIC)";
            B->Langs["bas"] = B;
            Me.singcomment = "'";
            Me.mulcomment = false;
            Me.caseinsensitive = true;
            KeyWords->push_back("if");
            KeyWords->push_back("else");
            KeyWords->push_back("elseif");
            KeyWords->push_back("then");
            KeyWords->push_back("endif");
            KeyWords->push_back("while");
            KeyWords->push_back("wend");
            KeyWords->push_back("for");
            KeyWords->push_back("to");
            KeyWords->push_back("step");
            KeyWords->push_back("next");
            KeyWords->push_back("do");
            KeyWords->push_back("loop");
            KeyWords->push_back("until");
            KeyWords->push_back("function");
            KeyWords->push_back("sub");
            KeyWords->push_back("end");
            KeyWords->push_back("dim");
            KeyWords->push_back("def");
            KeyWords->push_back("as");
            KeyWords->push_back("redim");
            KeyWords->push_back("type");
            KeyWords->push_back("select");
            KeyWords->push_back("case");
            KeyWords->push_back("declare");
            KeyWords->push_back("const");
            // Common functions, often serving as keywords
            KeyWords->push_back("input");
            KeyWords->push_back("out");
            KeyWords->push_back("poke");
            KeyWords->push_back("peek");
            KeyWords->push_back("using");
            KeyWords->push_back("print");
            KeyWords->push_back("cls");
        }
    }
}