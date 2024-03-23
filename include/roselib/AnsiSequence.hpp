/* ************************************************************************** */
/*         .-.                                                                */
/*   __   /   \   __                                                          */
/*  (  `'.\   /.'`  )  AnsiSequence.hpp                                       */
/*   '-._.(;;;)._.-'                                                          */
/*   .-'  ,`"`,  '-.                                                          */
/*  (__.-'/   \'-.__)  By: Rosie (https://github.com/BlankRose)               */
/*      //\   /        Last Updated: March 23, 2024 [09:02 pm]                */
/*     ||  '-'                                                                */
/* ************************************************************************** */

#pragma once

/// Defines all various terminal colors available for usage,
/// but those may not works properly depending on terminals'
/// ANSI escape codes supports.
///
/// Wiki:    https://en.wikipedia.org/wiki/ANSI_escape_code
/// Source:  https://gist.github.com/fnky/458719343aabd01cfb17a3a4f7296797

#define ANSI_ESC                        "\033["
#define ANSI_RESET_ALL                  "0m"
#define ANSI_RESET                      ANSI_RESET_ALL

/// STYLES
///
/// Definitions of most available ANSI output styling options

#define ANSI_BOLD                       ANSI_ESC"1m"
#define ANSI_FAINT                      ANSI_ESC"2m"
#define ANSI_ITALIC                     ANSI_ESC"3m"
#define ANSI_UNDERLINE                  ANSI_ESC"4m"
#define ANSI_BLINK                      ANSI_ESC"5m"
#define ANSI_INVERSE                    ANSI_ESC"7m"
#define ANSI_INVISIBLE                  ANSI_ESC"8m"
#define ANSI_STRIKE                     ANSI_ESC"9m"

#define ANSI_NORMAL                     ANSI_ESC"22m"
#define ANSI_NO_ITALIC                  ANSI_ESC"23m"
#define ANSI_NO_UNDERLINE               ANSI_ESC"24m"
#define ANSI_NO_BLINK                   ANSI_ESC"25m"
#define ANSI_NO_INVERSE                 ANSI_ESC"27m"
#define ANSI_VISIBLE                    ANSI_ESC"28m"
#define ANSI_NO_STRIKE                  ANSI_ESC"29m"
#define ANSI_RESET_STYLE                ANSI_ESC"22;23;24;25;27;28;29m"

/// COLORING
///
/// Definitions of most available ANSI output coloring
/// features. Might need to check if the terminals
/// support true colors for some of them
///
/// @note   Some terminals might change these colors,
///         or allow users to customize the colors within
///         their configurations. ANSI_ID and ANSI_RGB are
///         usually unaffected by these changes

#define ANSI_FG_GREY                    ANSI_ESC"90m"
#define ANSI_FG_BLACK                   ANSI_ESC"30m"
#define ANSI_FG_RED                     ANSI_ESC"31m"
#define ANSI_FG_GREEN                   ANSI_ESC"32m"
#define ANSI_FG_YELLOW                  ANSI_ESC"33m"
#define ANSI_FG_BLUE                    ANSI_ESC"34m"
#define ANSI_FG_MAGENTA                 ANSI_ESC"35m"
#define ANSI_FG_CYAN                    ANSI_ESC"36m"
#define ANSI_FG_WHITE                   ANSI_ESC"37m"

#define ANSI_BG_GREY                    ANSI_ESC"100m"
#define ANSI_BG_BLACK                   ANSI_ESC"40m"
#define ANSI_BG_RED                     ANSI_ESC"41m"
#define ANSI_BG_GREEN                   ANSI_ESC"42m"
#define ANSI_BG_YELLOW                  ANSI_ESC"43m"
#define ANSI_BG_BLUE                    ANSI_ESC"44m"
#define ANSI_BG_MAGENTA                 ANSI_ESC"45m"
#define ANSI_BG_CYAN                    ANSI_ESC"46m"
#define ANSI_BG_WHITE                   ANSI_ESC"47m"

#define ANSI_FG_LIGHT_BLACK             ANSI_ESC"90m"
#define ANSI_FG_LIGHT_RED               ANSI_ESC"91m"
#define ANSI_FG_LIGHT_GREEN             ANSI_ESC"92m"
#define ANSI_FG_LIGHT_YELLOW            ANSI_ESC"93m"
#define ANSI_FG_LIGHT_BLUE              ANSI_ESC"94m"
#define ANSI_FG_LIGHT_MAGENTA           ANSI_ESC"95m"
#define ANSI_FG_LIGHT_CYAN              ANSI_ESC"96m"
#define ANSI_FG_LIGHT_WHITE             ANSI_ESC"97m"

#define ANSI_BG_LIGHT_BLACK             ANSI_ESC"100m"
#define ANSI_BG_LIGHT_RED               ANSI_ESC"101m"
#define ANSI_BG_LIGHT_GREEN             ANSI_ESC"102m"
#define ANSI_BG_LIGHT_YELLOW            ANSI_ESC"103m"
#define ANSI_BG_LIGHT_BLUE              ANSI_ESC"104m"
#define ANSI_BG_LIGHT_MAGENTA           ANSI_ESC"105m"
#define ANSI_BG_LIGHT_CYAN              ANSI_ESC"106m"
#define ANSI_BG_LIGHT_WHITE             ANSI_ESC"107m"

#define ANSI_FG_ID(id)                  ANSI_ESC"38;5;"#id"m"
#define ANSI_BG_ID(id)                  ANSI_ESC"48;5;"#id"m"
#define ANSI_FG_RGB(red, green, blue)   ANSI_ESC"38;2;"#red";"#green";"#blue"m"
#define ANSI_BG_RGB(red, green, blue)   ANSI_ESC"48;2;"#red";"#green";"#blue"m"

#define ANSI_FG_DEFAULT                 ANSI_ESC"39m"
#define ANSI_BG_DEFAULT                 ANSI_ESC"49m"
#define ANSI_RESET_FG                   ANSI_FG_DEFAULT
#define ANSI_RESET_BG                   ANSI_BG_DEFAULT

/// SPECIALS
///
/// Definitions which can comes in handy for terminal-only programms,
/// though they might only be implement in the most recent terminals!
/// Use with precaution

#define ANSI_ERASE_TO_END               ANSI_ESC"0J"
#define ANSI_ERASE_TO_BEGIN             ANSI_ESC"1J"
#define ANSI_ERASE_VIEW                 ANSI_ESC"2J"
#define ANSI_ERASE_TO_ENDLN             ANSI_ESC"0K"
#define ANSI_ERASE_TO_BEGINLN           ANSI_ESC"1K"
#define ANSI_ERASE_LINE                 ANSI_ESC"2K"

#define ANSI_SHOW_CURSOR                ANSI_ESC"?25h"
#define ANSI_HIDE_CURSOS                ANSI_ESC"?25l"
