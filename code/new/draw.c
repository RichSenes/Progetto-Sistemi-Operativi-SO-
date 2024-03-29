#include "draw.h"

char *frog[] = {
    "            _     _" ,
    "           (')-=-(') " ,
    "         __(   '   )__ " ,
    "        / _|'-----'|_ \\ " ,
    "     ___\\\\ \\\\     // //___ " ,
    "     >____)|_|---|_|(____< "
};

char *good_croco[] = {
    "            .-._   _ _ _ _ _ _ _ _ ",
    " .-''-.__.-'v v '-' ' ' ' ' ' ' ' '-. ",
    "'.___ '    .   .--_'-' '-' '-' _'-' '._ ",
    " U: U '---'   '_   '.       .'  _..' '.'. ",
    "   '=.____.=_.--'   :_.__.__:_   '.   : : ",
    "           (((____.-'        '-.  /   : : ",
    "                             (((-'\\ .' / ",
    "                           _____..'  .' ",
    "                          '-._____.-' "
};

char *bad_croco[] = {
    "            \\-/._   _ _ _ _ _ _ _ _ ",
    " .-''-.__.-'o o '-' ' ' ' ' ' ' ' '-. ",
    "'.___ '    .   .--_'-' '-' '-' _'-' '._ ",
    " V: V 'vv-'   '_   '.       .'  _..' '.'. ",
    "   '=.____.=_.--'   :_.__.__:_   '.   : : ",
    "           <<<____.-'        '-.  /   : : ",
    "                             <<<-'\\ .' / ",
    "                           _____..'  .' ",
    "                          '-._____.-' "
};

char *open_hole[] = {
    "+------------------------+",
    "|                        |",
    "|                        |",
    "|                        |",
    "|                        |",
    "|                        |",
    "|                        |",
    "|                        |",
    "|                        |",
    "|                        |",
    "+------------------------+"
};

char *close_hole[] = {
    "+----+----+----+----+----+",
    "|    |    |    |    |    |",
    "|----+----+----+----+----|",
    "|    |    |    |    |    |",
    "|----+----+----+----+----|",
    "|    |    |    |    |    |",
    "|----+----+----+----+----|",
    "|    |    |    |    |    |",
    "|----+----+----+----+----|",
    "|    |    |    |    |    |",
    "+----+----+----+----+----+"
};

char *river[] = {
    ""
};

char *plant[] = {
    "               __/) ",
    "            .-(__(=: ",
    "            |    \\) ",
    "      (\\__  | ",
    "     :=)__)-|  __/) ",
    "      (/    |-(__(=: ",
    "    ______  |  _ \\) ",
    "   /      \\ | / \\ ",
    "        ___\\|/___\\ "
};

char *bullet[] = {
    " ____",
    "|____| ",
    "||  || ",
    "||  || ",
    "\\\\  // ",
    " \\\\// ",
    "  \\/"
};

char *spikes[] = {
    " ^ * ^ * ^ * ^ * ^ * ^ * ^",
    "* ^ * ^ * ^ * ^ * ^ * ^ * ",
    " ^ * ^ * ^ * ^ * ^ * ^ * ^",
    "* ^ * ^ * ^ * ^ * ^ * ^ * ",
    " ^ * ^ * ^ * ^ * ^ * ^ * ^",
    "* ^ * ^ * ^ * ^ * ^ * ^ * ",
    " ^ * ^ * ^ * ^ * ^ * ^ * ^",
    "* ^ * ^ * ^ * ^ * ^ * ^ * ",
    " ^ * ^ * ^ * ^ * ^ * ^ * ^",
    "* ^ * ^ * ^ * ^ * ^ * ^ * ",
    " ^ * ^ * ^ * ^ * ^ * ^ * ^"
};

char *mushroom [] = {
    "   _,=---=._", 
    ",'   _____  `.",   
    "{   {-O=O-}   }",   
    " '==-\\{_}/-=='",
    "     (( ))",        
    "    ()(.)()", 
    "   (((( ))))"  
};

char *game_title[] = {
    " _____ ____   ___   ____  ____ _____ ____  ____   ",
    "|  ___|  _ \\ / _ \\ / ___|/ ___| ____|  _ \\/ ___|  ",
    "| |_  | |_) | | | | |  _| |  _|  _| | |_) \\___ \\  ",
    "|  _| |  _ <| |_| | |_| | |_| | |___|  _ < ___) | ",
    "|_|   |_| \\_\\\\___/ \\____|\\____|_____|_| \\_\\____/  ",
    "                \\ \\   / / ___|                    ",
    "                 \\ \\ / /\\___ \\                    ",
    "                  \\ V /  ___) |                   ",
    "       ____  _     \\_/_ |____/ _ _____ ____       ",
    "      |  _ \\| |      / \\  | \\ | |_   _/ ___|      ",
    "      | |_) | |     / _ \\ |  \\| | | | \\___ \\      ",
    "      |  __/| |___ / ___ \\| |\\  | | |  ___) |     ",
    "      |_|   |_____/_/   \\_\\_| \\_| |_| |____/      "
};

void draw_game_title (ScreenSize screen) {
    mvprintw(screen.y / 2 - 10, screen.x / 2 - 49/2, " _____ ____   ___   ____  ____ _____ ____  ____      ");
    mvprintw(screen.y / 2 - 9,  screen.x / 2 - 49/2, "|  ___|  _ \\ / _ \\ / ___|/ ___| ____|  _ \\/ ___|  ");
    mvprintw(screen.y / 2 - 8,  screen.x / 2 - 49/2, "| |_  | |_) | | | | |  _| |  _|  _| | |_) \\___ \\   ");
    mvprintw(screen.y / 2 - 7,  screen.x / 2 - 49/2, "|  _| |  _ <| |_| | |_| | |_| | |___|  _ < ___) |    ");
    mvprintw(screen.y / 2 - 6,  screen.x / 2 - 49/2, "|_|   |_| \\_\\\\___/ \\____|\\____|_____|_| \\_\\____/  ");
    mvprintw(screen.y / 2 - 5,  screen.x / 2 - 49/2, "                \\ \\   / / ___|                    ");
    mvprintw(screen.y / 2 - 4,  screen.x / 2 - 49/2, "                 \\ \\ / /\\___ \\                    ");
    mvprintw(screen.y / 2 - 3,  screen.x / 2 - 49/2, "                  \\ V /  ___) |                   ");
    mvprintw(screen.y / 2 - 2,  screen.x / 2 - 49/2, "      ____  _      \\_/ |____/ _ _____ ____       ");
    mvprintw(screen.y / 2 - 1,  screen.x / 2 - 49/2, "     |  _ \\| |      / \\  | \\ | |_   _/ ___|      ");
    mvprintw(screen.y / 2 - 0,  screen.x / 2 - 49/2, "     | |_) | |     / _ \\ |  \\| | | | \\___ \\      ");
    mvprintw(screen.y / 2 + 1,  screen.x / 2 - 49/2, "     |  __/| |___ / ___ \\| |\\  | | |  ___) |     ");
    mvprintw(screen.y / 2 + 2,  screen.x / 2 - 49/2, "     |_|   |_____/_/   \\_\\_| \\_| |_| |____/      ");
}