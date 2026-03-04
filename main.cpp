#include <emscripten/emscripten.h>

extern "C" {

// Returns: 1 = AMAN, 2 = WASPADA, 3 = KRITIS
EMSCRIPTEN_KEEPALIVE
int hitungStatus(int ph_score, int kelembapan_score, int kerusakan_score) {
    int total = ph_score + kelembapan_score + kerusakan_score;
    if (total >= 3 && total <= 4) return 1; // AMAN
    if (total >= 5 && total <= 7) return 2; // WASPADA
    if (total >= 8 && total <= 9) return 3; // KRITIS
    return 0; // invalid
}

EMSCRIPTEN_KEEPALIVE
int hitungTotal(int ph_score, int kelembapan_score, int kerusakan_score) {
    return ph_score + kelembapan_score + kerusakan_score;
}

// Convert pH value to score
EMSCRIPTEN_KEEPALIVE
int phKeScore(float ph) {
    if (ph < 5 || ph > 8) return 3; // Asam atau Basa
    if (ph >= 5 && ph <= 6) return 2; // Sedikit Asam
    if (ph == 7) return 1; // Netral
    return 1; // default netral range 6-8
}

}
