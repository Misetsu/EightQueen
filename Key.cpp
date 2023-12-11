#include "DxLib.h"

static int m_key[256];

void Keyboard_Update() {

    char tmpKey[256];
    int i;
    
    GetHitKeyStateAll(tmpKey);

    for (i = 0 ; i < 256 ; i++) {
        if (tmpKey[i] != 0) {
            m_key[i]++;
        } else {
            m_key[i] = 0;
        }
    }
}

int Keyboard_Get(int KeyCode) {
    return m_key[KeyCode];
}