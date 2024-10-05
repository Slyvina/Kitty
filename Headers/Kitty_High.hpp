// Lic:
// Kitty/Headers/Kitty_High.hpp
// Kitty High (header)
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

#pragma once

#include <SlyvQCol.hpp>

namespace Slyvina {
    namespace Kitty {

#pragma region "Class to shared pointer.
        // Remember this is just manually translated C# code, and C# only uses pointers for classes and has automated garbage collection.
        // C++ has none of that.
#define KittyClass(real,pseudo) class real; typedef std::shared_ptr<real> pseudo;
        KittyClass(_KittyOutput, KittyOutput);
        KittyClass(_KittyHigh, KittyHigh);
        class _KittyPL;
        class _KittyMarkup;



        typedef void (*KittyOutputVoidString)(_KittyOutput*, std::string);
        typedef void (*KittyOutputShow)(_KittyHigh* SELF,std::string src, bool linenumbers);
#pragma region


        struct _KittyColors {
            Units::qColor
                KeyWord = Units::qColor::Yellow,
                Identifier = Units::qColor::White,
                Number = Units::qColor::Cyan,
                String = Units::qColor::Green,
                Comment = Units::qColor::DarkGrey,
                LineNumbers = Units::qColor::DarkGrey,
                Other = Units::qColor::Grey,
                Error = Units::qColor::Red,
                Attribute = Units::qColor::Blue,
                BaseType = Units::qColor::Magenta;
        };
        _KittyColors KittyColors;

        
        class _KittyOutput {
        public:
            ~_KittyOutput() {
                //Console.ResetColor();
                QCol->Reset();
            }
            /* Due to bad experiences with abstract methods (or virutals as they are called in C++), I'll do this a different way
            abstract public void Write(std::string a);
            abstract public void WriteLine(std::string a);
            */
            KittyOutputVoidString abstract_Write{ nullptr };
            KittyOutputVoidString abstract_WriteLine{ nullptr };
            inline void Write(std::string a) { if (!abstract_Write) throw std::runtime_error("abstract_Write not set!"); abstract_Write(this, a); }
            inline void WriteLine(std::string a) { if (!abstract_WriteLine) throw std::runtime_error("abstract_Write not set!"); abstract_WriteLine(this, a); }
            inline void WriteLine() { WriteLine(""); }
            inline void Write(char c) { char ca[2]{ c,0 }; Write(ca); } // Dirty, but what works that works!
            /* Due to lack of a proper cross platform way to do this in C++ , this will be kept on hold.
            public ConsoleKeyInfo ReadKey() = > Console.ReadKey();
            public ConsoleKeyInfo ReadKey(bool b) = > Console.ReadKey(b);
            */
            void ResetColor();
            // I don't expect to need this, and if I do, I might to go a different approach as this is too reliant on C#'s approach
            //public void Write(object a) = > Write($"{a}");
            // public void WriteLine(object a) = > WriteLine($"{a}");
            Units::qColor ForegroundColor{ Units::qColor::Grey };
            Units::qColor BackgroundColor{ Units::qColor::Black };
            int WindowHeight = 25;
        };

        //class KittyCLI :KittyOutput {
        KittyOutput KittyCLI();
        

        class _KittyHigh {
        private:
            static KittyOutput _ko;
            //std::string _Language{ "" };
            //inline void Language(std::string L) { _Language = L; }
        public:
            static std::map<std::string, KittyHigh> Langs; //static readonly public SortedDictionary<std::string, KittyHigh> Langs = new SortedDictionary<std::string, KittyHigh>();

            static int NumLines();
            static int PagLines;
            static bool BrkLines;
            static KittyOutput Console();
            static void Console(KittyOutput ko);


            static void PageBreak();

            inline static void WriteLine(std::string a = "") {
                Console()->WriteLine(a);
                PageBreak();
            }

            //public abstract void Show(std::string src, bool linenumbers = false);
            KittyOutputShow abstract_Show{ nullptr };
            void Show(std::string src, bool linenumbers = false);
            //public void Show(std::stringBuilder src, bool linenumbers = false) = > Show(src, linenumbers);
            std::string Language{ "" }; //inline std::string Language() { return _Language; }
            static void LineNumber(int ln);

            static void Init();
            _KittyPL* PLKid{ nullptr };
            _KittyMarkup* MLKid{ nullptr };
        };


        class _KittyPL { //: KittyHigh {
        public:
            KittyHigh Base{ std::shared_ptr<_KittyHigh>(new _KittyHigh()) };
            VecString KeyWords = NewVecString(); //protected List<std::string> KeyWords = new List<std::string>();
            VecString BaseTypes = NewVecString(); //List<std::string> BaseTypes = new List<std::string>();
            std::string stringstart = "\"";
            std::string stringend = "\"";
            std::string stringstart = "@\"";
            std::string stringend = "\"";
            std::string stringstart = "'";
            std::string astringend = "'";
            std::string singcomment = "//";
            std::string mulcommentstart = "/*";
            std::string mulcommentend = "*/";
            char escape = '\\';
            bool mulcomment = true;
            bool mulcommentfullline = false; // Needed for BlitzMax where commands taking up a full line are used for multi line comments. This is not entirely fool-proof, but it'll have to do.
            bool caseinsensitive = false;
            bool supcom = true;

            _KittyPL();

        };
        

        /* No longer needed as class, but a few things need to be set in order nonetheless
        class KittyNiks : KittyHigh {
            public KittyNiks() { Language = "Unrecognized"; }
            public override void Show(std::string src, bool linenumbers = false) {
                src = src.Replace("\r\n", "\n");
                var lines = src.Split('\n');
                for (int i = 0; i < lines.Length; i++) {
                    if (linenumbers) LineNumber(i + 1);
                    Console.ForegroundColor = KittyColors.Other; WriteLine(lines[i]);
                }
            }
        }
        */
        KittyHigh KittyNiks();

        // Markup support by freezernick (translated to C++ by Jeroen P. Broks)
        class _KittyMarkup {      
        public:
            KittyHigh Base{ std::shared_ptr<_KittyHigh>(new _KittyHigh()) };
            std::string stringstart = "\"";
            std::string stringend = "\"";
            bool mulcomment = true;
            std::string mulcommentstart = "<!--";
            std::string mulcommentend = "-->";
            std::string opentagchar = "<";
            std::string closetagchar = ">";
            std::string endtagchar = "/>";
            char escape = '\\';

            _KittyMarkup();
        };
    }
}