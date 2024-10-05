// Lic:
// Kitty/Source/KittyHighINI.cpp
// Kitty High INI
// version: 24.10.05
// Copyright (C) 2019, 2023, 2024 Jeroen P. Broks
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
		static void INI_Show(_KittyHigh* SELF, String src, bool linenumbers = false) {
			src = StReplace(src, "\r\n", "\n");
			auto sh_lines = Split(src, '\n');
			auto lines{ *sh_lines };
			auto Console{ SELF->Console() };
			//WriteLine($"SOURCE>{lines.Length}/{lines[0]}");
			for (int i = 0; i < lines.size(); i++) {
				if (linenumbers) SELF->LineNumber(i + 1); //LineNumber(i + 1);
				auto line = Trim(lines[i]);
				if (line == "") {
					Console->WriteLine();
				} else if ((line[0] == '[' || line[line.size() - 1] == ']')) {
					if (!(line[0] == '[' && line[line.size() - 1] == ']')) {
						Console->ForegroundColor = KittyColors.Error;
					} else {
						Console->ForegroundColor = KittyColors.KeyWord;
						Console->WriteLine(lines[i]);
					}
				} else if (Trim(line)[0] == ';' || Trim(line)[0] == '#') {
					Console->ForegroundColor = KittyColors.Comment;
					Console->WriteLine(lines[i]);
				} else {
					auto isteken = IndexOf(lines[i], '=');
					if (isteken <= 0) isteken = IndexOf(lines[i], ':');
					if (isteken <= 0) {
						Console->ForegroundColor = KittyColors.Error; Console->WriteLine(lines[i]);
					} else {
						Console->ForegroundColor = KittyColors.Identifier;
						Console->Write(lines[i].substr(0, isteken));
						Console->ForegroundColor = KittyColors.Other;
						Console->Write(lines[i][isteken]);
						Console->ForegroundColor = KittyColors.String;
						Console->WriteLine(lines[i].substr(isteken + 1));
					}
				}
			}
		}

		void KittyHighINI() {
			static KittyHigh Me{ KittyHigh(new _KittyHigh()) };
			Me->Language = "Configuration File";
			Me->Langs["ini"] = Me;
			Me->abstract_Show = INI_Show;
		}
	}
}