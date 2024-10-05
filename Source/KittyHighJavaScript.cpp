// Lic:
// Kitty/Source/KittyHighJavaScript.cpp
// Kitty High JavaScript
// version: 24.10.05
// Copyright (C) 2019, 2024 Jeroen P. Broks
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

        static void KittyHighJSON() {
            static _KittyPL Me{};
            Me.supcom = false;
            Me.Base->Language = "JSON";
            Me.Base->Langs["json"] = Me.Base;
            Me.KeyWords->push_back("true");
            Me.KeyWords->push_back("false");
            Me.KeyWords->push_back("null");
        }

        void KittyHighJavaScript() {
            static _KittyPL Me{};
            auto KeyWords{ Me.KeyWords }, BaseTypes{ Me.BaseTypes };
            // JavaScript is due to it's lack of thinking things true from the start, cursed with more changes in a short time
            // than any other programming lanuage I can think of. I hope this list is up-to-date, and I know some keywords have been removed, but 
            // I cannot care less, as keeping this up to date is undoable.
            KeyWords->push_back("abstract");
            KeyWords->push_back("arguments");
            KeyWords->push_back("await");
            KeyWords->push_back("boolean");
            KeyWords->push_back("break");
            KeyWords->push_back("byte");
            KeyWords->push_back("case");
            KeyWords->push_back("catch");
            KeyWords->push_back("char");
            KeyWords->push_back("class");
            KeyWords->push_back("const");
            KeyWords->push_back("continue");
            KeyWords->push_back("debugger");
            KeyWords->push_back("default");
            KeyWords->push_back("delete");
            KeyWords->push_back("do");
            KeyWords->push_back("double");
            KeyWords->push_back("else");
            KeyWords->push_back("enum");
            KeyWords->push_back("eval");
            KeyWords->push_back("export");
            KeyWords->push_back("extends");
            KeyWords->push_back("false");
            KeyWords->push_back("final");
            KeyWords->push_back("finally");
            KeyWords->push_back("float");
            KeyWords->push_back("for");
            KeyWords->push_back("function");
            KeyWords->push_back("goto");
            KeyWords->push_back("if");
            KeyWords->push_back("implements");
            KeyWords->push_back("import");
            KeyWords->push_back("in");
            KeyWords->push_back("instanceof");
            KeyWords->push_back("int");
            KeyWords->push_back("interface");
            KeyWords->push_back("let");
            KeyWords->push_back("long");
            KeyWords->push_back("native");
            KeyWords->push_back("new");
            KeyWords->push_back("null");
            KeyWords->push_back("package");
            KeyWords->push_back("private");
            KeyWords->push_back("protected");
            KeyWords->push_back("public");
            KeyWords->push_back("return");
            KeyWords->push_back("short");
            KeyWords->push_back("static");
            KeyWords->push_back("super");
            KeyWords->push_back("switch");
            KeyWords->push_back("synchronized");
            KeyWords->push_back("this");
            KeyWords->push_back("throw");
            KeyWords->push_back("throws");
            KeyWords->push_back("transient");
            KeyWords->push_back("true");
            KeyWords->push_back("try");
            KeyWords->push_back("typeof");
            KeyWords->push_back("var");
            KeyWords->push_back("void");
            KeyWords->push_back("volatile");
            KeyWords->push_back("while");
            KeyWords->push_back("with");
            KeyWords->push_back("yield");
            Me.Base->Language = "JavaScript";
            Me.Base->Langs["js"] = Me.Base;
            KittyHighJSON();
        }
    }

}