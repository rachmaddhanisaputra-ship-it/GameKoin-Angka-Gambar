#include <iostream>
#include <cstdlib>
#include <ctime>
#include <ncurses.h>

using namespace std;

int main() {
    srand(time(0));

    initscr();
    cbreak();
    noecho();

    start_color();
    init_pair(1, COLOR_CYAN, COLOR_BLACK);
    init_pair(2, COLOR_GREEN, COLOR_BLACK);
    init_pair(3, COLOR_RED, COLOR_BLACK);
    init_pair(4, COLOR_YELLOW, COLOR_BLACK);

    int menu;
    int pilihan;
    int hasil;

    while (true) {
        clear();

        attron(COLOR_PAIR(1));
        mvprintw(2, 10, "==============================");
        mvprintw(3, 10, "     GAME KOIN ANGKA/GAMBAR");
        mvprintw(4, 10, "==============================");
        attroff(COLOR_PAIR(1));

        mvprintw(7, 10, "1. Mulai Permainan");
        mvprintw(8, 10, "2. Petunjuk");
        mvprintw(9, 10, "3. Keluar");

        mvprintw(12, 10, "Pilih menu (1-3): ");
        refresh();

        menu = getch();

        if (menu == '1') {
            clear();

            attron(COLOR_PAIR(1));
            mvprintw(2, 10, "=== LEMPAR KOIN ===");
            attroff(COLOR_PAIR(1));

            mvprintw(5, 10, "Pilih sisi koin:");
            mvprintw(7, 10, "1. ANGKA");
            mvprintw(8, 10, "2. GAMBAR");
            mvprintw(11, 10, "Pilihan kamu: ");
            refresh();

            pilihan = getch();

            if (pilihan != '1' && pilihan != '2') {
                mvprintw(14, 10, "Pilihan tidak valid!");
                mvprintw(16, 10, "Tekan tombol untuk kembali.");
                refresh();
                getch();
                continue;
            }

            hasil = rand() % 2 + 1;

            clear();

            mvprintw(3, 10, "Pilihan kamu : %s",
                     pilihan == '1' ? "ANGKA" : "GAMBAR");

            mvprintw(5, 10, "Hasil koin   : %s",
                     hasil == 1 ? "ANGKA" : "GAMBAR");

            if ((pilihan - '0') == hasil) {
                attron(COLOR_PAIR(2));
                mvprintw(9, 10, "ANDA MENANG!");
                attroff(COLOR_PAIR(2));
            } else {
                attron(COLOR_PAIR(3));
                mvprintw(9, 10, "ANDA KALAH!");
                attroff(COLOR_PAIR(3));
            }

            mvprintw(13, 10, "Tekan tombol untuk kembali.");
            refresh();
            getch();
        }

        else if (menu == '2') {
            clear();

            attron(COLOR_PAIR(4));
            mvprintw(2, 10, "=== PETUNJUK PERMAINAN ===");
            attroff(COLOR_PAIR(4));

            mvprintw(5, 10, "1. Pilih ANGKA atau GAMBAR.");
            mvprintw(6, 10, "2. Komputer akan mengacak koin.");
            mvprintw(7, 10, "3. Cocokkan pilihan dengan hasil.");
            mvprintw(8, 10, "4. Jika cocok, kamu menang.");

            mvprintw(12, 10, "Tekan tombol untuk kembali.");
            refresh();
            getch();
        }

        else if (menu == '3') {
            break;
        }
    }

    clear();
    mvprintw(10, 10, "TERIMA KASIH SUDAH BERMAIN!");
    refresh();
    getch();

    endwin();

    return 0;
}