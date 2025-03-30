#pragma once

#include <string>
#include <vector>
#include <iostream>



std::vector<std::vector<int>> map_editor() {
    std::vector<std::vector<bool>> map(100)(100);
    bool tmp;
    int cx, cy;

    bool is_runing = true;
    for (int iy = 0; is_runing; ++iy) {
        for (int ix = 0; is_runing; ++ix) {
            std::cin >> tmp;
            switch (tmp) {
                case ' ': // Ставит пустоту
                    map[iy][ix] = 0;
                    break;
                case '0': // Ставит пустоту
                    map[iy][ix] = 0;
                    break;
                case '1': // Ставит клетку
                    map[iy][ix] = 1;
                    break;
                case 'n': // Перенос на новую строку
                    ++iy;
                    ix=-1;
                    break;
                case 'h': // Перенос на нулевые координаты
                    ix = -1; iy = 0;
                    break;
                case 'r': // Перенос в начало строки
                    ix=-1;
                    break;
                case 'e': // Досрочное завершение
                    is_runing=false;
                    break;
                case 'w': // Перемещение вверх
                    --iy; --ix;
                    break;
                case 'a': // Перемещение вправо
                    ----ix;
                    break;
                case 's': // Перемещение вниз
                    ++iy; --ix;
                    break;
                case 'd': // Перемещение вправо
                    break;
                case 'c': // Скопировать положение коретки
                    --ix;
                    cy = iy; cx = ix;
                    break;
                case 'p': // переместить коретку в точку копирования
                    iy = cy; ix = cx;
                    break;
                case '\0': // Досрочное завершение
                    is_runing = false;
                    break;
                default: // Перемещение вправо
                    break;
            }
        }
    }
}