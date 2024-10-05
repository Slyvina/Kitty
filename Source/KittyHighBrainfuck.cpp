// Lic:
// Kitty/Source/KittyHighBrainfuck.cpp
// Kitty High Brainfuck
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
#include <SlyvString.hpp>
using namespace Slyvina::Units;

namespace Slyvina {
	namespace Kitty {
		static void BrainFuck_Show(_KittyHigh* SELF, String src, bool linenumbers = false) {
			src = StReplace(src, "\r\n", "\n");
			auto lines{ Split(src,'\n') };
			auto Console{ SELF->Console() };
			//Console.WriteLine($"SOURCE>{lines.Length}/{lines[0]}");
			for (int i = 0; i < lines->size(); i++) {
				if (linenumbers) SELF->LineNumber(i + 1);
				for (int p = 0; p < (*lines)[i].size(); p++) {
					switch ((*lines)[i][p]) {
					case '+':
					case '-':
						Console->ForegroundColor = KittyColors.Number;
						break;
					case '.':
					case ',':
						Console->ForegroundColor = KittyColors.String;
						break;
					case '<':
					case '>':
						Console->ForegroundColor = KittyColors.Identifier;
						break;
					case '[':
					case ']':
						Console->ForegroundColor = KittyColors.KeyWord;
						break;
					default:
						Console->ForegroundColor = KittyColors.Comment;
						break;
					}
					Console->Write((*lines)[i][p]);
				}
				SELF->WriteLine();
			}
		}

		void KittyHighBrainFuck() {
			auto BF{ std::shared_ptr<_KittyHigh>(new _KittyHigh()) };
			BF->Langs["bf"] = BF;
			BF->Language = "Brainfuck";
			BF->abstract_Show = BrainFuck_Show;
		}
	}
}