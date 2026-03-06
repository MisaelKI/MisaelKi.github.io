#include <emscripten/emscripten.h>

extern "C" {

EMSCRIPTEN_KEEPALIVE
int hitungStatus(int ph_score, int kelembapan_score, int kerusakan_score) {
    int total = ph_score + kelembapan_score + kerusakan_score;
    if (total >= 3 && total <= 4) return 1; 
    if (total >= 5 && total <= 7) return 2; 
    if (total >= 8 && total <= 9) return 3; 
    return 0;
}

EMSCRIPTEN_KEEPALIVE
int hitungTotal(int ph_score, int kelembapan_score, int kerusakan_score) {
    return ph_score + kelembapan_score + kerusakan_score;
}

EMSCRIPTEN_KEEPALIVE
int phKeScore(float ph) {
    if (ph < 5 || ph > 8) return 3; 
    if (ph >= 5 && ph <= 6) return 2; 
    if (ph == 7) return 1;
    return 1;
}

}
